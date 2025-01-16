#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;

class Corabie {

	int static nrCorabii;
	int capacitate;
	int nrPersoaneImbarcate;
	int* varstePasageri;
	string denumireCorabie;

public:
	//Constructor fara parametri
	Corabie() {
		this->capacitate = 0;
		this->nrPersoaneImbarcate = 0;
		this->varstePasageri = nullptr;
	}

	//Constructor cu toti parametrii
	Corabie(int capacitate, int nrPersoaneImbarcate, int* varstePasageri) {
		this->capacitate = capacitate;
		if (nrPersoaneImbarcate > capacitate) {
			cout << "Se atinge limita" << endl;
			nrPersoaneImbarcate = capacitate;
		}
		else {
			this->nrPersoaneImbarcate = nrPersoaneImbarcate;
		}
		//alocare memorie
		this->varstePasageri = new int[nrPersoaneImbarcate];
		//initializare
		for (int i = 0; i < nrPersoaneImbarcate; i++) {
			this->varstePasageri[i] = varstePasageri[i];
		}
		this->denumireCorabie = denumireCorabie;
	}

	//Constructor de copiere

	Corabie(Corabie& obj) {
		this->capacitate = obj.capacitate;
		this->nrPersoaneImbarcate = obj.nrPersoaneImbarcate;
		//alocare memorie
		this->varstePasageri = new int[nrPersoaneImbarcate];
		//initializare
		for (int i = 0; i < nrPersoaneImbarcate; i++) {
			this->varstePasageri[i] = obj.varstePasageri[i];
		}
		this->denumireCorabie = obj.denumireCorabie;
	}

	//Destructor
	~Corabie() {
		if (varstePasageri != nullptr) {
			delete this->varstePasageri;
		}
	}

	//getteri

	int getCapacitate() {
		return this->capacitate;
	}
	int getNrPersoaneImbarcate() {
		return this->nrPersoaneImbarcate;
	}

	int* getVarstePasageri() {
		return this->varstePasageri;
	}

	//Setteri
	void setCapacitate(int Capacitate) {
		this->capacitate = Capacitate;
	}

	void setPasageri(int nrNoiPersoaneImbarcate, int* varsteNoiPasageri) {
		this->nrPersoaneImbarcate = nrNoiPersoaneImbarcate;
		if (this->varstePasageri != nullptr) {
			delete[]varstePasageri;
		}
		this->varstePasageri = new int[nrPersoaneImbarcate];
		for (int i = 0; i < nrPersoaneImbarcate; i++) {
			this->varstePasageri[i] = varsteNoiPasageri[i];
		}
	}
}; int Corabie::nrCorabii = 3;

void main() {
	//Constructor fara param
	Corabie c1;
	cout << "Capacitate corabie: " << c1.getCapacitate() << endl;
	cout << "Nr persoane imbarcate: " << c1.getNrPersoaneImbarcate() << endl;
	for (int i = 0; i < c1.getNrPersoaneImbarcate(); i++) {
		cout << "Varstele pasagerilor: "<<c1.getVarstePasageri()[i] << endl;
	}
	cout << endl << endl;
	//Constructor cu toti parametrii
	int varstePersoane[] = { 10,3};
	Corabie c2(3, 2, varstePersoane);
	cout << "Capacitate corabie: " << c2.getCapacitate() << endl;
	cout << "Nr persoane imbarcate: " << c2.getNrPersoaneImbarcate() << endl;
	for (int i = 0; i < c2.getNrPersoaneImbarcate(); i++) {
		cout << "Varstele pasagerilor: " << c2.getVarstePasageri()[i] << endl;
	}

	cout << endl << endl;
	//Constructor de copiere

	Corabie c3(c2);
	cout << "Capacitate corabie: " << c3.getCapacitate() << endl;
	cout << "Nr persoane imbarcate: " << c3.getNrPersoaneImbarcate() << endl;
	for (int i = 0; i < c3.getNrPersoaneImbarcate(); i++) {
		cout << "Varstele pasagerilor: " << c3.getVarstePasageri()[i] << endl;
	}

	//Setter
	cout << endl << endl;
	c2.setCapacitate(4);
	cout << "Capacitate corabie: " << c2.getCapacitate() << endl;
	cout << "Nr persoane imbarcate: " << c2.getNrPersoaneImbarcate() << endl;
	for (int i = 0; i < c2.getNrPersoaneImbarcate(); i++) {
		cout << "Varstele pasagerilor: " << c2.getVarstePasageri()[i] << endl;
	}

	cout << endl << endl;
	int varstePasageri2[] = { 5,4,22 };
	c2.setPasageri(3, varstePasageri2);
	cout << "Capacitate corabie: " << c2.getCapacitate() << endl;
	cout << "Nr persoane imbarcate: " << c2.getNrPersoaneImbarcate() << endl;
	for (int i = 0; i < c2.getNrPersoaneImbarcate(); i++) {
		cout << "Varstele pasagerilor: " << c2.getVarstePasageri()[i] << endl;
	}
}