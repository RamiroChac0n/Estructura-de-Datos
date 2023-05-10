//inicialización del grafo
//Recorrido por Anchura
//Recorrido por Profundidad
//Algoritmo de Djikstra
#include <stdio.h>																//Importa las librerias necesarias.
#include <stdlib.h>																//Importa las librerias necesarias.
#define Nodo struct nodo														//Define la estructura nodo.
#define Arista struct arista													//Define la estructura arista.
#define Lista struct pila														//Define la estructura pila.

Nodo{																			//Estructura nodo.
	char dato;																	//Dato de tipo char.
	Nodo* siguiente;															//Puntero de tipo nodo.
	Arista* adyacencia;															//Puntero de tipo arista.
	int visitado,terminado;														//Variables de tipo int.
	int monto;																	//Variable de tipo int.
	char anterior;																//Variable de tipo char.
};

Arista{																			//Estructura arista.
	Nodo* vrt;																	//Puntero de tipo nodo.
	Arista* siguiente;															//Puntero de tipo arista.
	int peso;																	//Variable de tipo int.
};

Lista{																			//Estructura pila.
	Nodo* dato;																	//Puntero de tipo nodo.
	Lista* siguiente;															//Puntero de tipo pila.
};

Nodo* inicio=NULL;																//Puntero de tipo nodo.
Lista* ini=NULL;																//Puntero de tipo pila.
Lista* final=NULL;																//Puntero de tipo pila.

void insertarNodo();															//Funcion para insertar un nodo.
void agregarArista(Nodo* aux,Nodo* aux2,Arista* nuevo);							//Funcion para agregar una arista.
void insertarArista();															//Funcion para insertar una arista.
void visualizarGrafo();															//Funcion para visualizar el grafo.
void recorridos();																//Funcion para recorrer el grafo.
void recorridoAnchura();														//Funcion para recorrer el grafo por anchura.
void recorridoProfundidad(Nodo* aux);											//Funcion para recorrer el grafo por profundidad.
void insertarPila(Nodo* aux);													//Funcion para insertar un nodo en la pila.
void insertarCola(Nodo* aux);													//Funcion para insertar un nodo en la cola.
Nodo* desencolar();																//Funcion para desencolar un nodo.
void reiniciar();																//Funcion para reiniciar el grafo.
void dijkstra();																//Funcion para aplicar el algoritmo de dijkstra.

int main(){																		//Funcion principal.
    int opcion,N,i;																//Variables de tipo int.
	printf("Ingrese número de vertices:\n");									//Imprime en pantalla.
    scanf("%i",&N);																//Lee la variable N.
    for(i=0;i<N;i++){															//Ciclo for.
    	insertarNodo();															//Llama a la funcion insertarNodo.
	}
	//system("cls");
    do{																			//Ciclo do while.
    	printf("-----------\n");
        printf(" 1. Insertar Vertice                 \n");						//Imprime en pantalla.
        printf(" 2. Insertar Arista                  \n");						//Imprime en pantalla.
        printf(" 3. Mostrar Listas                   \n");						//Imprime en pantalla.
        printf(" 4. Recorrer Grafo                   \n");						//Imprime en pantalla.
        printf(" 5. Dijkstra                         \n");						//Imprime en pantalla.
        printf(" 6. Salir                            \n");						//Imprime en pantalla.
        printf("------------\n");
        printf("Escoge opcion:\n");												//Imprime en pantalla.
        scanf("%i",&opcion);													//Lee la variable opcion.
        switch(opcion){															//Switch para las opciones.
            case 1:insertarNodo();break;										//Caso 1: Llama a la funcion insertarNodo.
            case 2:insertarArista();break;										//Caso 2: Llama a la funcion insertarArista.
            case 3:visualizarGrafo();break;										//Caso 3: Llama a la funcion visualizarGrafo.
            case 4:recorridos();break;											//Caso 4: Llama a la funcion recorridos.
            case 5:dijkstra();break;											//Caso 5: Llama a la funcion dijkstra.
			case 6: break;														//Caso 6: Termina el programa.
            default:printf("Opcion no valida...!!!\n");break;					//Caso default: Imprime en pantalla.
        }
        //system("pause");
        //system("cls");
    }while(opcion!=6);															//Condicion del ciclo do while.
    return 1;																	//Retorna 1.
}

