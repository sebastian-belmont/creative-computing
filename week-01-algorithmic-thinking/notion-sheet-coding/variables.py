# variables.py
# Program 2: Variables about me, plus a calculation (how many weeks until Christmas).

from datetime import date

# Text (strings) with details
name = "Seb"
favourite_colour = "black"

# Whole number (integer)
number_of_modules = 2  # Introduction to Programming + Introduction to Digital Culture

print("Name:", name)
print("Favourite colour:", favourite_colour)
print("Modules this semester:", number_of_modules)

# Calculation: weeks until Christmas
today = date.today()
christmas = date(today.year, 12, 25)

# If Christmas has already passed this year, count to next year's
if today > christmas:
    christmas = date(today.year + 1, 12, 25)

days_left = (christmas - today).days
weeks_left = days_left // 7  # // divides and rounds down to a whole number

print(f"Days until Christmas: {days_left}")
print(f"That's about {weeks_left} weeks")
