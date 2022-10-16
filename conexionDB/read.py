import serial
import time
import mysql.connector

# Conexion a la base de datos
mydb = mysql.connector.connect(
  host="192.168.1.106",
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
        ts = time.time()
        [temp, hr, luz] = string.split(",")
        temp = float(temp)
        hr = float(hr)
        luz = luz.split("\r")[0]
        met = 70
        id = 1
        
        final_string = str(id) + ", " + str(ts) + ", " + str(temp) + ", " + str(hr) + ", " + str(luz) + ", " + str(met) + "\n"

        sql = f"INSERT INTO registro (id, fecha, temperatura, humedad, luz, riesgoDesertificacion) VALUES ({id}, {ts}, {temp},{hr},{luz},{met});\n"
        # file_object.write(final_string)
        # file_object.flush()
        print("consulta: ", sql)
        mycursor.execute(sql)
        mydb.commit()
        print("ejecutado")
        
    except:
        print("Keyboard Interrupt")
        file_object.close()
        break
