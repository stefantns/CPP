#include <iostream>
#include <fstream>
using namespace std;
#pragma warning(disable:4996)

class CameraHotel {
private:
	string numeCamera;
	int nrFacilitati;
	float pretFacilitate;
	string* facilitateCamera;
public:
	CameraHotel() {
		this->numeCamera = " ";
		this->nrFacilitati = 0;
		this->pretFacilitate = 0;
		this->facilitateCamera = nullptr;
	}
	CameraHotel(string nume,int nrfac, float pretfac) {
		if (nume.length() > 2) {
			this->numeCamera = nume;
		}
		else this->numeCamera = " ";
		if (nrfac > 0) {
			this->nrFacilitati = nrfac;
		}
		else this->nrFacilitati = 0;
		if (pretfac > 0) {
			this->pretFacilitate = pretfac;
		}
		else this->pretFacilitate = 0;
		this->facilitateCamera = nullptr;
	}
	CameraHotel(string nume, int nrfac, float pretfac, string* facilitatiD) {
		if (nume.length() > 2) {
			this->numeCamera = nume;
		}
		else this->numeCamera = " ";
		if (nrfac > 0 && facilitatiD != nullptr) {
			this->nrFacilitati = nrfac;
			this->facilitateCamera = new string[nrfac];
			for (int i = 0; i < nrfac; i++) {
				this->facilitateCamera[i] = facilitatiD[i];
			}
		}
		else {
			this->nrFacilitati = 0;
			this->facilitateCamera = nullptr;
		}
		if (pretfac > 0) {
			this->pretFacilitate = pretfac;
		}
		else this->pretFacilitate = 0;
	}
	CameraHotel(const CameraHotel& sursa) {
		this->numeCamera =sursa.numeCamera;
		this->nrFacilitati = sursa.nrFacilitati;
		this->pretFacilitate = sursa.pretFacilitate;
		this->facilitateCamera = new string[sursa.nrFacilitati];
		for (int i = 0; i < sursa.nrFacilitati; i++) {
			this->facilitateCamera[i] = sursa.facilitateCamera[i];
		}
	}
	CameraHotel& operator=(const CameraHotel& sursa) {
		if (this != &sursa) {
			delete[] this->facilitateCamera;
			this->numeCamera = sursa.numeCamera;
			this->nrFacilitati = sursa.nrFacilitati;
			this->pretFacilitate = sursa.pretFacilitate;
			this->facilitateCamera = new string[this->nrFacilitati];
			for (int i = 0; i < this->nrFacilitati; i++) {
				this->facilitateCamera[i] = sursa.facilitateCamera[i];
			}
		}
		return *this;
	}
	~CameraHotel() {
		if (this->facilitateCamera != nullptr)
		{
			delete[] this->facilitateCamera;
			this->facilitateCamera = nullptr;
		}
	}
	friend ostream& operator<<(ostream& out,const CameraHotel& sursa) {
		out << "nume camera: " << sursa.numeCamera << endl;
		out << "numar facilitati: " << sursa.nrFacilitati << endl;
		out << "pret facilitate: " << sursa.pretFacilitate << endl;
		if (sursa.facilitateCamera != nullptr)
		{
			out << "facilitati: " << endl;
			for (int i = 0; i < sursa.nrFacilitati; i++) {
				out << i + 1 << ": " << sursa.facilitateCamera[i] << endl;
			}
		}
		else out << "camera nu are facilitati" << endl;
		return out;
	}
	friend ofstream& operator<<(ofstream& out, const CameraHotel& sursa) {
		out << "nume camera: " << sursa.numeCamera << endl;
		out << "numar facilitati: " << sursa.nrFacilitati << endl;
		out << "pret facilitate: " << sursa.pretFacilitate << endl;
		if (sursa.facilitateCamera != nullptr)
		{
			out << "facilitati: " << endl;
			for (int i = 0; i < sursa.nrFacilitati; i++) {
				out << i + 1 << ": " << sursa.facilitateCamera[i] << endl;
			}
		}
		else out << "camera nu are facilitati" << endl;
		return out;
	}
	friend istream& operator>>(istream& in, CameraHotel& sursa) {
		in >> sursa.numeCamera;
		return in;
	}
	
	string& operator[](int i) {
		if (i >= 0 && i < this->nrFacilitati) {
			return this->facilitateCamera[i];
		}
		else throw new exception();
	}
	float metoda() {
		float pretTotalFacilitati = 0;
		pretTotalFacilitati = this->nrFacilitati * this->pretFacilitate;
		return pretTotalFacilitati;
	}
};

class Baie : public CameraHotel {
private:
	bool areBaie=false;
public:
	Baie(){}
	Baie(string nume, int nrfac, float pretfac, string* facilitatiD, bool arebaie) :CameraHotel( nume,  nrfac,  pretfac,  facilitatiD) {
		this->areBaie = arebaie;
	}
	Baie(const Baie& sursa) :CameraHotel((CameraHotel)sursa) {
		this->areBaie = sursa.areBaie;
	}
	Baie& operator=(const Baie& sursa) {
		if (this != &sursa) {
			CameraHotel::operator=((CameraHotel)sursa);
			this->areBaie = sursa.areBaie;
		}
		return *this;
	}
	~Baie(){}
	friend ostream& operator<<(ostream& out, const Baie& sursa) {
		out << (CameraHotel)sursa;
		out << "are baie: " << sursa.areBaie;
		return out;
	}
	friend istream& operator>>(istream& in, Baie& sursa) {
		in >> (CameraHotel&)sursa;
		in >> sursa.areBaie;
		return in;
	}
};


int main() {
	CameraHotel c1;
	CameraHotel c2("rosu",2,200);
	CameraHotel c3("verde", 2, 250, new string[2]{ "wifi","minibar" });
	cout << c2 << endl;
	cout << c3;
	cout << c3[1] << endl;
	cout << c2.metoda();
	Baie b1;
	cin >> b1;
	cout << b1;
	ofstream f("fisier.txt");
	if (f.is_open()) {
		f << c2;
		f.close();
	}
	else throw out_of_range("nu exista fisierul");
	return 0;
}