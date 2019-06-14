#! /usr/bin/gnuplot --persist

set term png;
set out 'wyniki/wyniki.png'
set xlabel 'czas [s]'
set ylabel 'wychylenie [rad]'

print("Rysowanie wyniki.png")
set multiplot layout 2,1
plot for [i=0:(files-1)] 'dane/wahadlo'.i.'.txt' u 1:2 w line tit sprintf("fi(t) - wahadło%d.txt", i)
plot for [i=0:(files-1)] 'dane/wahadlo'.i.'.txt' u 1:3 w line tit sprintf("energia(t) -wahadło%d",i)
unset multiplot


set ylabel 'Energia [J]'

do for [i=0:(files-1)]{
	set out 'wyniki/energia'.i.'.png'
	filename=sprintf("energia%d.png", i)
	print("Rysowanie ".filename)
	plot 'dane/wahadlo'.i.'.txt' u 1:3 w points tit 'Energia całkowita wahadła'
}

set out 'wyniki/okres.png'
set xlabel 'Kąt początkowy [rad]'
set ylabel 'Okres drgań [s]'

print("Rysowanie okres.png")
plot 'dane/okres.txt' u 1:2 w dots notitle
