#include <iostream>
using namespace std;
#pragma warning (disable:4996)

class Imprimanta {
private:
	int nrExemplare;
	char* material;
	int dimensiune;
	static float pret;
public:
	Imprimanta() {
		this->nrExemplare = 0;
		this->material = new char[strlen("na") + 1];
		strcpy(this->material, "na");
		this->dimensiune = 0;
	}
	Imprimanta(int nrexD, const char* matD, int dimensiuneD) {
		if (nrexD > 0)
			this->nrExemplare = nrexD;
		else this->nrExemplare = 0;
		if (strlen(matD) > 2) {
			this->material = new char[strlen(matD) + 1];
			strcpy(this->material, matD);
		}
		else {
			this->material = new char[strlen("na") + 1];
			strcpy(this->material, "na");
		}
		if (dimensiuneD > 0)
			this->dimensiune = dimensiuneD;
		else this->dimensiune = 0;
	}
	Imprimanta(const Imprimanta& sursa) {
		this->dimensiune = sursa.dimensiune;
		this->material = new char[strlen(sursa.material) + 1];
		strcpy(this->material, sursa.material);
		this->nrExemplare = sursa.nrExemplare;
	}
	Imprimanta& operator=(const Imprimanta& sursa) {
		if (this != &sursa) {
			this->dimensiune = sursa.dimensiune;
			this->nrExemplare = sursa.nrExemplare;
			this->material = new char[strlen(sursa.material) + 1];
			strcpy(this->material, sursa.material);
		}
	}
	friend ostream& operator<<(ostream& out, Imprimanta sursa) {
		out << "dimenisune: " << sursa.dimensiune;
		out << "pret: " << sursa.pret;
		out << "nr exemplare: " << sursa.nrExemplare;
		out << "material: " << sursa.material;
		return out;
	}
	float getDimensiune() {
		return this->dimensiune;
	}
	void setMaterial(const char* matD) {
		if (strlen(matD) > 2) {
			this->material = new char[strlen(matD) + 1];
			strcpy(this->material, matD);
		}
		else {
			this->material = new char[strlen("na") + 1];
			strcpy(this->material, "na");
		}
	}
	~Imprimanta() {
		delete[] this->material;
		this->material = nullptr;
	}


	bool operator<(Imprimanta sursa) {
		if (this->nrExemplare < sursa.nrExemplare) {
			return true;
		}
		else return false;
	}
	Imprimanta& operator+=(Imprimanta sursa) {
		this->nrExemplare = sursa.nrExemplare;
		return *this;
	}
};

float Imprimanta::pret = 2;

class ImprimantaDeriv : public Imprimanta {
private:
	bool vandut = false;
public:
	ImprimantaDeriv(){}
	ImprimantaDeriv(int nrexD, const char* matD, int dimensiuneD, bool vD):Imprimanta( nrexD,  matD,  dimensiuneD){
		this->vandut = vD;
	}
	ImprimantaDeriv(const ImprimantaDeriv& sursa):Imprimanta((Imprimanta)sursa) {
		this->vandut = sursa.vandut;
	}
	ImprimantaDeriv& operator=(const ImprimantaDeriv& sursa) {
		if (this != &sursa) {
			Imprimanta::operator=((Imprimanta)sursa);
			this->vandut = sursa.vandut;
		}
		return *this;
	}
	friend ostream& operator<<(ostream& out, ImprimantaDeriv sursa) {
		out << (Imprimanta)sursa;
		out << "vandut: " << sursa.vandut;
		return out;
	}
};



int main() {
	return 0;
}