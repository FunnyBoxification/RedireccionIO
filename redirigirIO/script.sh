#!/bin/sh
echo "Ingresar numero"
read numero
sum=0
sd=0
while [ $numero -gt 0 ]
do
	sd=`expr $numero % 10`
	sum=`expr $sum + $sd` 
	numero=`expr $numero / 10`
done 
	echo "La suma de los digitos es $sum"
