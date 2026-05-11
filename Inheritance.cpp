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