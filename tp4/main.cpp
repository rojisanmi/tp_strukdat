#include <iostream>
#include "list.h"
using namespace std;

int main()
{
    List L;
    int angka;
    address P[12];

    createList_103012330225(L);

    cout << "Masukkan NIM per digit" << endl;
    for(int i = 1; i <= 12; i++){
        cout << "Digit " << i << " : ";
        cin >> angka;
        P[i-1] = allocate_103012330225(angka);
        insertLast_103012330225(L, P[i-1]);
    }

    printInfo_103012330225(L);

    return 0;
}
