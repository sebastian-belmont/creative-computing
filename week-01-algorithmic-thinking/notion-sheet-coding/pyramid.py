# pyramid.py
# Challenge 5: ask for a height and print a pyramid of stars.
# Row n has (2n - 1) stars, with spaces in front to centre it.

height = int(input("Pyramid height: "))

for row in range(1, height + 1):
    spaces = " " * (height - row)
    stars = "*" * (2 * row - 1)
    print(spaces + stars)
