#include <stdio.h>

#define MAX_SIZE 100

// Fonction pour effectuer le produit matriciel
void produitMatriciel(int matrice1[][MAX_SIZE], int matrice2[][MAX_SIZE], int resultat[][MAX_SIZE], int m, int n, int p) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < p; j++) {
            resultat[i][j] = 0;
            for (int k = 0; k < n; k++) {
                resultat[i][j] += matrice1[i][k] * matrice2[k][j];
            }
        }
    }
}

int main() {
    // Exemple de matrices
    int matrice1[MAX_SIZE][MAX_SIZE] = {{1, 2, 3},
                                        {4, 5, 6}};

    int matrice2[MAX_SIZE][MAX_SIZE] = {{7, 8},
                                        {9, 10},
                                        {11, 12}};

    int resultat[MAX_SIZE][MAX_SIZE];

    int m = 2; // Nombre de lignes de la matrice1
    int n = 3; // Nombre de colonnes de la matrice1 (et nombre de lignes de la matrice2)
    int p = 2; // Nombre de colonnes de la matrice2

    // Appel de la fonction produitMatriciel
    produitMatriciel(matrice1, matrice2, resultat, m, n, p);

    // Affichage du résultat
    printf("Résultat du produit matriciel :\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < p; j++) {
            printf("%d ", resultat[i][j]);
        }
        printf("\n");
    }

    return 0;
}