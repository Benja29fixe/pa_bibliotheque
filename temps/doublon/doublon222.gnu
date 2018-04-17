set terminal pngcairo size 1000, 600
set output 'doublon222.png'
set xlabel "nombre d'éléments"
set ylabel "temps (s)"
set xrange [1000:100001]
set title "Fonction Doublon avec table de hachage : f(x)/n²"
plot "doublon222_1000.temps" using 1:($2/($1*$1)) with lines title "f(x)/n²"
