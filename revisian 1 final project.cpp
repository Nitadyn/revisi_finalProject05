#include <iostream>
#include <string>
#include <iomanip>
#include <limits>

using namespace std;

const int MAX_RECORDS = 100;

string dates[MAX_RECORDS];
string weatherConditions[MAX_RECORDS];
double temperatures[MAX_RECORDS];
double totalSales[MAX_RECORDS];
string specialMenus[MAX_RECORDS];
int recordCount = 0;

int main() {
    int choice;

    while (true) {
        cout << "\n=== Sistem Manajemen Cuaca dan Penjualan ===" << endl;
        cout << "1. Input Kondisi Cuaca Harian" << endl;
        cout << "2. Lihat Catatan Penjualan per Cuaca" << endl;
        cout << "3. Laporan Total Pendapatan Harian" << endl;
        cout << "4. Keluar" << endl;
        cout << "Pilih opsi (1-4): ";
        cin >> choice;

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (choice == 1) {
            if (recordCount >= MAX_RECORDS) {
                cout << "Data sudah penuh, tidak dapat menambahkan data baru!" << endl;
                continue;
            }

            cout << "\n--- Input Kondisi Cuaca Harian ---" << endl;
            cout << "Masukkan tanggal (YYYY-MM-DD): ";
            cin >> dates[recordCount];

            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "Masukkan kondisi cuaca (Cerah/Hujan/Berawan): ";
            getline(cin, weatherConditions[recordCount]);

            cout << "Masukkan suhu (celcius): ";
            cin >> temperatures[recordCount];

            cout << "Masukkan total penjualan harian: Rp ";
            cin >> totalSales[recordCount];

            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "Masukkan menu spesial hari ini: ";
            getline(cin, specialMenus[recordCount]);

            recordCount++;
            cout << "Data cuaca berhasil ditambahkan!" << endl;
        }
        else if (choice == 2) {
            if (recordCount == 0) {
                cout << "Belum ada data penjualan." << endl;
                continue;
            }

            cout << "\n--- Catatan Penjualan per Cuaca ---" << endl;
            cout << left << setw(12) << "Tanggal"
                << setw(15) << "Kondisi Cuaca"
                << setw(12) << "Suhu"
                << "Total Penjualan" << endl;
            cout << string(50, '-') << endl;

            for (int i = 0; i < recordCount; i++) {
                cout << left << setw(12) << dates[i]
                    << setw(15) << weatherConditions[i]
                    << setw(12) << temperatures[i]
                    << "Rp " << fixed << setprecision(2) << totalSales[i] << endl;
            }
        }
        else if (choice == 3) {
            cout << "\n--- Laporan Total Pendapatan Harian ---" << endl;
            cout << "Tanggal: 31 Desember 2024" << endl;

            cout << "\nDetail Penjualan Per Menu:\n";
            cout << "1. Mie Ayam Biasa (Rp 15,000)\n"
                << "   - Jumlah terjual: 22 porsi\n"
                << "   - Subtotal: Rp 330,000\n";
            cout << "2. Mie Ayam Pangsit (Rp 20,000)\n"
                << "   - Jumlah terjual: 28 porsi\n"
                << "   - Subtotal: Rp 560,000\n";
            cout << "3. Mie Ayam Bakso (Rp 22,000)\n"
                << "   - Jumlah terjual: 20 porsi\n"
                << "   - Subtotal: Rp 440,000\n";

            cout << "\nPerhitungan:\n";
            cout << "* Total Penjualan Menu = Rp 1,330,000\n";
            cout << "* Pendapatan Tambahan:\n"
                << "  - Minuman = Rp 250,000\n"
                << "  - Topping Tambahan = Rp 125,000\n";
            cout << "* Biaya Operasional Harian = Rp 300,000\n";

            cout << "\nRingkasan Keuangan:\n";
            cout << "* Total Pendapatan Kotor = Rp 1,705,000\n";
            cout << "* Total Biaya = Rp 300,000\n";
            cout << "* Total Pendapatan Bersih = Rp 1,405,000\n";

            cout << "\nCatatan:\n";
            cout << "- Kondisi cuaca: Cerah\n";
            cout << "- Jam operasional: 10:00 - 20:00\n";
            cout << "- Jumlah total pelanggan: 70 orang\n";
        }
        else if (choice == 4) {
            cout << "Terima kasih! Sampai jumpa." << endl;
            break;
        }
        else {
            cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
        }
    }
    return 0;
}
