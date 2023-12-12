#import maksudnya disini adalah kendali gui dari masing masing robot 

import serial
import tkinter as tk

# Inisialisasi koneksi serial dengan Arduino
ser = serial.Serial('COM6', 9600)  # Ganti 'COM3' dengan port yang sesuai dan sesuaikan baud rate (9600) sesuai dengan pengaturan di Arduino.

# Fungsi untuk mengirim perintah ke Arduino
def send_command(command):
    ser.write(command.encode())

# Membuat fungsi untuk menyalakan LED
def turn_on_led():
    send_command('H')

# Membuat fungsi untuk mematikan LED
def turn_off_led():
    send_command('L')

# Membuat GUI
root = tk.Tk()
root.title("Cartesian Robot")

on_button = tk.Button(root, text="Nyalakan LED", )
on_button.grid(row=0, column=0)

off_button = tk.Button(root, text="Matikan LED", )
off_button.grid(row=1, column=1)

quit_button = tk.Button(root, text="Keluar", command=root.quit)
quit_button.grid(row=2, column=2)

root.mainloop()

