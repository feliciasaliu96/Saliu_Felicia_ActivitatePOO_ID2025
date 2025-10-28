#include<iostream>
#include<cstring>

using namespace std;

class Floare {
public:
	string nume;
	float inaltime;

	static int nr_flori;
	const string culoare;
	float* pret_bucata;

	Floare() : culoare("necunoscut") {
		nume = "Necunoscut";
		inaltime = 0.0f;
		pret_bucata = new float(0.0f);
		nr_flori++;
	}

	Floare(string n, float i) : culoare("necunoscut") {
		nume = n;
		inaltime = i;
		pret_bucata = new float(0.0f);
		nr_flori++;
	}

	Floare(string n, float i, float pret, string c) : culoare(c) {
		nume = n;
		inaltime = i;
		pret_bucata = new float(pret);
		nr_flori++;
	}

	~Floare() {
		delete pret_bucata;
	}

	static void afiseaza_nr_flori() {
		cout << "Numar total de flori: " << nr_flori << endl;
	}

	void afiseaza() {
		cout << "Floare: " << nume << ", inaltime: " << inaltime << " cm, pret: " << pret_bucata << " lei, culoare: " << culoare << endl;

	}
};