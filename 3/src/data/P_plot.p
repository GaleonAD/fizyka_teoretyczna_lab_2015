set term png enhanced
set out 'ped.png'
set multiplot
 set size square
 set size 0.7,1
 set size ratio -1
set ylabel 'y[m]'
set xlabel 'x[m]'
set yrange [-3:5]
set xrange [-3:5]
plot 'P0' u 6:7 w l t 'p_{r,0}=0 kg*m/s', 'P-2' u 6:7 w l t 'p_{r,0}=-2 kg*m/s', 'P2' u 6:7 w l t 'p_{r,0}=2 kg*m/s'
