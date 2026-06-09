#include "pemasukan.h"
#include "tampilan.h"
#include <iostream>
using namespace std;

Pemasukan::Pemasukan() : kepala(nullptr), jumlahData(0), totalJumlah(0) {}

void Pemasukan::tambah(string keterangan, string hari, double jumlah) {
    NodePemasukan* dataBaru = new NodePemasukan();
    dataBaru->keterangan = keterangan;
    dataBaru->hari = hari;
    dataBaru->jumlah = jumlah;
    dataBaru->berikutnya = nullptr;

    if (kepala == nullptr)
        kepala = dataBaru;
    else {
        NodePemasukan* posisi = kepala;
        while (posisi->berikutnya != nullptr)
            posisi = posisi->berikutnya;
        posisi->berikutnya = dataBaru;
    }

    totalJumlah += jumlah;
    jumlahData++;
}

void menuPemasukan(Pemasukan& dataPemasukan) {
    int pilihan;

    do {
        cetakJudul("MENU PEMASUKAN");

        cout << "  1. Tambah Pemasukan\n";
        cout << "  2. Lihat Semua\n";
        cout << "  3. Kembali\n\n";
        cout << "  Pilih: ";

        if (cin >> pilihan) {
            cin.ignore();
        } else {
            cout << "\n  Pilihan tidak valid.\n\n";
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }

        if (pilihan == 1) {
            string keterangan, hari;
            double jumlah;

            cout << "\n";
            if (inputString("  Keterangan : ", keterangan) == 0) continue;
            if (inputString("  Hari       : ", hari) == 0)       continue;
            if (inputJumlah(jumlah) == 0)                        continue;

            dataPemasukan.tambah(keterangan, hari, jumlah);
            cout << "\n  Pemasukan berhasil ditambahkan.\n\n";
        }
        else if (pilihan == 2) {
            cetakJudul("DAFTAR PEMASUKAN");

            NodePemasukan* posisi = dataPemasukan.kepala;

            if (posisi == nullptr) {
                cout << "  Belum ada data pemasukan.\n\n";
            } else {
                int nomor = 1;
                while (posisi != nullptr) {
                    cout << "  " << nomor << ". "
                        << posisi->keterangan
                        << " | "
                        << posisi->hari
                        << " | Rp "
                        << (long long)posisi->jumlah << "\n";

                    posisi = posisi->berikutnya;
                    nomor++;
                }

                cout << "\n  Total: Rp "
                    << (long long)dataPemasukan.totalJumlah
                    << "\n\n";
            }
        }
        else if (pilihan != 3) {
            cout << "\n  Pilihan tidak valid.\n\n";
        }

    } while (pilihan != 3);
}