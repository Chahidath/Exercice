#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "vol.h"

void ajouterVol(Vol vols[], int *nbVols) {
    if (*nbVols >= MAX_VOLS) {
        printf("Capacite maximale atteinte. Impossible d'ajouter un nouveau vol.\n");
        return;
    }

    Vol nouveauVol;
    printf("Entrez le code du vol : ");
    fgets(nouveauVol.code, TAILLE_CODE, stdin);
    strtok(nouveauVol.code, "\n");  // Retirer le '\n'

    printf("Entrez la destination : ");
    fgets(nouveauVol.destination, TAILLE_DEST, stdin);
    strtok(nouveauVol.destination, "\n");

    printf("Entrez la date (YYYY-MM-DD) : ");
    fgets(nouveauVol.date, 11, stdin);
    strtok(nouveauVol.date, "\n");

    printf("Entrez le nombre de sieges disponibles : ");
    scanf("%d", &nouveauVol.sieges_disponibles);
    getchar();

    vols[*nbVols] = nouveauVol;
    (*nbVols)++;
    printf("Vol ajoute.\n");
}

void reserverSiege(Vol vols[], int nbVols) {
    char code[TAILLE_CODE];
    printf("Entrez le code du vol : ");
    fgets(code, TAILLE_CODE, stdin);
    strtok(code, "\n");

    for (int i = 0; i < nbVols; i++) {
        if (strcmp(vols[i].code, code) == 0) {
            if (vols[i].sieges_disponibles > 0) {
                vols[i].sieges_disponibles--;
                printf("Réservation réussie !\n");
            } else {
                printf("Aucun siege disponible pour ce vol.\n");
            }
            return;
        }
    }
    printf("Vol non trouve.\n");
}

void annulerReservation(Vol vols[], int nbVols) {
    char code[TAILLE_CODE];
    printf("Entrez le code du vol : ");
    fgets(code, TAILLE_CODE, stdin);
    strtok(code, "\n");

    for (int i = 0; i < nbVols; i++) {
        if (strcmp(vols[i].code, code) == 0) {
            vols[i].sieges_disponibles++;
            printf("Annulation reussie !\n");
            return;
        }
    }
    printf("Vol non trouve.\n");
}

void afficherVols(const Vol vols[], int nbVols) {
    if (nbVols == 0) {
        printf("Aucun vol enregistre.\n");
        return;
    }

    printf("\nListe des vols :\n");
    for (int i = 0; i < nbVols; i++) {
        printf("Code : %s, Destination : %s, Date : %s, Sieges disponibles : %d\n",
               vols[i].code, vols[i].destination, vols[i].date, vols[i].sieges_disponibles);
    }
}

