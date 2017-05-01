'''
Created on Apr 30, 2017

@author: aj
'''
from matplotlib import animation as anim, pyplot, cm
from matplotlib.widgets import Slider, Button, RadioButtons
from numpy import e, linspace, zeros, arange, meshgrid, array
from scipy.sparse import spdiags
import mpl_toolkits.mplot3d.axes3d as p3
from library import *
from heat_model import heat_model
from sliders import sliders





fig = pyplot.figure()

model_id = 1
m1 = heat_model([0,19],model_id, fig)
model_id += 1
m2 = heat_model([0,19,0,19], model_id, fig)
model_id += 1

ax1 = fig.add_subplot(121)
ax1.set_xlabel('x')
ax1.set_xlim(0.,m1.x_max)
ax1.set_ylim(0,10)
ax1.set_ylabel('u(x,t)')
ax2 = fig.add_subplot(122,projection='3d')
ax2.set_xlabel('x')
ax2.set_ylabel('y')
ax2.set_zlabel('u(x,y,t)')

line1, = ax1.plot([],[],lw=4)
surf1 = ax2.plot_surface(m2.X,m2.Y,m2.u,rstride=1,cstride=1,cmap=cm.autumn,linewidth=1,antialiased=False)

pyplot.subplots_adjust(left = 0.1, bottom = .4)

time = 0
steps = 1


def update(garbage):
	ax2.clear()
	steps = 1
	ax1.set_xlim(0,m1.x_max)
	time += m1.dt
	m1.time_step(steps)
	m2.time_step(steps)
	line1.set_data(m1.x,m1.u)
	

	surf1 = ax2.plot_surface(m2.X,m2.Y,m2.u,rstride=1,cstride=1,cmap=cm.autumn,linewidth=1,antialiased=False)

	return line1



anm = anim.FuncAnimation(fig, update , frames = int(m1.t_max/m1.dt), interval = 10, blit = False, repeat = False)
pyplot.show()
