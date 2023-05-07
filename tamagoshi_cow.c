#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include "citation.h"

const int min_stock = 0;
const int max_stock = 10;

int fitness = 5;
int stock = 5;
int game_mode = 0; // 0 = normal, 1 = pro, changer le points requis pour les trophees

void affiche_vache(int fitness) {

        // byebyelife_faim
        if (fitness<=0) {
            affiche_citation("Not Enough Food...Bye Bye Life!");
            printf("        \\   ^__^         /\n");
            printf("         \\  (XX)\\_______/\n");
            printf("            <__>\\-----w-)     \n");
            printf("              U |      |\n");
            printf("                 |     |\n");
        }

        // lifesucks_faim
        else if (fitness>=1 && fitness<=3) {
            affiche_citation("Not Enough Food...Life Sucks!");
            printf("        \\   ^__^          \n");
            printf("         \\  (o0)\\_______/\n");
            printf("            <__>\\-----w-)     \n");
            printf("              U |      |\n");
            printf("                 |     |\n");
        }

        // liferocks
        else if (fitness >=4 && fitness <=6) {
            affiche_citation("Life Rocks!");
            printf("        \\   ^__^\n");
            printf("         \\  (oo)\\_______\n");
            printf("            (__)\\       )\\/\\\n");
            printf("             U ||----w |\n");
            printf("                ||     ||\n");
        }

        // lifesucks_suralimentation
        else if (fitness>=7 && fitness<=9) {
            affiche_citation("Too Much Food...Life Sucks!");
            printf("        \\   ^__^\n");
            printf("         \\  (.o)\\_______\n");
            printf("            (__)\\       )\\/\\\n");
            printf("             U ||----w |\n");
            printf("                ||     ||\n");
        }

        // byebyelife_suralimentation
        else if (fitness >=10) {
            affiche_citation("Too Much Food...Bye Bye Life!");
            printf("        \\   ^__^\n");
            printf("         \\  (XX)\\_______\n");
            printf("            (__)\\       )\\/\\\n");
            printf("             U ||----w |\n");
            printf("                ||     ||\n");
        }

        else {
            printf("Erreur : entree inattendue. La condition physique des vaches doit etre comprise entre 0 et 10 inclus.\n");
        }
}

void affiche_trophee(int position) {

    printf("  _______\n");
    printf(" |       |\n");
    printf("(|   %d   |)\n", position);
    printf(" |       |\n");
    printf("  \\     /\n");
    printf("   `---'\n");
    printf("   _|_|_\n");
}

int fitness_update(int lunchfood_fitness) {
    int digestion = (rand() % 4) - 3;
    printf("Digestion is %d\n", digestion);
    return (fitness + lunchfood_fitness) + digestion;
}

int stock_update(int lunchfood_stock) {

    int crop = rand() % 7 - 3;
    printf("Crop is %d\n", crop);
    int updated_stock = (stock - lunchfood_stock) + crop;

    if (updated_stock > 10) {
        stock = 10; // Plafonner le stock à 10
        return stock;
    } else {
        stock = updated_stock;
        return stock;
    }
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

    printf("\n\n\n+++++++++++++++++++++++++++++++++++++++++++++++++\nBienvenue dans le jeu cowsay base sur "
           "l'automate\n+++++++++++++++++++++++++++++++++++++++++++++++++\n\n");
    printf("Selectionnez un mode de jeu. Le mode Pro necessite des points plus eleves pour gagner un trophee\n");
    printf("Pro - Taper 1, Normal - Taper 0: ");
    scanf("%d", &game_mode);

    while (1) {

        // Afficher la vache et le stock
        validInput = 0;
        printf("\n\n\n++++++++++++++++++++++++++++++\nDuree de vie: %d\n"
               "++++++++++++++++++++++++++++++\n\n", duree_de_vie);
        affiche_vache(fitness);
        //printf("\nFitness actuel: %d", fitness); // utile pour tester
        printf("\nStock actuel: %d\n\n", stock);

        // Demander à l'utilisateur la valeur de lunchfood
        while (!validInput) {

            printf("Donner la valeur de lunchfood pour la vache:");

            if (scanf("%d", &lunchfood) != 1) {
                printf("Erreur: entrez un nombre entier inferieur ou egal au niveau de stock actuel.\n");
            }
            else if (lunchfood<0) {
                printf("Lunchfood doit etre >= 0!\n");
            }
            else if (stock<0 && lunchfood!=0) {
                printf("Vous n'avez plus de nourriture dans votre stock! Lunchfood doit etre 0\n");
            }
            else if (stock<0 && lunchfood==0) {
                validInput=1;
            }
            else if ( (stock>=0) && (lunchfood > stock) ) {
                printf("La valeur de Lunchfood depasse le stock actuel. Essayer a nouveau.\n");
            }
            else if (lunchfood <= stock) {
                validInput=1;
            }
            else
                printf("Erreur: entrez un nombre entier inferieur ou egal au niveau de stock actuel.");

        }

        // Mettre à jour la condition physique et le stock
        fitness = fitness_update(lunchfood);
        stock = stock_update(lunchfood);

        if ( (fitness >= 1 && fitness <= 9) )
            duree_de_vie++;
        else {
            printf("\n\n\n++++++++++++++++++++++++++++++\nGAMEOVER\n++++++++++++++++++++++++++++++\n\n");
            affiche_vache(fitness);
            //printf("\nFitness actuel: %d", fitness); // Utile pour tester
            printf("\nStock actuel: %d\n", stock);
            printf("\n++++++++++++++++++++++++++++++\nSTATISTIQUES\n++++++++++++++++++++++++++++++\n");
            if (stock==-1) {
                printf("\nVous n'avez plus de nourriture dans votre stock!\n");
            }
            break;
        }
    }

    // Afficher le score final et le trophée
    printf("Score final: %d \n", duree_de_vie);

    if ( (duree_de_vie) >= ( (game_mode==0) ? 15 : 30) ) {
        affiche_trophee(1);
    } else if ( (duree_de_vie) >= ( (game_mode==0) ? 10 : 20) ){
        affiche_trophee(2);
    } else if ( (duree_de_vie) >= ( (game_mode==0) ? 5 : 10) ){
        affiche_trophee(3);
    } else {
        if (game_mode==0)
            printf("Vous n'avez pas gagne de medaille en mode normal!\n");
        if (game_mode==1)
            printf("Vous n'avez pas gagne de medaille en mode pro!\n");
    }

    return 0;
}