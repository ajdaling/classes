set terminal X11
set title 'Energy vs Time (Ising Opt 2-D Ferromagnetic Cooling Magnization Time Average vs Temperature)'
set timestamp

set ylabel 'Time Average of Magnetization'
set xlabel 'Temperature'

plot "ising_magnetization_cooling.dat" u 1:2 


set terminal postscript color
set out 'ising_magnetization_cooling.ps'
replot
