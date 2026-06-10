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