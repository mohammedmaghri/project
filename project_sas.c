#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_RESERVATIONS 100
#define STATUT_STAY 10

typedef struct {
    char nom[50];
    char prenom[50];
    char tel[15]; 
    int age;
    char statut[STATUT_STAY];
    int reference;
    char date[12]; 
} Reservation;
Reservation R[MAX_RESERVATIONS]; 
int total_reservations = 0;
void ajouterReservation(){
    int n,x;
     printf("Combien de réservations de rendez-vous dentaires vous voulez : ");
                scanf("%d", &n);
                for (int i = 0; i < n && i < MAX_RESERVATIONS; i++) { 

                    printf("\nEntrez les informations suivantes :\n");
                    printf("Nom: ");
                    scanf("%s",R[i].nom);
                    printf("Prénom: ");
                    scanf("%s", R[i].prenom);
                    printf("Téléphone: ");
                    scanf("%s", R[i].tel);  
                    printf("Âge: ");
                    scanf("%d", &R[i].age); 
                    
                    printf("\nChoisissez le statut (1-4):\n");
                    printf("1 --> Valide\n");
                    printf("2 --> Reporte\n");
                    printf("3 --> Annule\n");
                    printf("4 --> Traite\n");
                    scanf("%d", &x); 
                    
                    switch (x) {
                        case 1:
                            strcpy(R[i].statut, "Valide");
                            break;
                        case 2:
                            strcpy(R[i].statut, "Reporte");
                            break;
                        case 3:
                            strcpy(R[i].statut, "Annule");
                            break;
                        case 4:
                            strcpy(R[i].statut, "Traite");
                            break;
                        default:
                            printf("Please choose a number between 1 and 4.\n");
                    }

                    // Set reference number and date
                    R[i].reference = i + 1;
                    strcpy(R[i].date, "12-10-2024");
                    total_reservations++;
                }
              
}
void modifierReservation(){
    int ref,i;
     printf("Entrez la référence de la réservation à modifier : ");
                scanf("%d", &ref);

                for (int i = 0; i < total_reservations; i++) {
                    if (R[i].reference == ref) {
                        printf("Modifier la réservation pour %s %s\n", R[i].nom, R[i].prenom);
                        printf("Nouvelle statut (Valide, Reporte, Annule, Traite) : ");
                        scanf("%s", R[i].statut);
                        printf("Modification effectuée!\n");
                        break;
                    }
                }
                
                if (i == total_reservations) {
                    printf("Réservation non trouvée.\n");
                      
                }
              
                printf("Entrez la référence de la réservation à supprimer : ");
                scanf("%d", &ref);

                for (i = 0; i < total_reservations; i++) {
                    if (R[i].reference == ref) {
                        for (int j = i; j < total_reservations - 1; j++) {
                            R[j] = R[j + 1];
                        }
                        total_reservations--;
                        printf("Réservation supprimée avec succès!\n");
                        break;
                    }
                }
                if (i == total_reservations) {
                    printf("Réservation non trouvée.\n");
                       
                }
             
}
void afficherDetails() {
    int ref;
    printf("Entrez la référence de la réservation : ");
    scanf("%d", &ref);

    for (int i = 0; i < total_reservations; i++) {
        if (R[i].reference == ref) {
            printf("Détails de la réservation :\n");
            printf("Nom : %s\n", R[i].nom);
            printf("Prénom : %s\n", R[i].prenom);
            printf("Téléphone : %s\n", R[i].tel);
            printf("Âge : %d\n", R[i].age);
            printf("Statut : %s\n", R[i].statut);
            printf("Référence : %d\n", R[i].reference);
            printf("Date de réservation : %s\n", R[i].date);
            return;
        }
    }
    printf("Réservation non trouvée.\n");
}
void trierReservations() {
    for (int i = 0; i < total_reservations - 1; i++) {
        for (int j = i + 1; j < total_reservations; j++) {
            if (strcmp(R[i].nom, R[j].nom) > 0) {
                Reservation temp = R[i];
                R[i] = R[j];
                R[j] = temp;
            }
        }
    }
    printf("Réservations triées par nom.\n");
}
void rechercherReservation() {
    char nom[50];
    printf("Entrez le nom à rechercher : ");
    scanf("%s", nom);

    for (int i = 0; i < total_reservations; i++) {
        if (strcmp(R[i].nom, nom) == 0) {
            printf("Réservation trouvée : %s %s (Réf: %d)\n", R[i].nom, R[i].prenom, R[i].reference);
            return;
        }
    }
    printf("Aucune réservation trouvée avec ce nom.\n");
}
void afficherStatistiques() {
    int age_total = 0;
    int count_age[3] = {0, 0, 0}; // Tranches d'âge 0-18, 19-35, 36+
    int count_statut[4] = {0}; // validé, reporté, annulé, traité

    for (int i = 0; i < total_reservations; i++) {
        age_total += R[i].age;

        if (R[i].age <= 18)
            count_age[0]++;
        else if (R[i].age <= 35)
            count_age[1]++;
        else
            count_age[2]++;

        if (strcmp(R[i].statut, "validé") == 0) count_statut[0]++;
        else if (strcmp(R[i].statut, "reporté") == 0) count_statut[1]++;
        else if (strcmp(R[i].statut, "annulé") == 0) count_statut[2]++;
        else if (strcmp(R[i].statut, "traité") == 0) count_statut[3]++;
    }

    printf("Moyenne d'âge des patients : %.2f\n", (double)age_total / total_reservations);
    printf("Nombre de patients par tranche d'âge :\n");
    printf("0-18 ans : %d\n", count_age[0]);
    printf("19-35 ans : %d\n", count_age[1]);
    printf("36+ ans : %d\n", count_age[2]);
    printf("Nombre total de réservations par statut :\n");
    printf("Validé : %d, Reporté : %d, Annulé : %d, Traité : %d\n",
           count_statut[0], count_statut[1], count_statut[2], count_statut[3]);
}
int main() {
   
   
    int choix, i, n, x, ref;  // Declare 'ref' at the beginning

    do {
        printf("\n°°°°°°°°°°°°°°°°°°°°°°°°°°°°");
        printf("\nL'application permet de gérer les réservations de rendez-vous dentaires,");
        printf("\n~~~~~~~~~~~");
        printf("\nPlease choose a number between 1 to 6");
        printf("\nPour Ajouter une réservation --> 1");
        printf("\nPour Modifier ou supprimer une réservation --> 2");
        printf("\nPour Afficher les détails d'une réservation --> 3");
        printf("\nPour Tri des réservations --> 4");
        printf("\nPour Recherche des réservations --> 5");
        printf("\nPour Statistiques --> 6");
        printf("\nSortie --> 7");
        printf("\nEnter number choice: ");
        scanf("%d", &choix);

        switch (choix) {
            case 1:{
                     ajouterReservation();
                }
            case 2:{
                    modifierReservation();
                }
               
            case 3:{
                    afficherDetails();
                 } 
            
            case 4:{
                    trierReservations();
                break;
              }
             

            case 5:{
                    rechercherReservation();
                      break;
               }
                
            case 6:{
                   afficherStatistiques();
                   break; 
              }
              
             

            default:
                if (choix != 7)
                    printf("Veuillez choisir un numéro entre 1 et 7.\n");
                    break;
        }
        int genererReference() {
    static int ref = 1;
    return ref++;
}

    } while (choix != 7);

    printf("Sortie du programme.\n");
    return 0;
}