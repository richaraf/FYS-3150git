# Exercise 1:
from scitools.std import *
def fofx(x): # f(x)
    return arctan(x)
N = 1000
h = arange(1e-10,1e-5,1e-9)

# h = zeros(N+1)
# h[0] = 1e-7
# stplngth = 1e-7
# for i in range(N):
# 	h[i] = h[i-1] + stplngth

x = sqrt(2)
fdexact = 1./3
fd2c = (fofx(x+h)-fofx(x))/h
fd3c = (fofx(x+h)-fofx(x-h))/(2.*h)
# print 'fd2cerror =', fd2c-fdexact
# print 'fd3cerror =', fd3c-fdexact

epsilon2c = log10(abs((fd2c-fdexact))/(fdexact))
epsilon3c = log10(abs((fd3c-fdexact))/(fdexact))
plot(log10(h),epsilon2c,log10(h),epsilon3c,xlabel='log10(h)',ylabel='epsilon',legend=('epsilon2c','epsilon3c'))