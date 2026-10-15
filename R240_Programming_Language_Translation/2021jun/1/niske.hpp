#ifndef RECI_HPP
#define RECI_HPP

#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <string>
#include <cstring>

using namespace std;

class Niska {

	private:
		string _niska = "";
		
	public:
		Niska() {}
		Niska(string s);
		Niska(const Niska& niska);
		
		void show(ostream& s) const;
		bool set_niska(string s);
		string get_niska();
		
		//void dodela(const Niska& niska) const;
		Niska* operator +(const Niska& niska) const;
		string pomnozi(const int v) const;
		
		string podniska1(const int v); // [ v : ]
		string podniska2(const int v); // [ : v ]
		string podniska3(const int v1, const int v2); // [v1:v2]
		
		string lower() const;
		string upper() const;
		string reverse() const;
		
		int duzina() const;
		int indeks(const Niska& niska) const;
};

ostream& operator <<(ostream& s, const Niska& niska);

#endif
