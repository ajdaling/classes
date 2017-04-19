#Alec Daling - 4/17/17
#compares extrap1 with extrap2
#extrap1 has slope ~4 O(h^4)
#extrap2 has slope ~6 O(h^6)

set terminal X11
set ylabel "log_{10}(Relative Error)"
set xlabel "log_{10}(h)"

a = 1
b = 1

f(x) = a*x + b

fit [-2:-.01] f(x) "derivative_test.dat" u 1:4 via a,b

c = 1
d = 1
g(x) = c*x + d
fit [-1.53:-0.1] g(x) "derivative_test.dat" u 1:5 via c,d

f_title = sprintf("extrap1 slope = %f", a)
g_title = sprintf("extrap2 slope = %f", c)

plot "derivative_test.dat" u 1:4 t "Richardson Extrapolation 1",\
 "derivative_test.dat" u 1:5 t "Richardson Extrapolation 2",\
 [-2:0] f(x) t f_title,\
 [-2:0] g(x) t g_title


set out "derivative_test.ps"
set terminal postscript color
replot
