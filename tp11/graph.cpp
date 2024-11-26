#include <iostream>
#include "graph.h"
using namespace std;

void createVertex_103012330225(char newVertexID, adrVertex &v){
    v = new vertex;
    idVertex(v) = newVertexID;
    nextVertex(v) = NULL;
    firstEdge(v) = NULL;
}

void initGraph_103012330225(graph &G){
    firstVertex(G) = NULL;
}

void addVertex_103012330225(graph &G, char newVertexID){
    adrVertex v;
    if(firstVertex(G) == NULL){
        createVertex_103012330225(newVertexID, v);
        firstVertex(G) = v;
    }else{
        createVertex_103012330225(newVertexID, v);
        adrVertex vtx = firstVertex(G);
        while(nextVertex(vtx) != NULL){
            vtx = nextVertex(vtx);
        }
        nextVertex(vtx) = v;
    }
}

void buildGraph_103012330225(graph &G){
    initGraph_103012330225(G);

    cout << "Masukkan ID vertex (A-Z)!" << endl;
    cout << "Catatan: Masukkan karakter selain huruf untuk berhenti" << endl;
    cout << endl;
    int i = 1;
    cout << "Masukkan ID vertex ke-" << i << ": ";
    char newVertexID;
    cin >> newVertexID;
    while(newVertexID >= 'A' && newVertexID <= 'Z'){
        addVertex_103012330225(G, newVertexID);
        i++;
        cout << "Masukkan ID vertex ke-" << i << ": ";
        cin >> newVertexID;
    }
    cout << endl;
}

void show_103012330225(graph G){ // Tambahan buat ngecek isi graph-nya
    adrVertex v = firstVertex(G);
    int i = 0;
    while(v != NULL){
        i++;
        cout << "ID vertex ke-" << i << ": ";
        cout << idVertex(v) << endl;
        int j = 0;
        if(firstEdge(v) == NULL){
            j++;
            cout << "ID edge ke-" << j << ": NULL" << endl;
        }else{
            adrEdge e = firstEdge(v);
            while(e != NULL){
                j++;
                cout << "ID edge ke-" << j << ": " << destVertexID(e) << endl;
                cout << "Bobot: " << weight(e) << endl;
                e = nextEdge(e);
            }
        }
        cout << endl;

        v = nextVertex(v);
    }
}
