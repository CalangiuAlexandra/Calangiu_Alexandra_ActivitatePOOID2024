#pragma warning (disable: 4996)

#include <iostream>

using namespace std;

class Autobuz {
private:
    static int nrAutobuze;

    const int idAutobuz;
    int capacitate;
    int nrPersoaneImbracate;
    char* producator;
public:
    Autobuz(): idAutobuz(nrAutobuze)
    {
        nrAutobuze++;
        capacitate = 10;
        nrPersoaneImbracate = 0;
        producator = new char[strlen("Mercedes") + 1];
        strcpy(producator, "Mercedes");
    }
};

int Autobuz::nrAutobuze = 0;

int main()
{
    Autobuz autobuzFaraParametri = Autobuz();
}
