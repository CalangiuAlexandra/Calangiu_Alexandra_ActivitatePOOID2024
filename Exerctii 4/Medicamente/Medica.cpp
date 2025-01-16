#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;

class Farmacie {

	string adresa;
	int nrMedicamente;
	float* preturiMedicamente;
	const int codUnic;
	static int nrFarmacii;

public:

	//Constructor fara parametri
	Farmacie():codUnic(nrFarmacii) {
		this->adresa = "Anonima";
		this->nrMedicamente = 0;
		this->preturiMedicamente = nullptr;
		nrFarmacii++;
	}

	//Constructor cu toti parametrii

	Farmacie(string adresa, int nrMedicamente, float* preturiMedicamente):codUnic(nrFarmacii) {
		this->adresa = adresa;
		this->nrMedicamente = nrMedicamente;
		this->preturiMedicamente = new float[nrMedicamente];
		for (int i = 0; i < nrMedicamente; i++) {
			this->preturiMedicamente[i] = preturiMedicamente[i];
		}
		nrFarmacii++;
	}

	//Constructor de copiere

	Farmacie(Farmacie&obj):codUnic(obj.nrFarmacii) {
		this->adresa = obj.adresa;
		this->nrMedicamente = obj.nrMedicamente;
		this->preturiMedicamente = new float[nrMedicamente];
		for (int i = 0; i < nrMedicamente; i++) {
			this->preturiMedicamente[i] = obj.preturiMedicamente[i];
		}
		nrFarmacii++;
	}

	//Destructor

	~Farmacie() {
		if (this->preturiMedicamente != nullptr) {
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

	//Setteri

	void setAdresa(string nouaAdresa) {
		this->adresa = nouaAdresa;
	}

	void setMedicamente(int nrNouMedicamente, float* preturiNoiMedicamente) {
		if (this->preturiMedicamente != nullptr) {
			delete[] this->preturiMedicamente;
		}

		//aloc memorie
		this->nrMedicamente = nrNouMedicamente;
		this->preturiMedicamente = new float[nrMedicamente];
		//initializez
		for (int i = 0; i < nrMedicamente; i++) {
			this->preturiMedicamente[i] = preturiNoiMedicamente[i];
		}
	}


};
int Farmacie::nrFarmacii = 1;



	void main() {

		Farmacie f1;
		cout <<"Adresa farmaciei este:"<< f1.getAdresa() << endl;
		cout << "Nr de medicamente din farmacie: " << f1.getNrMedicamente() << endl;
		for (int i = 0; i < f1.getNrMedicamente(); i++) {
			cout << f1.getPreturiMedicamente()[i] << endl;
		}
		cout << endl << endl;

		//Constructor cu toti parametrii
		float pretMedicament[] = { 50.3,100.2,33.4 };
		Farmacie f2("Bulevardul Dacia",3,pretMedicament);
		cout << "Adresa farmaciei este:" << f2.getAdresa() << endl;
		cout << "Nr de medicamente din farmacie: " << f2.getNrMedicamente() << endl;
		for (int i = 0; i < f2.getNrMedicamente(); i++) {
			cout << f2.getPreturiMedicamente()[i] << endl;
		}

		cout << endl << endl;

		//setteri
		f2.setAdresa("Ciorogarla");
		cout << "Adresa farmaciei este:" << f2.getAdresa() << endl;
		cout << "Nr de medicamente din farmacie: " << f2.getNrMedicamente() << endl;
		for (int i = 0; i < f2.getNrMedicamente(); i++) {
			cout << f2.getPreturiMedicamente()[i] << endl;
		}

		cout << endl << endl;

		cout << "Obiectul f2 deja existent: " << endl;
		float preturiMedicamente2[] = { 20.3,59.5 };
		f2.setMedicamente(2,preturiMedicamente2);
		cout << "Adresa farmaciei este:" << f2.getAdresa() << endl;
		cout << "Nr de medicamente din farmacie: " << f2.getNrMedicamente() << endl;
		for (int i = 0; i < f2.getNrMedicamente(); i++) {
			cout << f2.getPreturiMedicamente()[i] << endl;
		}

		cout << "constructor de copiere" << endl;
		cout << "Obiectul f3 nou creat: " << endl;
		Farmacie f3(f2);
		cout << "Adresa farmaciei este:" << f3.getAdresa() << endl;
		cout << "Nr de medicamente din farmacie: " << f3.getNrMedicamente() << endl;
		for (int i = 0; i < f3.getNrMedicamente(); i++) {
			cout << f3.getPreturiMedicamente()[i] << endl;
		}
	}
