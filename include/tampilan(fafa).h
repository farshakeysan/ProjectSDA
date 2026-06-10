#ifndef TAMPILAN_H
#define TAMPILAN_H

#include "pemasukan(dimas).h"
#include "pengeluaran(key).h"

#include <string>
using namespace std;

void cetakJudul(string judul);
int inputString(const string& label, string& hasil);
int inputJumlah(double& hasil);

void menuLaporan(Pemasukan& dataPemasukan, Pengeluaran& dataPengeluaran);

#endif