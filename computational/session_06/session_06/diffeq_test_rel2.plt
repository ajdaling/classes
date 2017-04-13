# plot file for diffeq_test_exp_back
set timestamp
set xlabel 't'
set ylabel 'log_{10}(Relative Error)'
set xrange [.001:3]

set title 'Comparing Differential Equation Algorithms'




plot \
  "diffeq_test.dat" using ($1):(log(abs(($4-$2)/$4))) title 'Euler h=0.1', \
  "diffeq_test.dat" using ($1):(log(abs(($4-$3)/$4))) title '4th order Runge-Kutta h=0.1', \
  "diffeq_test2.dat" using ($1):(log(abs(($4-$2)/$4))) title 'Euler h=0.01', \
  "diffeq_test2.dat" using ($1):(log(abs(($4-$3)/$4))) title '4th order Runge-Kutta h=0.01'
  
set out "diff_eq_rel2.ps"
set terminal postscript
replot
