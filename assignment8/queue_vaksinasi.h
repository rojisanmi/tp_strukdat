#ifndef QUEUE_VAKSINASI_H_INCLUDED
#define QUEUE_VAKSINASI_H_INCLUDED

#include <iostream>
#define head(Q) Q.head
#define tail(Q) Q.tail
#define info(P) P->info
#define next(P) P->next
using namespace std;

struct Infotype {
    string nama;
    int usia;
    string pekerjaan;
    bool prioritas;
    int nomor_antrean;
    bool kondisi_darurat;
    int waktu_daftar; // waktu daftar dalam menit dari antrian pertama
};

struct ElemQ {
    Infotype info;
    ElemQ *next;
};

struct Queue {
    ElemQ *head;
    ElemQ *tail;
};

void createQueue_103012330225(Queue &Q);
bool isEmpty_103012330225(Queue Q);
ElemQ* createElemQueue_103012330225(string nama, int usia, string pekerjaan, int nomor_antrean, int waktu_daftar);
void enqueue_103012330225(Queue &Q, ElemQ *P);
void dequeue_103012330225(Queue &Q, ElemQ *&P);
ElemQ* front_103012330225(Queue Q);
ElemQ* back_103012330225(Queue Q);
int size_103012330225(Queue Q);
void printInfo_103012330225(Queue Q);
void serveQueue_103012330225(Queue &Q);
void reassignQueue_103012330225(Queue &Q);
void checkWaitingTime_103012330225(Queue &Q, int waktu_sekarang);
void emergencyHandle_103012330225(Queue &Q, int nomor_antrean);
void updatePriority_103012330225(Queue &Q);
ElemQ* findAndRemove_103012330225(Queue &Q, int nomor_antrean);

#endif // QUEUE_VAKSINASI_H_INCLUDED
