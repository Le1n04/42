import sys
# n = len(sys.argv)
# i = 1
# while i < n:
# 	print(sys.argv[i])
# 	i += 1
txt = str(sys.argv[1:])
txt = txt.replace("[","")
txt = txt.replace("]","")
txt = txt.replace("'","")
txt = txt.replace(",","")
txt = txt[::-1]
txt = txt.swapcase()
print(txt)