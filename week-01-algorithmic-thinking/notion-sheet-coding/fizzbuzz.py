# fizzbuzz.py
# Challenge 4: print 1 to 30, but "Fizz" for multiples of 3, "Buzz" for multiples of 5, and "FizzBuzz" for multiples of both.

for number in range(1, 31):
    # Check "both" first, otherwise 15 would just print "Fizz"
    if number % 3 == 0 and number % 5 == 0:
        print("FizzBuzz")
    elif number % 3 == 0:
        print("Fizz")
    elif number % 5 == 0:
        print("Buzz")
    else:
        print(number)
