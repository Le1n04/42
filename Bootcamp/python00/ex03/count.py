#!/usr/bin/env python3
import sys
import string


def	text_analyzer(*args):
	"""Counts the number of upper, lower, punctuation and space characters."""
	a = int(len(args))
	space = 0
	if a > 1:
		print('Error, more than one argument.')
		return
	elif a == 0:
		print('No arguments given, please give me a text:')
		sys.stdout.flush()
		str = sys.stdin.readline()
		space -= 1
	else:
		str = args[0]
	i = 0
	upper = 0
	lower = 0
	punc = 0
	for i in range(len(str)):
		if str[i].isupper():
			upper += 1
		elif str[i].islower():
			lower += 1
		elif str[i] in (string.punctuation):
			punc += 1
		elif str[i] in (' ', '\t', '\n', '\r', '\v', '\f'):
			space += 1
	print ("The text contains {} characters:".format(len(str)))
	print ("- {} upper letter(s)".format(upper))
	print ("- {} lower letter(s)".format(lower))
	print ("- {} punctuation mark(s)".format(punc))
	print ("- {} space(s)".format(space))
	return

if __name__ == "__main__":
	str = ""
	if len(sys.argv) == 1 or len(sys.argv[1]) == 0:
		while len(str) == 0:
			if len(sys.argv) == 1 or len(sys.argv[1]) == 0:
				print("Give me a string:")
				print(">> ", end="")
				str = input()
	else:
		str = sys.argv[1]
	text_analyzer(str)
