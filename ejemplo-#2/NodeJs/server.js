const express = require('express');
const { SerialPort } = require('serialport');
const { ReadlineParser } = require('@serialport/parser-readline');

const app = express();
const port = 3000;

// Configura el puerto serial (ajusta el puerto según tu sistema)
const serialPort = new SerialPort({
    path: '/dev/ttyACM0', // Cambia esto según tu sistema operativo
    baudRate: 9600,
});

// Parser para leer datos del puerto serial
const parser = serialPort.pipe(new ReadlineParser({ delimiter: '\n' }));

let lastMessageFromArduino = ''; // Almacena el último mensaje recibido

// Escucha los datos del puerto serial
parser.on('data', (data) => {
    console.log(`Datos recibidos del Arduino: ${data}`);
    lastMessageFromArduino = data.trim(); // Guarda el último mensaje
});

// Endpoint para obtener los datos del Arduino
app.get('/arduino-data', (req, res) => {
    if (lastMessageFromArduino) {
        res.json({ message: lastMessageFromArduino });
    } else {
        res.status(404).json({ error: 'No se han recibido datos del Arduino aún.' });
    }
});

// Endpoint POST para simular el envío de datos (pruebas con Postman)
app.post('/send-data', express.json(), (req, res) => {
    const { data } = req.body;
    if (data) {
        console.log(`Datos recibidos por POST: ${data}`);
        lastMessageFromArduino = data; // Simula que el Arduino envió estos datos
        res.json({ success: true, message: 'Datos recibidos correctamente.' });
    } else {
        res.status(400).json({ error: 'Falta el campo "data" en el cuerpo de la solicitud.' });
    }
});

// Inicia el servidor
app.listen(port, () => {
    console.log(`Servidor escuchando en http://localhost:${port}`);
});

/*npm run start*/