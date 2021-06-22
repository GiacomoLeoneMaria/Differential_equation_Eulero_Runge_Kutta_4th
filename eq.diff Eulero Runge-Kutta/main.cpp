#include"EquazioniDifferenziali.h"
#include"VettoreLineare.h"
#include<cstdlib>
#include<iostream>
#include"TCanvas.h"
#include"TGraph.h"
#include"TAxis.h"
#include"TApplication.h"

using namespace std;

int main(int argc, char** argv) {

	if(argc!=1) {
	cerr << " inserire " << argv[0] << endl;
	return -1;
	}

	double h;
   cout << "passo con qui calcolare l'equazione differenziale: ";
   cin >> h;
	TApplication myApp("myApp",0,0);
	Runge_Kutta RungeKutta;
  Eulero Eulero;
	OscillatoreArmonico *oscillatore=new OscillatoreArmonico(1.); //omega0=1
	double tmax=70;
	TGraph *Posizione=new TGraph();
	TGraph *Errore=new TGraph();
	Posizione->SetTitle("Posizione RungeKutta");
	Errore->SetTitle("Errore RungeKutta");
  TGraph *Posizione1=new TGraph();
	TGraph *Errore1=new TGraph();
	Posizione1->SetTitle("Posizione Eulero");
	Errore1->SetTitle("Errore Eulero");
	int nstep=(tmax/h);
	double t=0;
	VettoreLineare x(2);
	x.SetComponent(0,0.); //posizione
	x.SetComponent(1,1.); //velocità
  VettoreLineare x1(2);
	x1.SetComponent(0,0.); 
	x1.SetComponent(1,1.);
	for (int step=0; step<nstep; step++) {
		Posizione->SetPoint(step,t,x.GetComponent(0));
		Errore->SetPoint(step,t,x.GetComponent(0)-sin(t));
		x=RungeKutta.Passo(t,x,h,oscillatore);
    Posizione1->SetPoint(step,t,x1.GetComponent(0));
		Errore1->SetPoint(step,t,x1.GetComponent(0)-sin(t));
		x1=Eulero.Passo(t,x,h,oscillatore);
		t=t+h;
	}
	
	TCanvas *myCanvas=new TCanvas("c1","c2",1);
	myCanvas->Divide(2,2);
	myCanvas->cd(1);
	Posizione->Draw("AL*");
  Posizione->GetXaxis()->SetTitle("t[s]");
  Posizione->GetYaxis()->SetTitle("x[m]");
	myCanvas->cd(2);
  Errore->GetXaxis()->SetTitle("t[s]");
  Errore->GetYaxis()->SetTitle("errore a t=70s");
	Errore->Draw("AL*");
  myCanvas->cd(3);
	Posizione1->Draw("AL*");
  Posizione1->GetXaxis()->SetTitle("t[s]");
  Posizione1->GetYaxis()->SetTitle("x[m]");
	myCanvas->cd(4);
  Errore1->GetXaxis()->SetTitle("t[s]");
  Errore1->GetYaxis()->SetTitle("errore a t=70s");
	Errore1->Draw("AL*");

	myApp.Run();
}




