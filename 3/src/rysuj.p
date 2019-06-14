set term png
set out 'R3.png'
set multiplot 
set ytics nomirror
set y2tics nomirror
set ylabel 'x[m]'
set xlabel 'y[m]'
plot 'R3' u 6:7 w l t ''
