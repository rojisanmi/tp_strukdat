#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include "kerucut.h"

using namespace std;

int main() {
    kerucut k;
    inputKerucut(k);
    cout << "Volume = " << volume(k) << endl;
    cout << "Luas Permukaan = " << luas_permukaan(k);
    return 0;
}
