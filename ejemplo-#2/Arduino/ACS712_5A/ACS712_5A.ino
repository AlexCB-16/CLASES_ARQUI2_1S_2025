// Pin analógico donde está conectado el sensor
const int sensorPin = A0;c

// Parámetros del sensor ACS712 (5A)
const float sensitivity = 0.185; // Sensibilidad en V/A
const float zeroCurrentVoltage = 2.5; // Voltaje de offset en reposo (2.5V)

void setup() {
  // Inicializar comunicación serial
  Serial.begin(9600);
}

void loop() {
  // Leer el valor analógico del sensor (0-1023)
  int sensorValue = analogRead(sensorPin);

  // Convertir el valor analógico a voltios (0-1023 -> 0-5V)
  float voltage = sensorValue * (5.0 / 1023.0);

  // Calcular la corriente usando la fórmula
  float current = (voltage - zeroCurrentVoltage) / sensitivity;

  // Mostrar solo la corriente en el monitor serial
  Serial.print("Corriente: ");
  Serial.print(current, 3); // Mostrar corriente con 3 decimales
  Serial.println(" A");

  // Esperar un momento antes de la siguiente lectura
  delay(500);
}