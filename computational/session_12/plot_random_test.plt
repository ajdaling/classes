set terminal X11
set timestamp
set title "Test of Random Number Generator"

plot "< sort -nk2 random_numbers.dat" u 2 t 'uniform1',\
	"< sort -nk3 random_numbers.dat" u 3 t 'uniform2',\
	"< sort -nk4 random_numbers.dat" u 4 t 'gaussian1',\
	"< sort -nk5 random_numbers.dat" u 5 t 'gaussian2'
	
set terminal postscript color
set out "random_test.ps"
replot
