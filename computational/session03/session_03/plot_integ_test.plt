set terminal X11
set ylabel 'relative error'
set xlabel 'N'
a = 1
b = 1
c = 1
d = 1
l = 1
m = 1
f(x) = a*x+b+1e-9
g(x) = c*x+d+1e-9
h(x) = l*x+m+1e-9

fit [1.5:2.5] f(x) "integ.dat" u 1:4 via a, b
fit g(x) "integ.dat" u 1:2 via c, d
fit [0.5:1.2] h(x) "integ.dat" u 1:3 via l, m

tif = sprintf("slope = %f", a)
tig = sprintf("slope = %f", c)
tih = sprintf("slope = %f", l)

plot "integ.dat" u 1:2 title 'trapezoid rule', "integ.dat" using 1:3 title 'simpsons rule', "integ.dat" using 1:4 title 'gauss quadrature', f(x) t tif, g(x) t tig, h(x) t tih
set out "integ.ps"
set terminal postscript color
replot
