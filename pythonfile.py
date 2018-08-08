import serial #Import Serial Library
from visual import *                                                                                            #all vpython libraries imported

arduinoData=serial.Serial('com5',9600);                                                                         #object for communication on serial port
measuringRod=cylinder(title="My Meter" , radius=.5 , length=.6 ,color=color.yellow , pos=(-3,0,0))              #cylinder object
myLabel= label(pos=(0,1,0) , text="Target Distance Is: " , box=false , height=20)                               #label object

while(1==1):
    rate(10)                                                                                                    #loop runs 20 times a second
    if(arduinoData.inWaiting()>0):
        data=arduinoData.readline()                                                                             #reads the data on the serial port in form of string
        dist=float(data)
        print dist
        measuringRod.length=dist                                                                                #measures distance in the measuring rod
        mylabel="Target Dist is: " + data                                                                       #append string.
        myLabel.text=mylabel                                                                                    #display updated mylabel
    
