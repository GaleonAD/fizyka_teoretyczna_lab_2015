#!/bin/bash

# nazwa_pliku | fi_0 | oega_0 | z_0 | v_0 | dt | N | a
NAZWA_PLIKU_WYJSCIE='R0.8'
FI_POCZATKOWE=0.0
R_POCZATKOWE=0.8
PED_R_POCZOTKOWY=1.0
KROCZEK_CZASOWY=0.00001
DO_ILU_SEKUND_LICZYC=15.0
./out.o $NAZWA_PLIKU_WYJSCIE $FI_POCZATKOWE $R_POCZATKOWE $PED_R_POCZOTKOWY $KROCZEK_CZASOWY $DO_ILU_SEKUND_LICZYC 

NAZWA_PLIKU_WYJSCIE='R1'
R_POCZATKOWE=1.0
./out.o $NAZWA_PLIKU_WYJSCIE $FI_POCZATKOWE $R_POCZATKOWE $PED_R_POCZOTKOWY $KROCZEK_CZASOWY $DO_ILU_SEKUND_LICZYC 
NAZWA_PLIKU_WYJSCIE='R1.5'
R_POCZATKOWE=1.5
./out.o $NAZWA_PLIKU_WYJSCIE $FI_POCZATKOWE $R_POCZATKOWE $PED_R_POCZOTKOWY $KROCZEK_CZASOWY $DO_ILU_SEKUND_LICZYC 
NAZWA_PLIKU_WYJSCIE='R2'
R_POCZATKOWE=2.0
./out.o $NAZWA_PLIKU_WYJSCIE $FI_POCZATKOWE $R_POCZATKOWE $PED_R_POCZOTKOWY $KROCZEK_CZASOWY $DO_ILU_SEKUND_LICZYC 
NAZWA_PLIKU_WYJSCIE='R3'
R_POCZATKOWE=3.0
./out.o $NAZWA_PLIKU_WYJSCIE $FI_POCZATKOWE $R_POCZATKOWE $PED_R_POCZOTKOWY $KROCZEK_CZASOWY $DO_ILU_SEKUND_LICZYC 
# prepare to draw trajectory


echo "set term png" > rysuj.p
echo "set out '$NAZWA_PLIKU_WYJSCIE.png'" >> rysuj.p
echo "set multiplot " >> rysuj.p
#echo "set size square" >> rysuj.p
echo "set ytics nomirror" >> rysuj.p
echo "set y2tics nomirror" >> rysuj.p
#echo "set ylabel 'energia [J]'" >> rysuj.p
#echo "set xlabel 'czas [s]'" >> rysuj.p
echo "set ylabel 'x[m]'" >> rysuj.p
echo "set xlabel 'y[m]'" >> rysuj.p
#echo "plot '$NAZWA_PLIKU_WYJSCIE' u 1:5 w l " >> rysuj.p
echo "plot '$NAZWA_PLIKU_WYJSCIE' u 6:7 w l t ''" >> rysuj.p

# draw

#gnuplot rysuj.p

#display $NAZWA_PLIKU_WYJSCIE.png
