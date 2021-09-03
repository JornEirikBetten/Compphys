import matplotlib.pyplot as plt
import pandas as pd

#reading csv-file
data = pd.read_csv("exact.csv")
print(data.head()) 

#extracting columns
x = data['x']
exact = data['exact_u']

#plotting
plt.plot(x, exact, label="Exact sol") 
plt.xlabel("x") 
plt.ylabel("Function value") 
plt.legend()
plt.show()

