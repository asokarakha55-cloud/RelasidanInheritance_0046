#include <iostream>
#include <vector>
#include <string>
using namespace std;

class User
{
protected:
    static int globalId;
    int id;
    string nama;
    string email;

public:
    User(string n, string e)
    {
        nama = n;
        email = e;
        id = generateId();
    }

    int generateId()
    {
        return ++globalId;
    }
};

int User::globalId = 0;

class Member : public User
{
private:
    bool status;

public:
    Member(string n, string e) : User(n, e)
    {
        status = true;
    }

    bool getStatus() { return status; }
    void setStatus(bool s) { status = s; }
    string getNama() { return nama; }

    void showProfile()
    {
        cout << "--- Profile Member ---" << endl;
        cout << "ID     : " << id << endl;
        cout << "Nama   : " << nama << endl;
        cout << "Email  : " << email << endl;
        cout << "Status : " << (status ? "Aktif" : "Non-Aktif") << endl;
        cout << "----------------------" << endl;
    }
};

class Admin : public User
{
public:
    Admin(string n, string e) : User(n, e) {}

    void showAllMember(vector<Member> &listMember)
    {
        cout << "\n[Admin Panel] Daftar Semua Member:" << endl;
        for (int i = 0; i < listMember.size(); i++)
        {
            cout << i + 1 << ". " << listMember[i].getNama()
                 << " [" << (listMember[i].getStatus() ? "Aktif" : "Non-Aktif") << "]" << endl;
        }
    }

    void toggleActivationMember(Member &m)
    {
        m.setStatus(!m.getStatus());
        cout << "\nStatus member " << m.getNama() << " berhasil diubah!" << endl;
    }
};

int main()
{
    vector<Member> databaseMember;
    databaseMember.push_back(Member("Budi", "budi@email.com"));
    databaseMember.push_back(Member("Santi", "santi@email.com"));
    Admin adminUtama("Ahmad Admin", "admin@email.com");
    databaseMember[0].showProfile();
    adminUtama.showAllMember(databaseMember);
    adminUtama.toggleActivationMember(databaseMember[0]);
    adminUtama.showAllMember(databaseMember);

    return 0;
}