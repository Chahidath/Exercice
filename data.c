#include <stdio.h>
#include "data.h"

// Fonction pour enregistrer les données des vols dans un fichier texte
void enregistrerDonnees(const Vol vols[], int nbVols) {
    FILE *fichier = fopen("vols.txt", "w");
    if (fichier == NULL) {
        printf("Erreur : impossible d'ouvrir le fichier pour Ecrire.\n");
        return;
    }

    for (int i = 0; i < nbVols; i++) {
        fprintf(fichier, "%s;%s;%s;%d\n",
                vols[i].code,
                vols[i].destination,
                vols[i].date,
                vols[i].sieges_disponibles);
    }

    fclose(fichier);
    printf("Données enregistrées dans le fichier.\n");
}

// Fonction pour charger les données des vols depuis un fichier texte
void chargerDonnees(Vol vols[], int *nbVols) {
    FILE *fichier = fopen("vols.txt", "r");
    if (fichier == NULL) {
        printf("Aucun fichier de données trouve. Une nouvelle base sera cree.\n");
        return;
    }

    *nbVols = 0;
    while (fscanf(fichier, "%[^;];%[^;];%[^;];%d\n",
                  vols[*nbVols].code,
                  vols[*nbVols].destination,
                  vols[*nbVols].date,
                  &vols[*nbVols].sieges_disponibles) == 4) {
        (*nbVols)++;
    }

    fclose(fichier);
    printf("Donnees chargees depuis le fichier.\n");
}

