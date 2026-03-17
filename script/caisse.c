#include <stdio.h>
#include <stdlib.h>
#include <time.h>
double calcule_monnaie(double x,double y)
{	double  monnaie = x - y ;
	return monnaie;
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
    return 0;
}
