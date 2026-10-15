#ifndef UGLOVI_HPP
#define UGLOVI_HPP

#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <vector>

using namespace std;

class Ugao {
	
	private:
		int stepen, minut, sekund;
	
	public:
		Ugao() {}
		Ugao(int step, int m, int sek);
		Ugao(const Ugao& ug);
		Ugao(const Ugao& ug, char mode);
		
		void show(ostream& s) const;
		
		Ugao* operator +(const Ugao& ug);
		Ugao* operator -(const Ugao& ug);
		Ugao* operator *(const int v);
		
		//Ugao* komplement(const Ugao& ug) const:
		//Ugao* suplement(const Ugao& ug) const;
		
		bool set_stepen(int v);
		bool set_minut(int v);
		bool set_sekund(int v);
		
		int get_stepen();
		int get_minut();
		int get_sekund();
		
		void sredi(int& step, int& m, int& sek);
};

ostream& operator <<(ostream& s, const Ugao& ug);

#endif
