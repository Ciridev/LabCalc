import matplotlib.pyplot as plt
from matplotlib.patches import Ellipse
import numpy as np

datax, datay = np.loadtxt('punti_generic.dat', usecols=(0,1), unpack=True, skiprows=1)

x = datax[1:len(datax)]
y = datay[1:len(datay)]

a = plt.subplot(1, 1, 1, aspect='equal')
a.add_patch(Ellipse((0, 0), 2 * 1 / datax[0], 2 * 1 / datay[0], angle=0, fill=False))
a.add_patch(Ellipse((0, 0), 2 * 1 / datax[0], 2 * 1 / datay[0], angle=90, fill=False))

intervallo = 2 / max(datax[0], datay[0])

plt.xlabel('x')
plt.ylabel('y')
plt.grid()
plt.xlim(-intervallo, intervallo)
plt.ylim(-intervallo, intervallo)

plt.plot(x, y, 'r.')

plt.savefig('hmsave_generic.png')
