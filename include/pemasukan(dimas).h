#ifndef PEMASUKAN_H
#define PEMASUKAN_H

#include <string>
using namespace std;

struct NodePemasukan {
    string keterangan;
    string hari;
    double jumlah;
    NodePemasukan* berikutnya;
};

class Pemasukan {
public:
    NodePemasukan* kepala;
    int jumlahData;
    double totalJumlah;

    Pemasukan();
    void tambah(string keterangan, string hari, double jumlah);
};

void menuPemasukan(Pemasukan& dataPemasukan);

#endif