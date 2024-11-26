#include <iostream>
#include "flight.h"
using namespace std;

int main()
{
    ListJadwal L;
    int n;
    infotype X;
    adr_jadwalP jadwal;

    createListJadwal_103012330225(L);
    cout << "Masukkan jumlah jadwal yang ingin dimasukkan ke list: ";
    cin >> n;

    for(int i = 1; i <= n; i++){
        cout << "Masukkan data jadwal ke-" << i << endl;
        cout << "Kode: ";
        cin >> X.Kode;
        cout << "Jenis: ";
        cin >> X.Jenis;
        cout << "Tanggal: ";
        cin >> X.Tanggal;
        cout << "Waktu: ";
        cin >> X.Waktu;
        cout << "Asal: ";
        cin >> X.Asal;
        cout << "Tujuan: ";
        cin >> X.Tujuan;
        cout << "Kapasitas: ";
        cin >> X.Kapasitas;
        jadwal = createElemenJadwal_103012330225(X);
        InsertLastJ_103012330225(L, jadwal);
        cout << endl;
    }

    cout << "List jadwal setelah dimasukkan data: " << endl;
    ShowJadwal_103012330225(L);

    cout << "List jadwal setelah dihapus jadwal urutan pertama: " << endl;
    DeleteFirstJ_103012330225(L, jadwal);
    ShowJadwal_103012330225(L);
    cout << endl;

    cout << "Mencari jadwal penerbangan dari surabaya ke malang tanggal 9 Desember 2022: " << endl;
    jadwal = SearchJ_103012330225(L, "Surabaya(SUB)", "Malang(MLG)", "9-Desember-2022");
    if(jadwal == NULL){
        cout << "Jadwal tidak ditemukan dalam list";
    }else{
        cout << "Jadwal ditemukan" << endl;
        cout << endl;
        cout << "Kode: " << Info(jadwal).Kode << endl;
        cout << "Jenis: " << Info(jadwal).Jenis << endl;
        cout << "Tanggal: " << Info(jadwal).Tanggal << endl;
        cout << "Waktu: " << Info(jadwal).Waktu << endl;
        cout << "Asal: " << Info(jadwal).Asal << endl;
        cout << "Tujuan: " << Info(jadwal).Tujuan << endl;
        cout << "Kapasitas: " << Info(jadwal).Kapasitas << endl;
    }

    return 0;
}
