import json
import serial
import time

from io import open

hw_sensor = serial.Serial(port='COM6', baudrate=9600, timeout=1, write_timeout=1)

if __name__ == '__main__':
    # while True:
    raw_string_b = hw_sensor.readline()
    print(len(raw_string_b))
