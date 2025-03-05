#include <iostream>
using namespace std;
#pragma warning (disable:4996)

class Locuinte {
private:
	float suprafata;
	int nrCamere;
	const int id;
	static int contor;
	char* numeLocalitate;
public:
	Locuinte():id(Locuinte::contor++) {
		this->suprafata = 0;
		this->nrCamere = 0;
		this->numeLocalitate = new char[strlen("na") + 1];
		strcpy(this->numeLocalitate, "na");
	}
	Locuinte(float suprafataDat, int nrCamereDat, const char* numeLocalitateDat) :id(Locuinte::contor++) {
		if (suprafataDat > 2) {
			this->suprafata = suprafataDat;
		}
		else this->suprafata = 0;
		if (nrCamereDat > 2) {
			this->nrCamere = nrCamereDat;
		}
		else this->nrCamere = 0;
		if (strlen(numeLocalitateDat) > 2) {
			this->numeLocalitate = new char[strlen(numeLocalitateDat) + 1];
			strcpy(this->numeLocalitate, numeLocalitateDat);
		}
		else {
			this->numeLocalitate = new char[strlen("na") + 1];
			strcpy(this->numeLocalitate, "na");
		}
	}
	Locuinte(const Locuinte& sursa): id(Locuinte::contor++) {
		this->suprafata = sursa.suprafata;
		this->nrCamere = sursa.nrCamere;
		this->numeLocalitate = new char[strlen(sursa.numeLocalitate) + 1];
		strcpy(this->numeLocalitate, sursa.numeLocalitate);
	}
	Locuinte& operator=(const Locuinte& sursa) {
		if (this != &sursa) {
			delete[] this->numeLocalitate;
			this->suprafata = sursa.suprafata;
			this->nrCamere = sursa.nrCamere;
			this->numeLocalitate = new char[strlen(sursa.numeLocalitate) + 1];
			strcpy(this->numeLocalitate, sursa.numeLocalitate);
		}
		return *this;
	}
	~Locuinte() {
		delete[] this->numeLocalitate;
		this->numeLocalitate = nullptr;
	}
	friend ostream& operator<<(ostream& out,Locuinte sursa) {
		out << "id: " << sursa.id << endl;
		out << "suprafata: " << sursa.suprafata << endl;
		out << "nr camere: " << sursa.nrCamere << endl;
		out << "nume localitate: " << sursa.numeLocalitate << endl;

		return out;
	}

	Locuinte operator+(int val) {
		Locuinte copie(*this);
		copie.nrCamere += 10;
		return copie;
	}


	//operator functie
	bool operator()(int nrLocatari) {
		if (nrLocatari <= this->nrCamere) {
			return true;
		}
		else return false;
	}
	//operator ==
	bool operator==(Locuinte sursa) {
		if (this->suprafata == sursa.suprafata) {
			if (this->nrCamere == sursa.nrCamere) {
				if (strcmp(this->numeLocalitate, sursa.numeLocalitate) == 0) {
					return true;
				}
				else return false;
			}
			else return false;
		}
		else return false;
	}
	

};

class LocuinteDerivat : public Locuinte {
private:
	bool baieProprie = false;
public:
	LocuinteDerivat() {}; // constr fara parm
	LocuinteDerivat(float suprafataDat,int nrCamereDat, const char* numeLocalitateDat,bool baieDat) :Locuinte(suprafataDat, nrCamereDat, numeLocalitateDat) {
		this->baieProprie = baieDat;
	}
	LocuinteDerivat(const LocuinteDerivat& sursa) :Locuinte((Locuinte)sursa) {
		this->baieProprie = sursa.baieProprie;
	}
	LocuinteDerivat& operator=(const LocuinteDerivat& sursa) {
		if (this != &sursa) {
			Locuinte::operator=((Locuinte)sursa);
			this->baieProprie = sursa.baieProprie;
		}
		return *this;
	}
	~LocuinteDerivat() {}
	friend ostream& operator<<(ostream& out, LocuinteDerivat sursa) {
		out << (Locuinte)sursa;
		out << sursa.baieProprie << endl;
		return out;
	}


};

int Locuinte::contor = 0;


int main() {
	Locuinte l1;
	cout << "locuinta 1" << endl << l1 << endl;
	Locuinte l2(1200, 5, "Gaesti");
	cout << "locuinta 2 constr cu param " << endl << l2 << endl;
	Locuinte l3(l2);
	cout << "locuinta 3 copiere cu l2" << endl << l3 << endl;
	Locuinte l4 = l3;
	cout << "Locuinta 4 operator = cu l3" << endl << l4 << endl;
	cout << l2(5) << endl;
	cout << (l2 == l1) << endl;
	LocuinteDerivat l5(1600,4,"buc",1);
	cout << l5;
	LocuinteDerivat l8(l5);
	cout << l8;
	cout << l3 + 2;
	return 0;
}