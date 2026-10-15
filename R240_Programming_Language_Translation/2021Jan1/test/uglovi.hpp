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
		vector<int> _u = {0,0,0};
	
	public:
		Ugao() {}
		Ugao(int step, int m, int sek);
		Ugao(const Ugao& ug);
		Ugao(const Ugao& ug, char mode);
		
		int get_size() const;
		void push_back(const Ugao& ug);
		
		void show(ostream& s) const;
		
		Ugao* operator +(const Ugao& ug);
		Ugao* operator -(const Ugao& ug);
		Ugao* operator *(const int v);
		
		void set_stepen(int v);
		void set_minut(int v);
		void set_sekund(int v);
		
		int get_stepen();
		int get_minut();
		int get_sekund();
		
		void sredi(int& step, int& m, int& sek);
};

ostream& operator <<(ostream& s, const Ugao& ug);

#endif
