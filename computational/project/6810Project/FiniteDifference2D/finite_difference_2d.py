'''
Created on Apr 28, 2017

@author: aj
'''

from matplotlib import animation as anim, pyplot as pp, cm
from matplotlib.widgets import Slider, Button, RadioButtons
from numpy import e, linspace, zeros, arange, meshgrid, array

import mpl_toolkits.mplot3d.axes3d as p3
from library import time_step_fd_2d


l = 20
x_min = 0
x_max = l-1 
y_min = 0
y_max = l-1
max_temp = 10.

num_points = l #number of x points
#initialize 1d array of points
x,dx = linspace(x_min,x_max,num_points,retstep = True)
y,dy = linspace(y_min,y_max,num_points,retstep = True)
X,Y = meshgrid(x,y)
t0 = 0
r = 0.25	#must be <0.25 for stability for FD
dt = r*(dx**2)
t_max = 2000
time = t0

#u = zeros(num_points) #u(x,t)
#u_1 = zeros(num_points) #u(x,t-1)
u = zeros((num_points,num_points))
u_1 = zeros((num_points,num_points))

for i in range(x_min,x_max):
	for j in range(y_min,y_max):
		u_1[i,j] = float((i+j))/2.

u[:,:] = u_1
#plot vars
fig = pp.figure()
#ax = fig.add_subplot(1,2,1,projection='3d')
#ax = p3.Axes3D(fig)
ax = fig.add_subplot(111,projection='3d',)
ax.set_title('Finite Difference 2-D Heat Simulation')
ax.set_xlim3d([x_min,x_max])
ax.set_xlabel('x')
ax.set_ylim3d([y_min,y_max])
ax.set_ylabel('y')
ax.set_zlim3d([0.,max_temp])
ax.set_zlabel('u(x,y)')


pp.subplots_adjust(left = 0.25, bottom = 0.4)

#create sliders
ax_r = pp.axes([0.25,0.3,0.65,0.03])
r_slider = Slider(ax_r,'mu',0.,1.,valinit=0.1)

ax_bc_xmin = pp.axes([0.25,0.1,0.65,0.03])
bc_xmin = 0.
bc_xmin_slider = Slider(ax_bc_xmin, 'Left Boundary Condition', 0.,10.,valinit=0.)

bc_xmax = 0.
ax_bc_xmax = pp.axes([0.25,0.15,0.65,0.03])
bc_xmax_slider = Slider(ax_bc_xmax, 'Right Boundary Condition', 0.,10.,valinit=0.)

ax_bc_ymin = pp.axes([0.25,0.2,0.65,0.03])
bc_ymin = 0.
bc_ymin_slider = Slider(ax_bc_ymin,'ymin BC', 0., 10., valinit=0.)

ax_bc_ymax = pp.axes([0.25,0.25,0.65,0.03])
bc_ymax = 0.
bc_ymax_slider = Slider(ax_bc_ymax, 'ymax BC', 0., 10., valinit = 0.)


def update(garbage, u, u_1, surf):
# 	u[x_min,:] = bc_xmin_slider.val
# 	u[x_max-1,:] = bc_xmax_slider.val
# 	u[:,y_min] = bc_ymin_slider.val
# 	u[:,y_max-1] = bc_ymax_slider.val
	steps = 1
	dims = array([[x_min,x_max],[y_min,y_max]])
	bcs = array([[bc_xmin_slider.val,bc_xmax_slider.val],[bc_ymin_slider.val,bc_ymax_slider.val]])
	r = r_slider.val
	#u, u_1 = time_step(u,u_1,x_min,x_max)
	u,u_1 = time_step_fd_2d(u, u_1, r, dims, bcs, steps)
	ax.clear()
	surf = ax.plot_surface(X,Y,u,rstride=1,cstride=1,cmap=cm.autumn,linewidth=1,antialiased=False)
surf = ax.plot_surface(X,Y,u,rstride=1,cstride=1,cmap=cm.autumn,linewidth=1,antialiased=False)

anm = anim.FuncAnimation(fig, update , fargs = (u,u-1,surf), frames = int(t_max/dt), interval = 10, blit = False, repeat = False)
pp.show()


