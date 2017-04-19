#Alec Daling - 4/17/16



set terminal X11
set ylabel "log_{10}(Relative Error)"
set xlabel "log_{10}(X)"

# Regions: (looking at the log-log plot)
# 1. x = [1:10] 
# 	This region shows a linear slope of -19.12, or a trend of x^-20. Here, we are seeing, 
#		for both recursive directions, a linear decrease in error until x=l (at x = 10), where the
# 	relative error is limited by the machine precision.
#
# 2. x = [1:35] 
#		This region is roughly flat and the relative error corresponds to the machine
#		precision for double's, ~10e-16.
#
#	3. x [35:50]
#		This region shows a linear slope of ~68, (x^68) power law, which is a very steep increase
# 	in the relative error. This is due to the fact that, looking at the bessel.ps plot, the
#		downward recursion method exhibits asymptotic behavior while the upward recursion method
#		is smooth. These deviations result in significant relative error (around unity).

a = 0
b = 0

f(x) = a*x + b
fit [0.16:0.95] f(x) "bessel.dat" u (log10($1)):(log10($4)) via a,b
f_title = sprintf("fit = %fx + %f",a,b)

c = 0
d = 0
g(x) = c*x+d
fit [1.48:1.66] g(x) "bessel.dat" u (log10($1)):(log10($4)) via c,d
g_title = sprintf("fit = %fx + %f",c,d)


plot "bessel.dat" u (log10($1)):(log10($4)) t "Relative Difference", [0.16:0.85] f(x) t f_title, [1.48:1.66] g(x) t g_title
set out "bessel_error_loglog.ps"
set terminal postscript color
replot
