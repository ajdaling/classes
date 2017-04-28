# gnuplot plot file for variational_SHO program
set timestamp

set title 'Variational Energy'

set xlabel 'Variational Parameter a'
set ylabel 'Ground-State Energy'

set xrange [0:2]
set yrange [0:1.5]

f(x) = 1./2.

set term x11

plot "variational_SHO.dat" using 1:2:3 title "MCS = ??" with yerrorbars, \
   f(x) title "y = 1/2" 

set out "variational_SHO_plt.ps"
set term postscript color
replot

reset 
set term x11
