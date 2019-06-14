set term png
set out 'VV0.png'
set multiplot 
set ytics nomirror
set y2tics nomirror
set ylabel 'wychylenie [rad]'
set y2label 'położenie [m]'
set xlabel 'czas [s]'
plot 'VV0' u 1:2 axis x1y1 w l t '', 'VV0' u 1:4 axis x1y2 w l t ''
