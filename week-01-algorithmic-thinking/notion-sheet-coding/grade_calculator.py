# grade_calculator.py
# Challenge 3: ask for 5 test scores, work out the average, and show the UK degree classification for it.

scores = []
for i in range(1, 6):
    score = float(input(f"Score for test {i}: "))
    scores.append(score)

average = sum(scores) / len(scores)
print(f"\nAverage: {average:.1f}")

if average >= 70:
    grade = "First class"
elif average >= 60:
    grade = "Upper second (2:1)"
elif average >= 50:
    grade = "Lower second (2:2)"
elif average >= 40:
    grade = "Third class"
else:
    grade = "Fail"

print(f"Grade: {grade}")
