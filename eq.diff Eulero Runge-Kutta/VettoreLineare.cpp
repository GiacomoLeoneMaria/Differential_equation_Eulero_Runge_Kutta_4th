#include"VettoreLineare.h"
#include"Vettore.h"
#include<iostream>

using namespace std;

VettoreLineare::VettoreLineare(unsigned int a): Vettore(a) { }

VettoreLineare::~VettoreLineare() { }

VettoreLineare VettoreLineare::operator+(const VettoreLineare &V) const {

	VettoreLineare r(GetN());
	
	if (GetN()!=V.GetN()) {
		cerr << " vettori di dimensione diversa " << endl;
	return -1;
	}

	for (int i=0; i<GetN(); i++) {
		r.SetComponent(i, V.GetComponent(i)+GetComponent(i));
	}
	return r;
}

VettoreLineare VettoreLineare::operator*(const double x) const {
	VettoreLineare r(GetN());
	for (int i=0; i<GetN(); i++) {
		r.SetComponent(i, x*GetComponent(i));
	}
	return r;
}
		
	
double VettoreLineare::operator*(const VettoreLineare &V) const {
	if (GetN()!=V.GetN()) { 
		cerr << " vectors of different size " << endl;
	return -1;
	}
	
	double k=0;

	for (int i=0; i<GetN(); i++) {
		k+=GetComponent(i)*V.GetComponent(i);
	}
	return k;
}		
		





	
