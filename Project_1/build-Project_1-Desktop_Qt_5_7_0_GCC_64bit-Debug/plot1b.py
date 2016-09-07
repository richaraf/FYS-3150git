from scitools.std import *
with open('1b.txt', 'r') as ins:
	v = []
	for line in ins:
		v.append(float(line))
v = array(v)