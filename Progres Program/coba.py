import serial
import time

ser = serial.Serial('COM9', 9600, timeout=1)

def move_to_position(position):
    ser.write(f'{position}\n'.encode())
    print(f"Moving to position: {position}")

try:
    while True:
        try:
            target_position = int(input("Enter target position (integer): "))
            move_to_position(target_position)
        except ValueError:
            print("Invalid input. Please enter an integer.")
except KeyboardInterrupt:
    pass

finally:
    ser.close()
    print("Serial Connection Closed")
