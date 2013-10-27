import serial
userIn = ""
ser = serial.Serial("COM3", 9600)

while (userIn is not "X"):
	userIn = raw_input("Enter an Integer 0 - 255\n\n")
	ser.write(userIn)
