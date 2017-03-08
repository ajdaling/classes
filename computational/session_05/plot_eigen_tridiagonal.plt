set terminal X11
set ylabel "u(r)"
set xlabel "r"
plot "eigen_tridiagonal.dat" u 1:2
set out "eigen_tridiagonal.ps"
set terminal postscript color
replot
