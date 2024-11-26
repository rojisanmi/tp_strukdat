#include <iostream>
#include "list.h"
using namespace std;

int selectMenu_103012330225(){
    cout << "======= MENU =======" << endl;
    cout << "1. Menambah N data baru" << endl;
    cout << "2. Menampilkan semua data" << endl;
    cout << "3. Menampilkan pengunjung dengan nama terpendek yang datang terakhir" << endl;
    cout << "4. Menampilkan nama pengunjung yang berawalan huruf tertentu dengan jumlah tertentu" << endl;
    cout << "0. Exit" << endl;
    int input;
    cout << "Masukkan menu : ";
    cin >> input;
    return input;
}
void createList_103012330225(list &L){
  first(L) = NULL;
}
address allocate_103012330225(infotype X){
    address P = new elmlist;
    info(P) = X;
    next(P) = NULL;
    return P;
}
void insertLast_103012330225(list &L, address P){
    address Q;
    if(first(L) == NULL){
        first(L) = P;
    }else{
        Q = first(L);
        while(next(Q) != NULL){
            Q = next(Q);
        }
        next(Q) = P;
    }
}
void showList_103012330225(list L){
    address Q;
    int number = 1;
    Q = first(L);
    while(Q != NULL){
        cout << number << ". " << info(Q) << endl;
        Q = next(Q);
        number++;
    }
}
address shortestName_103012330225(list L){
    address Q;
    address shortest = NULL;
    Q = first(L);
    while(Q != NULL){
        if (shortest == NULL || info(Q).length() <= info(shortest).length()) {
            shortest = Q;
        }
        Q = next(Q);
    }

    return shortest;
}
void showFirstKNameC_103012330225(list L, int k, char c){
    address P;
    int count = 0;
    P = first(L);
    while(P != NULL && count < k){
        if (info(P)[0] == c) {
            cout << info(P) << endl;
            count++;
        }
        P = next(P);
    }

    if(count == 0){
        cout << "Tidak ada pengunjung dengan nama berawalan '" << c << "' yang ditemukan." << endl;
    } else if (count < k) {
        cout << "Hanya ditemukan " << count << " pengunjung dengan nama berawalan '" << c << "'." << endl;
    }
}
