set terminal X11
set key bottom
set xlabel "log_{10}(N)"
set ylabel "log_{10}(Sum), log_{10}(Relative Error)"
plot "sum1.dat" u 1:2 t "log_{10}(Sum Up)", "sum1.dat" u 1:3 t "log_{10}(Sum Down)", "sum1.dat" u 1:4 t "log_{10}(Relative Error)"
set out "sum_plot.ps"
set terminal postscript color
replot

