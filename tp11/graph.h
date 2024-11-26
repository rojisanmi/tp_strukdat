#ifndef GRAPH_H_INCLUDED
#define GRAPH_H_INCLUDED

#include <iostream>
#define firstVertex(G) G.firstVertex
#define idVertex(v) v->idVertex
#define nextVertex(v) v->nextVertex
#define firstEdge(v) v->firstEdge
#define destVertexID(e) e->destVertexID
#define weight(e) e->weight
#define nextEdge(e) e->nextEdge
using namespace std;
typedef struct edge *adrEdge;
typedef struct vertex *adrVertex;

struct vertex {
    char idVertex;
    adrVertex nextVertex;
    adrEdge firstEdge;
};

struct edge {
    char destVertexID;
    int weight;
    adrEdge nextEdge;
};

struct graph {
    adrVertex firstVertex;
};

void createVertex_103012330225(char newVertexID, adrVertex &v);
void initGraph_103012330225(graph &G);
void addVertex_103012330225(graph &G, char newVertexID);
void buildGraph_103012330225(graph &G);
void show_103012330225(graph G); // Tambahan buat ngecek isi graph-nya

#endif // GRAPH_H_INCLUDED
