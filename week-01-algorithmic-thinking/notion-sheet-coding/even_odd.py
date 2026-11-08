# even_odd.py
# Challenge 2: tell the user whether their number is even or odd.
# % (modulo) gives the remainder after dividing. If a number divided by 2 leaves no remainder, it is even.

number = int(input("Enter a whole number: "))

if number % 2 == 0:
    print(f"{number} is even")
else:
    print(f"{number} is odd")
