import numpy as np
import matplotlib.pyplot as plt

x, y = np.loadtxt('histogram.dat', unpack=True, usecols=(0,1))
plt.title('Histogram')
plt.xlabel('Number of throws')
plt.ylabel('Frequency of throws')
plt.bar(x, y, fill=True)
plt.savefig('histogram.png')
