from flask import Flask, jsonify
import pymysql
from dotenv import load_dotenv
import os
# Crear el entorno virtual con el nombre "venv1"
#python3 -m venv venv1
# Activar el entorno virtual
#source venv1/bin/activate
#curl -X GET http://192.168.0.28:5000/datos

# Cargar las variables de entorno desde el archivo .env
load_dotenv()

app = Flask(__name__)

# Leer las variables de entorno
RDS_HOST = os.getenv('RDS_HOST')
RDS_USER = os.getenv('RDS_USER')
RDS_PASSWORD = os.getenv('RDS_PASSWORD')
RDS_DB = os.getenv('RDS_DB')

def obtener_datos_desde_procedimiento():
    """
    Función para conectarse a la base de datos RDS y ejecutar el procedimiento almacenado.
    """
    try:
        # Conexión a la base de datos
        connection = pymysql.connect(
            host=RDS_HOST,
            user=RDS_USER,
            password=RDS_PASSWORD,
            database=RDS_DB,
            cursorclass=pymysql.cursors.DictCursor
        )

        with connection.cursor() as cursor:
            # Llamar al procedimiento almacenado
            cursor.callproc('obtener_ultimo_insertado') 
            result = cursor.fetchall()

        # Cerrar la conexión
        connection.close()
        return result

    except Exception as e:
        print(f"Error al conectar o ejecutar el procedimiento: {e}")
        return None

@app.route('/datos', methods=['GET'])
def obtener_datos():
    """
    Endpoint para obtener los datos desde el procedimiento almacenado.
    """
    datos = obtener_datos_desde_procedimiento()
    if datos:
        return jsonify(datos), 200
    else:
        return jsonify({"error": "No se pudieron obtener los datos"}), 500

if __name__ == '__main__':
    app.run(debug=True, host='0.0.0.0', port=5000)