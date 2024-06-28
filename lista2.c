#include "lista2.h"

lista_t *lista_inicia(void){
  lista_t *p = NULL;
  return p;
}

void lista_termina( lista_t *l ){
  lista_t *aux;
  while ( l != NULL ){
    aux = l;
    l = l->prox;
    free(aux);
  }
}

lista_t *lista_append( lista_t *l, int d ){
  
  lista_t *novo = (lista_t *) malloc(sizeof(lista_t));
  novo->x = d;
  novo->ante = NULL;
  novo->prox = NULL;
  
  if ( l == NULL ){
    l = novo;
    return l;
  }
  
  lista_t *aux = l;
  while ( aux->prox != NULL ){
    aux = aux->prox;
  }
  aux->prox = novo;
  novo->ante = aux;
  
  return l;
}

void lista_imprime( lista_t *l ){
  lista_t *aux = l;
  while ( aux != NULL ){
    printf("%d ", aux->x);
    aux = aux->prox;
  }
}

void lista_imprime_inverso( lista_t *l ){
  lista_t *aux = l;
  while ( aux->prox != NULL ){
    aux = aux->prox;
  }
  while ( aux != NULL ){
    printf("%d ", aux->x);
    aux = aux->ante;
  }
}

// adiciona no inicio
lista_t *lista_push( lista_t *l, int d ){
  lista_t *novo = (lista_t *) malloc(sizeof(lista_t));
  novo->x = d;
  novo->ante = NULL;
  novo->prox = l;
  
  l->ante = novo;
  
  return novo;
}

// remove do inicio
lista_t *lista_pop( lista_t *l ){
  
  lista_t *aux = l;
  l = l->prox;
  l->ante = NULL;
  free(aux);

  return l;
}

void selection_sort(lista_t *l){
  lista_t *i = l;
  lista_t *j, *ordenado;

  ordenado = (lista_t *) malloc(sizeof(lista_t));

  
  while (i != NULL){
    j = i->prox;    
    
    while (j != NULL){  
      
      if(i-> x > j->x ){
         
        *ordenado = *i ; // copia valor de i em aux.
        *i =  *j; // copia valor de j em i.
        i->prox = ordenado->prox; // altera ponterio do próximo de i para que ele continue sendo o mesmo que era antes da copia
        ordenado->prox = j->prox; // copia o valor do ponteiro do proximo j
        *j = *ordenado; // copia valor de aux em j.
        j->prox = ordenado->prox; // altera ponterio do próximo de i para que ele continue sendo o mesmo que era antes da copia                        
      }
      
      j = j -> prox;
    }

    i = i ->prox;

  }

}

void bubble_sort(lista_t *l)
{
  lista_t *i = l;
  lista_t *aux;
  lista_t *j;

  aux = (lista_t *)malloc(sizeof(lista_t));

  if ( sizeof(l) < 2) return;
  
  while (i != NULL)
  {
    

    while ( i->prox != NULL)    
    {
      
      if(i > i -> prox){
        aux = i->prox;
        i->prox = i;
        *i = *aux;
          
      }
      i = i->prox;             
    }
    
  i = i->prox;    
  }

} 

      

