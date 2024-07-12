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
    printf("[%d] ", aux->x);
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

  if(l->prox == NULL)return;
  
  lista_t *i = l;
  lista_t *j, *ordenado;

  ordenado = (lista_t *) malloc(sizeof(lista_t));

  
  while (i != NULL){
    j = i->prox;
        
    
    while (j != NULL){  
      
      if(i-> x > j->x ){
         
        *ordenado = *i ; 
        *i =  *j;
        i->prox = ordenado->prox; 
        ordenado->prox = j->prox; 
        *j = *ordenado; 
        j->prox = ordenado->prox;                        
      }
      
      j = j -> prox;
    }

    i = i ->prox;

  }
  free(ordenado);

}


void bubble_sort(lista_t *l)
{
  if(l->prox == NULL)return;
  
  lista_t *i = l;
  lista_t *aux, *j;
  int len_lista = sizeof(l);
  int swaped = 0;
  aux = (lista_t *)malloc(sizeof(lista_t));

  if(len_lista < 2)return;
   
  while ( swaped != len_lista)
  {
    i = l;
    while(i != NULL){
      j = i-> prox;      
      
      if(j == NULL)break;
      
      if(i-> x > j->x ){         
          *aux = *i ; 
          *i =  *j;
          i->prox = aux->prox; 
          aux->prox = j->prox; 
          *j = *aux;
          j->prox = aux->prox; 
                 
      }
      i = i->prox;      
      
    }
    swaped++;
    
  }
  free(aux);
} 

lista_t *MERGE(lista_t *esq, lista_t *dir){

  lista_t* aux = NULL;
  if (esq == NULL){
    return (dir);
  }else if(dir == NULL){
    return (esq);
  }
  if(esq->x <= dir->x){
    aux = esq;    
    aux->prox = MERGE(esq->prox, dir);    
  }else{
    aux = dir;    
    aux->prox = MERGE(esq, dir->prox);    
  } 
  return (aux);
}

 lista_t* meio( lista_t* l) {
     lista_t* p1 = l;
     lista_t* p2 = l;
     lista_t* aux = NULL;

    
    while (p1 != NULL && p1->prox != NULL) {
        p1 = p1->prox->prox;
        aux = p2;
        p2 = p2->prox;
    }
    if (aux != NULL) {
        aux->prox = NULL; 
    }

    return p2;
}

void MERGE_SORT( lista_t** l) {
    lista_t* l1 = *l;
    lista_t* esq;
    lista_t* dir;

   
    if (l1 == NULL || l1->prox == NULL) {
        return;
    }

   
    lista_t* mid = meio(l1);
    esq = l1;
    dir = mid;    
    MERGE_SORT(&esq);
    MERGE_SORT(&dir);    
    *l = MERGE(esq, dir);
}