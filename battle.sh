#!/bin/sh

i=0

while [ $i -le 50 ]
do
    echo "POUR LA VICTOIIIIIIRE"
    ./lemipc 2 &
    i=$(( $i + 1))
done
