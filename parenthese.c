#include <stdlib.h>
#include <string.h>
#include "pile.h"
#include "parenthese.h"

bool estPaire(char pOuvrant, char pFermant)
{
  if (pOuvrant == '(' && pFermant == ')')
    return true;
  else if (pOuvrant == '{' && pFermant == '}')
    return true;
  else if (pOuvrant == '[' && pFermant == ']')
    return true;

  return false;
}

bool bienParenthese(char *expression)
{
  Pile *parenthesePile = creerPile();
  char c;
  int i = 0;
  do {
    c = expression[i];
    if (c == '(' || c == '[' || c == '{')
    {
      empiler(parenthesePile,c);
    }
    else if (c == ')' || c == ']' || c == '}')
    {
      if (pileEstVide(parenthesePile) || !estPaire(sommetPile(parenthesePile),c))
      {
        return false;
      }
      else
      {
        depiler(parenthesePile);
      }
    }
    i++;
  } while(c != '\0');
  if (pileEstVide(parenthesePile))
  {
    detruirePile(parenthesePile);
    return true;
  }
  detruirePile(parenthesePile);
  return false;
}
