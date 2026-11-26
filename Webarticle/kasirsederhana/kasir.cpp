#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

using namespace std;

// Struct untuk menyimpan data menu
struct Menu {
    string nama;
    int harga;
};

int main() {
    // Array menu (bisa diubah sesuai selera)
    vector<Menu> daftarMenu = {
        {"Nasi Goreng", 15000},
        {"Mie Ayam", 12000},
        {"Ayam Geprek", 14000},
        {"Es Teh Manis", 5000},
        {"Es Jeruk", 6000}
    };

    vector<int> keranjangJumlah(daftarMenu.size(), 0); // Keranjang belanja
    int totalBayar = 0;
    int pilihan;
    int jumlah;
    char lanjut;

    // Header Aplikasi
    cout << "========================================\n";
    cout << "        APLIKASI KASIR SEDERHANA        \n";
    cout << "========================================\n";
    cout << "1. Lihat Daftar Menu\n";
    cout << "2. Pesan Makanan/Minuman\n";
    cout << "3. Cetak Struk & Bayar\n";
    cout << "0. Keluar\n";

    do {
        cout << "\nPilih Menu (0-3): ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                // Tampilkan Daftar Menu
                cout << "\n--- DAFTAR MENU ---\n";
                for (size_t i = 0; i < daftarMenu.size(); i++) {
                    cout << i + 1 << ". " << setw(15) << left << daftarMenu[i].nama 
                         << " : Rp " << daftarMenu[i].harga << endl;
                }
                break;

            case 2:
                // Proses Pesanan
                cout << "\nMasukkan nomor menu yang ingin dipesan: ";
                cin >> pilihan;
                if (pilihan > 0 && pilihan <= daftarMenu.size()) {
                    cout << "Masukkan jumlah: ";
                    cin >> jumlah;
                    keranjangJumlah[pilihan - 1] += jumlah;
                    cout << "Berhasil ditambahkan ke keranjang!\n";
                } else {
                    cout << "Menu tidak ditemukan!\n";
                }
                break;

            case 3:
                // Cetak Struk & Pembayaran
                cout << "\n========================================\n";
                cout << "             STRUK BELANJA              \n";
                cout << "========================================\n";
                for (size_t i = 0; i < daftarMenu.size(); i++) {
                    if (keranjangJumlah[i] > 0) {
                        int subtotal = daftarMenu[i].harga * keranjangJumlah[i];
                        cout << setw(15) << left << daftarMenu[i].nama 
                             << " x" << keranjangJumlah[i] 
                             << " = Rp " << subtotal << endl;
                        totalBayar += subtotal;
                    }
                }
                cout << "----------------------------------------\n";
                cout << "TOTAL BAYAR : Rp " << totalBayar << endl;
                cout << "========================================\n";

                if (totalBayar > 0) {
                    int uangBayar;
                    cout << "Masukkan uang bayar: Rp ";
                    cin >> uangBayar;
                    
                    if (uangBayar >= totalBayar) {
                        int kembalian = uangBayar - totalBayar;
                        cout << "Kembalian Anda : Rp " << kembalian << endl;
                        cout << "\nTerima kasih telah berbelanja!\n";
                    } else {
                        cout << "Uang Anda kurang! Transaksi gagal.\n";
                    }
                } else {
                    cout << "Anda belum memesan apapun.\n";
                }
                
                // Reset keranjang
                for (size_t i = 0; i < daftarMenu.size(); i++) {
                    keranjangJumlah[i] = 0;
                }
                totalBayar = 0;
                break;

            case 0:
                cout << "Keluar dari aplikasi. Sampai jumpa!\n";
                break;

            default:
                cout << "Pilihan tidak valid. Coba lagi.\n";
        }

    } while (pilihan != 0);

    return 0;
} 