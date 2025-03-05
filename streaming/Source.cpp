#include <iostream>
using namespace std;
#pragma warning(disable:4996)


class Streamer {
private:
	static float pretPerVizionare;
	bool activ = false;
	int nrClipuri = 0;
	int* vizionari = nullptr;
public:
	Streamer() {}
	Streamer(bool activD, int nrClipD, int* vizionariD) {
		this->activ = activD;
		if (nrClipD > 0 && vizionariD != nullptr) {
			this->nrClipuri = nrClipD;
			this->vizionari = new int[nrClipD];
			for (int i = 0; i < nrClipD; i++) {
				this->vizionari[i] = vizionariD[i];
			}
		}
	}
	Streamer(const Streamer& sursa) {
		this->activ = sursa.activ;
		if (sursa.nrClipuri > 0 && sursa.vizionari != nullptr) {
			this->nrClipuri = sursa.nrClipuri;
			this->vizionari = new int[sursa.nrClipuri];
			for (int i = 0; i < sursa.nrClipuri	; i++) {
				this->vizionari[i] = sursa.vizionari[i];
			}
		}
	}
	Streamer& operator=(const Streamer& sursa) {
		if (this != &sursa) {
			delete[] this->vizionari;
			this->activ = sursa.activ;
			if (sursa.nrClipuri > 0 && sursa.vizionari != nullptr) {
				this->nrClipuri = sursa.nrClipuri;
				this->vizionari = new int[sursa.nrClipuri];
				for (int i = 0; i < sursa.nrClipuri; i++) {
					this->vizionari[i] = sursa.vizionari[i];
				}
			}
		}
		return *this;
	}
	~Streamer() {
		delete[] this->vizionari;
		this->vizionari = nullptr;
	}
	bool getActiv() {
		return this->activ;
	}
	void setActiv(bool activd) {
		this->activ = activd;
	}
	friend ostream& operator<< (ostream& out, Streamer sursa) {
		out << "status: ";
		if (sursa.activ == true) {
			out << "Activ" << endl;
		}
		else out << "blocat" << endl;
		out << "Nr videoclipuri: " << sursa.nrClipuri << endl;
		for (int i = 0; i < sursa.nrClipuri; i++) {
			out << "Videoclipul " << i + 1 << " are " << sursa.vizionari[i] << " vizualizari" << endl;
		}
		return out;
	}

	Streamer& operator+=(int ValoareNoua) {
		int* vectornou = new int[this->nrClipuri + 1];
		for (int i = 0; i < this->nrClipuri; i++) {
			vectornou[i] = this->vizionari[i];
		}
		vectornou[this->nrClipuri] = ValoareNoua;
		delete[] this->vizionari;
		this->nrClipuri++;
		this->vizionari = vectornou;
		return *this;
	}
	Streamer& operator-=(int ValoareDeSters) {
		int* vectornou = new int[this->nrClipuri - 1];
		int j = 0;
		for (int i = 0; i < this->nrClipuri; i++) {
			if (this->vizionari[i] != ValoareDeSters) {
				vectornou[j] = this->vizionari[i];
				j++;
			}
		}
		delete[] this->vizionari;
		this->vizionari = vectornou;
		this->nrClipuri -= 1;
		return *this;
	}

	explicit operator double() {
		double max = this->vizionari[0];
		for (int i = 0; i < this->nrClipuri; i++) {
			if (max < this->vizionari[i]) {
				max = this->vizionari[i];
			}
		}
		return max;
	}

};
float Streamer::pretPerVizionare = 0.2;


class TikToker :public Streamer {
private:
	char* tag;
	int nrTap;
public:
	TikToker() {
		this->tag = new char[strlen("na") + 1];
		strcpy(this->tag, "na");
		this->nrTap = 0;
	}
	TikToker(bool activD, int nrClipD, int* vizionariD, const char* tagD, int nrTapD) :Streamer(activD, nrClipD, vizionariD) {
		if (strlen(tagD) > 2) {
			this->tag = new char[strlen(tagD) + 1];
			strcpy(this->tag, tagD);
		}
		else {
			this->tag = new char[strlen("na") + 1];
			strcpy(this->tag, "na");
		}
		this->nrTap = nrTapD;
	}
	TikToker(const TikToker& sursa) :Streamer((Streamer)sursa) {
		this->tag = new char[strlen(sursa.tag) + 1];
		strcpy(this->tag, sursa.tag);
		this->nrTap = sursa.nrTap;
	}
	TikToker& operator=(const TikToker& sursa) {
		if (this != &sursa) {
			delete[] this->tag;
			Streamer::operator=((Streamer)sursa);
			this->tag = new char[strlen(sursa.tag) + 1];
			strcpy(this->tag, sursa.tag);
			this->nrTap = sursa.nrTap;
		}
		return *this;
	}
	~TikToker() {
		delete[] this->tag;
		this->tag = nullptr;
	}
	friend ostream& operator<<(ostream& out, TikToker sursa) {
		out << (Streamer)sursa;
		out << "tag :" << sursa.tag << endl;
		out << "nr tapuri: " << sursa.nrTap << endl;
		return out;
	}
};


int main() {
	Streamer s;
	cout << s;
	int vizionari[5] = { 259, 285, 345, 234, 899 };
	Streamer s1(true, 5, vizionari);//new int[5] {259, 285, 345, 234, 899}
	cout << s1;
	Streamer s2(s1);
	cout << s2;
	s2 += 25894;
	cout << s2;
	s2 -= 259;
	cout << s2;
	cout << (double)s2 << endl;
	TikToker t;
	TikToker t1(true, 3, new int[3] {132, 23, 1111}, "tag", 200);
	TikToker t2(t1);
	cout << t1;
	cout << t2;
	return 0;
}