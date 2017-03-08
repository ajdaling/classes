# gnuplot plot file: derivate_test.plt
set terminal x11   # terminal type: for a Mac, use "aqua" instead of "x11"
set title 'Derivative Test'
set xlabel 'h'
set ylabel 'Relative Error'
set key top left    # move the key away from the lines
set timestamp	  # turn on a date/time indicator
plot "derivative_test.dat" using 1:2 title 'Forward Derivative', "derivative_test.dat" using 1:3 title 'Central Derivative', "derivative_test.dat" using 1:4 title 'Richardson Extrapolation'
set out "derivative_test.ps"	# name of the output postscript file
set terminal postscript	color        # switch to postscript mode
replot  		  	# plot to the file
