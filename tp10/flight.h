#ifndef FLIGHT_H_INCLUDED
#define FLIGHT_H_INCLUDED

#include <iostream>
#define First(P) P.First
#define Info(P) P->Info
#define next(P) P->next
using namespace std;
typedef struct jadwalPenerbangan infotype;
typedef struct elemenJadwal *adr_jadwalP;

struct jadwalPenerbangan {
    string Kode, Jenis, Tanggal, Waktu, Asal, Tujuan;
    int Kapasitas;
};
struct elemenJadwal {
    infotype Info;
    adr_jadwalP next;
};
struct ListJadwal {
    adr_jadwalP First;
};

void createListJadwal_103012330225(ListJadwal &L);
adr_jadwalP createElemenJadwal_103012330225(infotype X);
void InsertLastJ_103012330225(ListJadwal &L, adr_jadwalP P);
void ShowJadwal_103012330225(ListJadwal L);
void DeleteFirstJ_103012330225(ListJadwal &L, adr_jadwalP &P);
adr_jadwalP SearchJ_103012330225(ListJadwal L, string dari, string ke, string tanggal);

#endif // FLIGHT_H_INCLUDED
