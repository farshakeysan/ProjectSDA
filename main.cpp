#include <iostream>
#include <string>
using namespace std;

struct NodePemasukan {
    string keterangan;
    double jumlah;
    NodePemasukan* berikutnya;
};

class Pemasukan {
public:
    NodePemasukan* kepala;
    int jumlahData;
    double totalJumlah;

    Pemasukan() : kepala(nullptr), jumlahData(0), totalJumlah(0) {}

    void tambah(string keterangan, double jumlah) {
        NodePemasukan* dataBaru = new NodePemasukan();
        dataBaru->keterangan = keterangan;
        dataBaru->jumlah = jumlah;
        dataBaru->berikutnya = nullptr;

        if (kepala == nullptr) {
            kepala = dataBaru;
        } else {
            NodePemasukan* posisi = kepala;
            while (posisi->berikutnya != nullptr) {
                posisi = posisi->berikutnya;
            }
            posisi->berikutnya = dataBaru;
        }

        totalJumlah += jumlah;
        jumlahData++;
    }
};

const int maks = 100;
