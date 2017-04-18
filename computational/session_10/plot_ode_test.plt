set term x11
set timestamp

set title "Phase-Space ODE Test"

set xlabel 'x'
set ylabel 'v'
plot "ode_test_x0_1_v0_0.dat" u 2:3 t 'x0=1, v0=0',\
 "ode_test_x0_-1.5_v0_2.dat" u 2:3 t 'x0=-1.5, v0=-2',\
 "ode_test_x0_0.1_v0_0.dat" u 2:3 t 'x0=0.1, v0=0'
 
set terminal postscript color
set out "ode_test.ps"
replot
