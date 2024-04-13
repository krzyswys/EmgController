# immitates data sent via serial
import serial
import time

ser = serial.Serial("COM4", 115200)
time.sleep(2)

with open("DataProcessing/InterceptedData/data.txt", "r") as file:
    lines = file.readlines()

for line in lines:
    ser.write(line.encode())
    time.sleep(0.1)

ser.close()
