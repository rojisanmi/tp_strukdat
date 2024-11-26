#include <iostream>
#include "list.h"
using namespace std;

void createList_103012330225(List &L){
    first(L) = NULL;
}

address allocate_103012330225(infotype x){
    address p = new elmlist;
    info(p) = x;
    next(p) = NULL;

    return p;
}

void insertFirst_103012330225(List &L, address P){
    next(P) = first(L);
    first(L) = P;
}

void printInfo_103012330225(List L){
    address p = first(L);
    cout << "Isi list : ";
    while(p != NULL){
        cout << info(p);
        p = next(p);
    }
}

void insertLast_103012330225(List &L, address P){
    address Q;
    if(first(L) == NULL){
        first(L) = P;
    } else {
        Q = first(L);
        while(next(Q) != NULL){
            Q = next(Q);
        }
        next(Q) = P;
    }
}

void insertAfter_103012330225(List &L, address P, address Prec){
    address Q;
    if(first(L) == NULL){
        first(L) = P;
    } else {
        if(first(L) == Prec){
            next(first(L)) = P;
        } else {
            Q = first(L);
            while(next(Q) != Prec){
                Q = next(Q);
            }
            next(Q) = P;
        }
    }
}

void deleteLast_103012330225(List &L){
    address Q;
    if(first(L) == NULL){
        cout << "List Kosong" << endl;
    } else {
        Q = first(L);
        while(next(Q) != NULL){
            Q = next(Q);
        }
        Q = NULL;
    }
}

void deleteAfter_103012330225(List &L, address Prec){
    address Q;
    if(first(L) == NULL){
        cout << "List Kosong" << endl;
    } else {
        if(first(L) == Prec){
            next(first(L)) = NULL;
        } else {
            Q = first(L);
            while(next(Q) != Prec){
                Q = next(Q);
            }
            next(Q) = NULL;
        }
    }
}

address searchInfo_103012330225(List L, infotype x){
    address P;
    if(first(L) == NULL){
        cout << "List Kosong" << endl;
        return NULL;
    } else {
        if(info(first(L)) == x){
            return first(L);
        } else {
            P = first(L);
            while(info(next(P)) != x && next(P) == NULL){
                P = next(P);
            }
            if(next(P) != NULL){
                cout << "Info ditemukan dalam list" << endl;
                return next(P);
            } else {
                cout << "Info tidak ditemukan dalam list" << endl;
                return NULL;
            }
        }
    }
}