void insertarNodo(){															//Funcion para insertar un nodo.
    Nodo* aux;																	//Puntero de tipo nodo.
	Nodo* nuevo=(Nodo*)malloc(sizeof(Nodo));									//Puntero de tipo nodo.
	fflush(stdin);																//Limpia el buffer.
	printf("Ingrese vertice:\n");												//Imprime en pantalla.
	scanf("%c",&nuevo->dato);													//Lee la variable dato.
	nuevo->siguiente=NULL;														//El puntero siguiente apunta a NULL.
	nuevo->adyacencia=NULL;														//El puntero adyacencia apunta a NULL.
	nuevo->visitado=nuevo->terminado=0;											//Las variables visitado y terminado son 0.
	nuevo->monto=-1;															//La variable monto es -1.
	nuevo->anterior=0;															//La variable anterior es 0.
	if(inicio==NULL){															//Si inicio es igual a NULL.
		inicio=nuevo;															//Inicio es igual a nuevo.
	}else{																		//Sino.
		aux=inicio;																//Aux es igual a inicio.
		while(aux->siguiente!=NULL){											//Mientras aux->siguiente sea diferente de NULL.
			aux=aux->siguiente;													//Aux es igual a aux->siguiente.
		}
		aux->siguiente=nuevo;													//Aux->siguiente es igual a nuevo.
	  }

 }	

void insertarArista(){															//Funcion para insertar una arista.
    char ini, fin;																//Variables de tipo char.
    Arista* nuevo=(Arista*)malloc(sizeof(Arista));								//Puntero de tipo arista.
    nuevo->siguiente=NULL;														//El puntero siguiente apunta a NULL.
    Nodo* aux;																	//Puntero de tipo nodo.
	Nodo* aux2;																	//Puntero de tipo nodo.
    if(inicio==NULL){															//Si inicio es igual a NULL.
         printf("Error: El grafo está vacio\n");								//Imprime en pantalla.	
         return;																//Retorna.								
    }
    fflush(stdin);																//Limpia el buffer.
    printf("Ingresar Nodo Inicial y Final:\n");									//Imprime en pantalla.								
    scanf("%c %c",&ini,&fin);													//Lee las variables ini y fin.
    printf("Ingresar Peso de la arista:\n");									//Imprime en pantalla.	
    scanf("%i",&nuevo->peso);													//Lee la variable peso.
    aux=inicio;																	//Aux es igual a inicio.
    aux2=inicio;																//Aux2 es igual a inicio.
    while(aux2!=NULL){															//Mientras aux2 sea diferente de NULL.
        if(aux2->dato==fin){													//Si aux2->dato es igual a fin.
            break;																//Termina el ciclo.
        }
        aux2=aux2->siguiente;													//Aux2 es igual a aux2->siguiente.
    }
    if(aux2==NULL){																//Si aux2 es igual a NULL.
    	printf("Error:Vertice no encontrado\n");								//Imprime en pantalla.
    	return;																	//Retorna.										
	}
    while(aux!=NULL){															//Mientras aux sea diferente de NULL.
        if(aux->dato==ini){														//Si aux->dato es igual a ini.
            agregarArista(aux,aux2,nuevo);										//Llama a la funcion agregarArista.
            return;																//Retorna.									
        }
        aux = aux->siguiente;													//Aux es igual a aux->siguiente.
    }
    if(aux==NULL)																//Si aux es igual a NULL.
    	printf("Error:Vertice no encontrado\n");								//Imprime en pantalla.
}

