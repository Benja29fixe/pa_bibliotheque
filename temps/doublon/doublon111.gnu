set terminal pngcairo size 1000, 600
set output 'doublon111.png'
set xlabel "nombre d'éléments"
set ylabel "temps (s)"
set title "Fonction Doublon avec Liste : f(x)/n²"
plot "doublon111.temps" using 1:($2/($1*$1)) with lines title "f(x)/n²"
