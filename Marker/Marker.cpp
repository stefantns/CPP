#include <iostream>
using namespace std;
#pragma warning(disable:4996)
class Marker {
private:
	string culoare;
	char* producator;
	float nivelCurent;
	static float pret;
public:
	Marker() {
		this->culoare = "-";
		this->producator = new char[strlen("na") + 1];
		strcpy(this->producator, "na");
		this->nivelCurent = 0;
	}
	Marker(string culoareD, const char* producatorD, float nivelD) {
		if (culoareD.length() > 2) {
			this->culoare = culoareD;
		}
		else this->culoare = "-";
		if (strlen(producatorD) > 2) {
			this->producator = new char[strlen(producatorD) + 1];
			strcpy(this->producator, producatorD);
		}
		else {
			this->producator = new char[strlen("na") + 1];
			strcpy(this->producator, "na");
		}
		if (nivelD > 0) {
			this->nivelCurent = nivelD;
		}
		else this->nivelCurent = 0;
	}
	Marker(const Marker& sursa) {
		this->culoare = sursa.culoare;
		this->producator = new char[strlen(sursa.producator) + 1];
		strcpy(this->producator, sursa.producator);
		this->nivelCurent = sursa.nivelCurent;
	}
	Marker& operator=(const Marker& sursa) {
		if (this != &sursa) {
			delete[] this->producator;
			this->culoare = sursa.culoare;
			this->producator = new char[strlen(sursa.producator) + 1];
			strcpy(this->producator, sursa.producator);
			this->nivelCurent = sursa.nivelCurent;
		}
		return *this;
	}
	~Marker() {
		delete[] this->producator;
		this->producator = nullptr;
	}
	friend ostream& operator<<(ostream& out, Marker sursa) {
		out << "Producator: " << sursa.producator << endl;
		out << "Culoare: " << sursa.culoare << endl;
		out << "Nivel curent: " << sursa.nivelCurent << endl;
		out << "Pret: " << sursa.pret << endl;
		return out;
	}
	friend istream& operator>>(istream& in, Marker& sursa) {
		cout << "da culoare: ";
		in >> sursa.culoare;
		cout << "numele producatorului: ";
		char buffer[250];
		in >> buffer;
		delete[] sursa.producator;
		sursa.producator = new char[strlen(buffer) + 1];
		strcpy(sursa.producator, buffer);
		cout << "da nivel: ";
		in >> sursa.nivelCurent;
		return in;
	}
	string getCuloare() {
		return this->culoare;
	}
	void setNivel(float nivel) {
		if (nivel > 0) {
			this->nivelCurent = nivel;
		}
		else this->nivelCurent = 0;
	}
	bool operator==(Marker sursa) {
		if (strcmp(sursa.producator, this->producator) == 0) {
			if (this->nivelCurent == sursa.nivelCurent) {
				return true;
			}
			else return false;
		}
		else return false;
	}
	Marker& operator/=(float val) {
		this->nivelCurent /= 20;
		return *this;
	}
	Marker operator+(float val) {
		Marker copie(*this);
		copie.nivelCurent += val;
		return copie;
	}
	Marker& operator++() {
		this->nivelCurent += 10;
		return *this;
	}
	Marker operator++(int) {
		Marker copie(*this);
		this->nivelCurent += 10;
		return copie;
	}
	bool operator>=(float val) {
		return this->nivelCurent >= val;
	}
	char& operator[](int i) {
		if (i >= 0 && i < strlen(this->producator)) {
			return this->producator[i];
		}
		else throw new exception();
	}
	explicit operator float() {
		return this->nivelCurent;
	}
	void operator()(float nivelDat) {
		if (nivelDat > 0) {
			this->nivelCurent = nivelDat;
		}
		else this->nivelCurent = 0;
	}

};
float Marker::pret = 10.05;

class MarkerSmart :public Marker {
private:
	float grosime=0;
public:
	MarkerSmart() {}
	MarkerSmart(string culoareD, const char* producatorD,float nivelD, float grosimeD) :Marker( culoareD,  producatorD,  nivelD) {
		if (grosimeD > 0) {
			this->grosime = grosimeD;
		}
		else this->grosime = 0;
	}
	MarkerSmart(const MarkerSmart& sursa) :Marker((Marker)sursa) {
		this->grosime = sursa.grosime;
	}
	MarkerSmart& operator=(const MarkerSmart& sursa) {
		if (this != &sursa) {
			Marker::operator=((Marker)sursa);
			this->grosime = sursa.grosime;
		}
		return *this;
	}
	~MarkerSmart(){}
	friend ostream& operator<<(ostream& out, MarkerSmart sursa) {
		out << (Marker)sursa;
		out << "grosime: " << sursa.grosime << endl;
		return out;
	}
};
int main() {
	Marker marker1;
	Marker marker2("verde", "maped", 25.02);
	Marker marker3(marker2);
	/*cout << marker2;
	cout << marker3;
	Marker marker4;
	cin >> marker4;
	cout << marker4;
	cout << (marker2 == marker3) << endl;
	MarkerSmart marker5;
	cout << marker5;*/
	/*marker2 += 20;
	cout << marker2;
	cout << marker2 + 10;*/
	/*++marker2;
	cout << marker2;
	++marker2;
	cout << marker2;
	cout << marker2[3] << endl;
	cout << (float)marker2 << endl;
	cout << !marker2 << endl;
	marker2();
	cout << marker2;*/
	return 0;
}