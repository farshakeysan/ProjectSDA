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

    cout << "  PEMASUKAN\n";
    cout << "  --------------------------------\n";
    if (dataPemasukan.jumlahData == 0) {
        cout << "  Belum ada data pemasukan.\n";
    } else {
        for (int i = 0; i < dataPemasukan.jumlahData; i++) {
            cout << "  " << i + 1 << ". "
                << dataPemasukan.data[i].keterangan
                << " | " << dataPemasukan.data[i].hari
                << " | Rp " << (long long)dataPemasukan.data[i].jumlah << "\n";
        }
        cout << "  Total Pemasukan  : Rp " << (long long)dataPemasukan.totalJumlah << "\n";
    }

    cout << "\n";

    // Struk Pengeluaran
    cout << "  PENGELUARAN\n";
    cout << "  --------------------------------\n";
    if (dataPengeluaran.jumlahData == 0) {
        cout << "  Belum ada data pengeluaran.\n";
    } else {
        for (int i = 0; i < dataPengeluaran.jumlahData; i++) {
            cout << "  " << i + 1 << ". "
                << dataPengeluaran.data[i].keterangan
                << " | " << dataPengeluaran.data[i].hari
                << " | Rp " << (long long)dataPengeluaran.data[i].jumlah << "\n";
        }
        cout << "  Total Pengeluaran: Rp " << (long long)dataPengeluaran.totalJumlah << "\n";
    }

    // Saldo
    double saldo = dataPemasukan.totalJumlah - dataPengeluaran.totalJumlah;
    cout << "\n  ================================\n";
    cout << "  Saldo              : Rp " << (long long)saldo << "\n";

    if (saldo < 0)
        cout << "  Status             : Keuangan tidak sehat\n";
    else
        cout << "  Status             : Keuangan dalam kondisi normal\n";

    cout << "  ================================\n\n";
}