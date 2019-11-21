/* File : driver_graph.c */
/* File driver dari graph */

#include <stdio.h>
#include "graph.h"

int main(){
    Graph G;
    List L;
    addrNode Pn;
    CreateGraph(1,&G);
    InsertEdge(&G,1,2);
    InsertEdge(&G,1,3);
    InsertEdge(&G,2,5);
    InsertEdge(&G,3,5);
    InsertEdge(&G,4,5);

    L = MakeListEdge(G,1);
    PrintInfo(L);
    return 0;
}