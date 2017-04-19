a = 1
b = 1
f(x) = a*x + b + 1e-19

set yrange[-3:0]
set cbrange[1e-9:1024]
fit [0:.81] f(x) "eigen_tridiagonal_error.dat" u 1:2 via a,b
f_title = sprintf("slope = %fx+%f",a,b)

set ylabel "log_{10}(Relative Error)"
set xlabel "log_{10}(N)"
set title "Relative Error in First Eigenvalue vs N for R_{max} = 4"

plot "eigen_tridiagonal_error.dat" u 1:2, f(x) t f_title
set out "eigen_tridiagonal_error_Rmax_4.ps"
set terminal postscript color
replot
