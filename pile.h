#ifndef PILE_H_INCLUDED
#define PILE_H_INCLUDED

#include <stdlib.h>

#if !defined(__bool_true_false_are_defined) && !defined(__cplusplus)
typedef int bool;
#define true 1
#define false 0
#define __bool_true_false_are_defined
#endif

#define Data char

typedef struct Pile Pile;

Pile *creerPile();
void detruirePile(Pile *pile);
void viderPile(Pile *pile);
bool pileEstVide(Pile *pile);
size_t taillePile(Pile *pile);
Data sommetPile(Pile *pile);
bool empiler(Pile *pile, Data data);
Data depiler(Pile *pile);
void afficherPile(Pile *pile);

#endif
