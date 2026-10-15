#ifndef VEKTOR_HPP
#define VEKTOR_HPP

#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <vector>
#include <cmath>
#include <utility>

using namespace std;

class Vektor {
	
	private:
		vector<pair<double, double>> _vektor;
		
	public:
		Vektor() {}
		Vektor(double x, double y);
		Vektor(pair<double, double> vek);
		Vektor(double x1, double x2, double y1, double y2);
		Vektor(const Vektor& vek);
		
		void push_back(pair<double, double> par);
		int get_size() const;
		
		void show(ostream& s) const;
		int operator [](int i);
		
		Vektor* operator +(const Vektor& vek) const;
		Vektor* operator -(const Vektor& vek) const;
		Vektor* operator *(const int v) const;
		Vektor* operator -() const;
		
		Vektor* refleksijaX(const Vektor& vek);
		Vektor* refleksijaY(const Vektor& vek);
		Vektor* simetricni(const Vektor& vek);
		
		double duzina();
		//Vektor* rotacija(const Vektor& vek, double angle);
		//double izracunaj_ugao(const Vektor& vek1, const Vektor& vek2);

};

ostream& operator <<(ostream& s, const Vektor& vek);

#endif
