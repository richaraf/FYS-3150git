#from scitools.std import *
import matplotlib.pyplot as plt
from numpy import *
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

plt.figure(1)
plt.plot(x,v,'--',x,anasol)
plt.xlabel('x')
plt.ylabel('u(x)')
plt.legend(['numerical','analytical'])
plt.title('n=10')

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
plt.figure(2)
plt.plot(x,v,'--',x,anasol)
plt.xlabel('x')
plt.ylabel('u(x)')
plt.legend(['numerical','analytical'])
plt.title('n=100')

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
plt.figure(3)
plt.plot(x,v,'--',x,anasol)
plt.xlabel('x')
plt.ylabel('u(x)')
plt.legend(['numerical','analytical'])
plt.title('n=1000')
plt.show()