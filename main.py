import serial
import pyautogui
import time

serial = serial.Serial('/dev/ttyACM0', 9600)
time.sleep(2)

while True:
    value = str(serial.readline())

    if 'play' in value:
        pyautogui.typewrite(["space"], 0.2)

    elif 'volumeup' in value:
        pyautogui.hotkey("ctrl", "i")

    elif 'volumedown' in value:
        pyautogui.hotkey("ctrl", "u")
