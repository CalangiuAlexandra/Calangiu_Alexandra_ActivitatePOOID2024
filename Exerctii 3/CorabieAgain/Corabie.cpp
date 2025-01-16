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

	//Constructor fara parametrii
public:
	Corabie() {
		this->capacitate = 0;
		this->nrPersoaneImbarcate = 0;
		this->varstePasageri = nullptr;
		this->denumireCorabie = "Anonima";
	}

	//Constructor cu toti parametrii
	Corabie(int capacitate, int nrPersoaneImbarcate, int* varstePasageri, string denumireCorabie) {
		this->capacitate = capacitate;
		if (nrPersoaneImbarcate > capacitate) {
			cout << "Limita este depasita" << endl;
			nrPersoaneImbarcate = capacitate;
		}
		else {
			this->nrPersoaneImbarcate = nrPersoaneImbarcate;
		}
		this->varstePasageri = new int[nrPersoaneImbarcate];
		for (int i = 0; i < nrPersoaneImbarcate; i++) {
			this->varstePasageri[i] = varstePasageri[i];
		}
		this->denumireCorabie = denumireCorabie;
	}

	//Constructor de copiere

	Corabie(Corabie& obj) {
		this->capacitate = obj.capacitate;
		this->nrPersoaneImbarcate = obj.nrPersoaneImbarcate;
		this->varstePasageri = new int[nrPersoaneImbarcate];
		for (int i = 0; i < nrPersoaneImbarcate; i++) {
			this->varstePasageri[i] = obj.varstePasageri[i];
		}
		this->denumireCorabie = obj.denumireCorabie;
	}

	//Destructor

	~Corabie() {
		if (varstePasageri != nullptr) {
			delete[] this->varstePasageri;
		}
	}

	//getter

	int getCapacitate() {
		return this->capacitate;
	}
	int getNrPersoaneImbarcate() {
		return this->nrPersoaneImbarcate;
	}
	int* getVarstePasageri() {
		return this->varstePasageri;
	}
	string getDenumireCorabie() {
		return this->denumireCorabie;
	}

	//setter

	void setCapacitate(int nouaCapacitate) {
		this->capacitate = nouaCapacitate;
	}

	void setPasageri(int nrNouPasageri, int* noileVarste) {
		this->nrPersoaneImbarcate = nrNouPasageri;
		if (this->varstePasageri != nullptr) {
			delete[] this->varstePasageri;
		}
		this->varstePasageri = new int[nrNouPasageri];
		
		for (int i = 0; i < nrNouPasageri; i++) {
			this->varstePasageri[i] = noileVarste[i];
		}
	}


}; int Corabie::nrCorabii = 3;

void main() {

	cout << "Constructor fara parametrii: " << endl;
	Corabie c1;
	cout << "Capacitate corabie: "<<c1.getCapacitate() << endl;
	cout << "Persoane imbarcate: "<<c1.getNrPersoaneImbarcate() << endl;
	for (int i = 0; i < c1.getNrPersoaneImbarcate(); i++) {
		cout << "Varste persoane"<<c1.getVarstePasageri()[i] << endl;
	}
	cout << "Denumire corabie"<<c1.getDenumireCorabie() << endl;

	cout << endl << endl;
	cout << "Constructor cu parametrii: " << endl;
	int varstelePasagerilor[] = { 20,5,10 };
	Corabie c2(5,3,varstelePasagerilor,"Alexuta");
	cout << "Capacitate corabie: " << c2.getCapacitate() << endl;
	cout << "Persoane imbarcate: " << c2.getNrPersoaneImbarcate() << endl;
	for (int i = 0; i < c2.getNrPersoaneImbarcate(); i++) {
		cout << "Varste persoane" << c2.getVarstePasageri()[i] << endl;
	}
	cout << "Denumire corabie" << c2.getDenumireCorabie() << endl;

	cout << endl << endl;

	cout << "Constructor de copiere: " << endl;
	Corabie c3(c2);
	cout << "Capacitate corabie: " << c3.getCapacitate() << endl;
	cout << "Persoane imbarcate: " << c3.getNrPersoaneImbarcate() << endl;
	for (int i = 0; i < c3.getNrPersoaneImbarcate(); i++) {
		cout << "Varste persoane" << c3.getVarstePasageri()[i] << endl;
	}
	cout << "Denumire corabie" << c3.getDenumireCorabie() << endl;

	cout << endl << endl;
	cout << "Setteri" << endl;
	c2.setCapacitate(2);
	cout << "Capacitate corabie: " << c2.getCapacitate() << endl;
	cout << "Persoane imbarcate: " << c2.getNrPersoaneImbarcate() << endl;
	for (int i = 0; i < c2.getNrPersoaneImbarcate(); i++) {
		cout << "Varste persoane" << c2.getVarstePasageri()[i] << endl;
	}
	cout << "Denumire corabie" << c2.getDenumireCorabie() << endl;

	cout << endl << endl;



}

