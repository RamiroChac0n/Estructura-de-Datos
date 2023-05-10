#include <stdio.h>
#include <conio.h>
#include <windows.h>
#define INFINITY 9999
#define MAX 10
 typedef struct {
	int dato;
	int marca;
} t_Grafo;
t_Grafo G[MAX][MAX];
int i,j,k,a,b,u,v,n,ne=1;
int min,mincost=0,cost[9][9],parent[9];
 int find(int);
int uni(int,int);
void titulo();
void gotoxy(int x,int y);
int spanning[MAX][MAX];
 void IngresaMAD(t_Grafo G[MAX][MAX],int n);
void dijkstra(t_Grafo G[MAX][MAX],int n,int startnode);
 void mostrar(t_Grafo G[MAX][MAX],int n);
void  Dijktra();
void Kruskal ();
void Prim();
int prims();
int main()
{

	int op;


	do{
		titulo();

		printf("\n 1- Recorrido minimo de Grafo Algoritmo de KRUSKAL  \n 2-Recorrido minimo de Grafo Algoritmo de PRIM  \n 3-Distancia minima de Nodo de partida al Resto de Grafo Algoritmo de DIJKTRA  \n 4-Salir \n\n Opcion :...  " );
		scanf("%d",&op);
		switch(op){
			case 1 :
				titulo();
				Kruskal();
				system("pause");
				break;
		    case 2:
			     titulo();
				Prim();
				system("pause");
				break;
		    case 3:
		        titulo();
				Dijktra();
				system("pause");
				break;

		}
	system("cls");
	}while(op!=4);

    return 0;
 }
void gotoxy(int x,int y){
      HANDLE hcon;
      hcon = GetStdHandle(STD_OUTPUT_HANDLE);
      COORD dwPos;
      dwPos.X = x;
      dwPos.Y= y;
      SetConsoleCursorPosition(hcon,dwPos);
 }
void titulo(){
int x,y,i,z,a;
system("cls");
 gotoxy(35,10);

 printf("******RECORRIDOS DE GRAFOS ESTATICOS******");


 for(i=1; i<90; i++)
 {
  gotoxy(i,13);
  printf("%c",177);

  for(x=50;x<70;x++){
   for(y=1;y<70;y++){
    gotoxy(y,24);
   }
  }
 }
gotoxy(20,20);
}

void Dijktra(){
   int n,u;
    printf("***CAMINO MINIMO CON DIJKTRA***\n");
    printf("Ingrese numero  de Nodos: ");
    scanf("%d",&n);
   printf("\nIngrese La Matriz De Adyacencia :\n");


     IngresaMAD( G,n);
    mostrar( G,n);
    printf("\nIngrese el Nodo De Partida :");
    scanf("%d",&u);
    dijkstra(G,n,u);

}

 void IngresaMAD(t_Grafo G[MAX][MAX],int n){
 	int i,j;
 	for(i=0;i<n;i++){
    	for(j=0;j<n;j++){

        		G[i][j].dato=0;
				G[i][j].marca=0;

        }
    }

    for(i=0;i<n;i++){
    	for(j=0;j<n;j++){
        	   if((i!=j)&&(G[i][j].marca==0)){
        		   printf("\nIngrese Peso De Arista %d,%d :\n",i+1,j+1);
                   scanf("%d",&G[i][j].dato);
                   G[j][i].dato=G[i][j].dato ;
                   G[j][i].marca= 1;
        		}




        	}

        }

 }
 void mostrar(t_Grafo G[MAX][MAX] , int n){
 	int i ,j;
 	  printf("\n Matrix Peso De Arista  \n\n");
        for(i=0;i<n;i++){
        	for(j=0;j<n;j++){
        	printf("%d \t", G[i][j].dato);
        }
              printf("\n");
        }
 }
