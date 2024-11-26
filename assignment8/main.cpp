#include <iostream>
#include "queue_vaksinasi.h"
using namespace std;

int main(){
    // Membuat antrean
    Queue Q;
    createQueue_103012330225(Q);

    // Menambahkan beberapa elemen ke dalam queue
    ElemQ* P1 = createElemQueue_103012330225("John Doe", 65, "lansia", 1, 0);
    ElemQ* P2 = createElemQueue_103012330225("Alice", 30, "tenaga kesehatan", 2, 1);
    ElemQ* P3 = createElemQueue_103012330225("Bob", 25, "pekerja", 3, 4);
    ElemQ* P4 = createElemQueue_103012330225("Charlie", 70, "pensiunan", 4, 4);
    ElemQ* P5 = createElemQueue_103012330225("David", 28, "pekerja", 5, 7);

    enqueue_103012330225(Q, P1);
    enqueue_103012330225(Q, P2);
    enqueue_103012330225(Q, P3);
    enqueue_103012330225(Q, P4);
    enqueue_103012330225(Q, P5);

    // Menampilkan isi queue
    cout << "Isi antrean awal:" << endl;
    printInfo_103012330225(Q);

    // Melayani antrean
    cout << "\nMelakukan pelayanan pada antrean:" << endl;
    serveQueue_103012330225(Q);

    // Memeriksa antrean setelah pelayanan
    cout << "\nIsi antrean setelah pelayanan:" << endl;
    printInfo_103012330225(Q);

    // Menambahkan elemen baru untuk simulasi pengaturan ulang prioritas
    ElemQ* P6 = createElemQueue_103012330225("Edward", 22, "pekerja", 6, 9);
    enqueue_103012330225(Q, P6);

    // Simulasi reassignQueue untuk mengatur ulang antrean ke prioritas
    cout << "\nMengatur ulang antrean berdasarkan prioritas:" << endl;
    reassignQueue_103012330225(Q);
    printInfo_103012330225(Q);

    // Simulasi kondisi warga yang menunggu lebih dari 2 jam
    cout << "\nMemeriksa waktu tunggu dan mengubah prioritas jika lebih dari 2 jam:" << endl;
    checkWaitingTime_103012330225(Q, 130); // Asumsikan waktu sekarang 130 menit dari nomor antrean pertama

    printInfo_103012330225(Q);

    // Menangani kondisi darurat untuk seorang warga
    cout << "\nMenangani kondisi darurat untuk warga dengan nomor antrean 5:" << endl;
    emergencyHandle_103012330225(Q, 5);
    printInfo_103012330225(Q);

    // Update prioritas warga setiap jam
    cout << "\nMengupdate prioritas antrean setiap jam:" << endl;
    updatePriority_103012330225(Q);
    printInfo_103012330225(Q);

    // Mencari dan menghapus warga dengan nomor antrean tertentu
    cout << "\nMenghapus warga dengan nomor antrean 3:" << endl;
    ElemQ* removedElem = findAndRemove_103012330225(Q, 3);

    if (removedElem) {
    cout << "Warga yang dihapus: " << info(removedElem).nama << endl;
    }

    printInfo_103012330225(Q);

    // Mengecek ukuran queue
    cout << "\nUkuran antrean saat ini: " << size_103012330225(Q) << endl;

    return 0;
}
