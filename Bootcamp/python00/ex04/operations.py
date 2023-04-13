#!/usr/bin/env python3
import sys

error = 0
if int(len(sys.argv)) != 3:
	error = 1
if error == 0:
	stra = str(sys.argv[1])
	strb = str(sys.argv[2])
	lena = int(len(sys.argv[1]))
	lenb = int(len(sys.argv[2]))
i = 0
if error == 0:
	while i < lena:
		if stra[i].isalpha():
			error = 1
		i += 1
i = 0
if error == 0:
	while i < lenb:
		if strb[i].isalpha():
			error = 1
		i += 1
if error == 1:
	print ("ERROR.")
if error == 0:
	n = int(sys.argv[1])
	m = int(sys.argv[2])
	suma = n + m
	diff = n - m
	prod = n * m
	if (m != 0):
		quot = n / m
		rem = n % m
	else:
		quot = "Error, impossible operation."
		rem = "Error, impossible operation."
	print("Sum:		{}".format(suma))
	print("Difference:	{}".format(diff))
	print("Product:	{}".format(prod))
	print("Quotient:	{}".format(quot))
	print("Remainder:	{}".format(rem))