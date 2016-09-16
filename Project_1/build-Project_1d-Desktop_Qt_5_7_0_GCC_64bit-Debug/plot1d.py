from numpy import *
import matplotlib.pyplot as plt

# Read file containing the maximum errors
with open('1d.txt', 'r') as ins:
	error = []
	for line in ins:
		error.append(float(line))

# Compute the number of gridpoints for the errors
n = zeros(len(error))
for i in range(1,len(error)+1):
	n[i-1] = 10**(i/2.0)
# Step length h
h = 1.0/(n+1)
# Plot the relative maximum error
plt.plot(log10(h),error,'-o')
plt.xlabel('$log_{10}(h)$')
plt.ylabel('$log_{10}$ of maximum relative error')
plt.show()

# Write grid points n, step length h and maximum error to terminal
for i in range(1,len(error)+1):
	pot = i/2.0
	print 'pot = ', pot, 'step length = ', log10(h[i-1]) ,'error = ',error[i-1]	