#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int vide = 0;
const int saturee = 10;
const int niveau_fitness_initiale = 5;
const int niveau_stock_initiale = 5;

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
            printf("         \\  (XX)\\_______/\n");
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
            printf("Erreur : entrée inattendue. La condition physique des vaches doit être comprise entre 0 et 10 inclus.\n");
            break;
    }
}



int main(int argc, char* argv[]) {

    // On déclare les variables qui influencent le jeu.
    int fitness = niveau_fitness_initiale;
    int stock = niveau_stock_initiale;
    int digestion; // sera généré aléatoirement sur chaque boucle entre 0 et 3 inclus
    int crop; // sera généré aléatoirement sur chaque boucle entre -3 et 3 inclus.
    int lunchfood; // sera demandé à chaque fois à l'utilisateur. N'acceptez les entrées de l'utilisateur que si <=stock
    int duree_de_vie; // iterateur dans la boucle principale

    // Start timer

    /* Enter loop
     * - Print cow according to current fitness level
     * - Print current stock
     * - Ask user what value of lunchfood they want to give to the cow, checking it is greater than stock.
     * - Update fitness
     *      fitness_update(int lunchfood)
     *      - can access fitness
     *      - generate digestion
     *      - return (fitness + lunchfood) + digestion
     *
     * - If fitness between 1 and 9 inclusive,
     * - Then increment duree_de_vie
     * - Then update stock to add or subtract randomly generated crop and proceed with the loop.
     *      This is achieved with stock_update(int lunchfood) within which we
     *      - can access stock, even though we're in a new function
     *      - generate crop
     *      - return (stock-lunchfood) + crop
     * - Else break out of the loop - we have lost the game
     */

    // End timer

    /*
     * - Output final score (time elapsed in seconds).
     * - Output ASCII trophy based on how well the user did. Give bronze, silver, and gold medals.
     */

    /*
     * Question: is the user allowed to input a lunchfood that, combined with digestion,
     * will produce a fitness way over 10? In this case, do we move to overate stage? Or do we circle
     * back and ask the user for another lunchfood value?
    */


    printf("Enter a choice (1, 2, or 3): ");
    scanf("%d", &choice);

    return 0;
}

