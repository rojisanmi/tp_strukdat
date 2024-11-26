#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

#include <iostream>
#define first(L) L.first
#define next(P) P->next
#define info(P) P->info
using namespace std;
typedef int infotype;
typedef struct elmlist *address;

struct elmlist {
    infotype info;
    address next;
};
struct List{
    address first;
};

void createList_103012330225(List &L);
address allocate_103012330225(infotype x);
void insertFirst_103012330225(List &L, address P);
void printInfo_103012330225(List L);

void insertLast_103012330225(List &L, address P);
void insertAfter_103012330225(List &L, address P, address Prec);
void deleteLast_103012330225(List &L);
void deleteAfter_103012330225(List &L, address Prec);

address searchInfo_103012330225(List L, infotype x);

#endif // LIST_H_INCLUDED
