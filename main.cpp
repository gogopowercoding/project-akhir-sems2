#include <iostream>
#include <ifstream>

struct data_lagu{
int kode;
char judul;	
string lirik;
};
data_lagu lagu[1000];

int ulang = 0;

void binarySearch(data_lagu *lagu, int& ulang, int target) {
    bool ditemukan = false;
    int kiri = 0;
    int kanan = ulang - 1;
    int tengah;
    while (kiri <= kanan) {
		// Jika target ditemukan di tengah
        tengah = kiri + (kanan - kiri) / 2;
        if (lagu[tengah].kode == target) {
			cout<<"---------------------------------------"<<endl;
			cout<<"|            BINARY SEARCH            |"<<endl;
			cout<<"---------------------------------------"<<endl;
            cout<<"Kode Lagu\t : "<<lagu[tengah].kode<<endl;
            cout<<"Judul Lagu\t: "<<lagu[tengah].judul<<endl;
            cout<<"Lirik lagau : "<<endl<<lagu[tengah].lirik<<endl;
           
            ditemukan = true;
            break;
        }
        // Jika target lebih besar, cari di setengah kiri
        else if (lagu[tengah].kode < target) {
            kiri = tengah + 1;
        }
        // Jika target lebih kecil, cari di setengah kanan
        else {
            kanan = tengah - 1;
        }
    }   
			if (!ditemukan) {
				cout << "Judul lagu tidak ditemukan." << endl;
			}
}

