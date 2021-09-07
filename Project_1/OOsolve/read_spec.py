
import matplotlib.pyplot as plt
import numpy as np
import pandas as pd
import sys

filename = sys.argv[1]

data = pd.read_csv(filename)

x = data["x"]
ux = data["u(x)"]

def u(x): 
	return 1-(1-np.exp(-10))*x-np.exp(-10*x)

plt.plot(x, ux, label="special")
plt.plot(x, u(x), label="exact") 
plt.xlabel("x") 
plt.ylabel("Function value") 
plt.legend()
plt.show()



"""
Data from timing calculations. All timeused-values are the average of 10 recordings.
Plotting these against n. Timeused values are time spent in seconds. 
"""

special = np.array([2.7E-6, 5.7E-6, 3.2E-5, 2.3E-4, 2.3E-3, 1.3E-2])
general = np.array([3.8E-6, 1.0E-5, 6.5E-5, 4.4E-4, 3.3E-3, 1.6E-2])
logspecial = np.log10(special)
loggeneral = np.log10(general) 
relation = []
for i in range(len(special)): 
	relation.append(special[i]/general[i])

N = [1, 2, 3, 4, 5, 6]

plt.plot(N, special, label="Special algo") 
plt.plot(N, general, label="General algo") 
plt.xlabel("log10(N)")
plt.ylabel("Timeused in seconds")
plt.legend()
plt.show()

plt.plot(N, logspecial, label="Special algo") 
plt.plot(N, loggeneral, label="General algo") 
plt.xlabel("log10(N)")
plt.ylabel("Log10(Timeused in seconds)")
plt.legend()
plt.show()

plt.plot(N, relation, label="Relation between special and general") 
plt.xlabel("log10(number of datapoints, N)") 
plt.ylabel("Ratio special/general") 
plt.show()


