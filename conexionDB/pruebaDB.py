import mysql.connector

mydb = mysql.connector.connect(
  host="192.168.1.106",
  user="indat",
  passwd="IndatSuma00",
  database="desertificacion"
)

mycursor = mydb.cursor()
val = (25, 4532.32, 763.4321)
sql = f"INSERT INTO sensor (id, latitud, longitud) VALUES ({val[0]}, {val[1]}, {val[2]})"

mycursor.execute(sql)

mydb.commit()

print(mycursor.rowcount, "registro insertado")
