import matplotlib.pyplot as plt
import numpy as np

bins, occurrencies, frequencies = np.loadtxt("isto.dat", unpack=True, usecols=(0,1,2))

sum = 0
for i in occurrencies:
    sum += i
throws = sum

plt.figure(1)
plt.xlabel("Bins")
plt.ylabel("Occurrencies")
plt.title("Occurrencies per bins")
plt.bar(bins, occurrencies, fill=True, color='darkviolet', label='O/B')
plt.savefig(f'Images/histogram_occ_{int(throws)}.png')

plt.figure(2)
plt.xlabel("Bins")
plt.ylabel("Frequencies")
plt.title("Frequencies per bins")
plt.bar(bins, frequencies, fill=True, color='darkviolet', label='F/B')
plt.savefig(f'Images/histogram_freq_{int(throws)}.png')
