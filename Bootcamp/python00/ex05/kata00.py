kata = (19,42,21)
txt = str(kata)
txt = txt.replace("(","")
txt = txt.replace(")","")
if len(kata) == 0:
    print("No numbers in the tuple...")
else:
	print("The {} numbers are: {}".format(len(kata), txt))