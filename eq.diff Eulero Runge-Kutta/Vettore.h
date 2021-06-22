#ifndef _Vettore_h_
#define _Vettore_h_

using namespace std;

class Vettore {
	
	protected:
	
	int m_N;	//vector size
	double *m_v;	//vector pointer

	public:

	Vettore();	
	Vettore(int N);	
	~Vettore();	
	
	int GetN() const {return m_N;}	//access to the size of the vector
	void SetComponent(unsigned int N , double x) {m_v[N]=x;}	//modify the i-th component
	double GetComponent(unsigned int i) const {return m_v[i];}	//access to the i-th component
	Vettore(const Vettore &);	//copy constructor
	Vettore& operator=(const Vettore &);	//overloading operatore di assegnazione
	
};

#endif 
