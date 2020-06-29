import time
import serial
import tty
serdev = '/dev/ttyUSB0'
s = serial.Serial(serdev, 9600)
fp = open("123.txt", "w")
while(True):
    line = s.readline()
    # print(line)
    tmp = line.decode("utf-8")
    print(tmp)
    fp.write(tmp)
    # time.sleep(1)
fp.close()