#!/bin/bash

# nazwa_pliku | fi_0 | omega_0 | z_0 | v_0 | dt | N | a
NAZWA_PLIKU_WYJSCIE='VV0'
FI_POCZATKOWE=1.1
OMEGA_POCZATKOWE=0.0
Z_POCZATKOWE=3.0
V_POCZATKOWE=0.0
KROCZEK_CZASOWY=0.0001
DO_ILU_SEKUND_LICZYC=10.0
DEFINICJA_STOKA_ALFA=0.2
./out.o $NAZWA_PLIKU_WYJSCIE $FI_POCZATKOWE $OMEGA_POCZATKOWE $Z_POCZATKOWE $V_POCZATKOWE  $KROCZEK_CZASOWY $DO_ILU_SEKUND_LICZYC $DEFINICJA_STOKA_ALFA

# prepare to draw trajectory


echo "set term png" > rysuj.p
echo "set out '$NAZWA_PLIKU_WYJSCIE.png'" >> rysuj.p
echo "set multiplot " >> rysuj.p
echo "set ytics nomirror" >> rysuj.p
echo "set y2tics nomirror" >> rysuj.p
#echo "set ylabel 'energia [J]'" >> rysuj.p
echo "set ylabel 'wychylenie [rad]'" >> rysuj.p
echo "set y2label 'położenie [m]'" >> rysuj.p
echo "set xlabel 'czas [s]'" >> rysuj.p
#echo "plot '$NAZWA_PLIKU_WYJSCIE' u 1:6 w l " >> rysuj.p
echo "plot '$NAZWA_PLIKU_WYJSCIE' u 1:2 axis x1y1 w l t '', '$NAZWA_PLIKU_WYJSCIE' u 1:4 axis x1y2 w l t ''" >> rysuj.p

# draw

gnuplot rysuj.p

display $NAZWA_PLIKU_WYJSCIE.png
