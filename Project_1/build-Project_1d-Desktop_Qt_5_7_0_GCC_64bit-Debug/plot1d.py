from scitools.std import *

with open('1d.txt', 'r') as ins:
	error = []
	for line in ins:
		error.append(float(line))
#print error

n = zeros(len(error))
for i in range(len(error)):
	n[i] = 10**(i/2.0)

print n
h = 1.0/(n+1)
subplot(2,1,1)
plot(log10(n),error,'-o',xlabel='log10(n)', ylabel='maxerror')
subplot(2,1,2)
plot(log10(h),error,'-o',xlabel='log10(h)', ylabel='maxerror')