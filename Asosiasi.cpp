#include <iostream>
#include <vector>
using namespace std;

class dokter;
class pasien
{
public:
    string nama;
    vector<dokter *> daftar_dokter;

    pasien(string pNama) : nama(pNama)
    {
        cout << "pasien \"" << nama << "\"ada\n";
    }
    ~pasien()
    {
        cout << "pasien \"" << nama << "\"tidak ada\n";
    }
};