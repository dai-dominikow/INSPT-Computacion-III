##########################################################################################################
#    Unidad 9: PySerial
# Autor: Daiana Dominikow
# Computación 3 - Comisión 2024 - INSPT UTN
##########################################################################################################
# Finalmente así es cómo debería quedarles este extremadamente simplificado código para levantar la 
# información de un sensor previamente programado en Arduino y conectado por Serial para almacenarlo 
# en un archivo .csv que luego podrían analizar y levantar en un jupyter notebook con las herramientas 
# que ya conocemos de haber utilizado durante toda la cursada ;)
##########################################################################################################

# si la biblioteca PySerial no está instalada.
import os
os.system('pip install PySerial')

import serial #para leer la data del arduino uno
import serial.tools.list_ports as lp
import numpy as np
import time
import pandas as pd

#defino donde va a caer mi archivo final y su nombre
PATH = f'U9 - PySerial - obtención data sensores/U9 - Parte I - leer datos Arduino/data_sensor_{time.strftime('%H%M%S')}.csv'
#información de la placa
PUERTO_ARDUINO = '/dev/cu.usbmodem1201' # el puerto 
BAUD = 9600 # velocidad de comunicación entre la compu y el arduino
#durante cuanto tiempo vá a ejecutar mi script
TIEMPO_EJECUCION = 10 #segundos

def conectar_arduino(port, baud):
    #con el método serial.Serial(puerto, baud) puedo conectarme a la placa.
    arduino = serial.Serial(port=port, baudrate=baud)  
    print(f'Conectado exitosamente al puerto: {port} BAUD rate: {baud}')
    return arduino

#creo la función que vá a devolver cada registro
def sensor_data(arduino):
    data = arduino.readline().decode('utf-8').strip()
    print(f"Guardando data sensor a las {time.strftime('%H:%M:%S')}: {data}")
    return data 

def save_data(arduino,tiempo, ruta_archivo):
    #inicializamos el array
    datos = np.array([])

    #ahora voy a setear el tiempo final de ejecución, cosa que corte en el tiempo que establecí en la variable TIEMPO_EJECUCIÓN
    t_end = time.time() + tiempo  

    #loop de toma de datos y agregado al array
    while time.time() < t_end:
        data = sensor_data(arduino)
        datos = np.append(datos, int(data))

    #convierto a un dataframe así finalmente guardo mi archivo
    df = pd.DataFrame(datos)
    df.to_csv(ruta_archivo)

if __name__ == "__main__":
    arduino = conectar_arduino(PUERTO_ARDUINO, BAUD)
    save_data(arduino,TIEMPO_EJECUCION,PATH)
    arduino.close()
