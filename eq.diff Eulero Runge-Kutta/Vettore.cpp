#include"Vettore.h"

using namespace std;

Vettore::Vettore() {

	m_N=0;
	m_v=0;
}

Vettore::Vettore(int N) {

	m_N=N;
	m_v=new double[N];
	for(int i=0; i<N; i++) { m_v[i]=0; }
}

Vettore::~Vettore() { delete []m_v; }

Vettore::Vettore(const Vettore& V) {
	m_N=V.GetN();
	m_v=new double[m_N];
	for(int i=0; i<m_N; i++) {
	m_v[i]=V.GetComponent(i);}
}

Vettore& Vettore::operator=(const Vettore& V) {
	m_N=V.GetN();
	if(m_v) delete[] m_v;
	m_v=new double[m_N];
	for(int i=0; i<m_N; i++) {
	m_v[i]=V.GetComponent(i);}
	return *this;
}
