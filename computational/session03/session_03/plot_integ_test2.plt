set terminal X11
set ylabel 'relative error'
set xlabel 'N'
plot "integ2.dat" using 1:2 title 'trapezoid rule', "integ2.dat" using 1:3 title 'simpsons rule', "integ2.dat" using 1:4 title 'gauss quadrature'
set terminal postscript color
replot
