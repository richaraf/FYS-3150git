from scitools.std import *

with open('1b.txt', 'r') as ins:
	v = []
	for line in ins:
		v.append(float(line))

v = array(v)
n = len(v)
h = 1.0/(n+1);
x = zeros(n)
for i in range(n):
	x[i] = i*h

anasol = 1 - (1 - exp(-10))*x - exp(-10*x)
plot(x,v,x,anasol,xlabel='x',ylabel='v(x)',legend=('numerical','analytical'))