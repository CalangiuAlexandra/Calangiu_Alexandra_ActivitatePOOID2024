#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;

class Farmacie {

	int const CODUnic;
	string adresa;
	int nrMedicamente;
	float* preturiMedicamente;
	static int nrFarmacii;
public:
	//Constructor fara parametrii
	Farmacie() :CODUnic(nrFarmacii) {
		this->adresa = "Anonima";
		this->nrMedicamente = 0;
		this->preturiMedicamente = nullptr;
		nrFarmacii++;
	}

	//Constructor cu toti parametrii
	Farmacie(string adresa, int nrMedicamente, float* preturiMedicamente) :CODUnic(nrFarmacii) {
		this->adresa = adresa;
		this->nrMedicamente = nrMedicamente;

		//alocare
		this->preturiMedicamente = new float[nrMedicamente];
		//initializare
		for (int i = 0; i < nrMedicamente; i++) {
			this->preturiMedicamente[i] = preturiMedicamente[i];
		}
		nrFarmacii++;
	}

	//Constructor de copiere

	Farmacie(Farmacie& obj):CODUnic(nrFarmacii) {
		this->adresa = obj.adresa;
		this->nrMedicamente = obj.nrMedicamente;

		//alocare
		this->preturiMedicamente = new float[nrMedicamente];
		//initializare
		for (int i = 0; i < nrMedicamente; i++) {
			this->preturiMedicamente[i] = obj.preturiMedicamente[i];
		}

		nrFarmacii++;
	}

	//Destructor

	~Farmacie() {
		if (preturiMedicamente != nullptr) {
			delete[] this->preturiMedicamente;
		}
	}



	//getter

	string getAdresa() {
		return this->adresa;
	}

	int getNrMedicamente() {
		return this->nrMedicamente;
	}

	float* getPreturiMedicamente() {
		return this->preturiMedicamente;
	}

	//setter

	void setAdresa(string nouaAdresa) {
		this->adresa = nouaAdresa;
	}

	void setMedicamente(int nrNouMedicamente, float* preturiNoi) {
		this->nrMedicamente = nrNouMedicamente;
		//sterg memorie
		if (preturiMedicamente != nullptr) {
			delete[] this->preturiMedicamente;
		}
		//alocare
		this->preturiMedicamente = new float[nrNouMedicamente];
		//initializare
		for (int i = 0; i < nrNouMedicamente; i++) {
			this->preturiMedicamente[i] = preturiNoi[i];
		}
	}



}; int Farmacie::nrFarmacii = 1;

void main() {
	cout << "Constructorul fara parametrii: " << endl;
	Farmacie f1;
	cout << "Adresa farmaciei este: " << f1.getAdresa() << endl;
	cout << "Numarul de medicamente este: " << f1.getNrMedicamente() << endl;
	for (int i = 0; i < f1.getNrMedicamente(); i++) {
		cout << "Pretul medicamentelor este: "<<f1.getPreturiMedicamente()[i] << endl;
	}
	cout << endl << endl;

	cout << "Constructorul cu toti parametrii: " << endl;
	float preturiMedicamente2[] = { 100.2,300.3 };
	Farmacie f2("Bulevardul Dacia",2,preturiMedicamente2);

	cout << "Adresa farmaciei este: " << f2.getAdresa() << endl;
	cout << "Numarul de medicamente este: " << f2.getNrMedicamente() << endl;
	for (int i = 0; i < f2.getNrMedicamente(); i++) {
		cout << "Pretul medicamentelor este: " << f2.getPreturiMedicamente()[i] << endl;
	}
	cout << endl << endl;

	cout << "Constructorul de copiere: " << endl;
	float preturiMedicamente3[] = { 500.4,200.3 };
	Farmacie f3(f2);

	cout << "Adresa farmaciei este: " << f3.getAdresa() << endl;
	cout << "Numarul de medicamente este: " << f3.getNrMedicamente() << endl;
	for (int i = 0; i < f3.getNrMedicamente(); i++) {
		cout << "Pretul medicamentelor este: " << f3.getPreturiMedicamente()[i] << endl;
	}
	cout << endl << endl;

	cout << "Setter" << endl;
	float preturiNoiMedicamente[] = { 20.3,50.6,20.7 };
	f2.setMedicamente(3, preturiNoiMedicamente);
	cout << "Adresa farmaciei este: " << f2.getAdresa() << endl;
	cout << "Numarul de medicamente este: " << f2.getNrMedicamente() << endl;
	for (int i = 0; i < f2.getNrMedicamente(); i++) {
		cout << "Pretul medicamentelor este: " << f2.getPreturiMedicamente()[i] << endl;
	}
	cout << endl << endl;


}