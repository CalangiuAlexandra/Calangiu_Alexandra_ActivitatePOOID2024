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

    Autobuz(const Autobuz& altAutobuz): idAutobuz(altAutobuz.idAutobuz+1)
    {
        nrAutobuze++;
        this->capacitate = altAutobuz.capacitate;
        this->nrPersoaneImbracate = altAutobuz.nrPersoaneImbracate;

        this->producator = new char[strlen(altAutobuz.producator) + 1];
        strcpy(this->producator, altAutobuz.producator);
    }

    ~Autobuz()
    {
        delete[] producator;
    }

    char* getProducator()
    {
        return producator;
    }

    void setProducator(char* altProducator)
    {
        delete[] producator;
        producator = new char[strlen(altProducator) + 1];
        strcpy(producator, altProducator);
    }

    int getCapacitate()
    {
        return capacitate;
    }

    int setCapacitate(int capacitateNoua)
    {
        capacitate = capacitateNoua;
    }

    int numarLocuriLibere()
    {
        if (nrPersoaneImbracate > capacitate) {
            return 0;
        }
        else {
            return capacitate - nrPersoaneImbracate;
        }
    }

    Autobuz& operator=(const Autobuz& altAutobuz)
    {
        if (this != &altAutobuz) {
            delete[] producator;

            this->capacitate = altAutobuz.capacitate;
            this->nrPersoaneImbracate = altAutobuz.nrPersoaneImbracate;

            this->producator = new char[strlen(altAutobuz.producator) + 1];
            strcpy(this->producator, altAutobuz.producator);
        }

        return *this;
    }

    friend std::ostream& operator<<(std::ostream& os, const Autobuz& autobuz);

    explicit operator int()
    {
        return nrPersoaneImbracate;
    }

    bool operator>(const Autobuz& altAutobuz)
    {
        return this->capacitate > altAutobuz.capacitate;
    }
};

std::ostream& operator<<(std::ostream& os, const Autobuz& autobuz)
{
    os << autobuz.idAutobuz << ";" << autobuz.capacitate << ";" << autobuz.nrPersoaneImbracate << ";" << autobuz.producator << endl;

    return os;
}

int Autobuz::nrAutobuze = 0;

int main()
{
    Autobuz autobuzFaraParametri = Autobuz();
    Autobuz autobuzCuParametri = Autobuz(15, 1, (char*)"Ford");
    Autobuz autobuzCopie = autobuzCuParametri;

    cout << "Autobuz produse de: " << autobuzFaraParametri.getProducator() << " cu capacitatea de: " << autobuzFaraParametri.getCapacitate() << " pasageri." << endl;
    cout << "Autobuz produse de: " << autobuzCuParametri.getProducator() << " cu capacitatea de: " << autobuzCuParametri.getCapacitate() << " pasageri." << endl;
    cout << "Autobuz produse de: " << autobuzCopie.getProducator() << " cu capacitatea de: " << autobuzCopie.getCapacitate() << " pasageri." << endl;

    autobuzCopie = autobuzFaraParametri;
    cout << "Autobuz produse de: " << autobuzCopie.getProducator() << " cu capacitatea de: " << autobuzCopie.getCapacitate() << " pasageri." << endl;

    cout << autobuzFaraParametri;
    cout << autobuzCuParametri.numarLocuriLibere() << endl;
    cout << "Numarul de persoane imbarcate este: " << (int)autobuzCopie << endl;

    int maiMare = autobuzFaraParametri > autobuzCuParametri;
    if (maiMare) {
        cout << "Autobuzul fara parametri e mai mare ca cel cu parametri";
    }
    else {
        cout << "Autobuzul fara parametri nu e mai mare ca cel cu parametri";
    }
}
