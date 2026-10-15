#ifndef VEKTOR_HPP
#define VEKTOR_HPP

#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

class Vektor {
	
	private:
		double _x,_y;
		
	public:
		Vektor() {}
		Vektor(double x, double y);
		Vektor(double x1, double x2, double y1, double y2);
		Vektor(const Vektor& vek);
		
		void show(ostream& s) const;
		
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
		
		void set_x(double x);
		void set_y(double y);
		
		double get_x();
		double get_y();
};

ostream& operator <<(ostream& s, const Vektor& vek);

#endif
