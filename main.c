#include <stdio.h>
#include "vol.h"
#include "data.h"

int main() {
    Vol vols[MAX_VOLS];
    int nbVols = 0;
    int choix;

    chargerDonnees(vols, &nbVols);

    do {
        printf("\n=== Systeme de reservation de vols ===\n");
        printf("1. Ajouter un vol\n");
        printf("2. Reserver un siege\n");
        printf("3. Annuler une reservation\n");
        printf("4. Afficher les vols\n");
        printf("5. Quitter\n");
        printf("Entrez votre choix : ");
        scanf("%d", &choix);
        getchar();  // Pour consommer le '\n' restant

        switch (choix) {
            case 1:
                ajouterVol(vols, &nbVols);
                break;
            case 2:
                reserverSiege(vols, nbVols);
                break;
            case 3:
                annulerReservation(vols, nbVols);
                break;
            case 4:
                afficherVols(vols, nbVols);
                break;
            case 5:
                enregistrerDonnees(vols, nbVols);
                printf("Donnees enregistrees.Merci !\n");
                break;
            default:
                printf("Choix invalide. Veuillez reessayer.\n");
        }
    } while (choix != 5);

    return 0;
}
