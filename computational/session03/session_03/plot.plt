set timestamp
set ylabel 'log_{10}(rel-error)'
set xlabel 'log_{10}(\delta-x)'
plot "derivative_test_simple.dat" using 2:1 title 'forward difference' , "derivative_test_simple.dat" using 3:1 title 'central difference'
