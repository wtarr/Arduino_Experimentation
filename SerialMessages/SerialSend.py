import serial
userIn = ""
ser = serial.Serial("COM3", 9600)

while (userIn is not "X"):
	userIn = raw_input("Enter a PIN to turn on 0 - 7, X to exit\n\n")
	ser.write(userIn[0])