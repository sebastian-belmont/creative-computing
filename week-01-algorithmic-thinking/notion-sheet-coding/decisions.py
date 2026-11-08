# decisions.py
# Program 3 task: ask for a temperature in Celsius, convert it to Fahrenheit, and say whether it is freezing, cold, mild, warm or hot.

celsius = float(input("Enter a temperature in Celsius: "))

# F = C x 9/5 + 32
fahrenheit = celsius * 9 / 5 + 32

print(f"{celsius}°C is {fahrenheit:.1f}°F")

# Check from coldest to hottest. Python stops at the first condition that is true, so each band only needs an upper limit.
if celsius <= 0:
    print("It's freezing")
elif celsius < 10:
    print("It's cold")
elif celsius < 18:
    print("It's mild")
elif celsius < 25:
    print("It's warm")
else:
    print("It's hot")