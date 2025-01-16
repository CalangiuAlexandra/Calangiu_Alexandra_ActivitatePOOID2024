#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<string>
using namespace std;


class Corabie {
	int capacitate;
	float suprafataMedie;
	int nrPersoaneImbarcate;
	int* varstePasageri;
	static int nrCorabii;

public:

	//Constructor fara parametrii
	Corabie() {
		this->capacitate = 0;
		this->suprafataMedie = 0;
		this->nrPersoaneImbarcate = 0;
		this->varstePasageri = nullptr;
	}

	//Constructor cu toti parametrii

	Corabie(int capacitate, float suprafataMedie,int nrPersoaneImbarcate, int* varstePasageri) {
		this->capacitate = capacitate;
		this->suprafataMedie = suprafataMedie;
		if (nrPersoaneImbarcate > capacitate) {
			cout << "Se depaseste limita: " << endl;
			this->nrPersoaneImbarcate = capacitate;
		}
		else {
			this->nrPersoaneImbarcate = nrPersoaneImbarcate;
		}
		//alocare de memorie
		this->varstePasageri = new int[nrPersoaneImbarcate + 1];
		//initializare
		for (int i = 0; i < nrPersoaneImbarcate; i++) {
			this->varstePasageri[i] = varstePasageri[i];
		}
	}

	//Getteri
	
	int getCapacitate() {
		return this->capacitate;
	}

	float getSuprafataMedie() {
		return this->suprafataMedie;
	}

	int getNrPersoaneImbarcate() {
		return this->nrPersoaneImbarcate;
	}

	int* getVarstePasageri() {
		return this->varstePasageri;
	}

	//Setteri
	void setCapacitate(int nouaCapacitate) {
		this->capacitate = nouaCapacitate;
	}

	void setSuprafataMedie(float nouaSuprafataMedie) {
		this->suprafataMedie = nouaSuprafataMedie;
	}

	void setPersoaneImbarcate(int noulNrPersoaneImbarcate,int* noileVarstePasageri) {
		//dezaloc memorie
		if (varstePasageri != NULL) {
			delete[] this->varstePasageri;
		}
		//
		this->nrPersoaneImbarcate = noulNrPersoaneImbarcate;
		this->varstePasageri = new int[nrPersoaneImbarcate];
		for (int i = 0; i < this->nrPersoaneImbarcate; i++) {
			this->varstePasageri[i] = noileVarstePasageri[i];
		}
	}


	//Destructor
	~Corabie() {
		if (varstePasageri != NULL) {
			delete[] this->varstePasageri;
		}
	}
};

int Corabie::nrCorabii = 5;

void main()
{
	//Constructor fara parametri

	Corabie c1;
	cout << c1.getCapacitate() << endl;
	cout << c1.getSuprafataMedie() << endl;
	cout << c1.getNrPersoaneImbarcate() << endl;
	//pentru pointer
	for (int i = 0; i < c1.getNrPersoaneImbarcate(); i++) {
		cout << c1.getVarstePasageri()[i] << endl;
	}
	cout << endl << endl;


	//constructor cu toti parametrii
	int varstelePasagerilor[] = {27,20,15};
	Corabie c2(30, 100.2, 3, varstelePasagerilor);
	cout << c2.getCapacitate() << endl;
	cout << c2.getSuprafataMedie() << endl;
	cout << c2.getNrPersoaneImbarcate() << endl;
	//pentru pointer
	for (int i = 0; i < c2.getNrPersoaneImbarcate(); i++) {
		cout << c2.getVarstePasageri()[i] << " ";
	}

	//setteri
	cout << endl << endl;
	cout << "Dupa modificare" << endl;
	c1.setCapacitate(3);
	c1.setSuprafataMedie(200.3);
	int persoane[] = { 10,3 };
	c1.setPersoaneImbarcate(2, persoane);
	cout << c1.getCapacitate() << endl;
	cout << c1.getSuprafataMedie() << endl;
	cout << c1.getNrPersoaneImbarcate() << endl;
	//pentru pointer
	for (int i = 0; i < c1.getNrPersoaneImbarcate(); i++) {
		cout << c1.getVarstePasageri()[i] << " ,";
	}
	
  
}
