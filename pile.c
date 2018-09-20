#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "pile.h"

typedef struct Element {
	Data data;				/** La donnée contenue dans l'élément. **/
	struct Element *suivant;		/** L'élément suivant dans la pile. **/
} Element;

struct Pile {
	size_t nombre; 	/** Nombre d'éléments dans la pile. **/
	Element *sommet;	/** Elément au sommet de la pile. **/
};

Pile *creerPile()
{
	/* Initialiser la pile and set everything to the default values. */
	Pile *pile = (Pile *) malloc(sizeof *pile);
	if(pile == NULL)
		return NULL;

	pile->nombre = 0;
	pile->sommet = NULL;

	return pile;
}

void detruirePile(Pile *pile)
{
	viderPile(pile);
	free(pile);
}

void viderPile(Pile *pile)
{
	while(!pileEstVide(pile))
		depiler(pile);
}

bool pileEstVide(Pile *pile)
{
	return pile->sommet == NULL ? true : false;
}

size_t taillePile(Pile *pile)
{
	return pile->nombre;
}

Data sommetPile(Pile *pile)
{
	return pile->sommet->data;
}

bool empiler(Pile *pile, Data data)
{
	Element *nouveauSommet = (Element *) malloc(sizeof *nouveauSommet);
	if(nouveauSommet == NULL)
		return false;

	nouveauSommet->data = data;
	nouveauSommet->suivant = pile->sommet;
	pile->sommet = nouveauSommet;

	pile->nombre += 1;
	return true;
}

Data depiler(Pile *pile)
{
	Element *ancienSommet;
	Data data;

	if(pile->sommet == NULL)
	{
		exit(EXIT_FAILURE);
	}

	ancienSommet = pile->sommet;
	data = ancienSommet->data;
	pile->sommet = ancienSommet->suivant;
	free(ancienSommet);
	ancienSommet = NULL;

	pile->nombre -= 1;
	return data;
}

void afficherPile(Pile* pile)
{
	if (pile == NULL)
	{
		exit(EXIT_FAILURE);
	}
	Element* actuel = pile->sommet;

	while (actuel != NULL)
	{
		printf("%c\n",actuel->data);
		actuel = actuel->suivant;
	}
}
