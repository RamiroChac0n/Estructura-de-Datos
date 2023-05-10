//inicialización del grafo
//Recorrido por Anchura
//Recorrido por Profundidad
//Algoritmo de Djikstra
#include <stdio.h>
#include <stdlib.h>
#define Nodo struct nodo
#define Arista struct arista
#define Lista struct pila

Nodo{
	char dato;
	Nodo* siguiente;
	Arista* adyacencia;
	int visitado,terminado;
	int monto;
	char anterior;
};

Arista{
	Nodo* vrt;
	Arista* siguiente;
	int peso;
};

Lista{
	Nodo* dato;
	Lista* siguiente;
};

Nodo* inicio=NULL;
Lista* ini=NULL;
Lista* final=NULL;

void insertarNodo();
void agregarArista(Nodo* aux,Nodo* aux2,Arista* nuevo);
void insertarArista();
void visualizarGrafo();
void recorridos();
void recorridoAnchura();
void recorridoProfundidad(Nodo* aux);
void insertarPila(Nodo* aux);
void insertarCola(Nodo* aux);
Nodo* desencolar();
void reiniciar();
void dijkstra();

int main(){
    int opcion,N,i;
	printf("Ingrese número de vertices:\n");
    scanf("%i",&N);
    for(i=0;i<N;i++){
    	insertarNodo();
	}
	//system("cls");
    do{
    	printf("-----------\n");
        printf(" 1. Insertar Vertice                 \n");
        printf(" 2. Insertar Arista                  \n");
        printf(" 3. Mostrar Listas                   \n");
        printf(" 4. Recorrer Grafo                   \n");
        printf(" 5. Dijkstra                         \n");
        printf(" 6. Salir                            \n");
        printf("------------\n");
        printf("Escoge opcion:\n");
        scanf("%i",&opcion);
        switch(opcion){
            case 1:
                    insertarNodo();
                    break;
            case 2: insertarArista();
                    break;
            case 3: visualizarGrafo();
                    break;
            case 4: recorridos();
                    break;
            case 5: dijkstra();
			        break;
			case 6: break;
            default: printf("Opcion no valida...!!!\n");
                     break;
        }
        //system("pause");
        //system("cls");
    }while(opcion!=6);
    return 1;
}

void insertarNodo(){
    Nodo* aux;
	Nodo* nuevo=(Nodo*)malloc(sizeof(Nodo));
	fflush(stdin);
	printf("Ingrese vertice:\n");
	scanf("%c",&nuevo->dato);
	nuevo->siguiente=NULL;
    nuevo->adyacencia=NULL;
    nuevo->visitado=nuevo->terminado=0;
    nuevo->monto=-1;
    nuevo->anterior=0;
    if(inicio==NULL){
        inicio=nuevo;
    }else{
        aux=inicio;
        while(aux->siguiente!=NULL){
            aux=aux->siguiente;
        }
        aux->siguiente=nuevo;
      }

 }

void insertarArista(){
    char ini, fin;
    Arista* nuevo=(Arista*)malloc(sizeof(Arista));
    nuevo->siguiente=NULL;
    Nodo* aux;
	Nodo* aux2;
    if(inicio==NULL){
         printf("Error: El grafo está vacio\n");
         return;
    }
    fflush(stdin);
    printf("Ingresar Nodo Inicial y Final:\n");
    scanf("%c %c",&ini,&fin);
    printf("Ingresar Peso de la arista:\n");
    scanf("%i",&nuevo->peso);
    aux=inicio;
    aux2=inicio;
    while(aux2!=NULL){
        if(aux2->dato==fin){
            break;
        }
        aux2=aux2->siguiente;
    }
    if(aux2==NULL){
    	printf("Error:Vertice no encontrado\n");
    	return;
	}
    while(aux!=NULL){
        if(aux->dato==ini){
            agregarArista(aux,aux2,nuevo);
            return;
        }
        aux = aux->siguiente;
    }
    if(aux==NULL)
    	printf("Error:Vertice no encontrado\n");
}

void agregarArista(Nodo* aux,Nodo* aux2,Arista* nuevo){
    Arista* a;
    if(aux->adyacencia==NULL){
	    aux->adyacencia=nuevo;
        nuevo->vrt=aux2;
    }else{
	    a=aux->adyacencia;
        while(a->siguiente!=NULL)
            a=a->siguiente;
        nuevo->vrt=aux2;
        a->siguiente=nuevo;
    }
}

void visualizarGrafo(){
    Nodo* aux=inicio;
    Arista* ar;
    printf("Nodos\n");
    while(aux!=NULL){
	    printf("%c:    ",aux->dato);
        if(aux->adyacencia!=NULL){
            ar=aux->adyacencia;
            while(ar!=NULL){
			    printf(" %c",ar->vrt->dato);
                ar=ar->siguiente;
            }
        }
        printf("\n");
        aux=aux->siguiente;
    }
    printf("\n");
}

