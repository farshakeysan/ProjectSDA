# Aplikasi Keuangan Pribadi

Program manajemen keuangan pribadi berbasis terminal menggunakan C++.

## Anggota Kelompok

| Nama | Branch | File |
|------|--------|------|
| Dimas | dimas | pemasukan.h, pemasukan.cpp |
| Key | key | pengeluaran.h, pengeluaran.cpp |
| Fafa | fafa | tampilan.h, tampilan.cpp |
| Intan | main | main.cpp |

## Struktur File

```
ujicobaProject/
├── main.cpp          # Program utama
├── pemasukan.h       # Header class Pemasukan (linked list)
├── pemasukan.cpp     # Implementasi Pemasukan
├── pengeluaran.h     # Header class Pengeluaran (array of struct)
├── pengeluaran.cpp   # Implementasi Pengeluaran
├── tampilan.h        # Header fungsi tampilan & input
└── tampilan.cpp      # Implementasi fungsi tampilan & input
```

## Cara Clone dan Menjalankan

### 1. Clone repo
```bash
git clone https://github.com/farshakeysan/ProjectSDA.git
cd ProjectSDA
```

### 2. Kompilasi
```bash
g++ g++ main.cpp "pemasukan(dimas).cpp" "pengeluaran(key).cpp" "tampilan(fafa).cpp" -o keuangan

```

### 3. Jalankan
```bash
.\keuangan.exe
```

## Fitur

- Tambah dan lihat data pemasukan
- Tambah, lihat, dan urutkan data pengeluaran (besar ke kecil)
- Validasi input kosong dan input tidak valid