import matplotlib.pyplot as plt
import numpy as np
import pandas as pd
import sys
filename1 = sys.argv[1]
filename2 = sys.argv[2]
filename3 = sys.argv[3]
filename4 = sys.argv[4]
filename5 = sys.argv[5]
filename6 = sys.argv[6]
filename7 = sys.argv[7]
#filename8 = sys.argv[8]
#reading csv-file
data1 = pd.read_csv(filename1) 
data2 = pd.read_csv(filename2) 
data3 = pd.read_csv(filename3) 
data4 = pd.read_csv(filename4) 
data5 = pd.read_csv(filename5) 
data6 = pd.read_csv(filename6) 
data7 = pd.read_csv(filename7) 
#data8 = pd.read_csv(filename8)

#extracting columns
x1 = data1["x"][data1["abs_error"]>0]
x2 = data2["x"][data2["abs_error"]>0]
x3 = data3["x"][data3["abs_error"]>0]
x4 = data4["x"][data4["abs_error"]>0]
x5 = data5["x"][data5["abs_error"]>0]
x6 = data6["x"][data6["abs_error"]>0]
#x7 = data7["x"][data7["abs_error"]>0]

ux1 = data1["u(x)"]
ux2 = data2["u(x)"]
ux3 = data3["u(x)"]
ux4 = data4["u(x)"]
ux5 = data5["u(x)"]
ux6 = data6["u(x)"]
#ux7 = data7["u(x)"]

a_err1 = data1["abs_error"][data1["abs_error"]>0]
a_err2 = data2["abs_error"][data2["abs_error"]>0]
a_err3 = data3["abs_error"][data3["abs_error"]>0]
a_err4 = data4["abs_error"][data4["abs_error"]>0]
a_err5 = data5["abs_error"][data5["abs_error"]>0]
a_err6 = data6["abs_error"][data6["abs_error"]>0]
#a_err7 = data7["abs_error"][data7["abs_error"]>0]
r_err1 = data1[" rel_error"][data1["abs_error"]>0]
r_err2 = data2[" rel_error"][data2["abs_error"]>0]
r_err3 = data3[" rel_error"][data3["abs_error"]>0]
r_err4 = data4[" rel_error"][data4["abs_error"]>0]
r_err5 = data5[" rel_error"][data5["abs_error"]>0]
r_err6 = data6[" rel_error"][data6["abs_error"]>0]
#r_err7 = data7[" rel_error"][data7["abs_error"]>0]

a_err_max1 = data1["abs_error"].max()
r_err_max1 = data1[" rel_error"].max()
a_err_max2 = data2["abs_error"].max()
r_err_max2 = data2[" rel_error"].max()
a_err_max3 = data3["abs_error"].max()
r_err_max3 = data3[" rel_error"].max()
a_err_max4 = data4["abs_error"].max()
r_err_max4 = data4[" rel_error"].max()
a_err_max5 = data5["abs_error"].max()
r_err_max5 = data5[" rel_error"].max()
a_err_max6 = data6["abs_error"].max()
r_err_max6 = data6[" rel_error"].max()
#a_err_max7 = data7["abs_error"].max()
r_err_max7 = data7[" rel_error"].max()
#a_err_max8 = data8["abs_error"].max()
#r_err_max8 = data8[" rel_error"].max()
 
def u(x): 
	return 1-(1-np.exp(-10))*x-np.exp(-10*x) 
#plotting
#approximations
"""
plt.plot(x1, ux1, label="N=10")
plt.plot(x2, ux2, label="N=10^2")
plt.plot(x3, ux3, label="N=10^3")
plt.plot(x4, ux4, label="N=10^4")
plt.plot(x5, ux5, label="N=10^5") 
plt.plot(x4, u(x4), label="Exact") 
plt.xlabel("x") 
plt.ylabel("Function value") 
plt.legend()
plt.show()

#log of absolute error against x
plt.plot(x1, np.log10(a_err1), label="N=10") 
plt.plot(x2, np.log10(a_err2), label="N=10^2") 
plt.plot(x3, np.log10(a_err3), label="N=10^3") 
plt.plot(x4, np.log10(a_err4), label="N=10^4") 
plt.plot(x5, np.log10(a_err5), label="N=10^5") 
plt.plot(x6, np.log10(a_err6), label="N=10^6") 
#plt.plot(x7, np.log10(a_err7), label="N=10^7") 
plt.xlabel("x")
plt.ylabel("Log10(absolute error)") 
plt.legend()
plt.show()
#log of relative error against x
plt.plot(x1, np.log10(r_err1), label="N=10")
plt.plot(x2, np.log10(r_err2), label="N=10^2")
plt.plot(x3, np.log10(r_err3), label="N=10^3")
plt.plot(x4, np.log10(r_err4), label="N=10^4")
plt.plot(x5, np.log10(r_err5), label="N=10^5")
plt.plot(x6, np.log10(r_err6), label="N=10^6")
#plt.plot(x7, np.log10(r_err7), label="N=10^7")
plt.xlabel("x")
plt.ylabel("Log10(relative error)") 
plt.legend()
plt.show()
"""
#log of relative errors against log n
plt.plot(np.log10([10, 10**2, 10**3, 10**4, 10**5, 10**6, 10**7]), np.log10([r_err_max1, r_err_max2, r_err_max3, r_err_max4, r_err_max5, r_err_max6, r_err_max7]))
plt.xlabel("Log10(n)")
plt.ylabel("Log10(relative error)")
plt.show()

