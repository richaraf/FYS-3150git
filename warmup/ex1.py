# Exercise 1:
from scitools.std import *
def fofx(x): # f(x)
    return arctan(x)
h = array([1e-0,1e-1,1e-2,1e-3,1e-4,1e-5,1e-6,1e-7,1e-8,1e-9,1e-10,1e-11,1e-12,1e-13,1e-14,1e-15,1e-16]) # step length
x = sqrt(2)
fdexact = 1./3
fd2c = (fofx(x+h)-fofx(x))/h
fd3c = (fofx(x+h)-fofx(x-h))/(2.*h)
print 'fd2cerror =', fd2c-fdexact
print 'fd3cerror =', fd3c-fdexact

epsilon2c = log10(abs((fd2c-fdexact))/(fdexact))
epsilon3c = log10(abs((fd3c-fdexact))/(fdexact))
plot(log10(h),epsilon2c,'-o',log10(h),epsilon3c,'-x',xlabel='log10(h)',ylabel='epsilon',legend=('epsilon2c','epsilon3c'))