void agregarArista(Nodo* aux,Nodo* aux2,Arista* nuevo){							//Funcion para agregar una arista.
    Arista* a;																	//Puntero de tipo arista.
    if(aux->adyacencia==NULL){													//Si aux->adyacencia es igual a NULL.
		aux->adyacencia=nuevo;													//Aux->adyacencia es igual a nuevo.
		nuevo->vrt=aux2;														//Nuevo->vrt es igual a aux2.
    }else{																		//Sino.								
	    a=aux->adyacencia;														//A es igual a aux->adyacencia.
        while(a->siguiente!=NULL)												//Mientras a->siguiente sea diferente de NULL.
            a=a->siguiente;														//A es igual a a->siguiente.
        nuevo->vrt=aux2;														//Nuevo->vrt es igual a aux2.
        a->siguiente=nuevo;														//A->siguiente es igual a nuevo.
    }
}

void visualizarGrafo(){															//Funcion para visualizar el grafo.
    Nodo* aux=inicio;															//Puntero de tipo nodo.
    Arista* ar;																	//Puntero de tipo arista.
    printf("Nodos\n");															//Imprime en pantalla.	
    while(aux!=NULL){															//Mientras aux sea diferente de NULL.
	    printf("%c:    ",aux->dato);											//Imprime en pantalla.
        if(aux->adyacencia!=NULL){												//Si aux->adyacencia es diferente de NULL.
            ar=aux->adyacencia;													//Ar es igual a aux->adyacencia.
            while(ar!=NULL){													//Mientras ar sea diferente de NULL.
			    printf(" %c",ar->vrt->dato);									//Imprime en pantalla.
                ar=ar->siguiente;												//Ar es igual a ar->siguiente.
            }
        }
        printf("\n");
        aux=aux->siguiente;														//Aux es igual a aux->siguiente.
    }
    printf("\n");
}

void recorridos(){																//Funcion para recorridos.
	char vertice;																//Variable de tipo char.
	Nodo* aux=inicio,*aux2=inicio;												//Punteros de tipo nodo.
  if(inicio!=NULL){																//Si inicio es diferente de NULL.
  	 fflush(stdin);																//Limpia el buffer.
  	 printf("Escoger vertice inicial:\n");										//Imprime en pantalla.							
     scanf("%c",&vertice);														//Lee la variable vertice.
     while(aux!=NULL){															//Mientras aux sea diferente de NULL.
  	    if(aux->dato==vertice)													//Si aux->dato es igual a vertice.
  		break;																	
	    aux=aux->siguiente;														//Aux es igual a aux->siguiente.
     }	
     if(aux==NULL){																//Si aux es igual a NULL.
     	printf("Error: Vertice no encontrado\n");								//Imprime en pantalla.
	 }else{																		//Sino.										
		printf("Recorrido por anchura: ");										//Imprime en pantalla.
		aux->visitado=1;														//Aux->visitado es igual a 1.
		insertarCola(aux);														//Llama a la funcion insertarCola.
		recorridoAnchura();														//Llama a la funcion recorridoAnchura.
		reiniciar();															//Llama a la funcion reiniciar.
		printf("\nRecorrido por profundidad: ");								//Imprime en pantalla.
		recorridoProfundidad(aux);												//Llama a la funcion recorridoProfundidad.
		while(aux2!=NULL){														//Mientras aux2 sea diferente de NULL.
			if(aux2->terminado==0)												//Si aux2->terminado es igual a 0.
			recorridoProfundidad(aux2);											//Llama a la funcion recorridoProfundidad.
			aux2=aux2->siguiente;												//Aux2 es igual a aux2->siguiente.
		}
		while(ini!=NULL)														//Mientras ini sea diferente de NULL.
			printf("%c ",desencolar()->dato);									//Imprime en pantalla.								
		reiniciar();															//Llama a la funcion reiniciar.
		printf("\n");	
	 }
   }
}

