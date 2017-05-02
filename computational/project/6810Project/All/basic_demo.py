'''
Created on Apr 30, 2017

@author: aj
'''
from matplotlib import animation as anim, pyplot, cm
from matplotlib.widgets import Slider, Button, RadioButtons
from numpy import e, linspace, zeros, arange, meshgrid, array
from scipy.sparse import spdiags
import mpl_toolkits.mplot3d.axes3d as p3
from heat_model import heat_model
from sliders import sliders





fig = pyplot.figure()

model_id = 1

#create basic 1d model
'''
basic_1d = heat_model([0,19],model_id, fig)
model_id += 1
ax_basic_1d = fig.add_subplot(121)
ax_basic_1d.set_xlabel('x')
ax_basic_1d.set_xlim(0.,basic_1d.x_max)
ax_basic_1d.set_ylim(0,10)
ax_basic_1d.set_ylabel('u(x,t)')
line_basic_1d, = ax_basic_1d.plot([],[],lw=4)
'''
'''
#create sparse 1d model
sparse_1d = heat_model([0,5],model_id,fig,sparse = True)
model_id += 1
ax_sparse_1d = fig.add_subplot(121)
ax_sparse_1d.set_xlabel('x')
ax_sparse_1d.set_xlim(0.,sparse_1d.x_max)
ax_sparse_1d.set_ylim(0,10)
ax_sparse_1d.set_ylabel('u(x,t)')
line_sparse_1d, = ax_sparse_1d.plot([],[],lw=4)
'''
'''
#create basic 2d model
m2 = heat_model([0,19,0,19], model_id, fig)
model_id += 1
ax2 = fig.add_subplot(122,projection='3d')
ax2.set_xlabel('x')
ax2.set_ylabel('y')
ax2.set_zlabel('u(x,y,t)')
surf1 = ax2.plot_surface(m2.X,m2.Y,m2.u,rstride=1,cstride=1,cmap=cm.autumn,linewidth=1,antialiased=False)
'''
'''
#creates sparse 2d model
sparse_2d = heat_model([0,19,0,19], model_id, fig, sparse=True)
model_id += 1
ax_sparse_2d = fig.add_subplot(122,projection='3d')
ax_sparse_2d.set_xlabel('x')
ax_sparse_2d.set_ylabel('y')
ax_sparse_2d.set_zlabel('u(x,y,t)')
surf_basic_2d = ax_sparse_2d.plot_surface(sparse_2d.X,sparse_2d.Y,sparse_2d.u,rstride=1,cstride=1,cmap=cm.autumn,linewidth=1,antialiased=False)
'''

#create backward difference 1d model
bd_1d = heat_model([0,19],model_id, fig, method="bd")
model_id += 1
ax_bd_1d = fig.add_subplot(111)
ax_bd_1d.set_xlabel('x')
ax_bd_1d.set_xlim(0.,bd_1d.x_max)
ax_bd_1d.set_ylim(0,10)
ax_bd_1d.set_ylabel('u(x,t)')
line_bd_1d, = ax_bd_1d.plot([],[],lw=4)



pyplot.subplots_adjust(left = 0.1, bottom = .4)

time = 0
steps = 1


def update(garbage):
	#clear surfaces
# 	ax_basic_2d.clear()
#	ax_sparse_2d.clear()
	steps_per_second = 1
# 	ax_sparse_1d.set_xlim(0,sparse_1d.x_max)
# 	sparse_1d.time_step(steps)
# 	basic_2d.time_step(steps)
# 	line_sparse_1d.set_data(sparse_1d.x,sparse_1d.u)
	line_bd_1d.set_data(bd_1d.x,bd_1d.u)
# 	sparse_2d.time_step(steps_per_second)
# 	surf1 = ax2.plot_surface(m2.X,m2.Y,m2.u,rstride=1,cstride=1,cmap=cm.autumn,linewidth=1,antialiased=False)
# 	surf_basic_2d = ax_sparse_2d.plot_surface(sparse_2d.X,sparse_2d.Y,sparse_2d.u,rstride=1,cstride=1,cmap=cm.autumn,linewidth=1,antialiased=False)



anm = anim.FuncAnimation(fig, update , frames = int(bd_1d.t_max/bd_1d.dt), interval = 10, blit = False, repeat = False)
pyplot.show()
