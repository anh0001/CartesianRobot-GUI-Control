import serial
import tkinter as tk
from tkinter.font import Font

arduino = serial.Serial('COM9', 9600)
root = tk.Tk()
root.title("Program GUI untuk Kartesian Robot")
root.configure(bg="#F5F5F5")


font = Font(family="roboto", size=16)

coordinates_label = tk.Label(root, text="Koordinat XY: ", font=font, bg="#F5F5F5")
coordinates_label.pack(pady=100, padx=50)

x_label = tk.Label(root, text="X: ", font=font, bg="#F5F5F5")
x_label.pack()
x_entry = tk.Entry(root, font=font)
x_entry.pack()

y_label = tk.Label(root, text="Y: ", font=font, bg="#F5F5F5")
y_label.pack()
y_entry = tk.Entry(root, font=font)
y_entry.pack()


coordinates_button = tk.Button(root, text="Tampilkan Koordinat", font=font, bg="#FF4500", fg="white", command=displayCoordinates)
coordinates_button.pack(pady=10)

start_button = tk.Button(root, text="START ROBOT", font=font, bg="#4682B4", fg="white", command=startRobot)
start_button.pack(pady=10)
start_label = tk.Label(root, text="", font=font, bg="#F5F5F5")
start_label.pack()

stop_button = tk.Button(root, text="STOP ROBOT", font=font, bg="#CD853F", fg="white", command=stopRobot)
stop_button.pack(pady=10)
stop_label = tk.Label(root, text="", font=font, bg="#F5F5F5")
stop_label.pack()

root.mainloop()


