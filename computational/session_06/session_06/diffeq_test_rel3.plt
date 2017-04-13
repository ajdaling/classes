# plot file for diffeq_test_exp_back
set timestamp
set xlabel 'log_{10}(h)'
set ylabel 'log_{10}(Relative Error)'

set title 'Comparing Differential Equation Algorithms'
a = 1
b = 1
f(x) = a*x + b + 1e-19
c = 1
d = 1
g(x) = c*x + d + 1e-19
e = 1
f = 1
h(x) = e*x + f + 1e-19
g = 1
h = 1
i(x) = g*x + h + 1e-19

fit [-3:-1.5] f(x) "diffeq_test3.dat" u (log($1)):(log(abs((($4)-($3))/($4)))) via a,b
f_title = sprintf("RK slope = %fx+%f",a,b)

fit [-2.8:-1.9] g(x) "diffeq_test3.dat" u (log($1)):(log(abs((($4)-($2))/($4)))) via c,d
g_title = sprintf("Euler slope = %fx+%f",c,d)

fit [-1.4:-0.6] h(x) "diffeq_test3.dat" u (log($1)):(log(abs((($4)-($3))/($4)))) via e,f
h_title = sprintf("RK slope = %fx+%f",e,f)

fit [-1.2: -0.5] i(x) "diffeq_test3.dat" u (log($1)):(log(abs((($4)-($2))/($4)))) via g,h
i_title = sprintf("Euler slope = %fx+%f",g,h)

plot "diffeq_test3.dat" u (log($1)):(log(abs((($4)-($2))/($4)))) title 'Euler', \
 "diffeq_test3.dat" u (log($1)):(log(abs((($4)-($3))/($4)))) title '4th order Runge-Kutta', \
 [-3:-1.5] f(x) t f_title,[-2.8:-1.9] g(x) t g_title,[-1.4:-0.6] h(x) t h_title, [-1.2: -0.5] i(x) t i_title
  
set out "diffeq_test_rel3.ps"
set terminal postscript color
replot
