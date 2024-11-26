#include <iostream>
#include "queue_vaksinasi.h"
using namespace std;

void createQueue_103012330225(Queue &Q){
    head(Q) = NULL;
    tail(Q) = NULL;
}

bool isEmpty_103012330225(Queue Q){
    return head(Q) == NULL;
}

ElemQ* createElemQueue_103012330225(string nama, int usia, string pekerjaan, int nomor_antrean, int waktu_daftar){
    ElemQ *P = new ElemQ;
    info(P).nama = nama;
    info(P).usia = usia;
    info(P).pekerjaan = pekerjaan;
    info(P).prioritas = (usia >= 60 || pekerjaan == "tenaga kesehatan");
    info(P).nomor_antrean = nomor_antrean;
    info(P).kondisi_darurat = false;
    info(P).waktu_daftar = waktu_daftar;
    next(P) = NULL;
    return P;
}

void enqueue_103012330225(Queue &Q, ElemQ *P){
    if(isEmpty_103012330225(Q)){
        head(Q) = P;
        tail(Q) = P;
    }else if (info(P).prioritas){
        if(!info(head(Q)).prioritas){
            next(P) = head(Q);
            head(Q) = P;
        }else{
            ElemQ *temp = head(Q);
            while(next(temp) != NULL && info(next(temp)).prioritas){
                temp = next(temp);
            }
            next(P) = next(temp);
            next(temp) = P;
            if(next(P) == NULL){
                tail(Q) = P;
            }
        }
    }else{
        next(tail(Q)) = P;
        tail(Q) = P;
    }
}

void dequeue_103012330225(Queue &Q, ElemQ *&P){
    if(isEmpty_103012330225(Q)){
        P = NULL;
        cout << "Semua warga telah terlayani" << endl;
    }else{
        P = head(Q);
        head(Q) = next(head(Q));
        if(head(Q) == NULL){
            tail(Q) = NULL;
        }
        next(P) = NULL;
    }
}

ElemQ* front_103012330225(Queue Q){
    return head(Q);
}

ElemQ* back_103012330225(Queue Q){
    return tail(Q);
}

int size_103012330225(Queue Q){
    int count = 0;
    ElemQ *temp = head(Q);
    while(temp != NULL){
        count++;
        temp = next(temp);
    }
    return count;
}
void printInfo_103012330225(Queue Q){
    if(isEmpty_103012330225(Q) == true){
        cout << "Antrean kosong." << endl;
    }else{
        cout << "Daftar Antrean:" << endl;
        ElemQ *P = front_103012330225(Q);
        while(P != NULL){
            cout << "Nama: " << info(P).nama << endl;
            cout << "Usia: " << info(P).usia << endl;
            cout << "Pekerjaan: " << info(P).pekerjaan << endl;
            if(info(P).prioritas == true){
                cout << "Prioritas: Ya" << endl;
            }else{
                cout << "Prioritas: Tidak" << endl;
            }
            cout << "Nomor Antrean: " << info(P).nomor_antrean << endl;
            cout << "----------------------------" << endl;

            P = next(P);
        }
    }
}

void serveQueue_103012330225(Queue &Q){
    int count = 0;
    ElemQ *P;
    while(isEmpty_103012330225(Q) != true && count <= 100){
        dequeue_103012330225(Q, P);
        cout << "Melayani warga:" << endl;
        cout << "Nama: " << info(P).nama << endl;
        cout << "Usia: " << info(P).usia << endl;
        cout << "Pekerjaan: " << info(P).pekerjaan << endl;
        if(info(P).prioritas == true){
            cout << "Prioritas: Ya" << endl;
        }else{
            cout << "Prioritas: Tidak" << endl;
        }
        cout << "Vaksinasi berhasil." << endl;
        cout << "----------------------------" << endl;
        count++;
    }

    if(size_103012330225(Q) > 100){
        cout << "Kapasitas harian telah penuh." << endl;
        if(isEmpty_103012330225(Q) == false){
            cout << "Warga yang belum terlayani diminta kembali besok." << endl;
        }
    }
}

void reassignQueue_103012330225(Queue &Q){
    Queue priorityQ, normalQ, waitingQ;
    createQueue_103012330225(priorityQ);
    createQueue_103012330225(normalQ);
    createQueue_103012330225(waitingQ);
    ElemQ *P;
    while(isEmpty_103012330225(Q) != true){ // Mengeluarkan isi queue Q
        dequeue_103012330225(Q, P);
        if(info(P).prioritas){
            enqueue_103012330225(priorityQ, P);
        }else{
            enqueue_103012330225(normalQ, P);
        }
    }
    while(isEmpty_103012330225(priorityQ) != true){ // Memasukkan queue priorityQ ke waitingQ
        dequeue_103012330225(priorityQ, P);
        enqueue_103012330225(waitingQ, P);
    }
    while(isEmpty_103012330225(normalQ) != true){ // Memasukkan queue normalQ ke waitingQ
        dequeue_103012330225(normalQ, P);
        enqueue_103012330225(waitingQ, P);
    }
    Q = waitingQ;
}

