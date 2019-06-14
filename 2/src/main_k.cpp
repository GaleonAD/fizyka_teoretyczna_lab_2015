#include <iostream>
#include <fstream>
#include <cmath>
#include <exception>

using namespace std;	

int main(int argc, char** argv){
// server
// 172.30.0.70/pft
	
	
	
// zmienne 
	double energia;
	double omega ; 
	double fi ;
	double z ;
	double v;

// warunki poczatkowe
	double fi_0 = 1.1;
	double omega_0 = 0.;
	double z_0 = 1.;
	double v_0 = 0.; 		 	 		
	double dt = 0.00001;
	double N = 10;
	double a = 0.5;
	// consty
	const double g = 9.81;	
	

	ofstream out;
	out.exceptions ( ofstream::failbit | ifstream::badbit );	
	
	
	string wynik_nazwa = "data.dat";

// argv
	wynik_nazwa = argv[1];
	fi_0 =atof( argv[2]);
	omega_0 =atof( argv[3]);
	z_0=atof( argv[4]);
	v_0=atof( argv[5]);
	dt=atof( argv[6]);
	N=atof(argv[7]);
	a=atof(argv[8]);

// zmienne stałe pomocnicze
	 double p1 = g * cos(a) * cos(a) / sin(a);
	 double p2 = sin(a)*sin(a);
	 double p3 = g * sin(a) * cos(a) * cos(a);
	 double ep1 = .5*sin(a)*sin(a)/(cos(a)*cos(a));
	 double ep2 = .5/(cos(a)*cos(a));
	 double ep3 = g*sin(a);
double V_max=0;
double a_max = 0;
	try{
		out.open( wynik_nazwa, std::ios::out );
			 	 
		omega = omega_0;
		fi = fi_0;
		z=z_0;
		v=v_0;
		energia = ep1*z*z*omega*omega + ep2*v*v +ep3*z*(1.-cos(fi));
	
		for( double aaa = 0.001 ; aaa < 1.4; aaa+=0.001 ){
		a = aaa;	
	  p1 = g * cos(a) * cos(a) / sin(a);
	  p2 = sin(a)*sin(a);
	  p3 = g * sin(a) * cos(a) * cos(a);
	  ep1 = .5*sin(a)*sin(a)/(cos(a)*cos(a));
	  ep2 = .5/(cos(a)*cos(a));
	  ep3 = g*sin(a);
		omega = omega_0;
		fi = fi_0;
		z=z_0;
		v=v_0;
		energia = ep1*z*z*omega*omega + ep2*v*v +ep3*z*(1.-cos(fi));
		for( double t = 0; t < N; t+=dt){

			omega -= ( p1*sin(fi)/z + 2*v*omega/z  )*dt;
			v +=  ( p2*z*omega*omega - p3*(1-cos(fi))  )*dt;
			fi += omega*dt;
			z += v*dt;

			energia = ep1*z*z*omega*omega + ep2*v*v +ep3*z*(1-cos(fi));
	
/*			out << t << " "
				<< fi << " " 
				<< omega << " " 
				<< z << " " 
				<< v << " " 
				<< energia  << endl;*/
		}
		out << a << " " << z << endl;
		if(V_max < z ){ V_max = z ; a_max = aaa; }
		}
		cout << "z_max: " << V_max << " alfa: "<< a_max << endl;
		out.close();
	
	}catch(exception& e){
	      cout << e.what() << endl;
	}
	

	return 0;
}

