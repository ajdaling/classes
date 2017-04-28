set terminal X11
set title 'Energy vs Time (Ising Opt 2-D Ferromagnetic Cooling)'
set timestamp

set ylabel 'Energy'
set xlabel 'Time

plot "ising_opt_cooling_4.dat" u 1:2 t 'kT = 4.0',\
 "ising_opt_cooling_2.4.dat" u 1:2 t 'kT = 2.4',\
  "ising_opt_cooling_1.2.dat" u 1:2 t 'kT = 1.2',\
# "ising_opt_cooling_3.8.dat" u 1:2 t 'kT = 3.8',\
# "ising_opt_cooling_3.6.dat" u 1:2 t 'kT = 3.6',\
# "ising_opt_cooling_3.4.dat" u 1:2 t 'kT = 3.4',\
# "ising_opt_cooling_3.2.dat" u 1:2 t 'kT = 3.2',\
# "ising_opt_cooling_3.dat" u 1:2 t 'kT = 3.0',\
# "ising_opt_cooling_2.8.dat" u 1:2 t 'kT = 2.8',\
# "ising_opt_cooling_2.6.dat" u 1:2 t 'kT = 2.6',\

# "ising_opt_cooling_2.2.dat" u 1:2 t 'kT = 2.2',\
# "ising_opt_cooling_2.dat" u 1:2 t 'kT = 2.0',\
# "ising_opt_cooling_1.8.dat" u 1:2 t 'kT = 1.8',\
# "ising_opt_cooling_1.6.dat" u 1:2 t 'kT = 1.6',\
# "ising_opt_cooling_1.4.dat" u 1:2 t 'kT = 1.4',\

# "ising_opt_cooling_1.dat" u 1:2 t 'kT = 1.0'


set terminal postscript color
set out 'ising_opt_cooling.ps'
replot
