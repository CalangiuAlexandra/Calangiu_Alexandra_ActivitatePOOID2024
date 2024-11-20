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

    Autobuz(int _capacitate, int _nrPersoaneImbarcate, char* _producator) : idAutobuz(nrAutobuze)
    {
        nrAutobuze++;
        if (_capacitate <= 0) {
            this->capacitate = 1;
        }
        else {
            this->capacitate = _capacitate;
        }

        if (_nrPersoaneImbarcate > _capacitate) {
            this->nrPersoaneImbracate = _capacitate;
        }
        else {
            this->nrPersoaneImbracate = _nrPersoaneImbarcate;
        }

        if (strlen(_producator) == 0) {
            producator = new char[strlen("Neidentificat") + 1];
            strcpy(producator, "Neidentificat");
        }
        else {
            producator = new char[strlen(_producator) + 1];
            strcpy(producator, _producator);
        }
    }

    ~Autobuz()
    {
        delete[] producator;
    }
};

int Autobuz::nrAutobuze = 0;

int main()
{
    Autobuz autobuzFaraParametri = Autobuz();
    Autobuz autobuzCuParametri = Autobuz(15, 1, (char*)"Ford");
}
