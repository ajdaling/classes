set terminal X11

a = 1
b = 1
f(x) = a*x + b + 1e-9

c = 1
d = 1
g(x) = c*x + d + 1e-9

fit [0:2.1] f(x) "eigen_times.dat" u 1:2 via a,b
f_title = sprintf("slope = %fx+%f",a,b)
fit [2.3:2.7] g(x) "eigen_times.dat" u 1:2 via c,d
g_title = sprintf("slope = %fx+%f",c,d)

set ylabel "log_{10}(time) (s)"
set xlabel "log_{10}(dimension)"


plot "eigen_times.dat" u 1:2 t "Length of Calculation", f(x) t f_title, g(x) t g_title
set out "eigen_times.ps"
set terminal postscript color
replot
