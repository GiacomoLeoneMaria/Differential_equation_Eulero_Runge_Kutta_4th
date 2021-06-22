#ifndef _EquazioniDifferenziali_h_
#define _EquazioniDifferenziali_h_
#include"VettoreLineare.h"

class FunzioneVettorialeBase {

	public:
	virtual VettoreLineare Eval(double t, const VettoreLineare &x) const=0;
};

class EquazioneDifferenzialeBase {

	public:
	virtual VettoreLineare Passo(double t, const VettoreLineare &x, double h, FunzioneVettorialeBase *f) const=0;
};

class OscillatoreArmonico: public FunzioneVettorialeBase {
	
	public:
	OscillatoreArmonico(double omega0);
	~OscillatoreArmonico();
	virtual VettoreLineare Eval(double t, const VettoreLineare &x) const;
	private:
	double m_omega0;
};

class Eulero: public EquazioneDifferenzialeBase {

	public:
	Eulero();
	~Eulero();
	virtual VettoreLineare Passo(double t, const VettoreLineare &x, double h, FunzioneVettorialeBase *f) const;
};

class Runge_Kutta: public EquazioneDifferenzialeBase {

	public:
	Runge_Kutta();
	~Runge_Kutta();
	virtual VettoreLineare Passo(double t, const VettoreLineare &x, double h, FunzioneVettorialeBase *f) const;
};

#endif
