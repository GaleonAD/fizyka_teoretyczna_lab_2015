#!/bin/bash

# nazwa_pliku | fi_0 | omega_0 | z_0 | v_0 | dt | N | a
NAZWA_PLIKU_WYJSCIE='xx'
FI_POCZATKOWE=1.1
OMEGA_POCZATKOWE=0.0
Z_POCZATKOWE=1.0
V_POCZATKOWE=0.0
KROCZEK_CZASOWY=0.0001
DO_ILU_SEKUND_LICZYC=10.0
DEFINICJA_STOKA_ALFA=0.5
./out_k.o $NAZWA_PLIKU_WYJSCIE $FI_POCZATKOWE $OMEGA_POCZATKOWE $Z_POCZATKOWE $V_POCZATKOWE  $KROCZEK_CZASOWY $DO_ILU_SEKUND_LICZYC $DEFINICJA_STOKA_ALFA



# prepare to draw trajectory


echo "set term png" > rysuj.p
echo "set out '$NAZWA_PLIKU_WYJSCIE.png'" >> rysuj.p
echo "set multiplot " >> rysuj.p
echo "set ytics nomirror" >> rysuj.p
echo "set y2tics nomirror" >> rysuj.p
#echo "set ylabel 'energia [J]'" >> rysuj.p
echo "set ylabel 'z(10 s) [m]'" >> rysuj.p
#echo "set y2label 'położenie [m]'" >> rysuj.p
echo "set xlabel 'alfa [rad]'" >> rysuj.p
#echo "plot '$NAZWA_PLIKU_WYJSCIE' u 1:6 w l " >> rysuj.p
echo "plot '$NAZWA_PLIKU_WYJSCIE' u 1:2  w l t ''" >> rysuj.p

# draw

gnuplot rysuj.p

display $NAZWA_PLIKU_WYJSCIE.png
