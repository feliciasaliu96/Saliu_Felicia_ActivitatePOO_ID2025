#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>

using namespace std;

class Autobuz {
private:

	static int nrAutobuze;
	const int idAutobuz;
	int capacitate;
	int nrPersoaneImbarcate;
	char* producator;

public:

	Autobuz() :idAutobuz(++nrAutobuze) {

		this->capacitate = 0;
		this->nrPersoaneImbarcate = 0;
		this->producator = new char[strlen("Necunoscut") + 1];
		strcpy(this->producator, "Necunoscut");
	}
	Autobuz(const char* producator, int capacitate, int nrPersoaneImbarcate) :idAutobuz(++nrAutobuze) {

		if (capacitate > 0)
			this->capacitate = capacitate;
		else
		{
			this->capacitate = 0;
			cout << "Eroare: Capacitatea trebuie sa fie mai mare decat 0." << endl;
		}

		if (nrPersoaneImbarcate <= capacitate)
			this->nrPersoaneImbarcate = nrPersoaneImbarcate;
		else
		{
			this->nrPersoaneImbarcate = 0;
			cout << "Eroare: Numarul de persoane imbarcate nu poate depasi capacitatea." << endl;
		}

		this->producator = new char[strlen(producator) + 1];
		strcpy(this->producator, producator);
	}

	Autobuz(const Autobuz& a) :idAutobuz(++nrAutobuze) {

		this->capacitate = a.capacitate;
		this->nrPersoaneImbarcate = a.nrPersoaneImbarcate;
		this->producator = new char[strlen(a.producator) + 1];
		strcpy(this->producator, a.producator);
	}

	~Autobuz() {

		if (this->producator != nullptr)
			delete[] this->producator;
	}

	int getcapacitate() {
		return this->capacitate;
	}

	void setcapacitate(int capacitate) {

		if (capacitate > 0)
			this->capacitate = capacitate;
		else
			throw new exception();
	}

	char* getproducator() {
		return this->producator;
	}

	void setproducator(const char* producator) {

		delete[] this->producator;
		if (producator != nullptr) {
			this->producator = new char[strlen(producator) + 1];
			strcpy(this->producator, producator);
		}
		else
			this->producator = nullptr;

	}

	Autobuz& operator=(const Autobuz& a) {

		if (this == &a)
			return *this;

		if (this->producator != nullptr)
			delete[] this->producator;

		this->producator = new char[strlen(a.producator) + 1];
		strcpy(this->producator, a.producator);
		this->capacitate = a.capacitate;
		this->nrPersoaneImbarcate = a.nrPersoaneImbarcate;

		return *this;
	}

	friend ostream& operator<<(ostream& out, const Autobuz& a) {

		out << "ID:" << a.idAutobuz << "; ";
		out << "Capacitate: " << a.capacitate << "; ";
		out << "Numar persoane imbarcate: " << a.nrPersoaneImbarcate << "; ";
		out << "Producator: " << a.producator << endl;
		return out;
	}

	int getNumarLocuriLibere() {

		int locuriLibere = this->capacitate - this->nrPersoaneImbarcate;
		return locuriLibere;
	}

	operator int() const {
		return this->nrPersoaneImbarcate;
	}

	bool operator>(Autobuz a) {

		return this->capacitate > a.capacitate;
	}

	static int getNrAutobuze() {
		return nrAutobuze;
	}

	const int getidAutobuz() const {
		return this->idAutobuz;
	}

};

int Autobuz::nrAutobuze = 0;

int main()
{
	Autobuz a1("Volkswagen", 20, 15);
	Autobuz a2 = a1;
	cout << a1;
	cout << a2;

	Autobuz a3("Mercedes", 30, 20);
	a3 = a1;
	cout << a3;

	a1.setcapacitate(30);
	cout << "Capacitate actualizata: " << a1.getcapacitate() << endl;

	a2.setproducator("Ford");
	char* producator = a2.getproducator();
	cout << "Producator actualizat: " << producator << endl;

	cout << "Numar locuri libere pentru autobuzul cu ID " << a3.getidAutobuz() << " este: " << a3.getNumarLocuriLibere() << endl;


	int personeImbarcate = (int)a2;
	cout << "Numar persone imbarcate: " << personeImbarcate << endl;

	Autobuz a4("Otokar", 40, 20);
	if (a1 > a4) {
		cout << "Autobuzul a1 are capacitate mai mare decat a4.\n";
	}
	else {
		cout << "Autobuzul a4 are capacitate mai mare sau egala cu a1.\n";
	}

	cout << "Numar autobuze dupa creare: " << Autobuz::getNrAutobuze() << endl;

	return 0;
}