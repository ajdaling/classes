set terminal X11
set timestamp
set title "Histogram of Random Number Generator"

plot "random_histogram.dat" u 1:3 t 'uniform1',\
"random_histogram.dat" u 1:4 t 'uniform2',\
"random_histogram.dat" u 1:6 t 'gaussian1',\
"random_histogram.dat" u 1:7 t 'gaussian2'

	
set terminal postscript color
set out "random_hist.ps"
replot
