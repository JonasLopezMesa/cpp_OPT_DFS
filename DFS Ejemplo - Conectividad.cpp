/*****************************************
 ***Problema: Componentes Conexas
 ***Tipo: Teoria de Grafos , DFS
 ***Autor: Jhosimar George Arias Figueroa
 ******************************************/

/*
EJEMPLO DE INGRESO

5 3
1 2
2 3
4 5

*/

#include <stdio.h>
#include <vector>
using namespace std;
#define MAX 10001
vector<int> ady[ MAX ];
bool visitado[ MAX ];

//algoritmo estandar de DFS
void dfs( int u ){
    visitado[ u ] = true;
    for( int v = 0 ; v < ady[ u ].size(); ++v ){
        if( !visitado[ ady[ u ][ v ] ] ){
            dfs( ady[ u ][ v ] );
        }
    }
}

int main(){
    ///enumerar vertices desde 1 hasta V
    int V, E , u ,v;
    scanf("%d %d" , &V , &E );
    while( E-- ){
        scanf("%d %d" , &u ,&v );
        ady[ u ].push_back( v );
        ady[ v ].push_back( u );

    }
    printf("Cantidad de Componentes Conexas\n");
    int total = 0;
    memset( visitado , 0 , sizeof( visitado ) );
    for( int i = 1 ; i <= V ; ++i ){    //recorremos todos los posibles vertices
         if( !visitado[ i ] ){          //si alguno no fue visitado tenemos una componente a partir de ese nodo
             dfs( i );                  //recorremos a partir de nodo i todo el grafo que se forma
             total++;                   //incrementamos cantidad de componentes
         }
    }
    printf("%d\n" , total );

    return 0;
}
