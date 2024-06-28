#include <stdio.h>
#include <stdlib.h>

#include "lista2.h"
//#include "lista_circular.h"

int main( void ){

  lista_t *l = lista_inicia();
  
  l = lista_append( l, 3 );
  l = lista_append( l, 5 );
  l = lista_append( l, 8 );
  l = lista_append( l, 1 );
  l = lista_append( l, 7 );
  
  lista_imprime(l);
  printf("\n");
  
  bubble_sort(l);
  
  lista_imprime(l);
  printf("\n");
  
  lista_termina(l);

  return 0;
}