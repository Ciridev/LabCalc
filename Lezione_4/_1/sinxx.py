import matplotlib.pyplot as plt
import numpy as np

x, y = np.loadtxt("sinxx.dat", unpack=True, usecols=(0, 1))
plt.title("Function plot")
plt.xlabel("x")
plt.ylabel("f(x)")
plt.plot(x, y, 'b-', linewidth=1, markersize=3, markerfacecolor='b', label='f(x)=sin(x)/x')
plt.plot(x, y, 'bo', linewidth=1, markersize=3, markerfacecolor='b', label= f'N_p = {len(x)}')
plt.legend()
plt.savefig("zero.png")
