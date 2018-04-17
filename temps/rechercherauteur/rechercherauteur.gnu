set terminal pngcairo size 1000, 600
set output 'rechercherauteur_1.png'
set xlabel "nombre d'éléments"
set ylabel "temps (s)"
set title "Fonction Recherche à partir d'un nom d'auteur"

set style line 10 linetype 1 \
    	       	  linewidth 3

set key on inside top left
plot "rechercherauteur1.temps" using 1:2 with lines title "liste" linestyle 10,\
"rechercherauteur2_1000.temps" using 2:3 with lines title "table de hachage 1000",\
"rechercherauteur22_10000.temps" using 2:3 with lines title "table de hachage 10000",\
"rechercherauteur22_25000.temps" using 2:3 with lines title "table de hachage 25000",\
"rechercherauteur22_45000.temps" using 2:3 with lines title "table de hachage 45000",\
"rechercherauteur22_65000.temps" using 2:3 with lines title "table de hachage 65000",\
"rechercherauteur22_85000.temps" using 2:3 with lines title "table de hachage 85000",\
"rechercherauteur22_85000.temps" using 2:3 with lines title "table de hachage 100000"

