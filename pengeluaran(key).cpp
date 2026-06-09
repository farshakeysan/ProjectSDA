#include "pengeluaran.h"
#include "tampilan.h"
#include <iostream>
using namespace std;

Pengeluaran::Pengeluaran() : jumlahData(0), totalJumlah(0) {}

void Pengeluaran::tambah(string ket, string hr, double jml) {
    if (jumlahData >= maks) return;

    data[jumlahData] = {ket, hr, jml};

    totalJumlah += jml;
    jumlahData++;
}

void Pengeluaran::urutkan() {
    for (int i = 0; i < jumlahData - 1; i++) {
        for (int j = 0; j < jumlahData - 1 - i; j++) {
            if (data[j].jumlah < data[j + 1].jumlah)
                swap(data[j], data[j + 1]);
        }
    }
}

void menuPengeluaran(Pengeluaran& dataPengeluaran) {
    int pilihan;

    do {
        cetakJudul("MENU PENGELUARAN");

        cout << "  1. Tambah Pengeluaran\n";
        cout << "  2. Lihat Semua\n";
        cout << "  3. Urutkan (Besar ke Kecil)\n";
        cout << "  4. Kembali\n\n";
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

            dataPengeluaran.tambah(keterangan, hari, jumlah);
            cout << "\n  Pengeluaran berhasil ditambahkan.\n\n";
        }
        else if (pilihan == 2) {
            cetakJudul("DAFTAR PENGELUARAN");

            if (dataPengeluaran.jumlahData == 0) {
                cout << "  Belum ada data pengeluaran.\n\n";
            } else {
                for (int i = 0; i < dataPengeluaran.jumlahData; i++) {
                    cout << "  " << i + 1 << ". "
                        << dataPengeluaran.data[i].keterangan
                        << " | "
                        << dataPengeluaran.data[i].hari
                        << " | Rp "
                        << (long long)dataPengeluaran.data[i].jumlah
                        << "\n";
                }

                cout << "\n  Total: Rp "
                    << (long long)dataPengeluaran.totalJumlah
                    << "\n\n";
            }
        }
        else if (pilihan == 3) {
            dataPengeluaran.urutkan();
            cout << "\n  Data berhasil diurutkan.\n\n";
        }
        else if (pilihan != 4) {
            cout << "\n  Pilihan tidak valid.\n\n";
        }

    } while (pilihan != 4);
}