#include <iostream>
#include "stack.h"
using namespace std;

int main()
{
    stack S;
    string huruf;
    string input[15];
    int i = 1;
    createStack_103012330225(S);

    cout << "Masukkan elemen huruf yang akan dimasukkan ke dalam stack: (ketik - jika ingin berhenti)" << endl;
    cin >> huruf;
    while(huruf != "-"){
        input[i] = huruf;
        cin >> huruf;
        i++;
    }

    while(i > 0){
        push_103012330225(S, input[i]);
        i--;
    }
    printInfo_103012330225(S);

    for(int i = 0; i < 4; i++){
        pop_103012330225(S);
    }
    printInfo_103012330225(S);

    return 0;
}
