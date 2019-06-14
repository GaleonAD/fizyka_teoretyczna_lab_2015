#include <iostream>
#include <fstream>
#include <cmath>
#include <exception>

using namespace std;	

int main(){
// server
// 172.30.0.70/pft
	
	double dt=0.00001;
	double R=1.;
	double g = 9.82;
	double omega_0 = 0.;
	double fi_0 = M_PI/4.;
	double N=5.;
	int M = 179;

	ofstream out;
	out.exceptions ( ofstream::failbit | ifstream::badbit );	
	
	
	string wynik_nazwa = "data.dat";

	cout << "Wyjście: ";
	cin >> wynik_nazwa;

	cout << "Fi_0: ";
//	cin >> fi_0;

	

//	cout << fi_0;

/*
	cout << "dt: ";
	cin >> dt;

	cout << "N: ";
	cin >> N;
*/	
	
	
	double  omega ; 
	double  fi ;
	double  energia ;
	

		
	
	try{
		out.open( wynik_nazwa, std::ios::out );
			 	 
		omega = omega_0;
		fi = fi_0;
		energia = R*R*omega_0*omega_0/2-g*R*cos( fi_0 );
	
		for( double t = 0; t < N; t+=dt){

			omega -= sin( fi ) * dt * g/R;
			fi +=  omega*dt;
			energia = R*R*omega*omega/2. - g*R*cos( fi ); 
	
			out << t << " "
				<< fi << " " 
				<< omega << " " 
				<< energia  << endl;
		}
		out.close();

// wykres T(A)

		wynik_nazwa += "T";
		out.open( wynik_nazwa , std::ios::out );
		
		double fi_T, omega_T, T;

		for( double j = 1; j < M; ++j ){
			
			fi_0 = j*M_PI/180.;
			fi_T = fi_0;
	 		omega_T= omega_0;
			T=0;
	
			for( double t =0.; t < N; t+=dt){

				omega_T -=  sin( fi_T ) * dt * g/R;
				fi_T += omega_T*dt;
				T +=dt;
				if(fi_T < 0.){ break; }
			}
			out << fi_0 << " " << 4*T << endl;
		}

		out.close();

	}catch(exception& e){
	      cout << e.what() << endl;
	}
	

	return 0;
}

