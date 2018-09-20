#include <stdio.h>
#include <stdlib.h>
#include "pile.h"
#include "parenthese.h"

int main(int argc, char *argv[])
{
  if (argc > 1)
  {
    if(bienParenthese(argv[1]))
    {
      printf("Expression bien parenthésée.\n");
    }
    else {
      printf("Expression mal parenthésée.\n");
    }
  }
  return 0;

}
