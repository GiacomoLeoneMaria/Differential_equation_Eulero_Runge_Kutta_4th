#include"EquazioniDifferenziali.h"
#include"VettoreLineare.h"
#include<cmath>

using namespace std;

Eulero::Eulero() { }
Eulero::~Eulero() { }

Runge_Kutta::Runge_Kutta() { }
Runge_Kutta::~Runge_Kutta() { }

//OscillatoreArmonico::OscillatoreArmonico() {
	//m_omega0=0;
//}
OscillatoreArmonico::OscillatoreArmonico(double omega0) {
	m_omega0=omega0;
}
OscillatoreArmonico::~OscillatoreArmonico() { }

VettoreLineare OscillatoreArmonico::Eval(double t, const VettoreLineare &x) const { 
	VettoreLineare r(x.GetN());
	r.SetComponent(0,x.GetComponent(1)); //velocity v
	r.SetComponent(1,-x.GetComponent(0)*pow(m_omega0,2)); //-omega^2x
	return r;
}

VettoreLineare Eulero::Passo(double t, const VettoreLineare &x, double h, FunzioneVettorialeBase *f) const{
	return x+f->Eval(t,x)*h;
}

VettoreLineare Runge_Kutta::Passo(double t, const VettoreLineare &x, double h, FunzioneVettorialeBase *f) const {
	VettoreLineare k1(x.GetN());
	k1=f->Eval(t,x);
	VettoreLineare k2(x.GetN());
	k2=f->Eval(t+h/2,x+k1*(h/2));
	VettoreLineare k3(x.GetN());
	k3=f->Eval(t+h/2,x+k2*(h/2));
	VettoreLineare k4(x.GetN());
	k4=f->Eval(t+h,x+k3*h);

	return x+(k1+k2*2+k3*3+k4)*(h/6);
}



