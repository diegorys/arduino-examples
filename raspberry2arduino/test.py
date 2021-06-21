import serial
import sys

ser = serial.Serial('/dev/serial0', 9600, timeout=1)
ser.write(sys.argv[1].encode())
response = ""
while response == "":
    response = ser.readline().decode()
print(response)
ser.close()
