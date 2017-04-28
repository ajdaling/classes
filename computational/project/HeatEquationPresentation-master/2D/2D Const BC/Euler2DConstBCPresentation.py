from Euler2DConstBC import *
from numpy import *
from mpl_toolkits.mplot3d import Axes3D
from matplotlib import cm
from matplotlib.ticker import LinearLocator, FormatStrFormatter
import matplotlib.pyplot as plt

set_printoptions(precision=3, suppress = True) # This is how to adjust the print options  for ndarrays in numpy.
number = 50
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

nr_times = 10
for i in range(nr_times):
	U, t = Euler2DConstBC(U, dx, dt, 1, num_unknowns, t)

fig = plt.figure()
ax = fig.gca(projection='3d', xlim=(0,pi), ylim=(0,pi), zlim=(0, 10))

surf = ax.plot_surface(X, Y, U, rstride=1, cstride=1, cmap=cm.autumn,
        linewidth=1, antialiased=False)
plt.show()

print amax(absolute(subtract(U, f(X,Y, t))))
