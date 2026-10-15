#include "niske.hpp"

using namespace std;

Niska::Niska(string s){
	_niska = s;
}
Niska::Niska(const Niska& niska){
	_niska = niska._niska;
}

void Niska::show(ostream& s) const{
	s << _niska << endl;
}	
bool Niska::set_niska(string s){
	_niska = s;
	return true;
}
string Niska::get_niska(){
	return _niska;
}				
		
Niska* Niska::operator +(const Niska& niska) const{
	Niska* novaNiska = new Niska();
	novaNiska->_niska = _niska;
	novaNiska->_niska += niska._niska;
	
	return novaNiska;
}
string Niska::pomnozi(const int v) const{
	if (v < 0){
		cerr << "Greska, pristup nealociranom delu niske" << endl;
		exit(EXIT_FAILURE);
	}
	string novaNiska = "";
	for(int i=0; i<v; i++)
		novaNiska += _niska;
	
	return novaNiska;
}

string Niska::podniska1(const int v){
	string novaNiska = "";
	for(int i=v; i<_niska.length(); i++)
		novaNiska += _niska[i];
		
	return novaNiska;
} // [ v : ]
string Niska::podniska2(const int v){
	if (v >= _niska.length()){
		cerr << "Greska, pristup nealociranom delu niske" << endl;
		exit(EXIT_FAILURE);
	}
	
	string novaNiska = "";
	for(int i=0; i<v; i++)
		novaNiska += _niska[i];
		
	return novaNiska;
} // [ : v ]
string Niska::podniska3(const int v1, const int v2){
	if (v2 >= _niska.length() || v1 < 0){
		cerr << "Greska, pristup nealociranom delu niske" << endl;
		exit(EXIT_FAILURE);
	}
	
	string novaNiska = "";
	for(int i=v1; i<v2; i++)
		novaNiska += _niska[i];
		
	return novaNiska;
} // [v1:v2]
		
string Niska::lower() const{
	string novaNiska = "";
	for(int i=0; i<_niska.length(); i++){
		novaNiska += tolower(_niska[i]);
	}
	
	return novaNiska;
}
string Niska::upper() const{
	string novaNiska = "";
	for(int i=0; i<_niska.length(); i++){
		novaNiska += toupper(_niska[i]);
	}
	
	return novaNiska;
}
string Niska::reverse() const{
	string novaNiska = "";
	for(int i=_niska.length(); i>=0; i--){
		novaNiska += _niska[i];
	}
	
	return novaNiska;
}
		
int Niska::duzina() const{
	return _niska.length();
}
int Niska::indeks(const Niska& niska) const{
	string s = niska._niska;
	int iterator = 0;
	while(iterator < _niska.length() - s.length()){
		if(_niska[iterator] == s[0]){
			int i;
			for( i=1; i<s.length(); i++)
				if(_niska[iterator + i] != s[i])
					break;
			if(i==s.length())
				return iterator;
		}	
		iterator++;
	}
	return -1;
}

ostream& operator <<(ostream& s, const Niska& niska){
	niska.show(s);
	return s;
}
