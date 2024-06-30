#ifndef LISTA2_H
#define LISTA2_H

  #include <stdio.h>
  #include <stdlib.h>

  struct _no_ {
    int x; // dado armazenado no nó de uma lista
    struct _no_ *ante;
    struct _no_ *prox;
  };
  typedef struct _no_ lista_t;


  lista_t *lista_inicia(void);
  void lista_termina( lista_t *l );
  lista_t *lista_append( lista_t *l, int d );
  void lista_imprime( lista_t *l );
  void lista_imprime_inverso( lista_t *l );
  lista_t *lista_push( lista_t *l, int d );
  lista_t *lista_pop( lista_t *l );
  void selection_sort(lista_t *l);
  void bubble_sort(lista_t *l);
  lista_t *merge_sort(lista_t *);
  void desaloca(lista_t *l);
  lista_t *merge(lista_t *l, lista_t *parte2);
  lista_t *divide(lista_t *l);

#endif // LISTA2_H;