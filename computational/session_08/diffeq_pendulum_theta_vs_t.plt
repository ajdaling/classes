set timestamp

set xlabel 't'
set ylabel 'theta'

set title 'Theta vs T for pendulum periodic motion'

set term x11  # or alternative
plot \
  "diffeq_pendulum.dat" using ($1):($2) title 'Theta' with lines, \

set out "diffeq_pendulum_theta_vs_t.ps"
set term postscript color enhanced
replot  