void checkWaitingTime_103012330225(Queue &Q, int waktu_sekarang){
    Queue priorityQ, tempQ;
    createQueue_103012330225(priorityQ);
    createQueue_103012330225(tempQ);
    ElemQ *P;
    while(isEmpty_103012330225(Q) != true){
        dequeue_103012330225(Q, P);
        if((waktu_sekarang - info(P).waktu_daftar) > 120){
            info(P).prioritas = true;
            enqueue_103012330225(priorityQ, P);
        }else{
            enqueue_103012330225(tempQ, P);
        }
    }
    while(isEmpty_103012330225(priorityQ) != true){ // Memasukkan queue priorityQ ke Q
        dequeue_103012330225(priorityQ, P);
        enqueue_103012330225(Q, P);
    }
    while(isEmpty_103012330225(tempQ) != true){ // Memasukkan queue tempQ ke Q
        dequeue_103012330225(tempQ, P);
        enqueue_103012330225(Q, P);
    }
}

void emergencyHandle_103012330225(Queue &Q, int nomor_antrean){
    Queue priorityQ, tempQ;
    createQueue_103012330225(priorityQ);
    createQueue_103012330225(tempQ);
    ElemQ *P;
    bool isFound = false;
    while(isEmpty_103012330225(Q) != true){
        dequeue_103012330225(Q, P);
        if(info(P).nomor_antrean == nomor_antrean){
            info(P).kondisi_darurat = true;
            isFound = true;
            enqueue_103012330225(priorityQ, P);
        }else{
            enqueue_103012330225(tempQ, P);
        }
    }
    if(isFound == false){
        cout << "Warga dengan nomor antrean " << nomor_antrean << " tidak ditemukan." << endl;
    }
    while(isEmpty_103012330225(priorityQ) != true){ // Memasukkan queue priorityQ ke Q
        dequeue_103012330225(priorityQ, P);
        enqueue_103012330225(Q, P);
    }
    while(isEmpty_103012330225(tempQ) != true){ // Memasukkan queue tempQ ke Q
        dequeue_103012330225(tempQ, P);
        enqueue_103012330225(Q, P);
    }
}

void updatePriority_103012330225(Queue &Q){
    Queue Qdepan, QpalingDepan, Qbelakang;
    createQueue_103012330225(QpalingDepan);
    createQueue_103012330225(Qdepan);
    createQueue_103012330225(Qbelakang);
    ElemQ *P;
    while(isEmpty_103012330225(Q) != true){
        dequeue_103012330225(Q, P);
        if(info(P).prioritas == true || info(P).waktu_daftar > 120){
            enqueue_103012330225(Qdepan, P);
        }else if(info(P).kondisi_darurat == true){
            enqueue_103012330225(QpalingDepan, P);
        }else{
            enqueue_103012330225(Qbelakang, P);
        }
    }
    while(isEmpty_103012330225(QpalingDepan) != true){ // Memasukkan queue tempQ ke Q
        dequeue_103012330225(QpalingDepan, P);
        enqueue_103012330225(Q, P);
    }
    while(isEmpty_103012330225(Qdepan) != true){ // Memasukkan queue tempQ ke Q
        dequeue_103012330225(Qdepan, P);
        enqueue_103012330225(Q, P);
    }
    while(isEmpty_103012330225(Qbelakang) != true){ // Memasukkan queue tempQ ke Q
        dequeue_103012330225(Qbelakang, P);
        enqueue_103012330225(Q, P);
    }
}




ElemQ* findAndRemove_103012330225(Queue &Q, int nomor_antrean){
    Queue tempQ;
    createQueue_103012330225(tempQ);
    ElemQ *P;
    ElemQ *Pketemu = NULL;
    while(isEmpty_103012330225(Q) != true){
        dequeue_103012330225(Q,P);
        if(info(P).nomor_antrean == nomor_antrean){
            Pketemu = P;
        }else{
            enqueue_103012330225(tempQ, P);
        }
    }
    while(isEmpty_103012330225(tempQ) != true){ // Memasukkan queue tempQ ke Q
        dequeue_103012330225(tempQ, P);
        enqueue_103012330225(Q, P);
    }
    if(Pketemu == NULL){
        cout << "Warga dengan nomor antrean " << nomor_antrean << " tidak ditemukan dalam antrean.";
    }
    return Pketemu;
}
