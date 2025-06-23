reset
set autoscale x
set autoscale y
set xlabel "n [-]"
set ylabel "t [s]"
set key top left

plot \
"quicksort2.txt" with linespoints title 'Quicksort',\
"insertionsort.txt" with linespoints title 'Insertionsort',\
