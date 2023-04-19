#!/usr/bin/env python3
kata = (0, 4, 132.42222, 10000, 12345.67)
if (len(kata) >= 5):
	print("module_0{}, ex_0{} : {:.2f}, {:.2e}, {:.2e}".format(kata[0], kata[1], kata[2], kata[3], kata[4]))
else:
	print("<ERROR>")