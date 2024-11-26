#ifndef KERUCUT_H_INCLUDED
#define KERUCUT_H_INCLUDED
struct kerucut {
    float jari_jari, tinggi;
};

void inputKerucut(kerucut &k);
float volume(kerucut k);
float luas_permukaan(kerucut k);
#endif // KERUCUT_H_INCLUDED
