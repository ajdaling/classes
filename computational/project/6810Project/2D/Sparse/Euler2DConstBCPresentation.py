from matplotlib import cm
from numpy import *

from Euler2DConstBC import Euler2DConstBC  # We can just import the function we need
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D


set_printoptions(precision=3, suppress = True) # This is how to adjust the print options  for ndarrays in numpy.
number = 20
x = linspace(0, pi, number)
dx = x[1] - x[0]
num_unknowns = len(x) - 2
y = linspace(pi, 0,  number) 
X, Y = meshgrid(x, y)
t0 = 0
f = lambda x, y, t: 10*e**(-2*t)*(sin(y)*sin(x)) + 2
U0 = f(X, Y, t0) # Our initial condition
U = U0
t = t0
dt = 0.1*(2*dx**2)
finaltime=10

nr_times = int(finaltime/dt)
for i in range(nr_times):
	U, t = Euler2DConstBC(U, dx, dt, 1, num_unknowns, t)

fig = plt.figure()
ax = plt.axes(projection='3d', xlim=(0,pi), ylim=(0,pi), zlim=(0, 10)) # The same as our 
ax.plot_surface(X, Y, U, rstride=1, cstride=1, linewidth=2, antialiased=1, cmap = cm.autumn)
plt.show()

print amax(absolute(subtract(U, f(X,Y, t))))
