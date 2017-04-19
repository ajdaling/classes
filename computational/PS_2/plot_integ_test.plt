#Alec Daling, 17 Apr 2017. PS_2
#Compares relative error of integration using Simpson's Rule and Milne's Rule.


set terminal X11
set ylabel 'log_{10}(relative error)'
set xlabel 'log_{10}(N)'
a = 1
b = 1
c = -4
d = 1
f(x) = a*x+b+1e-9
g(x) = c*x+d+1e-9

fit [0.1:2.8]f(x) "simpson.dat" u 1:2 via a, b
fit [0.1:1.9] g(x) "milne.dat" u 1:2 via c, d

tif = sprintf("Simpon's Rule slope = %f", a)
tig = sprintf("Milne's Rule slope = %f", c)

plot "simpson.dat" u 1:2 title 'simpsons rule', "milne.dat" using 1:2 title 'milnes rule',\
[0.1:3] f(x) t tif, [0.1:2] g(x) t tig
set out "simpson_milne_integ.ps"
set terminal postscript color
replot
