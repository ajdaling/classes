set terminal X11
set timestamp
set title 'Random Walk'

plot "random_walk.dat" u 1:2 with lines t 'random walk'

set terminal postscript color
set out "random_walk1.ps"
replot
