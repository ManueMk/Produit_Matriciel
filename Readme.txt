Pour executer le code parrallele cpp :
g++ -o parra_pm_cpp parra_prod_mat.cpp -fopenmp
./parra_pm_cpp

Pour executer le code parrallele c :
gcc -o parra_pm_c parra_prod_mat.c
./parra_pm_c

Pour executer le code sequentiel c :
gcc -o produit_m produit_matriciel.c
./produit_m

Pour executer le code sequentiel cpp :
g++ -o produit_matriciel produit_matriciel.cpp
./produit_matriciel
