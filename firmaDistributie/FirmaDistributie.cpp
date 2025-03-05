#include <iostream>
#include <fstream>
using namespace std;
#pragma warning(disable:4996)

class Firma {
private:
	string numeClient;
	int nrProduse;
	string* listaProduse;
	int* CantComandate;
	static string dataDeschidereFirma;
public:
	Firma() {
		this->numeClient = "-";
		this->nrProduse = 0;		
		this->listaProduse = nullptr;;
		this->CantComandate = nullptr;
	}
	Firma(string numeDat, int nrProdDat, string* listaProdDat, int* CantDate) {
		if (numeDat.length() > 2) {
			this->numeClient = numeDat;
		}
		else {
			this->numeClient = "-";
		}
		if (nrProdDat > 0 && listaProdDat != nullptr && CantDate != nullptr) {
			this->nrProduse = nrProdDat;
			this->listaProduse = new string[this->nrProduse];
			this->CantComandate = new int[this->nrProduse];
			for (int i = 0; i < nrProdDat; i++) {
				this->listaProduse[i] = listaProdDat[i];
				this->CantComandate[i] = CantDate[i];
			}
		}
		else {
			this->nrProduse = 0;
			this->listaProduse = nullptr;
			this->CantComandate = nullptr;
		}
	}
	Firma(const Firma& sursa) {
		this->numeClient = sursa.numeClient;
		this->nrProduse = sursa.nrProduse;
		this->listaProduse = new string[sursa.nrProduse];
		this->CantComandate = new int[sursa.nrProduse];
		for (int i = 0; i < sursa.nrProduse; i++) {
			this->listaProduse[i] = sursa.listaProduse[i];
			this->CantComandate[i] = sursa.CantComandate[i];
		}
	}
	Firma& operator=(const Firma& sursa) {
		if (this != &sursa) {
			delete[] this->listaProduse;
			delete[] this->CantComandate;
			this->numeClient = sursa.numeClient;
			this->nrProduse = sursa.nrProduse;
			this->listaProduse = new string[sursa.nrProduse];
			this->CantComandate = new int[sursa.nrProduse];
			for (int i = 0; i < sursa.nrProduse; i++) {
				this->listaProduse[i] = sursa.listaProduse[i];
				this->CantComandate[i] = sursa.CantComandate[i];
			}
		}
		return *this;
	}

	void setNrProduse(int nrProduseDat) {
		this->nrProduse = nrProduseDat;
	}
	string getNumeClient() {
		return this->numeClient;
	}
	~Firma() {
		delete[] this->listaProduse;
		this->listaProduse = nullptr;
		delete[] this->CantComandate;
		this->CantComandate = nullptr;
	}
	friend ostream& operator<<(ostream& out, Firma sursa) {
		out << "Nume client: " << sursa.numeClient << endl;
		out << "Numar produse comandate: " << sursa.nrProduse << endl;
		out << "Lista produse comandate: " << endl;
		for (int i = 0; i < sursa.nrProduse; i++) {
			out << "Produsul:" << i + 1 <<" " << sursa.listaProduse[i] << endl;
			out << "Cantitatea: " << sursa.CantComandate[i] << endl;
		}
		return out;
	}
	friend ofstream& operator<<(ofstream& out, Firma sursa) {
		out << "Nume client: " << sursa.numeClient << endl;
		out << "Numar produse comandate: " << sursa.nrProduse << endl;
		out << "Lista produse comandate: " << endl;
		for (int i = 0; i < sursa.nrProduse; i++) {
			out << "Produsul:" << i + 1 << " " << sursa.listaProduse[i] << endl;
			out << "Cantitatea: " << sursa.CantComandate[i] << endl;
		}
		return out;
	}
	
	string& operator[](int i) {
		if (i >= 0 && i < this->nrProduse) {
			return this->listaProduse[i];
		}
		else {
			throw new exception();
		}
	}
	Firma& operator+=(string ProdusNou) {
		string* vectorNou;
		for (int i = 0; i < this->nrProduse; i++) {
			if (this->listaProduse[i] == ProdusNou) {
				this->CantComandate[i]++;
				return *this;
			}
		}
			vectorNou = new string[this->nrProduse + 1];
			int* cantitatiNoi = new int[this->nrProduse + 1];
			for (int i = 0; i < this->nrProduse; i++) {
				vectorNou[i] = this->listaProduse[i];
				cantitatiNoi[i] = this->CantComandate[i];
			}
			vectorNou[this->nrProduse] = ProdusNou;
			cantitatiNoi[this->nrProduse] = 1;
			delete[] this->listaProduse;
			delete[] this->CantComandate;
			this->listaProduse = vectorNou;
			this->CantComandate = cantitatiNoi;
			this->nrProduse++;
			return *this;
	}
};

string Firma::dataDeschidereFirma = "10/02/2015";

int main() {
	Firma f35;
	/*cout << f;*/
	/*string lista[] = { "lapte", "lamuie" };*/
	/*int cantitati[] = { 5,2 };*/
	Firma f1("stefan", 2, new string[2]{ "lapte", "lamaie" }, new int[2] {5, 2});
	/*cout << f1;
	cout << f1[1]<<endl;*/
	f1 += "cereale";
	cout << f1;
	f1 += "cereale";
	cout << f1;
	ofstream f("comanda.txt");
	if (f.is_open()) {
		f << f35;
		f.close();
	}
	else throw out_of_range("eroare la deschiderea fisierului");
	return 0;
}