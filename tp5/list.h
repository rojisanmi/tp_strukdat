#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

#include <iostream>
#define first(L) L.first
#define info(P) P->info
#define next(P) P->next
using namespace std;
typedef string infotype;
typedef struct elmlist *address;

struct elmlist {
    infotype info;
    address next;
};
struct list {
    address first;
};

int selectMenu_103012330225();
void createList_103012330225(list &L);
address allocate_103012330225(infotype X);
void insertLast_103012330225(list &L, address P);
void showList_103012330225(list L);
address shortestName_103012330225(list L);
void showFirstKNameC_103012330225(list L, int k, char c);

#endif // LIST_H_INCLUDED
