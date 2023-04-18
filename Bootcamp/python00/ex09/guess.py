#!/usr/bin/env python3
import random

print("This is an interactive guessing game!")
print("You have to enter a number between 1 and 99 to find out the secret number.")
print("'Type 'exit' to end the game.")
print("Good luck!")

num = random.randint(1,99)
count = 1
while 1:
    print("What's your guess between 1 and 99?")
    choice = input(">> ")
    if choice == 'exit':
        print("Goodbye!")
        break
    try:
        choice = int(choice)
    except ValueError:
        print("That's not a number.")
        count += 1
        continue
    if choice < 1 or choice > 99:
        print("Number is out of range.")
    elif choice < num:
        print("Too low!")
    elif choice > num:
        print("Too high!")
    elif choice == num:
        if num == 42:
            print("The answer to the ultimate question of life, the universe and everything is 42.")
            if count == 1:
                print("Congratulation! You got it on your first try!")
            else:
                print("Congratulations, you've got it!")
        else:
            if count == 1:
                print("Congratulation! You got it on your first try!")
            else:
                print("Congratulations, you won in {} attempts!".format(count))
        break
    count += 1