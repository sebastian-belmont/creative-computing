from machine import Pin, ADC
from time import sleep

slider = ADC(Pin(34))

while True:
    value = slider.read_u16()
    print(value)
    sleep(0.05)
