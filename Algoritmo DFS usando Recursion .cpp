/*****************************************
 ***Algoritmo: Depth First Search Recursivo - Backtracking
 ***Tipo: Teoria de Grafos
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

/*
EJEMPLO DE INGRESO

5 5
1 2
1 3
2 4
2 5
1 5
1
5
*/

#include <stdio.h>
#include <vector>
using namespace std;

#define MAX 500
vector<int> ady[ MAX ];  //lista de adyacencia
bool visitado[ MAX ];    //para nodos visitados
int V;

///Ver todo el recorrido del grafo de acuerdo al orden ingresado en la lista de adyacencia
bool first;
void dfs( int u ){

    ( first )? printf("%d" , u ) : printf("->%d" , u );
    first = false;
    visitado[ u ] = true;
    for( int v = 0 ; v < ady[ u ].size(); ++v ){
        if( !visitado[ ady[ u ][ v ] ] ){
            dfs( ady[ u ][ v ] );
        }
    }
}



///Ver todos las rutas posibles partiendo de nodo inicial y llegando a uno final, usamos backtracking
void dfs_allPath( int u , int fin ){
    visitado[ u ] = true;
    if( u == fin ){                     //si se llego al final imprimimos ese path
        first = true;
        for( int i = 1 ; i <= V ; ++i ){
             if( !visitado[ i ] )continue;
             ( first ) ? printf("%d" , i ) : printf("->%d" , i );
             first = false;
        }
        printf("\n");
    }

    for( int v = 0 ; v < ady[ u ].size(); ++v ){
        if( !visitado[ ady[ u ][ v ] ] ){
            dfs_allPath( ady[ u ][ v ] , fin );
        }
    }
    //parte para backtracking, aquellos nodos hoja ya que no poseen adyacentes o ya fueron visitados
    visitado[ u ] = false;              //marcamos como no visitado para usarlo posteriormente en otro path
}


int main(){

    int  E , x , y, inicial , final;
    scanf("%d %d" , &V , &E );      //Numero de vertices y numero de aristas

    for(int i = 1 ; i <= E ; ++i ){
        scanf("%d %d" , &x , &y );  //Origen y destino
        ady[ x ].push_back( y );
        ady[ y ].push_back( x );
    }
    first = true;

    //Veremos todo el recorrido del grafo iniciando en el vertice ingresado
    printf("Nodo raiz: ");
    scanf("%d" , &inicial );

    memset( visitado , 0 ,sizeof( visitado ) );
    printf("Recorrido DFS de todo el grafo\n");
    dfs( inicial );
    printf("\n\n\n");


    //Veremos posibles rutas de nodo inicial a uno final
    memset( visitado , 0 , sizeof( visitado ) );        //inicializar a no visitado
    printf("Posibles Rutas de inicial a final usando Backtracking\n");
    printf("Nodo Final: ");
    scanf("%d" , &final );
    dfs_allPath( inicial , final );                     //posibles rutas de nodo inicial a final
    return 0;
}
