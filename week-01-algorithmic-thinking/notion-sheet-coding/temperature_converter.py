# temperature_converter.py
# Challenge 1: ask for a temperature in Celsius, convert it to Fahrenheit, and display both.

celsius = float(input("Temperature in Celsius: "))
fahrenheit = (celsius * 9 / 5) + 32

print(f"{celsius}°C = {fahrenheit:.1f}°F")
