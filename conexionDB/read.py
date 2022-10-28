import serial
from scipy.special import expit
from datetime import datetime
import time
import mysql.connector

# Conexion a la base de datos
mydb = mysql.connector.connect(
  host="192.168.5.64",
  user="indat",
  passwd="IndatSuma00",
  database="desertificacion"
)

mycursor = mydb.cursor()

# Conexion al arduino
ser = serial.Serial('COM5', 9600)
ser.flushInput()
file_object = open('./data.csv', 'a')

while True:
    try:
        line = ser.readline()
        
        string = line.decode()
        print("Linea\n" + string)
        ts = time.time()
        [temp, hr, luz] = string.split(",")
        temp = float(temp)
        hr = float(hr)
        hrInv = 100 - hr
        luz = float(luz.split("\r")[0])

        b = [ 1/40, 1/100, 1/1023 ]
        print(b[0] * temp + b[1] * hrInv + b[2] * luz )
        met = expit(b[0] * temp + b[1] * hrInv + b[2] * luz ) * 100
        id = 1
        
        fecha = "\"" + datetime.fromtimestamp(ts).strftime("%Y-%m-%d %H:%M:%S") + "\""

        sql = f"INSERT INTO registro (id, fecha, temperatura, humedad, luz, riesgoDesertificacion) VALUES ({id}, {fecha}, {temp},{hr},{luz},{met});\n"
        print("consulta: ", sql)
        mycursor.execute(sql)
        mydb.commit()
        print("ejecutado")
        
    except Exception as error:
        print(error)
        file_object.close()
        break
