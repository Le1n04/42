#!/usr/bin/env python3
import sys


morse_dict = {'A': '.-', 'B': '-...',
              'C': '-.-.', 'D': '-..', 'E': '.',
              'F': '..-.', 'G': '--.', 'H': '....',
              'I': '..', 'J': '.---', 'K': '-.-',
              'L': '.-..', 'M': '--', 'N': '-.',
              'O': '---', 'P': '.--.', 'Q': '--.-',
              'R': '.-.', 'S': '...', 'T': '-',
              'U': '..-', 'V': '...-', 'W': '.--',
              'X': '-..-', 'Y': '-.--', 'Z': '--..',
              '1': '.----', '2': '..---', '3': '...--',
              '4': '....-', '5': '.....', '6': '-....',
              '7': '--...', '8': '---..', '9': '----.',
              '0': '-----', ' ': '/'}

def print_morse(str):
    if str.translate(str.maketrans('', '', ' ')).isalnum():
        str = str.upper()
        for j in str:
            print(morse_dict[j], end=" ")
        print("")
    else:
        print("ERROR.")

length = int(len(sys.argv))
if length > 1:
    str = sys.argv[1]
    for i in range(length - 2):
        str = str + " " + sys.argv[i + 2]
    print_morse(str)
else:
    print("Not enough arguments.")