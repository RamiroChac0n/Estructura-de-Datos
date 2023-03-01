#include<stdio.h>
#include<stdlib.h>

struct node{
  int value;
  struct node *next;
};

struct node* createNode(int v){
  struct node *newNode = (struct node*) malloc( sizeof(struct node) );
  if( newNode ){
    newNode->value = v;  
    newNode->next = NULL;
  }
  return newNode;
}




//--------------------------Insert-------------------

void insertHead(struct node **list, int v){
  struct node *newNode = createNode(v);
  if( !newNode ){ //error al crear nodo
    return;
  }

  if( !(*list) ){ //lista vacia
    *list = newNode;                     
  }else{              //ya hay elementos
    newNode->next = *list;
    *list = newNode;
  }
}

void insertTail(struct node **list, int v){
  struct node *newNode = createNode(v);
  if( !newNode ){ //error al crear nodo
    return;
  }

  struct node *n = *list;
  if( !n ){ //lista vacia
    *list = newNode;
  }else{              //ya hay elementos
    struct node *lastNode = NULL;
    while( n ){
      if( !n->next ){  // si el puntero es igual a nulo 
        lastNode = n;
        break;
      }
      n = n->next;
    }
    lastNode->next = newNode;
  }
}




/* -------------------------------------------
* Coloque aquí la función de inserción
* en una posición arbitraria i
* que únicamente inserte si el valor v
* no se encuentra previamente en la lista
-------------------------------------------
*/ 





//--------------------------Search-------------------

int searchByValue(struct node *list, int v){
  struct node *n = list;
  int i = 0;

  while( n ){
    if( n->value == v ){
      return i;
    }
    n = n->next;
    i++;
  }

  return -1; //el valor no existe en la lista
  //se asume que -1 no es un valor del dominio del miembro n->value
}

int searchByIndex(struct node *list, int i){
  struct node *n = list;
  int j = 0;

  while( n && j < i ){
    n = n->next;
    j++;
  }

  if( n ){
    return n->value;
  }else{
    return -1; //indice fuera de rango
  }
}





//--------------------------Delete-------------------
void deleteHead(struct node **list){
  if( !(*list) ){
    return; //lista vacia
  }

  struct node *n = *list;
  *list = n->next;
  free(n);
}


void deleteTail(struct node **list){
  if( !(*list) ){
    return; //lista vacia
  }

  struct node *n = *list;
int searchByValue(struct node *list, int v){
  struct node *n = list;
  int i = 0;

  while( n ){
    if( n->value == v ){
      return i;
    }
    n = n->next;
    i++;
  }

  return -1; //el v
  }

  if( !penultimate ){//lista con solo un elemento
    *list = NULL;
  }else{             //la lista tiene mas de un elemento
    penultimate->next = NULL;
  }
  free(n);
}


void deleteByIndex(struct node **list, int i){
  if( !(*list) ){
    return; //lista vacia
  }

  if( i < 0 ){
    return; //indice fuera de rango
  }

  if( i == 0 ){ //eliminar el primero
    deleteHead(list);
    return;
  }

  struct node *n = *list;
  struct node *previous = NULL;
  int j = 0;
  while( n->next && j < i){
    previous = n;
    n = n->next;
    j++;
  }

  if( j != i ){ //indice fuera de rango
    return;
  }

  //eliminar un nodo no-primero de una lista con varios nodos
  previous->next = n->next;
  free(n);
}





/* -------------------------------------------
* Coloque aquí la función de eliminación por valor
* la cual debe remover de la lista todas las
* copias del valor seleccionado pra remover
-------------------------------------------
*/ 








//--------------------------Extras-------------------

void displayList(struct node *list){
  struct node *n = list;
  while( n ){
    printf("%d->",n->value);
    n = n->next;
  }
  printf("\n");
}

void clearList(struct node **list){
  struct node *n = *list;
  struct node *nextNode = NULL;
  while( n ){
    nextNode = n->next;
    free(n);
    n = nextNode;
  } 
  *list = NULL;
}


int main(){
  struct node *myList = NULL;

  /*
  insertAt(&myList, 5, 0);
  insertAt(&myList, 10, 0);
  insertAt(&myList, 13, 2);
  insertAt(&myList, 20, 3);
  insertAt(&myList, 50, 2);
  */

  insertTail(&myList, 8);
  insertHead(&myList, 6);


  displayList(myList);
/*
  printf("Buscar valor 6: indice: %d\n", searchByValue(myList, 6));
  printf("Buscar valor 50: indice: %d\n", searchByValue(myList, 50));
  printf("Buscar valor 8: indice: %d\n", searchByValue(myList, 8));
  printf("Buscar valor 64: indice: %d\n", searchByValue(myList, 64));

  printf("Obtener indice 0: %d\n", searchByIndex(myList, 0));
  printf("Obtener indice 3: %d\n", searchByIndex(myList, 3));
  printf("Obtener indice 6: %d\n", searchByIndex(myList, 6));
  printf("Obtener indice 7: %d\n", searchByIndex(myList, 7));
  printf("Obtener indice 20: %d\n", searchByIndex(myList, 20));*/

  //deleteHead(&myList);
  //deleteTail(&myList);
  //deleteByIndex(&myList, 1);

  //displayList(myList);


  clearList(&myList);

  return 0;
}