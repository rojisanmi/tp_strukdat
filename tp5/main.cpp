#include <iostream>
#include "list.h"
using namespace std;

int main()
{
    address P, alamat;
    infotype X;
    int jumlahData, angka;
    char hurufAwal;
    int menu = 0;
    string pilihan;
    list L;
    createList_103012330225(L);
    menu = selectMenu_103012330225();
    while(menu != 0){
        switch(menu){
        case 1 :
            pilihan = "N";
            while(pilihan != "Y"){
                cout << "Jumlah data yang akan ditambahkan : ";
                cin >> jumlahData;
                for(int i = 1; i <= jumlahData; i++){
                    cout << "Masukkan nama pengunjung baru : ";
                    cin >> X;
                    P = allocate_103012330225(X);
                    insertLast_103012330225(L, P);
                }
                cout << "Data berhasil dimasukkan" << endl;
                cout << "Kembali ke menu utama?(Y/N) ";
                cin >> pilihan;
            }
            break;
        case 2 :
            cout << "Berikut adalah data pengunjung perpustakaan :" << endl;
            showList_103012330225(L);
            break;
        case 3 :
            alamat = shortestName_103012330225(L);
            cout << "Pengunjung perpustakaan dengan nama terpendek yang datang paling akhir adalah " << info(alamat) << endl;
            break;
        case 4 :
            pilihan = "N";
            while(pilihan != "Y"){
                cout << "Masukkan jumlah pengunjung yang ingin ditampilkan : ";
                cin >> angka;
                cout << "Masukkan huruf awal nama pengunjung yang ingin ditampilkan : ";
                cin >> hurufAwal;
                showFirstKNameC_103012330225(L, angka, hurufAwal);
                cout << "Kembali ke menu utama?(Y/N) ";
                cin >> pilihan;
            }
            break;
        }
        menu = selectMenu_103012330225();
    }
    cout << "ANDA TELAH KELUAR DARI PROGRAM";

    return 0;
}
