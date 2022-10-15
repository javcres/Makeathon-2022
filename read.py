import serial
import time

ser = serial.Serial('COM6', 9600)
ser.flushInput()
file_object = open('./data.csv', 'a')

while True:
    try:
        line = ser.readline()
        string = line.decode()
        ts = time.time()
        [temp, hr] = string.split(",")
        temp = float(temp)
        hr = float(hr)
        met = 0.7
        id = 1
        
        final_string = str(id) + ", " + str(ts) + ", " + str(temp) + ", " + str(hr)
        file_object.write(final_string)
        print("LEIDOS: ", final_string)
        
    except:
        print("Keyboard Interrupt")
        file_object.close()
        break
