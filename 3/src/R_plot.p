set term png enhanced
set out 'pro2.png'
set multiplot
 set size square
 set size 0.7,1
 set size ratio -1
set ylabel 'y[m]'
set xlabel 'x[m]'
# set yrange [-3:5]
# set xrange [-3:5]
plot 'R1' u 6:7 w l t 'r_{0}=1 m', 'R1.5' u 6:7 w l t 'r_{0}=1,5 m', 'R2' u 6:7 w l t 'r_{0}=2 m', 'R3' u 6:7 w l t 'r_{0}=3 m', 'R0.8' u 6:7 w l t 'r_{0}=0,8 m'