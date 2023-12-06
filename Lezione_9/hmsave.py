import matplotlib.pyplot as plt
from matplotlib.patches import Ellipse
import numpy as np

x, y = np.loadtxt('punti.dat', usecols=(0,1), unpack=True, skiprows=1)

a = plt.subplot(1, 1, 1, aspect='equal')
a.add_patch(Ellipse((0, 0), 4, 2, angle=0, fill=False))
a.add_patch(Ellipse((0, 0), 4, 2, angle=90, fill=False))

plt.xlabel('x')
plt.ylabel('y')
plt.grid()
plt.xlim(-2, 2)
plt.ylim(-2, 2)

plt.plot(x, y, 'r.')

plt.savefig('hmsave.png')
