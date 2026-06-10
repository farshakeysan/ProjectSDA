#ifndef PENGELUARAN_H
#define PENGELUARAN_H

#include <string>
using namespace std;

const int maks = 100;

struct ItemPengeluaran {
    string keterangan, hari;
    double jumlah;
};

class Pengeluaran {
public:
    ItemPengeluaran data[maks];
    int jumlahData;
    double totalJumlah;

    Pengeluaran();
    void tambah(string ket, string hr, double jml);
    void urutkan();
};

void menuPengeluaran(Pengeluaran& dataPengeluaran);

#endif