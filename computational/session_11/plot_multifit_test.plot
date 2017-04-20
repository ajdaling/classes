set terminal X11
set timestamp
set title 'multifit test'

a = 5.04536
l = .10405
b = 1.01925

ea = .06028
el = .00316
eb = .03782

y(x) = a * exp(-l * x) + b

plot 'multifit_test.dat' u 1:2:3 with yerrorbars t 'initial data', y(x) t 'best fit'

set terminal postscript color
set out 'multifit_test.ps'
replot


