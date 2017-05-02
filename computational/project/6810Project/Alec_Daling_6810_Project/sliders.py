'''
Created on Apr 30, 2017

@author: Alec Daling

class Sliders used by class heat_model to auto-generate and configure
matplotlib.widgets sliders for plots.

'''
from matplotlib.widgets import Slider
from matplotlib import pyplot
class sliders(object):
	'''
	classdocs
	'''


	def __init__(self, fig, m, x_coord):
		'''
		Constructor
		'''
		#assign params
		self.m = m
		self.x_coord = x_coord
		self.y =  0.01
		self.x = x_coord + 0.2
		wid = 0.2
		ht = 0.03
		
		#array for boundary condition sliders
		self.bc_sliders = []
		
		
		#create steps per second slider
		self.ax_rate = fig.add_axes([self.get_x(),self.get_y(),wid,ht])
		self.slider_rate = Slider(self.ax_rate,'Steps per Iteration.',0.,100.,valinit = 1)
		self.slider_rate.on_changed(self.update_rate)
		
		#create bc sliders
		self.ax_bc_xmin = fig.add_axes([self.get_x(),self.get_y(),wid,ht])
		self.slider_bc_xmin = Slider(self.ax_bc_xmin,'Left B.C.',0.,10.,valinit = 0.)
		self.bc_sliders.append(self.slider_bc_xmin)
		
		self.ax_bc_xmax = fig.add_axes([self.get_x(),self.get_y(),wid,ht])
		self.slider_bc_xmax = Slider(self.ax_bc_xmax,'Right B.C.',0.,10.,valinit = 0.)
		self.bc_sliders.append(self.slider_bc_xmax)
		if m.is2d:
			self.ax_bc_ymin = fig.add_axes([self.get_x(),self.get_y(),wid,ht])
			self.slider_bc_ymin = Slider(self.ax_bc_ymin,'Bottom B.C.',0.,10.,valinit = 0.)
			self.bc_sliders.append(self.slider_bc_ymin)
			self.ax_bc_ymax = fig.add_axes([self.get_x(),self.get_y(),wid,ht])
			self.slider_bc_ymax = Slider(self.ax_bc_ymax,'Top B.C.',0.,10.,valinit= 0.)
			self.bc_sliders.append(self.slider_bc_ymax)
		#creates event listeners for boundary condition sliders
		for s in self.bc_sliders:
			s.on_changed(self.update_bc)
		
		#create r slider
		self.ax_r = fig.add_axes([self.get_x(),self.get_y(),wid,ht])
		self.slider_r = Slider(self.ax_r,'MU',0.,1.,valinit = 0.2)
		self.slider_r.on_changed(self.update_r) #event listener
		
		#create dimension sliders
		self.dim_sliders = []
		self.ax_xmax = fig.add_axes([self.get_x(),self.get_y(),wid,ht])
		self.slider_xmax = Slider(self.ax_xmax,'X length',0,100,valinit=self.m.x_max)
		self.dim_sliders.append(self.slider_xmax)

		#create event listeners for dimension sliders
		for s in self.dim_sliders:
			s.on_changed(self.update_dims) 
		
		#create text box to display run time
		self.m.timer_text = pyplot.figtext(self.get_x(),0.95,"Seconds per Step: " + str(self.m.dur))
		
		
	def update_rate(self,event):
		'''
		updates rate when rate slider is changed
		'''
		self.m.steps_per_second = int(self.slider_rate.val)
		
	def update_dims(self, event):
		'''
		updates dimensions of heat_model and plots when dim slider is changed
		'''
		self.m.x_max = int(self.slider_xmax.val)
		if self.m.is2d:
			self.m.y_max = int(self.slider_xmax.val)
 		self.m.resize()
		
	def update_bc(self, event):
		'''
		updates boundary conditions when a bc slider is changed
		'''
		self.m.bc_xmin = self.slider_bc_xmin.val
		self.m.bc_xmax = self.slider_bc_xmax.val
		if self.m.is2d:
			self.m.bc_ymin = self.slider_bc_ymin.val
			self.m.bc_ymax = self.slider_bc_ymax.val
		self.m.update_bc()
			
	def update_r(self, event):
		'''
		updates r when r slider is changed
		'''
		self.m.r = self.slider_r.val
		if not self.m.is2d:
			self.m.dt = self.m.r * self.m.dx ** 2
		else:
			self.m.dt = self.m.r * self.m.dx * self.m.dy
		
	def get_y(self):
		'''
		keeps track of y-coordinate in plot so that sliders do not overlap
		'''
		y_temp = self.y
		self.y+=0.05
		return y_temp
	
	def get_x(self):
		'''
		keeps track of x-coordinate is plot so that sliders do not overlap
		'''
		return self.x