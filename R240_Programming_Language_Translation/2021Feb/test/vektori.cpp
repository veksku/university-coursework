#include "vektori.hpp"		

Vektor::Vektor(double x, double y){ 
	pair<double, double> par;
	par.first = x;
	par.second = y;
	_vektor.push_back(par);
}

Vektor(pair<double, double> par){
	_vektor.push_back(par);
}

Vektor::Vektor(double x1, double x2, double y1, double y2){ 
	double x = x2 - x1;
	double y = y2 - y1;
	pair<double, double> par;
	par.first = x;
	par.second = y;
	_vektor.push_back(par);
}

Vektor::Vektor(const Vektor& vek){
	pair<double,double> par;
	par.first = vek->first;
	par.second = vek->second;
	_vektor.push_back(par);
}
		
void Vektor::push_back(pair<double, double> par){
	_vektor.push_back(par);
}

int Vektor::get_size() const{
	return _vektor.size();
}
		
void Vektor::show(ostream& s) const{
	if (_vektor.size() > 1) {
		s<<'<';
		for (auto it = _vektor.begin(); it != _vektor.end(); it++) {
			if (it != _vektor.begin())
				s<<',';
			s<<*it;
		}
		s<<'>';
	}
	else
		s<<_vektor[0];

	s<<endl;
}
		
int Vektor::operator [](int i) {
	return _vektor[i];
}		
		
Vektor* Vektor::operator +(const Vektor& vek) const{
	if (_vektor.size() != 1 && vek.get_size() != 1) {
		yyerror("Nesglasne dimenzije");
	}
	
	Vektor* novi = new Vektor();
	
	pair<double, double> par;
	par.first = _vektor.first + vek->first;
	par.second = y;
	
	novi->push_back(_b[i] + b._b[i]);

	return novi;
}

Vektor* Vektor::operator -(const Vektor& vek) const{
	Vektor* novi = new Vektor();
	
	novi->set_x(_x - vek._x);
	novi->set_y(_y - vek._y);
	
	return novi;
}

Vektor* Vektor::operator *(const int v) const{
	Vektor* novi = new Vektor();
	
	novi->set_x(_x * v);
	novi->set_y(_y * v);
	
	return novi;
}

Vektor* Vektor::operator -() const{
	Vektor* novi = new Vektor();
	
	novi->set_x(-_x);
	novi->set_y(-_y);
	
	return novi;
}
		
Vektor* Vektor::refleksijaX(const Vektor& vek){
	Vektor* novi = new Vektor();
	
	novi->set_x(vek._x);
	novi->set_y(-(vek._y));
	
	return novi;
}

Vektor* Vektor::refleksijaY(const Vektor& vek){
	Vektor* novi = new Vektor();
	
	novi->set_x(-(vek._x));
	novi->set_y(vek._y);
	
	return novi;
}

Vektor* Vektor::simetricni(const Vektor& vek){
	Vektor* novi = new Vektor();
	
	novi->set_x(-(vek._x));
	novi->set_y(-(vek._y));
	
	return novi;
}
		

double Vektor::duzina(){
	return sqrt(_x*_x + _y*_y);
}

//Vektor* Vektor::rotacija(const Vektor& vek, double angle){}

//double Vektor::izracunaj_ugao(const Vektor& vek1, const Vektor& vek2){}

ostream& operator <<(ostream& s, const Vektor& vek){ 
	vek.show(s);
	return s;
}

