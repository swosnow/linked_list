#include "lista_circular.h"

lista_t *lista_inicia(void){
  lista_t *p = NULL;
  return p;
}

void lista_termina( lista_t *l ){
  if ( l == NULL ) return;
  lista_t *aux = l;
  lista_t *para_liberar;
  do {
    para_liberar = aux;
    aux = aux->prox;
    free(para_liberar);
  } while (aux != l);
}

lista_t *lista_append( lista_t *l, int d ){
  
  lista_t *novo = (lista_t *) malloc(sizeof(lista_t));
  novo->x = d;
  novo->prox = l;
  
  if ( l == NULL ){
    novo->prox = novo;
    return novo;
  }
  
  lista_t *aux = l;
  while ( aux->prox != l ){
    aux = aux->prox;
  }
  aux->prox = novo;
  return l;
}

void lista_imprime( lista_t *l ){
  if ( l == NULL ) return;
  lista_t *aux = l;
  do {
    printf("%d ", aux->x);
    aux = aux->prox;
  } while ( aux != l );
}

// adiciona no inicio
lista_t *lista_push( lista_t *l, int d ){
  l = lista_append(l,d);
  lista_t *aux = l;
  while ( aux->prox != l ){
    aux = aux->prox;
  }
  return aux;
}

// remove do inicio
lista_t *lista_pop( lista_t *l ){
  if ( l == NULL ) return NULL;
  if ( l->prox == l ){
    free(l);
    return NULL;
  }
  
  lista_t *aux = l;
  while ( aux->prox != l ){
    aux = aux->prox;
  }
  aux->prox = l->prox;
  free(l);
  return aux->prox;
}