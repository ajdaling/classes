#Alec Daling - 4/17/16


#	The relative difference between the GSL bessel function and the downard recursion method
#	exhibits the same behavior as between upward and downward recursion above x=35; however, 
# between x = 0 and x = 35, the relative error is consistently at the machine precision of 
$ 10e-16, implying that the two functions give nearly identical results.

set terminal X11
set ylabel "log_{10}(Relative Error)"
set xlabel "log_{10}(X)"

plot "bessel.dat" u (log10($1)):(log10($6)) t "Relative Difference"
set out "gsl_bessel_error_loglog.ps"
set terminal postscript color
replot
