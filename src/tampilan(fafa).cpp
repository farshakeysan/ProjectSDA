#include "tampilan(fafa).h"
#include <iostream>
using namespace std;

void cetakJudul(string judul) {
    cout << "\n====================================\n";
    cout << "  " << judul << "\n";
    cout << "====================================\n\n";
}

int inputString(const string& label, string& hasil) {
    cout << label;
    getline(cin, hasil);
    if (hasil.empty()) {
        cout << "\n  Input tidak boleh kosong. Kembali ke menu.\n\n";
        return 0;
    }
    return 1;
}

int inputJumlah(double& hasil) {
    cout << "  Jumlah (Rp): ";
    if (cin >> hasil && hasil > 0) {
        cin.ignore();
        return 1;
    }
    cout << "\n  Jumlah tidak valid. Kembali ke menu.\n\n";
    cin.clear();
    cin.ignore(1000, '\n');
    return 0;
}

void menuLaporan(Pemasukan& dataPemasukan, Pengeluaran& dataPengeluaran) {
    cetakJudul("LAPORAN KEUANGAN");

    cout << "  === PEMASUKAN ===\n";
    if (dataPemasukan.jumlahData == 0) {
        cout << "  Tidak ada data pemasukan.\n";
    } else {
        NodePemasukan* posisi = dataPemasukan.getData();
        int no = 1;
        while (posisi != nullptr) {
            cout << "  " << no << ". "
                << posisi->keterangan
                << " | " << posisi->hari
                << " | Rp " << (long long)posisi->jumlah << "\n";
            posisi = posisi->berikutnya;
            no++;
        }
        cout << "  Total : Rp " << (long long)dataPemasukan.totalJumlah << "\n";
    }

    cout << "\n";

    cout << "  === PENGELUARAN ===\n";
    if (dataPengeluaran.jumlahData == 0) {
        cout << "  Tidak ada data pengeluaran.\n";
    } else {
        for (int i = 0; i < dataPengeluaran.jumlahData; i++) {
            int no = i + 1;
            string ket = dataPengeluaran.data[i].keterangan;
            string hr  = dataPengeluaran.data[i].hari;
            long long jml = (long long)dataPengeluaran.data[i].jumlah;
            cout << "  " << no << ". " << ket << " | " << hr << " | Rp " << jml << "\n";
        }
        cout << "  Total : Rp " << (long long)dataPengeluaran.totalJumlah << "\n";
    }

    double selisih = dataPemasukan.totalJumlah - dataPengeluaran.totalJumlah;
    string kondisi = (selisih < 0) ? "Keuangan tidak sehat" : "Keuangan dalam kondisi normal";

    cout << "\n  ================================\n";
    cout << "  Saldo  : Rp " << (long long)selisih << "\n";
    cout << "  Status : " << kondisi << "\n";
    cout << "  ================================\n\n";
}