void recorridos(){
	char vertice;
	Nodo* aux=inicio,*aux2=inicio;
  if(inicio!=NULL){
  	 fflush(stdin);
  	 printf("Escoger vertice inicial:\n");
     scanf("%c",&vertice);
     while(aux!=NULL){
  	    if(aux->dato==vertice)
  		break;
	    aux=aux->siguiente;
     }
     if(aux==NULL){
     	printf("Error: Vertice no encontrado\n");
	 }else{
		printf("Recorrido por anchura: ");
		aux->visitado=1;
		insertarCola(aux);
		recorridoAnchura();
		reiniciar();
		printf("\nRecorrido por profundidad: ");
		recorridoProfundidad(aux);
		while(aux2!=NULL){
			if(aux2->terminado==0)
			recorridoProfundidad(aux2);
			aux2=aux2->siguiente;
		}
		while(ini!=NULL)
			printf("%c ",desencolar()->dato);
		reiniciar();
		printf("\n");
	 }
   }
}

void recorridoAnchura(){
	Nodo* aux=desencolar();
	if(aux==NULL)
	return;
	printf("%c ",aux->dato);
	if(aux->adyacencia!=NULL){
		Arista*a=aux->adyacencia;
		while(a!=NULL){
			if(a->vrt->visitado==0){
			    insertarCola(a->vrt);
				a->vrt->visitado=1;
			}
			a=a->siguiente;
		}
	}
	recorridoAnchura();

}

void recorridoProfundidad(Nodo* aux){
	Arista* a;
	aux->visitado=1;
    if(aux->adyacencia!=NULL){
        a=aux->adyacencia;
        while(a!=NULL){
			if(a->vrt->visitado==0){
				recorridoProfundidad(a->vrt);
			}
            a=a->siguiente;
        }
    }
    aux->terminado=1;
    insertarPila(aux);
}

void insertarPila(Nodo* aux){
	Lista* nuevo= (Lista*) malloc(sizeof(Lista));
	nuevo->dato=aux;
	nuevo->siguiente=NULL;
	if(ini==NULL){
		ini=nuevo;
		final=nuevo;
	}else{
	   nuevo->siguiente=ini;
	   ini=nuevo;
	}
}

void insertarCola(Nodo* aux){
	Lista* nuevo=(Lista*) malloc(sizeof(Lista));
	nuevo->dato=aux;
	nuevo->siguiente=NULL;
	if(ini==NULL){
		ini=nuevo;
		final=nuevo;
	}else{
		final->siguiente=nuevo;
		final=nuevo;
	}
}

Nodo* desencolar(){
	Lista* aux;
	if(ini==NULL){
		return NULL;
	}else{
		aux=ini;
		ini=ini->siguiente;
		aux->siguiente=NULL;
		if(ini==NULL)
		final=NULL;
	}
	Nodo* resultado=aux->dato;
	free(aux);
	return resultado;
}

void reiniciar(){
	if(inicio!=NULL){
		Nodo* aux=inicio;
		while(aux!=NULL){
			aux->visitado=aux->terminado=0;
		    aux=aux->siguiente;
		}
	}
}

void dijkstra(){
	Nodo* aux=inicio;
	char a,b;
	fflush(stdin);
	printf("Ingresar Nodo Inicial y Final:\n");
	scanf("%c %c",&a,&b);
	while(aux!=NULL){
		if(aux->dato==a){
			aux->terminado=1;
			aux->monto=0;
			break;
		}
		aux=aux->siguiente;
	}
	if(aux==NULL){
		printf("Vertice no encontrado\n");
		return;
	}
	while(aux!=NULL){
		Arista* a=aux->adyacencia;
	    while(a!=NULL){
		    if(a->vrt->monto==-1 || (aux->monto+a->peso)<a->vrt->monto){
		    	a->vrt->monto=aux->monto+a->peso;
		        a->vrt->anterior=aux->dato;
			}
		    a=a->siguiente;
	    }
	    aux=inicio;
	    Nodo* min=inicio;
	    while(min->anterior==0 || min->terminado ==1)
	    min=min->siguiente;
	    while(aux!=NULL){
	    	if(aux->monto<min->monto && aux->terminado==0 && aux->anterior!=0)
	    	min=aux;
	    	aux=aux->siguiente;
		}
		aux=min;
		aux->terminado=1;
		if(aux->dato==b)
			break;
	}
	while(aux->anterior!=0){
		insertarPila(aux);
		char temp=aux->anterior;
		aux=inicio;
		while(aux->dato!=temp){
		   aux=aux->siguiente;
		}
	}
	insertarPila(aux);
	while(ini!=NULL){
		printf("%c ",desencolar()->dato);
	}
		printf("\n");
	reiniciar();
}