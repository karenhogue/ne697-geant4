import matplotlib.pyplot as plt
import numpy as np
import csv

x=np.array([])
z=np.array([])
eventID = -1

with open("./build/hits.csv", newline='') as csv_file:
    csv_reader = csv.DictReader(csv_file)
    for row in csv_reader:
        if(row['eventID']!=eventID):
            x = np.append(x, float(row['x[cm]']))
            z = np.append(z, float(row['z[cm]']))
            eventID = row['eventID']

plt.hist2d(x, z, bins=100, cmap = 'Oranges_r')
plt.xlabel("x position (cm)")
plt.ylabel("z position (cm)")
plt.colorbar()
plt.show()
