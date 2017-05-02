'''
Created on Apr 30, 2017

@author: aj
'''
from matplotlib import animation as anim, pyplot, cm
from matplotlib.widgets import Slider, Button, RadioButtons
from numpy import e, linspace, zeros, arange, meshgrid, array
from scipy.sparse import spdiags
from mpl_toolkits.mplot3d import Axes3D
from heat_model import heat_model

from models import add_fd_basic_1d, add_fd_basic_2d, add_fd_sparse_1d
from heat_model import heat_model





fig = pyplot.figure()

model_id = 1
num_models = 2
models = {"lines":[],"surfs":[]}

add_fd_basic_1d(model_id,fig,models, num_models)
# add_fd_basic_2d(model_id,fig,models,num_models)
# add_fd_sparse_1d(model_id,fig,models,num_models)

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
'''
'''
#create sparse bd 1d 
bd_1d_sparse = heat_model([0,19],model_id, fig, method="bd", sparse=True)
model_id += 1
ax_bd_1d_sparse = fig.add_subplot(111)
ax_bd_1d_sparse.set_xlabel('x')
ax_bd_1d_sparse.set_xlim(0.,bd_1d_sparse.x_max)
ax_bd_1d_sparse.set_ylim(0,10)
ax_bd_1d_sparse.set_ylabel('u(x,t)')
line_bd_1d_sparse, = ax_bd_1d_sparse.plot([],[],lw=4)
'''

pyplot.subplots_adjust(left = 0.1, bottom = .4)

time = 0
steps = 1


def update(garbage):
	
	for lin in models["lines"]:
		m = lin["model"]
		m.time_step()
		lin["axis"].clear()
		lin["axis"].set_xlim(m.x_min,m.x_max)
		lin["axis"].set_ylim(0,10.)
		lin["axis"].set_xlabel('x')
		lin["axis"].set_ylabel('u(x,t)')
		lin["line"], = lin["axis"].plot(m.x,m.u,lw=4)
	
	for surf in models["surfs"]:
		m = surf["model"]
		m.time_step()
		surf["axis"].clear()
		surf["axis"].set_xlabel('x')
		surf["axis"].set_ylabel('y')
		surf["axis"].set_zlabel('u(x,y,t)')
		surf["surf"] = surf["axis"].plot_surface(m.X,m.Y,m.u,rstride=1,cstride=1,cmap=cm.autumn,linewidth=1,antialiased=False)
		
	
	#clear surfaces
# 	ax_basic_2d.clear()
#	ax_sparse_2d.clear()
# 	ax_sparse_1d.set_xlim(0,sparse_1d.x_max)
# 	sparse_1d.time_step(steps)
# 	basic_2d.time_step(steps)
# 	line_sparse_1d.set_data(sparse_1d.x,sparse_1d.u)
# 	bd_1d.time_step(steps_per_second)
# 	line_bd_1d.set_data(bd_1d.x,bd_1d.u)
# 	bd_1d_sparse.time_step()
# 	line_bd_1d_sparse.set_data(bd_1d_sparse.x,bd_1d_sparse.u)
# 	sparse_2d.time_step(steps_per_second)
# 	surf1 = ax2.plot_surface(m2.X,m2.Y,m2.u,rstride=1,cstride=1,cmap=cm.autumn,linewidth=1,antialiased=False)
# 	surf_basic_2d = ax_sparse_2d.plot_surface(sparse_2d.X,sparse_2d.Y,sparse_2d.u,rstride=1,cstride=1,cmap=cm.autumn,linewidth=1,antialiased=False)


# frames = int(bd_1d_sparse.t_max/bd_1d_sparse.dt),
anm = anim.FuncAnimation(fig, update , interval = 10, blit = False, repeat = False)
pyplot.show()
