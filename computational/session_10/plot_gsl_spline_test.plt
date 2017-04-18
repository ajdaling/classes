set term x11
set timestamp

set title "GSL Spline Test with linear, polynomial, and cubic spline interpolation."

set xlabel 'Energy (MeV)'
set ylabel '\Sigma (mb)'
plot "gsl_spline_test.dat" u 1:2 t 'Linear' w linesp,\
"gsl_spline_test.dat" u 1:3 t "Polynomial" w linesp,\
"gsl_spline_test.dat" u 1:4 t "Cubic" w linesp,\
"gsl_spline_test.dat" u 1:5 t "Theoretical" w linesp
 
set terminal postscript color
set out "gsl_spline_test.ps"
replot
