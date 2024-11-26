#ifndef DLL_H_INCLUDED
#define DLL_H_INCLUDED

#include <iostream>
#define first(L) L.first
#define last(L) L.last
#define next(P) P->next
#define prev(P) P->prev
#define info(P) P->info
using namespace std;
typedef struct dataLagu infotype;
typedef struct elmtList *address;

struct dataLagu {
    string namaBand;
    string judulLagu;
};
struct elmtList {
    infotype info;
    address next;
    address prev;
};
struct List {
    address first;
    address last;
};

bool isEmpty_103012330225(List L);
void createList_103012330225(List &L);
void createNewElmt_103012330225(infotype X, address &P);
void insertFirst_103012330225(List &L, address P);
void insertAfter_103012330225(List &L, address &Prec, address &P);
void insertLast_103012330225(List &L, address P);
void deleteFirst_103012330225(List &L, address &P);
void deleteAfter_103012330225(List &L, address &Prec, address &P);
void deleteLast_103012330225(List &L, address &P);
void concat_103012330225(List L1, List L2, List &L3);
address findLagu_103012330225(string Judul, List L);
void removeLagu_103012330225(string Judul, List &L);
void show_103012330225(List L);

#endif // DLL_H_INCLUDED
