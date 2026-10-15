#include "matrica.hpp"

Matrica::Matrica(){
	_elementi.resize(0);
}

Matrica::Matrica(const vector<double> v) {
	_elementi.resize(0);
	_elementi.push_back(v);
}

void Matrica::dodajRed(const vector<double> v){
	if (sirina() != v.size())
		throw "Neodgovarajuce dimenzije redova u matrici";
	_elementi.push_back(v);
}

unsigned Matrica::visina() const{
	return _elementi.size();
}
unsigned Matrica::sirina() const{
	return _elementi[0].size();
}
void Matrica::pisi(ostream& izlaz) const{
	for (unsigned i = 0; i< visina(); i++){
		for (unsigned j = 0; j< sirina(); j++)
			izlaz << "\t" << _elementi[i][j];
		izlaz << endl;
	}
}


Matrica Matrica::operator+(const Matrica &m){
	if (visina() != m.visina() || sirina() != m.sirina())
		throw "Neodgovarajuce dimenzije pri sabiranju";
	Matrica r(m);
	for (unsigned i = 0; i< visina(); i++)
		for (unsigned j= 0; j< sirina(); j++)
			r._elementi[i][j] += _elementi[i][j];
	return r;
}

Matrica Matrica::operator-(const Matrica &m){
	if (visina() != m.visina() || sirina() != m.sirina())
		throw "Neodgovarajuce dimenzije pri oduzimanju";
	Matrica r(*this);
	for (unsigned i = 0; i< visina(); i++)
		for (unsigned j= 0; j< sirina(); j++)
			r._elementi[i][j] -= _elementi[i][j];
	return r;
}

Matrica Matrica::operator*(const Matrica &m){
	if(sirina() != m.visina())
		throw "Nemoguce mnozenje matrica";
	return *this;
}

Matrica Matrica::pm(const Matrica &m){ //pokoordinatno mnozenje
	if (visina() != m.visina() || sirina() != m.sirina())
		throw "Neodgovarajuce dimenzije pri pokoordinatnom mnozenju";
	Matrica r(*this);
	for (unsigned i = 0; i< visina(); i++)
		for (unsigned j= 0; j< sirina(); j++)
			r._elementi[i][j] *= _elementi[i][j];
	return r;
}

Matrica Matrica::transponovana() const{
	//TODO     
	return *this;
}

ostream& operator<<(ostream& izlaz, const Matrica m) {
	m.pisi(izlaz);
	return izlaz;
}
