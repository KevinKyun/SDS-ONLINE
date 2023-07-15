#include <iostream>
#include <string>
#include <queue>
using namespace std;

struct Sepatu {
    string nama;
    int harga;
    Sepatu* next;

    Sepatu(string nama, int harga) {
        this->nama = nama;
        this->harga = harga;
        next = nullptr;
    }
};

class Kasir {
private:
    Sepatu* head;

public:
    Kasir() {
        head = nullptr;
    }

    bool is_empty() {
        return head == nullptr;
    }

    void tambahSepatu(string nama, int harga) {
        Sepatu* newSepatu = new Sepatu(nama, harga);
        if (is_empty()) {
            head = newSepatu;
        }
        else {
            Sepatu* current = head;
            while (current->next) {
                current = current->next;
            }
            current->next = newSepatu;
        }
    }

    void tampilkanDaftarSepatu() {
        if (is_empty()) {
            cout << "Tidak ada sepatu yang dijual." << endl;
        }
        else {
            Sepatu* current = head;
            cout << "Daftar Sepatu yang Dijual:" << endl;
            while (current) {
                cout << "Nama: " << current->nama << ", Harga: " << current->harga << endl;
                current = current->next;
            }
        }
    }

    bool cariSepatu(string namaSepatu) {
        Sepatu* current = head;
        while (current) {
            if (current->nama == namaSepatu) {
                return true;
            }
            current = current->next;
        }
        return false;
    }

    void jualSepatu(queue<string>& keranjang) {
        while (!keranjang.empty()) {
            string namaSepatu = keranjang.front();
            keranjang.pop();

            if (cariSepatu(namaSepatu)) {
                cout << "Sepatu " << namaSepatu << " berhasil dibeli." << endl;
            }
            else {
                cout << "Sepatu " << namaSepatu << " tidak tersedia." << endl;
            }
        }
    }
};

int main() {
    Kasir kasir;
    queue<string> keranjang;

    kasir.tambahSepatu("Nike Air Max", 1500000);
    kasir.tambahSepatu("Adidas Ultraboost", 1800000);
    kasir.tambahSepatu("Vans Old Skool", 700000);

    kasir.tampilkanDaftarSepatu();

    keranjang.push("Nike Air Max");
    keranjang.push("Converse Chuck Taylor");
    keranjang.push("Adidas Ultraboost");

    cout << "Membeli sepatu..." << endl;
    kasir.jualSepatu(keranjang);

    return 0;
}
