# -*- coding: utf-8 -*-
"""
Created on Mon Apr 11 14:39:33 2022

@author: Jason
"""

import serial
import time

#右側輪胎
COM_PORT1 = 'COM1'
COM_PORT2 = 'COM2'

#左側輪胎
COM_PORT3 = 'COM3'
COM_PORT4 = 'COM4'

baudRate = 9600
ser1 = serial.Serial(COM_PORT1, baudRate, timeout=0.5)
ser2 = serial.Serial(COM_PORT2, baudRate, timeout=0.5)
ser3 = serial.Serial(COM_PORT3, baudRate, timeout=0.5)
ser4 = serial.Serial(COM_PORT4, baudRate, timeout=0.5)

try:
    while True:
        # 接收用戶的輸入值並轉成小寫
        choice = input('2/4/6/8 --> 2後退 /4往左 /6往右 /8前進 /q 離開')

        if choice == 'q':
            ser1.write(0)
            ser2.write(0)
            ser3.write(0)
            ser4.write(0)
            time.sleep(0.5)
            break

        elif (choice.isnumeric()): 
            if int(choice) == 2:
                 backward()

            elif int(choice) == 4:
                 left()

            elif int(choice) == 6:
                 right()

            elif int(choice) == 8:
                 forward()
            
            else :
                print('請重新輸入!! 2/4/6/8 --> 2後退 /4往左 /6往右 /8前進 /q 離開')
                pass

finally:
    ser1.close()
    ser2.close()
    ser3.close()
    ser4.close()
    print('各串口已關閉')


#0為靜止，1為正轉，2為反轉
def right():
    ser1.write(0)
    ser2.write(0)
    ser3.write(1)
    ser4.write(1)
    time.sleep(0.5)
    
    return True

def left():
    ser1.write(1)
    ser2.write(1)
    ser3.write(0)
    ser4.write(0)
    time.sleep(0.5)

    return True

def forward():
    ser1.write(1)
    ser2.write(1)
    ser3.write(1)
    ser4.write(1)
    time.sleep(0.5)

    return True


def backward():
    ser1.write(2)
    ser2.write(2)
    ser3.write(2)
    ser4.write(2)
    time.sleep(0.5)

    return True
