#include <iostream>
#include "DLL.h"
using namespace std;

int main() {
    // Deklarasi list
    List ListRock, ListJazz, ListGabungan;
    address P, Prec;
    infotype lagu1, lagu2, lagu3;

    // Membuat list baru
    createList_103012330225(ListRock);
    createList_103012330225(ListJazz);
    createList_103012330225(ListGabungan);

    // Mengecek apakah list ListRock kosong
    if (isEmpty_103012330225(ListRock)) {
        cout << "ListRock is empty!" << endl;
    }

    // Membuat lagu pertama
    lagu1.namaBand = "Nirvana";
    lagu1.judulLagu = "Smells Like Teen Spirit";
    createNewElmt_103012330225(lagu1, P);
    insertFirst_103012330225(ListRock, P); // Memasukkan di awal list ListRock

    // Membuat lagu kedua
    lagu2.namaBand = "Queen";
    lagu2.judulLagu = "Bohemian Rhapsody";
    createNewElmt_103012330225(lagu2, P);
    insertLast_103012330225(ListRock, P);  // Memasukkan di akhir list ListRock

    // Menampilkan isi list ListRock
    cout << "Isi List ListRock:" << endl;
    show_103012330225(ListRock);

    // Menambahkan lagu ketiga setelah elemen pertama
    lagu3.namaBand = "Guns N' Roses";
    lagu3.judulLagu = "Sweet Child O' Mine";
    createNewElmt_103012330225(lagu3, P);
    Prec = first(ListRock); // Elemen pertama sebagai Prec
    insertAfter_103012330225(ListRock, Prec, P); // Memasukkan setelah elemen pertama

    // Menampilkan isi list ListRock setelah insertAfter
    cout << "Isi List ListRock setelah insertAfter:" << endl;
    show_103012330225(ListRock);

    // Mencari lagu berdasarkan judul
    string judulDicari = "Bohemian Rhapsody";
    address ditemukan = findLagu_103012330225(judulDicari, ListRock);
    if (ditemukan != NULL) {
        cout << "Lagu ditemukan: " << info(ditemukan).judulLagu << " oleh " << info(ditemukan).namaBand << endl;
    } else {
        cout << "Lagu tidak ditemukan." << endl;
    }

    // Menghapus elemen pertama
    deleteFirst_103012330225(ListRock, P);
    cout << "Isi List ListRock setelah deleteFirst:" << endl;
    show_103012330225(ListRock);

    // Menghapus elemen terakhir
    deleteLast_103012330225(ListRock, P);
    cout << "Isi List ListRock setelah deleteLast:" << endl;
    show_103012330225(ListRock);

    // Menghapus berdasarkan judul lagu
    removeLagu_103012330225("Sweet Child O' Mine", ListRock);
    cout << "Isi List ListRock setelah removeLagu:" << endl;
    show_103012330225(ListRock);

    // Menambahkan elemen ke ListJazz
    createNewElmt_103012330225(lagu1, P); // Nirvana - Smells Like Teen Spirit
    insertFirst_103012330225(ListJazz, P);
    createNewElmt_103012330225(lagu2, P); // Queen - Bohemian Rhapsody
    insertLast_103012330225(ListJazz, P);

    // Menggabungkan ListRock dan ListJazz ke ListGabungan
    concat_103012330225(ListRock, ListJazz, ListGabungan);
    cout << "Isi List ListGabungan setelah concat ListRock dan ListJazz:" << endl;
    show_103012330225(ListGabungan);

    return 0;
}
