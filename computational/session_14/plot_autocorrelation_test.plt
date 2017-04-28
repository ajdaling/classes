set terminal X11
set timestamp
set title 'Autocorrelation function vs l'

set xlabel 'l'
set ylabel 'C(l)'

plot "autocorrelation_test.dat" u 1:2 

set terminal postscript color
set out 'autocorrelation_test.ps'
replot
