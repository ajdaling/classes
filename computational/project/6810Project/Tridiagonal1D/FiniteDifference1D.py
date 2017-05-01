'''
Created on Apr 29, 2017

@author: aj
'''

from matplotlib import animation as anim, pyplot
from matplotlib.widgets import Slider, Button, RadioButtons
from numpy import e, linspace, zeros, arange
from library import *

x_min = 0
x_max = 9
num_points = x_max+1 #number of x points
#initialize 1d array of points
x,dx = linspace(x_min,x_max,num_points,retstep = True)
t0 = 0
r = 0.4	#must be <0.5 for stability for FD
dt = r*(dx**2)
t_max = 200
time = t0

u = zeros(num_points) #u(x,t)
u_1 = zeros(num_points) #u(x,t-1)

for i in range(x_min,x_max+1):
	u_1[i] = i

#plot vars
#fig = pyplot.figure()

fig, ax = pyplot.subplots()
pyplot.subplots_adjust(left = 0.25, bottom = 0.25)
axes = pyplot.axes(xlim=(x_min,x_max), ylim=(0,9))
axes.set_title("Finite Difference 1-D Heat Simulation")
axes.set_xlabel("x")
axes.set_ylabel("u(x,t)")
line, = axes.plot([],[],lw=5)
t_label = axes.text(0,1,'',transform=axes.transAxes)


ax_bc_xmin = pyplot.axes([0.25,0.1,0.65,0.03])
ax_bc_xmax = pyplot.axes([0.25,0.15,0.65,0.03])
bc_xmin = 0.
bc_xmax = 0.
bc_xmin_slider = Slider(ax_bc_xmin, 'Left Boundary Condition', 0.,10.,valinit=0.)
bc_xmax_slider = Slider(ax_bc_xmax, 'Right Boundary Condition', 0.,10.,valinit=0.)

print(get_tridiagonal_1d(10,.5))

def init():
	t_label.set_text('')
	line.set_data([],[])
	return line, t_label

def update(garbage):

	global time, u, u_1, bc_xmin, bc_xmax
	bc_xmin = bc_xmin_slider.val
	bc_xmax = bc_xmax_slider.val
	time += dt
	dims = [x_min,x_max]
	bcs = [bc_xmin,bc_xmax]
	u,u_1 = time_step_fd_1d(u, u_1, r, dims, bcs)
	t_label.set_text('time = %.3f' % time)
	line.set_data(x,u)
	return line, t_label


anm = anim.FuncAnimation(fig, update , frames = int(t_max/dt), interval = 10, init_func = init, blit = True, repeat = False)
pyplot.show()


