#include <iostream>
#include <fstream>
#include <algorithm>
#include <pybind11/pybind11.h>

namespace py = pybind11;

using namespace std;
string files[99] = {"lagu1.txt", "lagu2.txt", "lagu3.txt"};//deklarasi arrray untuk nama file//
string toLower(const string &str) {
    string lowerStr = str;
    transform(lowerStr.begin(), lowerStr.end(), lowerStr.begin(), ::tolower);
    return lowerStr;
}//deklarasi agar program menjadi insensitive//

string cariLirik(const string &cari) {
    bool ditemukan = false;
    string judul;
    string cariLower = toLower(cari); //mengubah agar pencarian menjadi insensitive//
    for (int i = 0; i < 99 ; i++) { 
      // rekursif untuk mengecek semua file yang ada/
        ifstream MyFile(files[i]);
	
	//membuka dan membaca file//
        if (MyFile.is_open()) {
            string line;
            while (getline(MyFile, line)) {
                string lineLower = toLower(line); 
                if (lineLower.find(cariLower) != string::npos) {
		  //jika pencarian ditemukan maka akan menampilkan seluruh lirik pada file tersebut//
                    MyFile.close();
		    judul = files[i];
                    ditemukan = true;
                }
            }
            MyFile.close();//menutup file//
        }
    }
    if (!ditemukan) {//jika pencarian tidak ditemukan//
      return "";
    }
    return judul;
}


void tambahLagu(string judul, string lirik){
  ofstream file_judul("lagu.txt", ios::app);
  file_judul << judul << endl;
  file_judul.close();
  
  ofstream file_lirik("lirik/" + judul + ".txt");
  file_lirik << lirik << endl;
  file_lirik.close();
}

int main() {
    string lirik;
    cout << "Masukkan Lirik: ";
    getline(cin, lirik);
    cariLirik(lirik);
    return 0;
}


PYBIND11_MODULE(cpp, handle){
  handle.doc() = "Save songs and lyrics!";
  handle.def("tambah_lagu", &tambahLagu);
}



