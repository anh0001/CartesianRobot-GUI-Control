import serial
import tkinter as tk
from tkinter.font import Font

arduino = serial.Serial('COM5', 9600)

def send_command(command):
    try:
        arduino.write(command.encode())
    except serial.SerialException as e:
        print(f"Error: {e}")

def write_coordinates():
    try:
        x = float(x_entry.get())
        y = float(y_entry.get())

        # Kirim perintah untuk menggerakan motor stepper ke koordinat X dan Y
        send_command(f'x{x}y{y}')

        # Update label dengan koordinat yang dikirim
        coordinates_label.config(text=f"Koordinat XY: {x}, {y}")
    except ValueError:
        print("Error: Masukkan angka valid untuk X dan Y")


def stop_robot():
    try:
        send_command('u')
        stop_label.config(text="Robot Berhenti")
    except serial.SerialException as e:
        print(f"Error: {e}")

def display_coordinates():
    try:
        send_command('z')
    except serial.SerialException as e:
        print(f"Error: {e}")

def move_x_positive():
    send_command('w')

def move_x_negative():
    send_command('s')

def move_y_positive():
    send_command('a')

def move_y_negative():
    send_command('d')

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

coordinates_button = tk.Button(root, text="START ROBOT", font=font, bg="#FF4500", fg="white", command=write_coordinates)
coordinates_button.pack(pady=10)

stop_button = tk.Button(root, text="STOP ROBOT", font=font, bg="#CD853F", fg="white", command=stop_robot)
stop_button.pack(pady=10)
stop_label = tk.Label(root, text="", font=font, bg="#F5F5F5")
stop_label.pack()

# Buttons for X and Y movement
x_positive_button = tk.Button(root, text="X+", font=font, command=move_x_positive)
x_positive_button.pack(side=tk.LEFT, padx=10)

x_negative_button = tk.Button(root, text="X-", font=font, command=move_x_negative)
x_negative_button.pack(side=tk.LEFT, padx=10)

y_positive_button = tk.Button(root, text="Y+", font=font, command=move_y_positive)
y_positive_button.pack(side=tk.LEFT, padx=10)

y_negative_button = tk.Button(root, text="Y-", font=font, command=move_y_negative)
y_negative_button.pack(side=tk.LEFT, padx=10)

root.mainloop()