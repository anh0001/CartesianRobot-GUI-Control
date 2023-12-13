import tkinter as tk
from tkinter.font import Font


# Membuat fungsi untuk menampilkan koordinat XYZ
def show_coordinates():
    x = x_entry.get()
    y = y_entry.get()
    z = z_entry.get()
    coordinates_label.config(text="Koordinat XYZ: ({}, {}, {})".format(x, y, z))

# Membuat fungsi untuk memulai robot
def start_robot():
    start_label.config(text="Running")

# Membuat fungsi untuk menghentikan robot
def stop_robot():
    stop_label.config(text="Stopped")
#menghubungkan GUI ke Arduino

# Membuat GUI
root = tk.Tk()
root.title("Program GUI untuk Kartesian Robot")
root.configure(bg="#F5F5F5")




# Membuat font Roboto
font = Font(family="roboto", size=16)

# Membuat label untuk koordinat XYZ
coordinates_label = tk.Label(root, text="Koordinat XYZ: ", font=font, bg="#F5F5F5")
coordinates_label.pack(pady=100, padx=50)

# Membuat entry untuk koordinat X
x_label = tk.Label(root, text="X: ", font=font, bg="#F5F5F5")
x_label.pack()
x_entry = tk.Entry(root, font=font)
x_entry.pack()

# Membuat entry untuk koordinat Y
y_label = tk.Label(root, text="Y: ", font=font, bg="#F5F5F5")
y_label.pack()
y_entry = tk.Entry(root, font=font)
y_entry.pack()

# Membuat entry untuk koordinat Z
z_label = tk.Label(root, text="Z: ", font=font, bg="#F5F5F5")
z_label.pack()
z_entry = tk.Entry(root, font=font)
z_entry.pack()

# Membuat tombol untuk menampilkan koordinat XYZ
coordinates_button = tk.Button(root, text="Tampilkan Koordinat", font=font, bg="#FF4500", fg="white", command=show_coordinates)
coordinates_button.pack(pady=10)

# Membuat tombol untuk memulai robot
start_button = tk.Button(root, text="START ROBOT", font=font, bg="#4682B4", fg="white", command=start_robot)
start_button.pack(pady=10)
start_label = tk.Label(root, text="", font=font, bg="#F5F5F5")
start_label.pack()

# Membuat tombol untuk menghentikan robot
stop_button = tk.Button(root, text="STOP ROBOT", font=font, bg="#CD853F", fg="white", command=stop_robot)
stop_button.pack(pady=10)
stop_label = tk.Label(root, text="", font=font, bg="#F5F5F5")
stop_label.pack()


root.mainloop()