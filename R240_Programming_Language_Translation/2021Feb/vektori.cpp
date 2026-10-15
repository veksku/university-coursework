#include "vektori.hpp"		

Vektor::Vektor(double x, double y){ 
	_x = x;
	_y = y;
}

Vektor::Vektor(double x1, double x2, double y1, double y2){ 
	_x = x2 - x1;
	_y = y2 - y1;
}

Vektor::Vektor(const Vektor& vek){
	_x = vek._x;
	_y = vek._y;
}
		
void Vektor::show(ostream& s) const{
	s<<'<'<<_x<<","<<_y<<">"<<endl;
}
		
Vektor* Vektor::operator +(const Vektor& vek) const{
	Vektor* novi = new Vektor();
	
	novi->set_x(_x + vek._x);
	novi->set_y(_y + vek._y);
	
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
		
void Vektor::set_x(double x){
	_x = x;
}

void Vektor::set_y(double y){
	_y = y;
}
		
double Vektor::get_x(){
	return _x;
}

double Vektor::get_y(){
	return _y;
}

ostream& operator <<(ostream& s, const Vektor& vek){ 
	vek.show(s);
	return s;
}

