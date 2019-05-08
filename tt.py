import serial
import time
ser = serial.Serial('COM7',9600)
i=0
while(1):
    print(i)
    i+=1
    res_lis = ser.readline().decode().split('\t')
    if(len(res_lis)==5):
        p_sensor = res_lis[0]
        f_sensor = res_lis[1]
        h = res_lis[2]
        t = res_lis[3]
        p_sensor = int(p_sensor) 
        f_sensor = int(f_sensor)
        print("{} {} {} {}".format(p_sensor,f_sensor,h,t))
        if(p_sensor == 0):
            print("Robber is coming")
        elif(p_sensor == 1):
            print("No robber")
        if(f_sensor == 0):
            print("No Fire")
        elif(f_sensor == 1):
            print("Fire")
        print("Humid : {}".format(h))
        print("Temperature : {}".format(t))