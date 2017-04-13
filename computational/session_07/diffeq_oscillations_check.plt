# plot of kinetic energy and potential energy versus time
set term x11 4 title "Total Energy vs Time"  
set timestamp
set yrange [0:1]
set title 'Oscillations: Total Energy'
set xlabel 't'
set ylabel 'energy'
plot "diffeq_oscillations.dat" using ($1):(($4)+($5)) title 'E(t)' with lines
     
set out "diffeq_oscillations_check.ps"
set terminal postscript color
replot
