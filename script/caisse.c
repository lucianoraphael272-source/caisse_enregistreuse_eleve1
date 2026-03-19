#include <stdio.h>
#include <stdlib.h>
#include <time.h>
double calcule_monnaie(double x,double y)
{	double  monnaie = x - y ;
	return monnaie;
}

double afficher_monnaie(double rendu) {
    int billets[] = {2000, 500, 200, 100, 50, 20, 10};
    int pieces[] = {5, 2, 1};

    int montant = (int)rendu;

    printf("Détail de la monnaie:\n");

    for (int i = 0; i < 7; i++) {
        if (montant >= billets[i]) {
            int nb = montant / billets[i];
            montant %= billets[i];
            printf("Billet Rs%d x %d\n", billets[i], nb);
        }
    }

    for (int i = 0; i < 3; i++) {
        if (montant >= pieces[i]) {
            int nb = montant / pieces[i];
            montant %= pieces[i];
            printf("Pièce Rs%d x %d\n", pieces[i], nb);
        }
    }
}




int main() {
    // Initialisation du générateur aléatoire
    srand(time(NULL));

    // Générer un prix aléatoire entre 10 et 200
    double prix = (rand() % 2000) / 10; // 10 à 200
    double  montant = 0;

        printf("montant à payer : Rs%.2f\n", prix);

	while( montant < prix )
	{
	printf("Entrez le montant:\n");
	scanf("%lf" ,&montant);
	if( montant < prix )
	{
	printf("insuffisant\n"); 
	}
	}

double rendu = calcule_monnaie(montant , prix);
printf("Total a rendre est %.2f\n", rendu);
afficher_monnaie(rendu);   
 return 0;
}
