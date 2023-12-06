import serial
arduino = serial.Serial('COM9', 9600)

def send_command(command):
    try:
        arduino.write(command.encode())
    except serial.SerialException as e:
        print(f"Error: {e}")


def startRobot():
    send_command('A')
    start_label.config(text="Robot Mulai Bergerak")

def stopRobot():
    send_command('B')
    stop_label.config(text="Robot Berhenti")

def writeCoordinates():
    try:
        x = float(x_entry.get())
        y = float(y_entry.get())
        send_command(f'C {x} {y}')
        coordinates_label.config(text=f"Koordinat XY: {x}, {y}")
    except ValueError:
        print("Error: Masukkan angka valid untuk X dan Y")

def displayCoordinates():
    try:
        x = float(x_entry.get())
        y = float(y_entry.get())
        send_command(f'C {x} {y}')
        coordinates_label.config(text=f"Koordinat XY: {x}, {y}")
    except ValueError:
        print("Error: Masukkan angka valid untuk X dan Y")
