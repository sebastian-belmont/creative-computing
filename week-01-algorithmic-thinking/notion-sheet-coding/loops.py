# loops.py
# Program 4 task: using for and while loops to repeat things.

name = "Seb"

print("My name 10 times:")
for i in range(10):
    print(name)

print("\n9 times table:")
for i in range(1, 13):
    print(f"9 × {i} = {9 * i}")

print("\nCountdown from 20:")
count = 20
while count > 0:
    print(count)
    count = count - 1
print("Done!")

print("\nTriangle")
# Row 1 has 1 star, row 2 has 2 stars, and so on
for row in range(1, 6):
    print("*" * row)
