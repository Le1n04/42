#!/usr/bin/env python3
import string
import sys

n = int(len(sys.argv))
if (n != 3):
    print("Wrong arguments...")
    sys.exit()
else:
    try:
        length = int(sys.argv[2])
    except ValueError:
        print("ERROR.")
        sys.exit()
s = sys.argv[1].translate(str.maketrans('', '', string.punctuation))
txt = s.split(' ')
i = 0
while i < len(txt):
    if (len(txt[i]) <= length):
        txt.pop(i)
    else:
        i += 1
print(txt)