void recorridoAnchura(){														//Funcion para recorrido por anchura.
	Nodo* aux=desencolar();														//Puntero de tipo nodo.
	if(aux==NULL)																//Si aux es igual a NULL.
	return;	
	printf("%c ",aux->dato);													//Imprime en pantalla.
	if(aux->adyacencia!=NULL){													//Si aux->adyacencia es diferente de NULL.
		Arista*a=aux->adyacencia;												//Puntero de tipo arista.
		while(a!=NULL){															//Mientras a sea diferente de NULL.
			if(a->vrt->visitado==0){											//Si a->vrt->visitado es igual a 0.
			    insertarCola(a->vrt);											//Llama a la funcion insertarCola.
				a->vrt->visitado=1;												//A->vrt->visitado es igual a 1.
			}
			a=a->siguiente;														//A es igual a a->siguiente.
		}
	}
	recorridoAnchura();															//Llama a la funcion recorridoAnchura.

}

void recorridoProfundidad(Nodo* aux){											//Funcion para recorrido por profundidad.
	Arista* a;																
	aux->visitado=1;															//Aux->visitado es igual a 1.
    if(aux->adyacencia!=NULL){													//Si aux->adyacencia es diferente de NULL.
        a=aux->adyacencia;														//Puntero de tipo arista.
        while(a!=NULL){															//Mientras a sea diferente de NULL.
			if(a->vrt->visitado==0){											//Si a->vrt->visitado es igual a 0.
				recorridoProfundidad(a->vrt);									//Llama a la funcion recorridoProfundidad.
			}
            a=a->siguiente;														//A es igual a a->siguiente.
        }
    }
    aux->terminado=1;															//Aux->terminado es igual a 1.
    insertarPila(aux);															//Llama a la funcion insertarPila.
}

void insertarPila(Nodo* aux){													//Funcion para insertar en pila.
	Lista* nuevo= (Lista*) malloc(sizeof(Lista));								//Puntero de tipo lista.
	nuevo->dato=aux;															//Nuevo->dato es igual a aux.
	nuevo->siguiente=NULL;														//Nuevo->siguiente es igual a NULL.
	if(ini==NULL){																//Si ini es igual a NULL.
		ini=nuevo;																//Ini es igual a nuevo.
		final=nuevo;															//Final es igual a nuevo.
	}else{																		//Sino.		
	   nuevo->siguiente=ini;													//Nuevo->siguiente es igual a ini.
	   ini=nuevo;																//Ini es igual a nuevo.
	}
}

void insertarCola(Nodo* aux){													//Funcion para insertar en cola.
	Lista* nuevo=(Lista*) malloc(sizeof(Lista));								//Puntero de tipo lista.
	nuevo->dato=aux;															//Nuevo->dato es igual a aux.
	nuevo->siguiente=NULL;														//Nuevo->siguiente es igual a NULL.
	if(ini==NULL){																//Si ini es igual a NULL.
		ini=nuevo;																//Ini es igual a nuevo.
		final=nuevo;															//Final es igual a nuevo.
	}else{																		//Sino.
		final->siguiente=nuevo;													//Final->siguiente es igual a nuevo.
		final=nuevo;															//Final es igual a nuevo.
	}
}

Nodo* desencolar(){																//Funcion para desencolar.
	Lista* aux;																	//Puntero de tipo lista.
	if(ini==NULL){																//Si ini es igual a NULL.
		return NULL;															//Retorna NULL.									
	}else{																		//Sino.
		aux=ini;																//Aux es igual a ini.
		ini=ini->siguiente;														//Ini es igual a ini->siguiente.
		aux->siguiente=NULL;													//Aux->siguiente es igual a NULL.
		if(ini==NULL)															//Si ini es igual a NULL.
		final=NULL;																//Final es igual a NULL.
	}
	Nodo* resultado=aux->dato;													//Puntero de tipo nodo.
	free(aux);																	//Libera memoria.
	return resultado;															//Retorna resultado.
}

