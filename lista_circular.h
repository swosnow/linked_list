#ifndef LISTACIRCULAR_H
#define LISTACIRCULAR_H

  #include <stdio.h>
  #include <stdlib.h>

  struct _no_ {
    int x; // dado armazenado no nó de uma lista
    struct _no_ *prox;
  };
  typedef struct _no_ lista_t;


  lista_t *lista_inicia(void);
  void lista_termina( lista_t *l );
  lista_t *lista_append( lista_t *l, int d );
  void lista_imprime( lista_t *l );
  lista_t *lista_push( lista_t *l, int d );
  lista_t *lista_pop( lista_t *l );

#endif // LISTACIRCULAR_H