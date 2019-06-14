set term png
set out 'en.png'
set multiplot 
set ytics nomirror
set y2tics nomirror
set ylabel 'energia [J]'
set xlabel 'czas [s]'
plot 'E.001' u 1:5 w l t 'dt = 0,001', 'E.0001' u 1:5 w l t 'dt=0,0001','E.00001' u 1:5 w l t 'dt=0,00001' 
