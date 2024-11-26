#include <iostream>
#include "DLL.h"
using namespace std;

bool isEmpty_103012330225(List L){
    if(first(L) == NULL || last(L) == NULL){
        return true;
    }else{
        return false;
    }
}

void createList_103012330225(List &L){
    first(L) = NULL;
    last(L) = NULL;
}

void createNewElmt_103012330225(infotype X, address &P){
    P = new elmtList;
    info(P) = X;
    next(P) = NULL;
    prev(P) = NULL;
}

void insertFirst_103012330225(List &L, address P){
    if(isEmpty_103012330225(L)){
        first(L) = P;
        last(L) = P;
    }else{
        next(P) = first(L);
        prev(first(L)) = P;
        first(L) = P;
    }
}

void insertAfter_103012330225(List &L, address &Prec, address &P){
    next(P) = next(Prec);
    prev(P) = Prec;
    prev(next(Prec)) = P;
    next(Prec) = P;
}

void insertLast_103012330225(List &L, address P){
    if(isEmpty_103012330225(L)){
        first(L) = P;
        last(L) = P;
    }else{
        prev(P) = last(L);
        next(last(L)) = P;
        last(L) = P;
    }
}

void deleteFirst_103012330225(List &L, address &P){
    P = first(L);
    if(first(L) == last(L)){
        first(L) = NULL;
        last(L) = NULL;
    }else{
        first(L) = next(P);
        next(P) = NULL;
        prev(first(L)) = NULL;
    }
}

void deleteAfter_103012330225(List &L, address &Prec, address &P){
    P = next(Prec);
    next(Prec) = next(P);
    prev(next(P)) = Prec;
    prev(P) = NULL;
    next(P) = NULL;
}

void deleteLast_103012330225(List &L, address &P){
    P = last(L);
    if(first(L) == last(L)){
        first(L) = NULL;
        last(L) = NULL;
    }else{
        last(L) = prev(P);
        prev(P) = NULL;
        next(last(L)) = NULL;
    }
}

void concat_103012330225(List L1, List L2, List &L3){
    if(isEmpty_103012330225(L1)){
        L3 = L2;
    }else{
        L3 = L1;
        address Q = first(L2);
        while(Q != NULL){
            insertLast_103012330225(L3, Q);
            Q = next(Q);
        }
    }
}

address findLagu_103012330225(string Judul, List L){
    address P = last(L);
    while(P != NULL && info(P).judulLagu != Judul){
        P = prev(P);
    }
    return P;
}

void removeLagu_103012330225(string Judul, List &L){
    address P;
    if(info(first(L)).judulLagu == Judul){
        deleteFirst_103012330225(L, P);
    }else if(info(last(L)).judulLagu == Judul){
        deleteLast_103012330225(L, P);
    }else{
        P = findLagu_103012330225(Judul, L);
        deleteAfter_103012330225(L, prev(P), P);
    }
}

void show_103012330225(List L){
    address Q = first(L);
    int i = 1;
    while(Q != NULL){
        cout << "Lagu ke-" << i << " :" << endl;
        cout << "Artis : " << info(Q).namaBand << endl;
        cout << "Judul : " << info(Q).judulLagu << endl;
        i++;
        Q = next(Q);
    }
    cout << endl;
}
