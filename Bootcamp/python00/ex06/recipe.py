#!/usr/bin/env python3
import sys

cookbook = {
    'sandwich': (['ham', 'bread', 'cheese', 'tomatoes'], 'lunch', '10'),
    'cake': (['flour', 'sugar', 'eggs'], 'dessert', '60'),
    'salad': (['avocado', 'arugula', 'tomatoes', 'spinach'], 'lunch', '15')
}

# cookbook.keys is sandwich, cake, salad.
# ingredients is a list of string
# meal is a string representing the type of meal
# prep_time is a non negative integer representing a time in minutes

def	recipe_printer(name):
    if name in cookbook.keys():
        print("Recipe for {}:".format(name))
        print("The ingredients are: {}".format(cookbook[name][0]))
        print("This recipe is a {}.".format(cookbook[name][1]))
        print("It will take you {} minutes of cooking.".format(cookbook[name][2]))
    else:
        print("<ERROR 404 - recipe not found>")
        
def	print_names(name):
    if name in cookbook.keys():
        print("{}".format(name))

def print_all_names_details():
    for x in cookbook.keys():
        recipe_printer(x)
        print()

def	print_all_names():
    for x in cookbook.keys():
        print_names(x)
        print()

def	delete_recipe(name):
    if name in cookbook.keys():
        del cookbook[name]
        print("Recipe '{}' has been deleted...".format(name))
    else:
        print("<ERROR 404 - recipe not found>")

def add_recipe(name, ingredients, meal, time):
    if name in cookbook.keys():
        print("'{}' already exists, rewriting the recipe...".format(name))
    cookbook[name] = (ingredients, meal, time)
    print("'{}' successfully added to cookbook.".format(name))

# sys.stdout.flush() temporarily stores data while it is being moved
# The try block lets you test a block of code for errors.
# The except block lets you handle the error.
# The else block lets you execute code when there is no error.
# The finally block lets you execute code, regardless of the result of the try- and except blocks.

choice = 0
while not choice == 5:
    print("Select one of the following options by introducing the number:")
    print("1. Add recipe.")
    print("2. Delete recipe.")
    print("3. Print a recipe.")
    print("4. Print all recipes.")
    print("5. Quit.")
    print(">> ", end="")
    sys.stdout.flush()
    try:
        choice = int(sys.stdin.readline())
    except ValueError:
        choice = 0
    print ("")
    if choice == 1:
        name = input("Enter the name of the recipe you want to add: ")
        ingr = input("Enter the ingredients like this 'rice,corn,bread,...': ").split(',')
        meal = input("Enter the type of meal: ")
        time = input("Enter the cooking duration in minutes: ")
        add_recipe(name, ingr, meal, time)
    elif choice == 2:
        name = input("Enter the recipe to delete from the cookbook: ")
        delete_recipe(name)
    elif choice == 3:
        name = input("Enter the name of the recipe you want to print: ")
        recipe_printer(name)
    elif choice == 4:
        print_all_names_details()
    elif choice == 5:
        print("Closed.")
    else:
        print("Error, wrong input given...")
    print()