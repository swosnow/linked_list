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
          *aux = *i ; // copia valor de i em aux.
          *i =  *j; // copia valor de j em i.
          i->prox = aux->prox; // altera ponterio do próximo de i para que ele continue sendo o mesmo que era antes da copia
          aux->prox = j->prox; // copia o valor do ponteiro do proximo j
          *j = *aux; // copia valor de aux em j.
          j->prox = aux->prox; // altera ponterio do próximo de i para que ele continue sendo o mesmo que era antes da copia
          printf("entrou\n");           
      }
      i = i->prox;      
      printf("stop\n");    
    }
    swaped++;
    printf("2\n");
  }
  free(aux);
} 

lista_t *divide(lista_t *l){
  lista_t *part1 = l;
  lista_t *part2 = l;
  lista_t *parte2;
 
  while(part1->prox != NULL && part1->prox->prox != NULL){
    part1 = part1->prox->prox;
    part2 = part2->prox;
  }
  
  parte2 = part2->prox;
  part2->prox = NULL;

  return parte2;
}

void desaloca(lista_t *l){
  lista_t *i;
  i = l;

  if(i != NULL){
    desaloca(i->prox);

  }
  free(i);
}

lista_t *merge_sort(lista_t *l){
  lista_t *l2;
  if(l->prox == NULL) return l;
  

  
  l2 = divide(l);
  l = merge_sort(l);
  l2 = merge_sort(l2);

  return merge(l, l2);



}

lista_t *merge(lista_t *l, lista_t *parte2){
  if (l == NULL){
    desaloca(l);
    return parte2;
  }

  if (parte2 == NULL){
    desaloca(l);
    return parte2;
  }

  if(l->x < parte2->x){
    l->prox = merge(l->prox, parte2);
    l->prox->ante = l;
    l->ante = NULL;

    return l;
    desaloca(parte2);
  }
  else{
    parte2->prox = merge(l, parte2->prox);
    parte2->prox->ante = parte2;
    parte2->ante = NULL;
    return parte2;
    desaloca(l);
  }
  
}