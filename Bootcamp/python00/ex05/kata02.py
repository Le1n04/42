#!/usr/bin/env python3
kata = (2019, 9, 25, 3, 30)
m = ""
d = ""
y = ""
h = ""
min = ""
if (len(kata) >= 5):
    if kata[3] < 10:
        m = "0"
    if kata[4] < 10:
        d = "0"
    if kata[2] < 1000:
        y = "0"
    if kata[2] < 100:
        y = "00"
    if kata[2] < 10:
        y = "000"
    if kata[0] < 10:
        h = "0"
    if kata[1] < 10:
        min = "0"
    print("{}{}/{}{}/{}{} {}{}:{}{}"
          .format(m, kata[3], d, kata[4], y, kata[2], h, kata[0], min, kata[1]))
else:
    print("ERROR.")