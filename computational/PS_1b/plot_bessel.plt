set terminal X11
set yrange[-.15:0.15]
plot "bessel.dat" u 1:2 t "Downward Recursion", "bessel.dat" u 1:3 t "Upward Recursion"
set out "bessel.ps"
set terminal postscript color
replot
