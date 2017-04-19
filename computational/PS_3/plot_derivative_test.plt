set terminal X11
set ylabel "log_{10}(Relative Error)"
set xlabel "log_{10}(h)"

a = 1
b = 1
c = 1
d = 1

f(x) = a*x + b
g(x) = c*x + d

#fit [-2:0] f(x) "derivative_test.dat" u 1:4 via a,b
#fit [-2:0] g(x) "derivative_test.dat" u 1:5 via c,d

f_title = sprintf("extrap1 slope = %f", a)
g_title = sprintf("extrap2 slope = %f", c)

plot "derivative_test.dat" u 1:4 t "Richardson Extrapolation 1",\
 "derivative_test.dat" u 1:5 t "Richardson Extrapolation 2",\
 #f(x) t f_title,\
 #g(x) t g_title


set out "derivative_test.ps"
set terminal postscript color
replot
