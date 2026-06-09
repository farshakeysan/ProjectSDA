#include "tampilan(fafa).h"
#include "pemasukan(dimas).h"
#include "pengeluaran(key).h"
#include <iostream>
using namespace std;

int main() {
    Pemasukan dataPemasukan;
    Pengeluaran dataPengeluaran;

    int pilihan;

    do {
        cetakJudul("APLIKASI KEUANGAN PRIBADI");

        cout << "  1. Pemasukan\n";
        cout << "  2. Pengeluaran\n";
        cout << "  3. Keluar\n\n";

        cout << "  Pilih: ";

        if (cin >> pilihan) {
            cin.ignore();
        } else {
            cout << "\n  Pilihan tidak valid.\n\n";
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }

        switch (pilihan) {
            case 1: menuPemasukan(dataPemasukan);     break;
            case 2: menuPengeluaran(dataPengeluaran); break;
            case 3: break;
            default:
                cout << "\n  Pilihan tidak valid.\n\n";
        }

    } while (pilihan != 3);

    return 0;
}