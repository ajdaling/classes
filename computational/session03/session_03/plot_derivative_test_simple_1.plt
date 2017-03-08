set timestamp
set ylabel 'log_{10}(rel-error)'
set xlabel 'log_{10}(\delta-x)'
plot "derivative_test_simple.dat" using 1:2 title 'forward difference' , "derivative_test_simple.dat" using 1:3 title 'central difference'
set terminal postscriptc color
replot
