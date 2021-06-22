#ifndef _VettoreLineare_h_
#define _VettoreLineare_h_
#include"Vettore.h"

class VettoreLineare: public Vettore {

	public:

	VettoreLineare(unsigned int);
	~VettoreLineare();
	
	VettoreLineare operator+(const VettoreLineare &) const;
	VettoreLineare operator*(const double) const;
	double operator*(const VettoreLineare &) const;
};

#endif
