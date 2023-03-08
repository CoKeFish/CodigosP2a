import json
import serial
import time

hw_sensor = serial.Serial(port='COM7', baudrate=2000000, timeout=1, write_timeout=1)

if __name__ == '__main__':
    #while True:
        raw_string_b = hw_sensor.readline()
        print(raw_string_b)
        raw_string_b = hw_sensor.readline()
        print(raw_string_b)
