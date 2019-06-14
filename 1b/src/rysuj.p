set term jpeg
set out 'wykres.jpg'                   
set multiplot 

set xlabel 'Amplituda [rad]'
set ylabel 'Okres [s]'

plot 'QT' u 1:2 w l t 'T(A)' 
