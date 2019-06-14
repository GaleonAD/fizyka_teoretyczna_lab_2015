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
	double fi ; 
	double p_fi ;
	double r ;
	double p_r;
	double z;
	double p_z;
	double B,m,e,N,dt;



// warunki poczatkowe
	double fi_0;
	double p_fi_0 = 1.;
	double r_0=1.;
	double p_r_0=1.; 		
	double z_0=1.;
	double p_z_0=1.;
	// consty
	

	ofstream out;
	out.exceptions ( ofstream::failbit | ifstream::badbit );	
	
	
	string wynik_nazwa = "data.dat";

// argv
	B=m=e=1.;
	wynik_nazwa = argv[1];
	fi_0 =atof( argv[2]);
	r_0 =atof( argv[3]);
	p_r_0=atof( argv[4]);
	
	p_fi_0 = 0.;
	z_0=1.;
	p_z_0=1.;

	dt=atof( argv[5]);
	N=atof(argv[6]);


// zmienne stałe pomocnicze

	try{
		out.open( wynik_nazwa, std::ios::out );
			 	 
		fi = fi_0;
		p_fi=p_fi_0;
		r=r_0;
		p_r=p_r_0;
		z=z_0;
		p_z=p_z_0;

		energia = (p_z*p_z + p_r*p_r + p_fi*p_fi/(r*r))/(2.*m) - e*B*p_fi/(2.*m)  
					+ r*r*e*e*B*B/(8.*m);
			
	

		for( double t = 0; t < N; t+=dt){

			
			fi+=(p_fi/(m*r*r)-e*B/(2.*m))*dt; 
			r+=p_r*dt/m;
			p_r+=(p_fi*p_fi/(m*r*r*r) -e*e*B*B*r/(4.*m))*dt;

			energia = (p_z*p_z + p_r*p_r + p_fi*p_fi/(r*r))/(2.*m) - e*B*p_fi/(2.*m)  
					+ r*r*e*e*B*B/(8.*m);
	
			out << t << " "
				<< fi << " " 
				<< r << " " 
				<< p_r << " " 
				<< energia  << " "
				<< r*cos(fi) << " "
				<< r*sin(fi) << endl;
		}
		out.close();
	
	}catch(exception& e){
	      cout << e.what() << endl;
	}
	

	return 0;
}

