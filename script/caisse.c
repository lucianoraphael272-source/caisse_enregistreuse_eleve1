#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double calcule_monnaie(double x,double y)
{
    return x - y;
}

int peut_rendre(int montant, int billets[], int stock_b[], int pieces[], int stock_p[]) {
    for (int i = 0; i < 7; i++) {
        int besoin = montant / billets[i];
        if (besoin > stock_b[i]) {
            besoin = stock_b[i];
        }
        montant -= besoin * billets[i];
    }

    for (int i = 0; i < 3; i++) {
        int besoin = montant / pieces[i];
        if (besoin > stock_p[i]) {
            besoin = stock_p[i];
        }
        montant -= besoin * pieces[i];
    }

    return montant == 0;
}

void rendre_monnaie(int montant, int billets[], int stock_b[], int pieces[], int stock_p[]) {
    printf("Monnaie rendue:\n");

    for (int i = 0; i < 7; i++) {
        int nb = montant / billets[i];
        if (nb > stock_b[i]) nb = stock_b[i];

        if (nb > 0) {
            printf("Billet Rs%d x %d\n", billets[i], nb);
            stock_b[i] -= nb;
            montant -= nb * billets[i];
        }
    }

    for (int i = 0; i < 3; i++) {
        int nb = montant / pieces[i];
        if (nb > stock_p[i]) nb = stock_p[i];

        if (nb > 0) {
            printf("Pièce Rs%d x %d\n", pieces[i], nb);
            stock_p[i] -= nb;
            montant -= nb * pieces[i];
        }
    }
}

int main() {
    srand(time(NULL));

    int billets[] = {2000, 500, 200, 100, 50, 20, 10};
    int pieces[] = {5, 2, 1};

    int stock_b[] = {2,2,2,2,2,2,2};
    int stock_p[] = {5,5,5};

    while (1) {
        double prix = (rand() % 2000) / 10;
        double montant = 0;

        printf("\nMontant a payer : Rs%.2f\n", prix);

        while (montant < prix) {
            printf("Entrez le montant:\n");
            scanf("%lf", &montant);

            if (montant < prix) {
                printf("Insuffisant\n");
            }
        }

        int rendu = (int)calcule_monnaie(montant, prix);
        printf("Total a rendre : Rs%d\n", rendu);

        if (peut_rendre(rendu, billets, stock_b, pieces, stock_p)) {
            rendre_monnaie(rendu, billets, stock_b, pieces, stock_p);
        } else {
            int choix;
            printf("Impossible de rendre la monnaie.\n");
            printf("1. Quitter\n2. Recharger caisse\n");
            scanf("%d", &choix);

            if (choix == 1) {
                break;
            } else {
                for (int i = 0; i < 7; i++) stock_b[i] = 5;
                for (int i = 0; i < 3; i++) stock_p[i] = 10;
                printf("Caisse rechargée.\n");
            }
        }
    }

    return 0;
}
