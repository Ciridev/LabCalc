import numpy as np
import matplotlib.pyplot as plt

x, y = np.loadtxt('bernoulli.dat', unpack=True, usecols=(0,1))
plt.title('Bernoulli')
plt.xlabel('K')
plt.ylabel('P(K)')
plt.bar(x, y, fill=True)
plt.savefig('bernoulli.png')
