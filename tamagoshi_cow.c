#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

const int min_stock = 0;
const int max_stock = 10;

int fitness = 5;
int stock = 5;

void affiche_vache(int fitness) {

    switch(fitness) {

        // byebyelife_faim
        case 0:
            printf("        \\   ^__^         /\n");
            printf("         \\  (XX)\\_______/\n");
            printf("            <__>\\-----w-)     \n");
            printf("              U |      |\n");
            printf("                 |     |\n");
            break;

        // lifesucks
        case 1:
        case 2:
        case 3:
        case 7:
        case 8:
        case 9:
            printf("        \\   ^__^         /\n");
            printf("         \\  (..)\\_______/\n");
            printf("            <__>\\-----w-)     \n");
            printf("              U |      |\n");
            printf("                 |     |\n");
            break;

        // liferocks
        case 4:
        case 5:
        case 6:
            printf("        \\   ^__^\n");
            printf("         \\  (oo)\\_______\n");
            printf("            (__)\\       )\\/\\\n");
            printf("             U ||----w |\n");
            printf("                ||     ||\n");
            break;

        // byebyelife_suralimentation
        case 10:
            printf("        \\   ^__^\n");
            printf("         \\  (XX)\\_______\n");
            printf("            (__)\\       )\\/\\\n");
            printf("             U ||----w |\n");
            printf("                ||     ||\n");
            break;

        default:
            printf("Erreur : entree inattendue. La condition physique des vaches doit etre comprise entre 0 et 10 inclus.\n");
            break;
    }
}

int fitness_update(int lunchfood) {
    int digestion = rand() % 10;
    return (fitness + lunchfood) + digestion;
}

int stock_update(int lunchfood) {
    int crop = rand() % 20;
    return (stock - lunchfood) + crop;
}

int main() {

    srand(time(NULL)); // initialiser le germe aléatoire

    // On déclare les variables qui influencent le jeu.
    int digestion; // sera généré aléatoirement sur chaque boucle entre 0 et 3 inclus
    int crop; // sera généré aléatoirement sur chaque boucle entre -3 et 3 inclus.
    int lunchfood; // sera demandé à chaque fois à l'utilisateur. N'acceptez les entrées de l'utilisateur que si <=stock
    int lifespan = 0; // iterateur dans la boucle principale
    int validInput = 0; // la gestion des erreurs

    int duree_de_vie = 0;
    int time_elapsed = 0;
    clock_t start_time = clock(); // Démarrer la minuterie

    while (1) {

        // Afficher la vache et le stock
        affiche_vache(fitness);
        printf("\nStock actuel: %d\n", stock);

        // Demander à l'utilisateur la valeur de lunchfood
        while (!validInput) {
            printf("Donner la valeur de lunchfood pour la vache:");
            scanf("%d", &lunchfood);

            if (scanf("%d", &lunchfood) != 1 || getchar() != '\n' || !isdigit(lunchfood)) {
                printf("Error: Please enter a valid integer value.\n");
                fflush(stdin);
            }
            else if (lunchfood > stock) {
                printf("La valeur de Lunchfood depasse le stock actuel. Essayer a nouveau.\n");
            }
            else if (lunchfood <= stock) {
                validInput=1;
            }
            else
                printf("Erreur: entrez un nombre entier inferieur ou egal au niveau de stock actuel");
        }

        // Mettre à jour la condition physique et le stock
        fitness = fitness_update(lunchfood);
        if (fitness >= 1 && fitness <= 9) {
            duree_de_vie++;
            stock = stock_update(lunchfood);
        } else {
            break;
        }
    }

    // Arrêter la minuterie
    clock_t end_time = clock();
    time_elapsed = (end_time - start_time) / CLOCKS_PER_SEC;
    printf("\nTemps total ecoule: %d secondes\n", time_elapsed);

    // Afficher le score final et le trophée
    printf("Score final: %d secondes ecoulees\n", time_elapsed);
    if (duree_de_vie >= 20) {
        printf("Medaille d'or obtenue!\n");
    } else if (duree_de_vie >= 10) {
        printf("Medaille d'argent obtenue!\n");
    } else {
        printf("Medaille de bronze obtenue!\n");
    }

    return 0;
}