void dijkstra(t_Grafo G[MAX][MAX] ,int n,int startnode)
{


   startnode=startnode-1;
    int cost[MAX][MAX],distance[MAX],pred[MAX];
    int visited[MAX],count,mindistance,nextnode,i,j;


    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            if(G[i][j].dato==0)
                cost[i][j]=INFINITY;
            else
                cost[i][j]=G[i][j].dato;


    for(i=0;i<n;i++)
    {
        distance[i]=cost[startnode][i];
        pred[i]=startnode;
        visited[i]=0;
    }

    distance[startnode]=0;
    visited[startnode]=1;
    count=1;

    while(count<n-1)
    {
        mindistance=INFINITY;


        for(i=0;i<n;i++)
            if(distance[i]<mindistance&&!visited[i])
            {
                mindistance=distance[i];
                nextnode=i;
            }


            visited[nextnode]=1;
            for(i=0;i<n;i++)
                if(!visited[i])
                    if(mindistance+cost[nextnode][i]<distance[i])
                    {
                        distance[i]=mindistance+cost[nextnode][i];
                        pred[i]=nextnode;
                    }
        count++;
    }


    for(i=0;i<n;i++)
        if(i!=startnode)
        {
            printf("\nDistancia del Nodo %d = %d",i+1,distance[i]);
            printf("\n Camino = %d",i+1);

            j=i;
            do
            {
                j=pred[j];
                printf("<-%d",j+1);
            }while(j!=startnode);
    }
    printf("\n");

}
void Kruskal (){

 	printf("*** RECORRIDO MINIMO DE GRAFO CON KRUSKAL ***\n");
	printf("INGRESE NUMERO DE NODOS : ");
    scanf("%d",&n);
    int mat[n+1][n+1];
    printf("\nIngrese La Matriz De Adyacencia :\n");
    IngresaMAD( G,n);
    mostrar( G,n);
 for(i=1;i<=n;i++)
 {
  for(j=1;j<=n;j++)
  {
     cost[i][j]=G[i-1][j-1].dato;
   if(cost[i][j]==0)
    cost[i][j]=999;
  }
 }
  for(i=1;i<=n;i++)
 {
  for(j=1;j<=n;j++)
  {
     mat[i][j]=0;
  }
 }
 printf("");
  printf("\n ARISTAS DEL ARBOL EXPANSION MINIMO : \n",mincost);
 while(ne<n)
 {
  for(i=1,min=999;i<=n;i++)
  {
   for(j=1;j<=n;j++)
   {
    if(cost[i][j]<min)
    {
     min=cost[i][j];

     a=u=i;
     b=v=j;
    }
   }
  }

  u=find(u);
  v=find(v);

  if(uni(u,v))
  {
  printf("\n%d ARISTA   de nodo %d a %d  = %d\n",ne++,a,b,min);
  mat[a][b]=min;
   mincost +=min;
  }
  cost[a][b]=cost[b][a]=999;
 }
  for(i=1;i<=n;i++)
 {printf("\n");
  for(j=1;j<=n;j++)
  {
     printf(" %d ",mat[i][j]);
  }
 }
 printf("\n Peso Minimo = %d \n",mincost);
 getch();
}
int find(int i)
{
 while(parent[i])
  i=parent[i];
 return i;
}
int uni(int i,int j)
{
 if(i!=j)
 {
  parent[j]=i;
  return 1;
 }
 return 0;

}
void Prim(){
	int i,j,total_cost;
	printf("***RECORRIDO MINIMO GRAFO  CON PRIM ***\n");
    printf("Ingrese numero de Nodos :");
    scanf("%d",&n);

    printf("\nIngrese La Matriz De Adyacencia :\n");
    IngresaMAD( G,n);
    mostrar( G,n);



    total_cost=prims();
    printf("\n \n ARBOL DE EXPANSION MINIMO MATRIZ :\n");

    for(i=0;i<n;i++)
    {
        printf("\n");
        for(j=0;j<n;j++)
            printf("%d \t",spanning[i][j]);
    }

    printf("\n\n Costo Total  De Arbol de Expansion  Minimo = %d",total_cost);
    printf("\n");
}
int prims()
{
    int cost[MAX][MAX];
    int u,v,min_distance,distance[MAX],from[MAX];
    int visited[MAX],no_of_edges,i,min_cost,j;


    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
        {
            if(G[i][j].dato==0)
                cost[i][j]=INFINITY;
            else
                cost[i][j]=G[i][j].dato;
                spanning[i][j]=0;
        }


    distance[0]=0;
    visited[0]=1;

    for(i=1;i<n;i++)
    {
        distance[i]=cost[0][i];
        from[i]=0;
        visited[i]=0;
    }

    min_cost=0;
    no_of_edges=n-1;

    while(no_of_edges>0)
    {
        min_distance=INFINITY;
        for(i=1;i<n;i++)
            if(visited[i]==0&&distance[i]<min_distance)
            {
                v=i;
                min_distance=distance[i];
            }

        u=from[v];


        spanning[u][v]=distance[v];
        spanning[v][u]=distance[v];
        no_of_edges--;
        visited[v]=1;


        for(i=1;i<n;i++)
            if(visited[i]==0&&cost[i][v]<distance[i])
            {
                distance[i]=cost[i][v];
                from[i]=v;
            }

        min_cost=min_cost+cost[u][v];
    }

    return(min_cost);

}