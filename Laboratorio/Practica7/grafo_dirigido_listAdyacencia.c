#include <stdio.h>
#include <stdlib.h>

// Definir el número máximo de vértices en el graph
#define N 6

// Estructura de datos para almacenar un objeto graph
struct Graph
{
    // Una array de punteros a Node para representar una lista de adyacencia
    struct Node* head[N];
};

// Estructura de datos para almacenar los nodos de la lista de adyacencia del graph
struct Node
{
    int dest;
    struct Node* next;
};

// Estructura de datos para almacenar un borde de graph
struct Edge {
    int src, dest;
};

// Función para crear una lista de adyacencia desde bordes especificados
struct Graph* createGraph(struct Edge edges[], int n)
{
    // asignar almacenamiento para la estructura de datos del graph
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));

    // inicializa el puntero principal para todos los vértices
    for (int i = 0; i < N; i++) {
        graph->head[i] = NULL;
    }

    // agrega bordes al grafo dirigido uno por uno
    for (int i = 0; i < n; i++)
    {
        // obtener el vértice de origen y destino
        int src = edges[i].src;
        int dest = edges[i].dest;

        // asignar un nuevo nodo de lista de adyacencia de src a dest
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->dest = dest;

        // apunta el nuevo nodo al encabezado actual
        newNode->next = graph->head[src];

        // apunta el puntero de la cabeza al nuevo nodo
        graph->head[src] = newNode;
    }

    return graph;
}

// Función para imprimir la representación de la lista de adyacencia de un graph
void printGraph(struct Graph* graph)
{
    for (int i = 0; i < N; i++)
    {
        // imprime el vértice actual y todos sus vecinos
        struct Node* ptr = graph->head[i];
        while (ptr != NULL)
        {
            printf("(%d —> %d)\t", i, ptr->dest);
            ptr = ptr->next;
        }

        printf("\n");
    }
}

// Implementación de grafos dirigidos en C
int main(void)
{
    // array de entrada que contiene los bordes del graph (según el diagrama anterior)
    // (x, y) par en la array representa un borde de x a y
    struct Edge edges[] =
    {
        {0, 1}, {1, 2}, {2, 0}, {2, 1}, {3, 2}, {4, 5}, {5, 4}
    };

    // calcular el número total de aristas
    int n = sizeof(edges)/sizeof(edges[0]);

    // construye un grafo a partir de las aristas dadas
    struct Graph *graph = createGraph(edges, n);

    // Función para imprimir la representación de la lista de adyacencia de un graph
    printGraph(graph);

    return 0;
}