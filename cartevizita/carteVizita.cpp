#include <iostream>
using namespace std;
#pragma warning(disable:4996)


enum Enumeration {
	Sange, Vopsea, Aur
};

class Vizita {
private:
	char* nume;
	string tel;
	string email;
	Enumeration tip;
	static string data;
public:
	Vizita() {
		this->nume = new char[strlen("na") + 1];
		strcpy(this->nume, "na");
		this->tel = "-";
		this->email = "-";
		this->tip = Sange;
	}
	Vizita(const char* numeD, string telD, string emailD, Enumeration tipD)
	{
		if (strlen(numeD) > 2) {
			this->nume = new char[strlen(numeD) + 1];
			strcpy(this->nume, numeD);
		}
		else {
			this->nume = new char[strlen("na") + 1];
			strcpy(this->nume, "na");
		}
		if (telD.length() > 2) {
			this->tel = telD;
		}
		else this->tel = "-";
		if (emailD.length() > 2) {
			this->email = emailD;
		}
		if (tipD == Sange || tipD == Vopsea || tipD == Aur) {
			this->tip = tipD;
		}
		else this->tip = Sange;
	}
	Vizita(const Vizita& sursa) {
		this->nume = new char[strlen(sursa.nume) + 1];
		strcpy(this->nume, sursa.nume);
		this->tel = sursa.tel;
		this->email = sursa.email;
		this->tip = sursa.tip;
	}
	Vizita& operator=(const Vizita& sursa) {
		if (this != &sursa) {
			delete[] this->nume;
			this->nume = nullptr;
			this->nume = new char[strlen(sursa.nume) + 1];
			strcpy(this->nume, sursa.nume);
			this->tel = sursa.tel;
			this->email = sursa.email;
			this->tip = sursa.tip;
		}
		return *this;
	}
	~Vizita() {
		delete[] this->nume;
	}
	string getEmail() {
		return this->email;
	}
	void setTel(string telD) {
		if (telD.length() > 2) {
			this->tel = telD;
		}
		else this->tel = "-";
	}

	bool operator>=(Vizita obiect2) {
		if (strlen(this->nume) >= strlen(obiect2.nume)) {
			return true;
		}
		else return false;
	}
	friend istream& operator>>(istream& in, Vizita& sursa) {
		delete[] sursa.nume;
		sursa.nume = nullptr;
		char buffer[250];
		cout << "da nume:";
		in >> buffer;
		sursa.nume = new char[strlen(buffer) + 1];
		strcpy(sursa.nume, buffer);
		cout << "da email";
		in >> sursa.email;
		cout << "da tel:";
		in >> sursa.tel;
		int x;
		cout << "sange vopsea sau aur 0 1 2";
		cin >> x;
		if (x == 0) {
			sursa.tip = Sange;
		}
		else if (x == 1) {
			sursa.tip = Vopsea;
		}
		else if (x == 2) {
			sursa.tip = Aur;
		}
		return in;
	}
	friend ostream& operator<<(ostream& out, Vizita sursa) {
		out << "nume: " << sursa.nume << endl;
		out << "tel: " << sursa.tel << endl;
		out << "email: " << sursa.email << endl;
		if (sursa.tip == Sange) out << "sange" << endl;
		if (sursa.tip == Aur) out << "aur" << endl;
		if (sursa.tip == Vopsea)out << "vopsea" << endl;
		out << sursa.data << endl;
		return out;
	}

};

string Vizita::data = "1/01/2006";


class VizitaCool :public Vizita {
private:
	string descriere = "-";
public:
	VizitaCool(){}
	VizitaCool(const char* numed, string telD, string emailD, Enumeration tipD, string descriereD) :Vizita( numed,  telD, emailD,  tipD) {
		if (descriereD.length() > 2) {
			this->descriere = descriereD;
		}
		else this->descriere = "-";
	}
	VizitaCool(const VizitaCool& sursa):Vizita((Vizita)sursa) {
		this->descriere = sursa.descriere;
	}
	VizitaCool& operator=(const VizitaCool& sursa) {
		if (this != &sursa) {
			Vizita::operator=((Vizita)sursa);
			this->descriere = sursa.descriere;
		}
		return *this;
	}
	~VizitaCool(){}
	friend ostream& operator<<(ostream& out, VizitaCool sursa) {
		out << (Vizita)sursa;
		out << "descriere: " << sursa.descriere;
		return out;
	}
	friend istream& operator>>(istream& in, VizitaCool& sursa) {
		in >> (Vizita&)sursa;
		cout << "descriere: ";
		in >> sursa.descriere;
		return in;
	}
};


int main() {
	Vizita v1;
	cout << v1;
	Vizita v2("nume232", "0787578327", "mariusica@gmail", Vopsea);
	cout << v2;
	Vizita v3;
	cin >> v3;
	if (v3 >= v2) {
		cout << "obiectul 1 are numele mai mare";
	}
	else cout << "obiectul 1 il are mic";
	VizitaCool v96;
	cin >> v96;
	cout << v96;
	return 0;
}