void reiniciar(){																//Funcion para reiniciar.
	if(inicio!=NULL){															//Si inicio es diferente de NULL.
		Nodo* aux=inicio;														//Puntero de tipo nodo.
		while(aux!=NULL){														//Mientras aux sea diferente de NULL.
			aux->visitado=aux->terminado=0;										//Aux->visitado y aux->terminado son iguales a 0.
		    aux=aux->siguiente;													//Aux es igual a aux->siguiente.
		}
	}
}

void dijkstra(){																//Funcion para dijkstra.
	Nodo* aux=inicio;															//Puntero de tipo nodo.
	char a,b;																	//Variables de tipo char.	
	fflush(stdin);																//Limpia el buffer.
	printf("Ingresar Nodo Inicial y Final:\n");									//Imprime en pantalla.	
	scanf("%c %c",&a,&b);														//Lee las variables.
	while(aux!=NULL){															//Mientras aux sea diferente de NULL.
		if(aux->dato==a){														//Si aux->dato es igual a a.
			aux->terminado=1;													//Aux->terminado es igual a 1.
			aux->monto=0;														//Aux->monto es igual a 0.
			break;
		}
		aux=aux->siguiente;														//Aux es igual a aux->siguiente.
	}
	if(aux==NULL){																//Si aux es igual a NULL.
		printf("Vertice no encontrado\n");										//Imprime en pantalla.
		return;
	}
	while(aux!=NULL){															//Mientras aux sea diferente de NULL.
		Arista* a=aux->adyacencia;												//Puntero de tipo arista.
	    while(a!=NULL){															//Mientras a sea diferente de NULL.
		    if(a->vrt->monto==-1 || (aux->monto+a->peso)<a->vrt->monto){		//Si a->vrt->monto es igual a -1 o (aux->monto+a->peso) es menor a a->vrt->monto.
		    	a->vrt->monto=aux->monto+a->peso;								//A->vrt->monto es igual a aux->monto+a->peso.
		        a->vrt->anterior=aux->dato;										//A->vrt->anterior es igual a aux->dato.
			}
		    a=a->siguiente;														//A es igual a a->siguiente.
	    }
	    aux=inicio;																//Aux es igual a inicio.
	    Nodo* min=inicio;														//Puntero de tipo nodo.
	    while(min->anterior==0 || min->terminado ==1)							//Mientras min->anterior sea igual a 0 o min->terminado sea igual a 1.
	    min=min->siguiente;														//Min es igual a min->siguiente.
	    while(aux!=NULL){														//Mientras aux sea diferente de NULL.
	    	if(aux->monto<min->monto && aux->terminado==0 && aux->anterior!=0)	//Si aux->monto es menor a min->monto y aux->terminado es igual a 0 y aux->anterior es diferente de 0.
	    	min=aux;															//Min es igual a aux.
	    	aux=aux->siguiente;													//Aux es igual a aux->siguiente.
		}
		aux=min;																//Aux es igual a min.
		aux->terminado=1;														//Aux->terminado es igual a 1.
		if(aux->dato==b)														//Si aux->dato es igual a b.
			break;	
	}
	while(aux->anterior!=0){													//Mientras aux->anterior sea diferente de 0.
		insertarPila(aux);														//Inserta en pila.
		char temp=aux->anterior;												//Variable de tipo char.							
		aux=inicio;																//Aux es igual a inicio.						
		while(aux->dato!=temp){													//Mientras aux->dato sea diferente de temp.
		   aux=aux->siguiente;													//Aux es igual a aux->siguiente.
		}
	}
	insertarPila(aux);															//Inserta en pila.
	while(ini!=NULL){															//Mientras ini sea diferente de NULL.
		printf("%c ",desencolar()->dato);										//Imprime en pantalla.
	}	
		printf("\n");															//Imprime en pantalla.
	reiniciar();																//Reinicia.
}