import sys
import string
n = int(len(sys.argv))
if n > 2:
	print('Error')
elif n == 1:
	print('')
elif n == 2:
	error = 0
	i = 0
	while i < int(len(sys.argv[1])) and error == 0:
		if sys.argv[1][i].isalpha():
			print("ERROR.")
			error = 1
		i += 1
	if error == 0:
		number = int(sys.argv[1])
		if number == 0:
			print("I'm zero")
		elif number % 2 == 0:
			print("I'm even")
		elif number % 2 is not 0:
			print("Im odd")