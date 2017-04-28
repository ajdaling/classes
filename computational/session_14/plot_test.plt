set terminal X11

set xrange [1e-9:10e6]

a = 1
b = 1
f(x) = a*x+b
fit f(x) "test.dat" u (log10($1)):(log10($2)) via a,b

plot "test.dat" u (log10($1)):(log10($2)), f(x)
