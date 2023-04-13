#!/usr/bin/env python3
kata = "The right format"

if (len(kata) <= 42):
	s = (42 - len(kata)) * '-'
	print(s + kata, end ="")
else:
	print("Kata is too long.")