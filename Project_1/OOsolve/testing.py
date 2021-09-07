import numpy as np


N = 10.
h = 1/N
x = []
for i in range(int(N+1)): 
	x.append(i*h)
print(len(x)) 
print(x) 
