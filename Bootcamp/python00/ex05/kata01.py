kata = {
'Python': 'Guido van Rossum',
'Ruby': 'Yukihiro Matsumoto',
'PHP': 'Rasmus Lerdorf',
}
txt = str(kata)
txt = txt.replace("'","")
txt = txt.replace("'","")
txt = txt.replace("{","")
txt = txt.replace("}","")
i = 0
while i < int(len(txt)):
	if txt[i] == ":":
		print(" was created by", end ="")
	elif txt[i] == ',':
		print()
		i += 1
	elif (txt[i] != ":" and txt[i] != ','):
		print(txt[i], end="")
	i += 1
print()