#include "uglovi.hpp"

Ugao::Ugao(int step, int m, int sek){
	_u[0] = step;
	_u[1] = m;
	_u[2] = sek;
	sredi(_u[0], _u[1], _u[2]);
}

Ugao::Ugao(const Ugao& ug){
	_u[0] = ug._u[0];
	_u[1] = ug._u[1];
	_u[2] = ug._u[2];
	sredi(_u[0], _u[1], _u[2]);
}

Ugao::Ugao(const Ugao& ug, char mode){
	_u[0] = ug._u[0];
	_u[1] = ug._u[1];
	_u[2] = ug._u[2];
	sredi(_u[0], _u[1], _u[2]);	
	
	if(mode == 'k'){
		if(_u[0]>=90){
			_u[0] = 90 - _u[0];
			_u[1] = 0 - _u[1];
			_u[2] = 0 - _u[2];
		}
		else{
			_u[2] = 60 - _u[2];
			_u[1] = 59 - _u[1];
			_u[0] = 89 - _u[0];
		}
	}
	else if(mode == 's'){
		if(_u[0]>=180){
			_u[0] = 180 - _u[0];
			_u[1] = 0 - _u[1];
			_u[2] = 0 - _u[2];
		}
		else{
			_u[2] = 60 - _u[2];
			_u[1] = 59 - _u[1];
			_u[0] = 179 - _u[0];
		}		
	}
}

int Ugao::get_size() const{
	return _u.size()/3;
}

void Ugao::push_back(const Ugao& ug){
	_u.push_back(ug._u[0]);
	_u.push_back(ug._u[1]);
	_u.push_back(ug._u[2]);
}

void Ugao::show(ostream& s) const{
	s<<"<"<<_u[0]<<","<<_u[1]<<","<<_u[2]<<">"<<endl;
}
		
	
Ugao* Ugao::operator +(const Ugao& ug){

	Ugao* novi = new Ugao();
	
	novi->set_stepen(_u[0] + ug._u[0]);
	novi->set_minut(_u[1] + ug._u[1]);
	novi->set_sekund(_u[2] + ug._u[2]);
	
	sredi(novi->_u[0], novi->_u[1], novi->_u[2]);
	
	return novi;
}

Ugao* Ugao::operator -(const Ugao& ug){
	Ugao* novi = new Ugao();
	
	novi->set_stepen(_u[0] - ug._u[0]);
	novi->set_minut(_u[1] - ug._u[1]);
	novi->set_sekund(_u[2] - ug._u[2]);
	
	sredi(novi->_u[0], novi->_u[1], novi->_u[2]);
	
	return novi;
}

Ugao* Ugao::operator *(const int v){
	Ugao* novi = new Ugao();
	
	novi->set_stepen(_u[0]*v);
	novi->set_minut(_u[1]*v);
	novi->set_sekund(_u[2]*v);
	
	sredi(novi->_u[0], novi->_u[1], novi->_u[2]);
	
	return novi;
}

void Ugao::set_stepen(int v){
	_u[0] = v;
}

void Ugao::set_minut(int v){
	_u[1] = v;
}

void Ugao::set_sekund(int v){
	_u[2] = v;
}
		
int Ugao::get_stepen(){
	return _u[0];
}

int Ugao::get_minut(){
	return _u[1];
}

int Ugao::get_sekund(){
	return _u[2];
}

void Ugao::sredi(int& step, int& m, int& sek){
	while(sek>=60){
		m += 1;
		sek -= 60;
	}
	while(m>=60){
		step += 1;
		m -= 60;
	}
	while(step>=360)
		step -= 360;
}

ostream& operator <<(ostream& s, const Ugao& ug){
	ug.show(s);
	return s;
}
