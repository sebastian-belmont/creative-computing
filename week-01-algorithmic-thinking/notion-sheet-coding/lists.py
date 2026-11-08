# lists.py
# Program 5 task: a shopping list with prices.
# Each item is stored as a (name, price) tuple inside a list.

shopping = [
    ("bread", 1.40),
    ("milk", 1.25),
    ("pasta", 0.95),
    ("cheese", 3.10),
    ("coffee", 4.50),
]

print("Shopping list:")
for item, price in shopping:
    print(f"{item:<10} £{price:.2f}")

# Total cost: add up every price
total = 0
for item, price in shopping:
    total = total + price
print(f"\nTotal: £{total:.2f}")

# Most expensive item: same "largest so far" algorithm as in Part 1
most_expensive_item, highest_price = shopping[0]
for item, price in shopping:
    if price > highest_price:
        most_expensive_item = item
        highest_price = price
print(f"Most expensive: {most_expensive_item} (£{highest_price:.2f})")
