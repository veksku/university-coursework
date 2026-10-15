#ifndef __MATRICA_HPP__
#define __MATRICA_HPP__ 1

#include <vector>
#include <iostream>

using namespace std;

class Matrica {
	public:
		Matrica();
		Matrica(const vector<double> v);
		void dodajRed(const vector<double> v);
		unsigned visina() const; //konstantan metod = nece promeniti objekat nad kojim se poziva
		unsigned sirina() const;
		void pisi(ostream& izlaz) const;
		Matrica operator+(const Matrica &m);
		Matrica operator-(const Matrica &m);
		Matrica operator*(const Matrica &m);
		Matrica pm(const Matrica &m);
		Matrica transponovana() const;
		
	private:
		vector<vector<double>> _elementi;
};

ostream& operator<<(ostream& izlaz, const Matrica m);

#endif
