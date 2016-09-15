from scitools.std import *

with open('1bn10.txt', 'r') as ins:
	v = [0.0]
	for line in ins:
		v.append(float(line))
v.append(0.0)
v = array(v)
n = len(v)-2
h = 1.0/(n+1);
x = zeros(n+2)
for i in range(0,n+2):
	x[i] = i*h
anasol = 1 - (1 - exp(-10))*x - exp(-10*x)
figure(1)
#subplot(2,1,1)
plot(x,v,x,anasol,xlabel='x',ylabel='u(x)',legend=('numerical','analytical'),title='n=10')
#diff = abs(anasol-v)
#reldiff = diff/v
#subplot(2,1,2)
#plot(x,log10(reldiff),xlabel='x',ylabel='log10(relative error)')

with open('1bn100.txt', 'r') as ins:
	v = [0.0]
	for line in ins:
		v.append(float(line))
v.append(0.0)
v = array(v)
n = len(v)-2
h = 1.0/(n+1);
x = zeros(n+2)
for i in range(0,n+2):
	x[i] = i*h
anasol = 1 - (1 - exp(-10))*x - exp(-10*x)
figure(2)
#subplot(2,1,1)
plot(x,v,x,anasol,xlabel='x',ylabel='u(x)',legend=('numerical','analytical'),title='n=100')
#diff = abs(anasol-v)
#reldiff = diff/v
#subplot(2,1,2)
#plot(x,log10(reldiff),xlabel='x',ylabel='log10(relative error)')

with open('1bn1000.txt', 'r') as ins:
	v = [0.0]
	for line in ins:
		v.append(float(line))
v.append(0.0)
v = array(v)
n = len(v)-2
h = 1.0/(n+1);
x = zeros(n+2)
for i in range(0,n+2):
	x[i] = i*h
anasol = 1 - (1 - exp(-10))*x - exp(-10*x)
figure(3)
#subplot(2,1,1)
plot(x,v,x,anasol,xlabel='x',ylabel='u(x)',legend=('numerical','analytical'),title='n=1000')
#diff = abs(anasol-v)
#reldiff = diff/v
#subplot(2,1,2)
#plot(x,log10(reldiff),xlabel='x',ylabel='log10(relative error)')