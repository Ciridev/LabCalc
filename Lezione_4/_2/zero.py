import matplotlib.pyplot as plt
import numpy as np

x, y = np.loadtxt("zero.dat", unpack=True, usecols=(0, 1))
plt.title("Number of zeros")
plt.xlabel("Number of points")
plt.ylabel("Number of zeros")
plt.plot(x, y, 'c-o')
plt.savefig("zero.png")
