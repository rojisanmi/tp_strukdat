#include <iostream>
#include <cmath> // untuk sqrt()
#include "kerucut.h"

using namespace std;

void inputKerucut(kerucut &k) {
    cout << "input jari-jari = ";
    cin >> k.jari_jari;
    cout << "input tinggi = ";
    cin >> k.tinggi;
}

float volume(kerucut k) {
    return (3.14 * k.jari_jari * k.jari_jari * k.tinggi) / 3;
}

float luas_permukaan(kerucut k) {
    float tinggi_miring_kerucut;
    tinggi_miring_kerucut = sqrt((k.jari_jari * k.jari_jari) + (k.tinggi * k.tinggi));
    return (3.14 * k.jari_jari * (k.jari_jari + tinggi_miring_kerucut));
}
