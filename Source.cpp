#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <conio.h>
#include <stdio.h>
#include <string.h>
#include <iomanip>
#include <assert.h>
#include <cassert>
#include<malloc.h>
using namespace std;
class device
{
protected:
	char* firma_prod;
	int pret;
public:
	device();
	device(char*, int);
	device(device&);
	~device();
	inline void afisare();
	int get_pret();
	friend void set_firma_prod(device&, char*);
	void vinde_produse();
};
device::device()
{
	firma_prod = new char[15];
	strcpy(firma_prod, " ");
	pret = 0;
}
device::device(char* a, int b)
{
	firma_prod = new char[strlen(a) + 1];
	strcpy(firma_prod, a);
	pret = b;
}
device::device(device& c)
{
	firma_prod = new char[strlen(c.firma_prod) + 1];
	strcpy(firma_prod, c.firma_prod);
	pret = c.pret;
}
device::~device()
{
	delete firma_prod;
}
void device::afisare()
{
	cout << "Firma prod: " << firma_prod << endl;
	cout << "Pret: " << pret << endl;
}
int device::get_pret()
{
	return pret;
}
void set_firma_prod(device& X, char* Y)
{
	strcpy(X.firma_prod, Y);
}
void device::vinde_produse()
{
	cout << "Vinde produse" << endl;
}
class regulator :public device
{
protected:
	char* tip;
	int valoare_produse;
public:
	regulator();
	regulator(char*, int, char*, int);
	regulator(regulator&);
	~regulator();
	inline void afisare();
	friend int get_valoare_produse(regulator&);
	friend void set_tip(regulator&, char*);
	friend istream& operator>>(istream&, regulator&);
	void vinde_produse();
};
regulator::regulator()
{
	tip = new char[20];
	strcpy(tip, " ");
	valoare_produse = 0;
}
regulator::regulator(char* a, int b, char* e, int f) :device(a, b)
{
	tip = new char[strlen(e) + 1];
	strcpy(tip, e);
	valoare_produse = f;
}
regulator::regulator(regulator& c)
{
	tip = new char[strlen(c.tip) + 1];
	strcpy(tip, c.tip);
	valoare_produse = c.valoare_produse;
}
regulator::~regulator()
{
	delete tip;
}
void regulator::afisare()
{
	device::afisare();
	cout << "Tip produse oferite: " << tip << endl;
	cout << "Valoare produse: " << valoare_produse << endl;
}
int get_valoare_produse(regulator& g)
{
	return g.valoare_produse;
}
void set_tip(regulator& W, char* Z)
{
	strcpy(W.tip, Z);
}
istream& operator>>(istream& in, regulator& i)
{
	in >> i.tip;
	in >> i.valoare_produse;
	return in;
}
void regulator::vinde_produse()
{
	cout << "Vinde produse" << endl;
}
class regulator_PID :public regulator
{
private:
	int kr, ti, td;
public:
	regulator_PID();
	regulator_PID(char*, int, char*, int, int, int, int);
	regulator_PID(regulator_PID&);
	inline void afisare();
	friend ostream& operator<<(ostream&, regulator_PID&);
	friend istream& operator>>(istream&, regulator_PID&);
};
regulator_PID::regulator_PID()
{
	kr = 0;
	ti = 0;
	td = 0;
}
ostream& operator<<(ostream& out, regulator_PID& R)
{
	out << "\n valoare kr=" << R.kr;
	out << "\n valoare ti=" << R.ti;
	out << "\n valoare td=" << R.td;
	return out;
}
istream& operator>>(istream& in, regulator_PID& R)
{
	in >> setw(10) >> R.kr;
	in >> setw(10) >> R.ti;
	in >> setw(10) >> R.td;
	return in;
}
regulator_PID::regulator_PID(regulator_PID& RPID)
{
	kr = RPID.kr;
	ti = RPID.ti;
	td = RPID.td;
}
void regulator_PID::afisare()
{
	regulator::afisare();
	cout << "\n kr=" << kr;
	cout << "\n ti=" << ti;
	cout << "\n td=" << td;
}
regulator_PID::regulator_PID(char* a, int b, char* e, int f, int KR, int TI, int TD) : regulator(a, b, e, f)
{
	kr = KR;
	ti = TI;
	td = TD;
}
class regulator_fuzzy :public regulator
{
private:
	char* tip_inferenta;
	int nr1;
public:
	regulator_fuzzy();
	regulator_fuzzy(char*, int, char*, int, char*, int);
	regulator_fuzzy(regulator_fuzzy&);
	~regulator_fuzzy();
	friend char* get_inferenta(regulator_fuzzy&);
	inline void set_inferenta(char* I);
	void afisare();
};
regulator_fuzzy::regulator_fuzzy()
{
	tip_inferenta = (char*)calloc(6, sizeof(char));
	assert(tip_inferenta != 0);
	strcpy(tip_inferenta, " ");
	nr1 = 0;
}
regulator_fuzzy::regulator_fuzzy(regulator_fuzzy& RF)
{
	strcpy(tip_inferenta, RF.tip_inferenta);
	nr1 = RF.nr1;
}
regulator_fuzzy::~regulator_fuzzy()
{
	cout << "\n OBIECTUL ESTE DISTRUS!";
}
void regulator_fuzzy::afisare()
{
	cout << "\n tip inferenta" << tip_inferenta;
	cout << "\n numar functii de apartenenta" << nr1;
}
char* get_inferenta(regulator_fuzzy& RF)
{
	return RF.tip_inferenta;
}
void regulator_fuzzy::set_inferenta(char* I)
{
	tip_inferenta = new char[strlen(I) + 1];
	assert(tip_inferenta != 0);
	strcpy(tip_inferenta, I);
}
regulator_fuzzy::regulator_fuzzy(char* a, int b, char* e, int f, char* TI, int NR) : regulator(a, b, e, f)
{
	strcpy(tip_inferenta, TI);
	nr1 = NR;
}
class regulator_RNA : public regulator
{
private:
	int in, out, nr_straturi;
	int nr;
public:
	regulator_RNA();
	regulator_RNA(char*, int, char*, int, int, int, int, int);
	~regulator_RNA();
	void afisare();
	int get_nr_straturi();
	void set_in(int);
	void set_out(int);
};
regulator_RNA::regulator_RNA(char* a, int b, char* e, int f, int I, int O, int NRSTR, int NR) : regulator(a, b, e, f)
{
	nr_straturi = NRSTR;
	in = I;
	out = O;
}
regulator_RNA::~regulator_RNA()
{
	cout << "\n OBIECTUL ESTE DISTURS!";
}
void regulator_RNA::afisare()
{
	cout << "\n Numarul de straturi este:" << nr_straturi;
	cout << "\n Numarul de intrari este:" << in;
	cout << "\n Numarul de iesiri este:" << out;
}
int regulator_RNA::get_nr_straturi()
{
	return nr_straturi;
}
void regulator_RNA::set_in(int IN)
{
	in = IN;
}
void regulator_RNA::set_out(int OUT)
{
	out = OUT;
}
int main()
{
	char a[15] = "Firma 1";
	device ob1, ob2(a, 3500), ob3(ob2);
	ob1.afisare();
	ob2.afisare();
	ob3.afisare();
	cout << "vinde produs" << endl;
	cout << "Pretul este:" << ob2.get_pret() << endl;
	char r[15] = "firma2";
	set_firma_prod(ob2, r);
	ob2.afisare();
	cout << "vinde produs";
	char b[15] = "model1";
	char s[15] = "model2";
	regulator ob4, ob5(a, 3500, b, 2500), ob6(ob4);
	cout << "\n";
	ob4.afisare();
	ob5.afisare();
	ob6.afisare();
	cout << "Valoare produs:" << get_valoare_produse(ob5) << endl;
	set_tip(ob5, s);
	ob5.afisare();
	cout << "vinde produs";
	char g[15] = "model3";
	regulator_fuzzy r1, r2(a, 300, b, 400, g, 4), r3(r1);
	cout << "\n";
	r1.afisare();
	r2.afisare();
	r3.afisare();
	cout << " valoare inferenta" << get_inferenta(r2) << endl;
	r2.afisare();
	char t[15] = "model 4";
	char k[10] = "model5";
	regulator_RNA r4, r5(t, 500, k, 700, 1, 2, 3, 4), r6(r5);
	cout << "\n";
	r4.afisare();
	r5.afisare();
	r6.afisare();
	r6.set_in(20);
	r6.afisare();
	r5.set_out(20);
	r5.afisare();
}
