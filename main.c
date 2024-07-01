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
  l = lista_append( l, 10 );
  l = lista_append( l, 2 );
  l = lista_append( l, 11 );
  l = lista_append( l, 50);
  l = lista_append( l, 4 );
   
   


  
  lista_imprime(l);
  printf("\n");
  
  MERGE_SORT(&l);
  
  lista_imprime(l);
  printf("\n");
  
  lista_termina(l);

  return 0;
}