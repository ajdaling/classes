set terminal X11
set title "Autocorrelation Initial Skip Test"
set timestamp

plot "autocorrelation_test_initial_skip.dat" u 1:2 t 'Metro'

set terminal postscript color
set out "autocorrelation_test_initial_skip.ps"
replot
