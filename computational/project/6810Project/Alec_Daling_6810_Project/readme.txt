Alec Daling
daling.1@osu.edu
Physics 6810 - Furnstahl
Final Project

This project is a simulator for solving the heat equation in 1-D and 2-D. It was designed in order to provide real-time visual comparisons between the various algorithms used to approximate solutions. 

Instructions:

*******************
Necessary libraries include:
NumPy, SciPy, MatPlotLib, mpl_toolkits (should be included with MPL), matplotlib.widges (also should be included). 
Note, I did have to update my NumPy to the latest version for some of the linear algebra to function properly.
*****************

To execute, simply run heat_equation_modeller.py from the command line. You will be prompted to enter a number corresponding to the model you would like to see. After selecting the first model, you will be prompted to select a second optional model to view side by side. Your options currently include:
-Dense 1-D Finite Difference
-Dense 2-D Finite Difference
-Sparse 1-D Finite Difference
-Sparse 2-D finite Difference

** Many other models were attempted including backward difference and Crank-Nicholson but I was never able to get them functioning properly **

After selecting models, the program will open and the model(s) will appear. At the top of each plot is the CPU execution time for each iteration. You can customize various parameters including the dimensions, boundary conditions, the stability parameter Mu, and the number of iterations per frame, in order to compare the various algorithms under different conditions. For example, the dense calculations will exhibit better performance at lower dimensions than their sparse counterparts, and vice-verse for higher dimensions. The mu parameter is mostly relevent for the algorithms that I was not able to complete, and raising mu above 0.5 may result in undefined behavior.


Files included:

heat_model.py - contains all of the method for calculating the time evolution of u(x,t) for each model.
models.py - a library used to set up the plots for each model
slider.py - library for creating the "sliders" allowing for the varying of parameters on the plots.
heat_equation_modeller.py - the main program that interacts with the user


implementation details:

The layout is fairly simple. The project contains two classes. The first is heat_model, which contains one constructor and every method necessary to perform heat equation calculations. If I had more time, I would have implemented sub-classes and invoked inheritance to abstract out several components but I decided it was not a high priority. The class works for the four models shown in the program and nearly works for several others but I was forced to spend a lot of time navigation the confusing documentation of SciPy in order to figure out the linear algebra for the sparse implementations.

The second class is sliders, which is used as a member of each heat_model object to link the event listeners of the plot's sliders to the members of the heat_model so that no information would be lost if, for example, a slider was changed while a calculation was being performed.

Terminology:
Dense or Basic refers to an implementation in which full matrices were used.
Sparse refers to an implementation in which NumPy or SciPy's sparce matrices were used.
