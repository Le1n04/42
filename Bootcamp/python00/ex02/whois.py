import sys
n = int(len(sys.argv))
if n > 2:
	print('Error')
elif n == 1:
	print('')
elif n == 2:
	number = int(sys.argv[1])
	if number == 0:
		print("I'm zero")
	elif number % 2 == 0:
		print("I'm even")
	else:
		print("Im odd")