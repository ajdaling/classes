set terminal X11
set ylabel "Relative Error"
set xlabel "X"
plot "bessel.dat" u 1:4 t "Relative Difference"
set out "bessel_error.ps"
set terminal postscript color
replot
