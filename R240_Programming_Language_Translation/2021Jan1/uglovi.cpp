#include "uglovi.hpp"

Ugao::Ugao(int step, int m, int sek){
	stepen = step;
	minut = m;
	sekund = sek;
	sredi(stepen, minut, sekund);
}

Ugao::Ugao(const Ugao& ug){
	stepen = ug.stepen;
	minut = ug.minut;
	sekund = ug.sekund;
	sredi(stepen, minut, sekund);
}

Ugao::Ugao(const Ugao& ug, char mode){
	stepen = ug.stepen;
	minut = ug.minut;
	sekund = ug.sekund;
	sredi(stepen, minut, sekund);
	
	if(mode == 'k'){
		if(stepen>=90){
			stepen = 90 - stepen;
			minut = 0 - minut;
			sekund = 0 - sekund;
		}
		else{
			sekund = 60 - sekund;
			minut = 59 - minut;
			stepen = 89 - stepen;
		}
	}
	else if(mode == 's'){
		if(stepen>=180){
			stepen = 180 - stepen;
			minut = 0 - minut;
			sekund = 0 - sekund;
		}
		else{
			sekund = 60 - sekund;
			minut = 59 - minut;
			stepen = 179 - stepen;
		}	
	}
}

void Ugao::show(ostream& s) const{
	s<<"<"<<stepen<<","<<minut<<","<<sekund<<">"<<endl;
}
		
Ugao* Ugao::operator +(const Ugao& ug){

	Ugao* novi = new Ugao();
	
	novi->set_stepen(stepen + ug.stepen);
	novi->set_minut(minut + ug.minut);
	novi->set_sekund(sekund + ug.sekund);
	
	sredi(novi->stepen, novi->minut, novi->sekund);
	
	return novi;
}

Ugao* Ugao::operator -(const Ugao& ug){
	Ugao* novi = new Ugao();
	
	novi->set_stepen(stepen - ug.stepen);
	novi->set_minut(minut - ug.minut);
	novi->set_sekund(sekund - ug.sekund);
	
	sredi(novi->stepen, novi->minut, novi->sekund);
	
	return novi;
}

Ugao* Ugao::operator *(const int v){
	Ugao* novi = new Ugao();
	
	novi->set_stepen(stepen*v);
	novi->set_minut(minut*v);
	novi->set_sekund(sekund*v);
	
	sredi(novi->stepen, novi->minut, novi->sekund);
	
	return novi;
}
		
/*Ugao* Ugao::komplement(const Ugao& ug) const{
	Ugao* novi = new Ugao();
	
	if(ug.stepen>=90){
		novi.stepen = 90 - ug.stepen;
		novi.minut = 0 - ug.minut;
		novi.sekund = 0 - ug.sekund;
	}
	else{
		novi.sekund = 60 - ug.sekund;
		novi.minut = 59 - ug.minut;
		novi.stepen = 89 - ug.stepen;
	}
	
	return novi;
}

Ugao* Ugao::suplement(const Ugao& ug) const {
	Ugao* novi = new Ugao();
	
	if(ug.stepen>=180){
		novi.stepen = 180 - ug.stepen;
		novi.minut = 0 - ug.minut;
		novi.sekund = 0 - ug.sekund;
	}
	else{
		novi.sekund = 60 - ug.sekund;
		novi.minut = 59 - ug.minut;
		novi.stepen = 179 - ug.stepen;
	}
	
	return novi;
}	
*/
bool Ugao::set_stepen(int v){
	stepen = v;
	return true;
}

bool Ugao::set_minut(int v){
	minut = v;
	return true;
}

bool Ugao::set_sekund(int v){
	sekund = v;
	return true;
}
		
int Ugao::get_stepen(){
	return stepen;
}

int Ugao::get_minut(){
	return minut;
}

int Ugao::get_sekund(){
	return sekund;
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
