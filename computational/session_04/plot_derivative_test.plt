set terminal X11
set ylabel "log_{10}(Relative Error)"
set xlabel "log_{10}(h)"
plot "derivative_test.dat" u 1:2 t "Forward Difference", "derivative_test.dat" u 1:3 t "Central Difference", "derivative_test.dat" u 1:4 t "Richardson Extrapolation"
set out "derivative_test.ps"
set terminal postscript color
replot
