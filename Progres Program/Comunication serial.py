import serial
import time
import tkinter as tk

ser = serial.Serial('COM 6', baudrate=9600, timeout=1)

def send_data_on():
    ser.write(b'H')
    print("LED turned on")

def send_data_off():
    ser.write(b'L')
    print("LED turned off")

def quit():
    ser.close()
    tkTop.destroy()

tkTop = tk.Tk()
tkTop.geometry('200x100')

button1 = tk.Button(tkTop, text="ON", command=send_data_on)
button1.pack()

button2 = tk.Button(tkTop, text="OFF", command=send_data_off)
button2.pack()

button3 = tk.Button(tkTop, text="Quit", command=quit)
button3.pack()

tk.mainloop()