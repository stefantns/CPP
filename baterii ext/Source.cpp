#include <iostream>
using namespace std;
#pragma warning (disable:4996)

class BateriiExt {
private:
	float greutate;
	char* producator;
	float nivel;
	const int id;
	static int contor;
public:
	BateriiExt():id(BateriiExt::contor++) {
		this->greutate = 0;
		this->producator = new char[strlen("na") + 1];
		strcpy(this->producator, "na");
		this->nivel = 0;
	}
	BateriiExt(float greutateD,const char* producatorD,float nivelD):id(BateriiExt::contor++) {
		if (greutateD > 0) {
			this->greutate = greutateD;
		}
		else this->greutate = 0;
		if (strlen(producatorD) > 2) {
			this->producator = new char[strlen(producatorD) + 1];
			strcpy(this->producator, producatorD);
		}
		else {
			this->producator = new char[strlen("na") + 1];
			strcpy(this->producator, "na");
		}
		if (nivelD > 0) {
			this->nivel = nivelD;
		}
		else this->nivel = 0;
	}
	BateriiExt(const BateriiExt& sursa) :id(BateriiExt::contor++) {
		this->greutate = sursa.greutate;
		this->producator = new char[strlen(sursa.producator) + 1];
		strcpy(this->producator, sursa.producator);
		this->nivel = sursa.nivel;
	}
	BateriiExt& operator=(const BateriiExt& sursa) {
		if (this != &sursa) {
			delete[] this->producator;
			this->greutate = sursa.greutate;
			this->producator = new char[strlen(sursa.producator) + 1];
			strcpy(this->producator, sursa.producator);
			this->nivel = sursa.nivel;
		}
		return *this;
	}
	~BateriiExt() {
		delete[] this->producator;
		this->producator = nullptr;
		BateriiExt::contor--;
	}
	float getGreutate(){
		return this->greutate;
	}
	void setNivel(float nivelD){
		if(nivelD > 0){
			this->nivel=nivelD;
		}
		else this->nivel=0;
	}


	BateriiExt& operator+=(float val) {
		this->nivel += val;
		return *this;
	}
	BateriiExt& operator-=(float val) {
		this->nivel -= val;
		return *this;
	}
	bool operator==(BateriiExt sursa) {
		if (this->greutate == sursa.greutate) {
			if (strcmp(this->producator, sursa.producator) == 0) {
				if (this->nivel = sursa.nivel) {
					return true;
				}
				else return false;
			}
			else return false;
		}
		else return false;
	}




	friend ostream& operator<<(ostream& out, BateriiExt sursa) {
		out << "id: " << sursa.id << endl;
		out << "greutate: " << sursa.greutate << endl;
		out << "nivel: " << sursa.nivel << endl;
		out << "producator: " << sursa.producator << endl;
		return out;
	}





};
int BateriiExt::contor = 0;





class BEB :public BateriiExt {
private:
	int anFab;
public:
	BEB() {
		this->anFab = 1965;
	}
	BEB(float greutateD, const char* producatorD, float nivelD, int anfabD) :BateriiExt(greutateD, producatorD, nivelD) {
		if (anfabD > 1965)
		{
			this->anFab = anfabD;
		}
		else this->anFab = 1965;
	}
	BEB(const BEB& sursa) :BateriiExt((BateriiExt)sursa) {
		this->anFab = sursa.anFab;
	}
	BEB& operator=(const BEB& sursa) {
		if (this != &sursa) {
			BateriiExt::operator=((BateriiExt)sursa);
			this->anFab = sursa.anFab;
		}
		return *this;
	}
	~BEB() {}
	friend ostream& operator<<(ostream& out, BEB sursa) {
		out << (BateriiExt)sursa;
		out << "an fabricatie: " << sursa.anFab << endl;
		return out;
	}
};






int main() {
	BateriiExt b1;
	cout << b1;
	BateriiExt b2(25, "stefansrl", 85);
	cout << b2;
	BateriiExt b3(b2);
	cout << b3;
	BateriiExt b4 = b3;
	cout << b4;
	BateriiExt b5;
	cout << b5;
	BEB b6;
	cout << b6;
	
	return 0;
}