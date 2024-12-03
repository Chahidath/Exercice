#ifndef VOL_H
#define VOL_H

#define MAX_VOLS 100
#define TAILLE_CODE 10
#define TAILLE_DEST 50

// Structure pour représenter un vol
typedef struct {
    char code[TAILLE_CODE];
    char destination[TAILLE_DEST];
    char date[11];  // Format: YYYY-MM-DD
    int sieges_disponibles;
} Vol;

// Prototypes des fonctions
void ajouterVol(Vol vols[], int *nbVols);
void reserverSiege(Vol vols[], int nbVols);
void annulerReservation(Vol vols[], int nbVols);
void afficherVols(const Vol vols[], int nbVols);

#endif

