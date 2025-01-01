#include <iostream>
#include <vector>
#include <omp.h>

using namespace std;

// Fonction pour effectuer le produit matriciel parallèle
vector<vector<int>> produitMatricielParallele(const vector<vector<int>>& matrice1, const vector<vector<int>>& matrice2) {
    int m = matrice1.size();
    int n = matrice2.size();
    int p = matrice2[0].size();

    vector<vector<int>> resultat(m, vector<int>(p, 0));

    #pragma omp parallel for
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < p; j++) {
            for (int k = 0; k < n; k++) {
                #pragma omp atomic
                resultat[i][j] += matrice1[i][k] * matrice2[k][j];
            }
        }
    }

    return resultat;
}

int main() {
    // Exemple de matrices
    vector<vector<int>> matrice1 = {{1, 2, 3},
                                    {4, 5, 6}};

    vector<vector<int>> matrice2 = {{7, 8},
                                    {9, 10},
                                    {11, 12}};

    // Spécifie le nombre de threads à utiliser
    omp_set_num_threads(4);

    // Appel de la fonction produitMatricielParallele
    vector<vector<int>> resultat = produitMatricielParallele(matrice1, matrice2);

    // Affichage du résultat
    for (int i = 0; i < resultat.size(); i++) {
        for (int j = 0; j < resultat[0].size(); j++) {
            cout << resultat[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}