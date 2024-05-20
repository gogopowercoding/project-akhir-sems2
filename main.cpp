#include <iostream>
#include <fstream>
#include <algorithm>//deklarasi library//
using namespace std;
char files [][99] = {"lagu1.txt", "lagu2.txt", "lagu3.txt"};//deklarasi arrray untuk nama file//
string toLower(const string &str) {
    string lowerStr = str;
    transform(lowerStr.begin(), lowerStr.end(), lowerStr.begin(), ::tolower);
    return lowerStr;
}//deklarasi agar program menjadi insensitive//

void cariLirik(const string &cari) {
    bool ditemukan = false;
    string cariLower = toLower(cari); //mengubah agar pencarian menjadi insensitive//
    for (int i = 0; i < 99 ; i++) { // rekursif untuk mengecek semua file yang ada// note: ganti variabel rekursif dengan maksimal jumlah file yang ada//
        ifstream MyFile(files[i]);//membuka dan membaca file//
        if (MyFile.is_open()) {
            string line;
            while (getline(MyFile, line)) {
                string lineLower = toLower(line); // megubah pembacaan file agar menjadi insensitive //
                if (lineLower.find(cariLower) != string::npos) {//jika pencarian ditemukan maka akan menampilkan seluruh lirik pada file tersebut//
                    MyFile.close();
                    ifstream MyFile(files[i]);//program ditutup lagi lalu dibuka lagi untuk menampilkan keseluruhan lirik//
                    while (getline(MyFile, line)) {
                        cout << line << endl;//menampilkan file//
                    }
                    ditemukan = true;
                }
            }
            MyFile.close();//menutup file//
        }
    }
    if (!ditemukan) {//jika pencarian tidak ditemukan//
        cout << "Lirik tidak ditemukan";
    }
}
int main() {
    string lirik;
    cout << "Masukkan Lirik: ";
    getline(cin, lirik);
    cariLirik(lirik);
    return 0;
}
