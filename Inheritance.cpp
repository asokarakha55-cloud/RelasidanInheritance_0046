#include <iostream>
#include <string>
using namespace std;

class orang
{
public:
    string nama;
    orang(string pNama) : nama(pNama)
    {
        cout << "orang \"" << nama << "\"ada\n";
    }
    ~orang()
    {
        cout << "orang \"" << nama << "\"tidak ada\n";
    }

    int jumlah(int a, int b)
    {
        return a + b;
    }
};

class pelajar : public orang
{
public:
    string sekolah;
    pelajar(string pNama, string pSekolah) : orang(pNama), sekolah(pSekolah)
    {
        cout << "pelajar dibuat\n"
             << endl;
    }
    ~pelajar()
    {
        cout << "pelajar dihapus\n"
             << endl;
    }
};
