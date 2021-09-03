import matplotlib.pyplot as plt
import pandas as pd
import sys
filename = sys.argv[1]
row_1 = sys.argv[2]
row_2 = sys.argv[3]
label_1 = sys.argv[4]
#reading csv-file
data = pd.read_csv(filename)
print(data.head()) 

#extracting columns
x = data[row_1]
u_x = data[row_2]

#plotting
plt.plot(x, u_x, label=label_1) 
plt.xlabel("x") 
plt.ylabel("Function value") 
plt.legend()
plt.show()

