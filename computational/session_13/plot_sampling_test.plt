set terminal X11
set timestamp
set title "P(E) vs E"

plot "sampling_test.dat" u 1:2 t "Exact" with linespoints,\
"sampling_test.dat" u 1:3 t "Random" with linespoints,\
"sampling_test.dat" u 1:4 t "Metropolis" with linespoints

set terminal postscript color
set out "sampling_test.ps"
replot
