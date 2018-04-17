set terminal pngcairo size 1000, 600
set output 'inserer.png'
set xlabel "nombre d'éléments"
set ylabel "temps (s)"
set title "Fonction Inserer"
set style line 10 linetype 1 \
    	       	  linewidth 3

set key on inside top left
plot "inserer1.temps" using 1:2 with lines title "liste" linestyle 10,\
"inserer2_1000.temps" using 2:3 with lines title "table de hachage 1000",\
"inserer2_10000.temps" using 2:3 with lines title "table de hachage 10000",\
"inserer2_25000.temps" using 2:3 with lines title "table de hachage 25000",\
"inserer2_45000.temps" using 2:3 with lines title "table de hachage 45000",\
"inserer2_60000.temps" using 2:3 with lines title "table de hachage 60000",\
"inserer2_85000.temps" using 2:3 with lines title "table de hachage 85000"
