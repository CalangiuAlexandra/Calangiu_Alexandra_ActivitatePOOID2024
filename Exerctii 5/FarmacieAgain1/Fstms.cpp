#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;

class Farmacie {
	const int CODUnic;
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


	//Destructor
	~Farmacie() {
		if (preturiMedicamente != nullptr) {
			delete[] this->preturiMedicamente;
		}
	}

	//Constructor copiere

	Farmacie(Farmacie& obj) :CODUnic(obj.nrFarmacii) {
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

	//Getter

	string getAdresa() {
		return this->adresa;
	}

	int getNrMedicamente() {
		return this->nrMedicamente;
	}

	float* getPreturiMedicamente() {
		return this->preturiMedicamente;
	}

	//Setteri

	void setAdresa(string nouaAdresa) {
		this->adresa = nouaAdresa;
	}

	void setMedicamente(int nrNouMedicamente, float* preturiNoiMedicamente) {
		this->nrMedicamente = nrNouMedicamente;
		//alocare
		this->preturiMedicamente = new float[nrMedicamente];
		//initializare
		for (int i = 0; i < nrMedicamente; i++) {
			this->preturiMedicamente[i] = preturiNoiMedicamente[i];
		}
	}

}; int Farmacie::nrFarmacii = 3;

void main() {

	//constructor fara parametrii
	Farmacie f1;
	cout << "Adresa farmaciei: " << f1.getAdresa() << endl;
	cout << "Nr medicamente: " << f1.getNrMedicamente() << endl;
	for (int i = 0; i < f1.getNrMedicamente(); i++) {
		cout << f1.getPreturiMedicamente()[i] << endl;
	}
	cout << endl << endl;
	//constructor cu toti parametrii
	float pretMedicamente[] = { 200.3,50.2,400.3 };
	Farmacie f2("Bulevardul Dacia", 3, pretMedicamente);
	cout << "Adresa farmaciei: " << f2.getAdresa() << endl;
	cout << "Nr medicamente: " << f2.getNrMedicamente() << endl;
	for (int i = 0; i < f2.getNrMedicamente(); i++) {
		cout << f2.getPreturiMedicamente()[i] << endl;
	}
	cout << endl << endl;
	//constructor de copiere
	Farmacie f3(f2);
	cout << "Adresa farmaciei: " << f3.getAdresa() << endl;
	cout << "Nr medicamente: " << f3.getNrMedicamente() << endl;
	for (int i = 0; i < f3.getNrMedicamente(); i++) {
		cout << f3.getPreturiMedicamente()[i] << endl;
	}

	cout << endl << endl;
	//Setteri

	f2.setAdresa("Calea Mosilor");
	cout << "Adresa farmaciei: " << f2.getAdresa() << endl;
	cout << "Nr medicamente: " << f2.getNrMedicamente() << endl;
	for (int i = 0; i < f2.getNrMedicamente(); i++) {
		cout << f2.getPreturiMedicamente()[i] << endl;
	}
	cout << endl << endl;

	float pretMedic[] = { 20.3,50.4 };
	f2.setMedicamente(2, pretMedic);
	cout << "Adresa farmaciei: " << f2.getAdresa() << endl;
	cout << "Nr medicamente: " << f2.getNrMedicamente() << endl;
	for (int i = 0; i < f2.getNrMedicamente(); i++) {
		cout << f2.getPreturiMedicamente()[i] << endl;
	}
	}