#include <iostream>
#include <fstream>
#include <cmath>
#include <exception>

using namespace std;	

int main(int argc, char** argv){
// server
// 172.30.0.70/pft
	

// obsluga plikow
	ofstream outFile, elektrodyFile;
	ifstream inFile;

	outFile.exceptions ( ofstream::failbit | ifstream::badbit );	
	elektrodyFile.exceptions ( ofstream::failbit | ifstream::badbit );	
	inFile.exceptions ( ofstream::failbit | ifstream::badbit );	
	
	string inFile_name, outFile_name; 
	string elektrodyFile_name = "elektrody_out";

	inFile_name = argv[1];
	outFile_name = argv[2];
//  tworzenie tablic & zmiennych

	double dx;
	double dy;
	double dz;

	int nx;
	int ny;
	int nz;
	int nz1;
	int nz2;

	int nx_elektrody[12]; //nx1,nx2,nx3,nx4,nx5,nx6,nx7,nx8,nx9,nx10,nx11,nx12;
	int ny_elektrody[12]; //1,ny2,ny3,ny4,ny5,ny6,ny7,ny8,ny9,ny10,ny11,ny12;

	int iter_zew, iter_wew;



	try{
		inFile.open( inFile_name, std::ios::in );
		outFile.open( outFile_name, std::ios::out);
		elektrodyFile.open( elektrodyFile_name, std::ios::out);
		

		// czytanie z pliku 
		cout << "Czytam dane..." << endl;

		inFile >> dx >> dy >> dz
				 >> nx >> ny >> nz
				 >> nz1 >> nz2;
		inFile	 >> iter_zew;
		inFile 	 >> iter_wew;
		// tablice 	
		double V[nx][ny][nz];
		double Vn[nx][ny][nz];
		double V_const[7];
		double dd = 2./dx/dx+2./dy/dy+2./dz/dz;
		double dx2 = dx*dx;
		double dy2 = dy*dy;
		double dz2 = dz*dz;

		for( int i = 0; i<12 ; i+=2 ){
			inFile >> nx_elektrody[i] >> nx_elektrody[i+1]; 
			inFile >> ny_elektrody[i] >> ny_elektrody[i+1];
		}
		
		for( int i = 0; i < 7 ; ++i )
			inFile >> V_const[i];

		cout << "Sprawdzam reading... " << endl;
		cout << dx << " " << dy << " " << dz << endl;
		cout << nx << " " << ny << " " << nz << endl;
		cout << nz1 << " " << nz2 << " " << endl
			<< iter_zew <<  " " << iter_wew << endl;

			cout << endl;

		for( int i = 0; i<12 ; i+=2 )
			cout << nx_elektrody[i] << " " << nx_elektrody[i+1] << " " 
					<< ny_elektrody[i] << " " << ny_elektrody[i+1] << endl;
			cout << endl;
				
		for( int i = 0; i < 7 ; ++i )
			cout << V_const[i] << " ";
			cout << endl;
			cout << endl;

		//	petle programu
		cout << "Rozpoczynam symlację" << endl;
		// for zmieniajace Vn
		// for poprawiajace odtwarzanie
		// warunki brzegowe => dolna płyta cała = 0, jej nie zmieniamy, jej tu nie ma, na brzegach pochodne = 0;
		
		//zrowanie V
		for( int x = 0; x < nx; ++x){
			for(int y = 0; y < ny; ++y){
				for(int z = 0; z < nz; ++z){
					V[x][y][z]= Vn[x][y][z] = 0.;
				}}}
		// potencjał podłoża I ele
		for( int x =0; x < nx; ++x){
			for( int y =0; y < ny; ++y){
				V[x][y][0]=Vn[x][y][0]=V_const[0];
			}}
		for( int i = 0; i<6 ; i++ ){
			for( int x=nx_elektrody[2*i]; x < nx_elektrody[2*i+1]; x++){
				for( int y =ny_elektrody[2*i]; y < ny_elektrody[2*i+1]; y++){
					V[x][y][nz2] = V_const[i+1];
				}}}
		for( int x = 0; x < nx ; ++x){
			for( int y = 0; y < ny ; ++y){
			//	elektrodyFile << x << " " << y << " ";
			//	if( V[x][y][nz2]  > 0 ) elektrodyFile << 1.  << endl;
			//	else elektrodyFile << 0. << endl;
				elektrodyFile << x << " " << y << " " << V[x][y][nz2] << endl;
			}
		}
		elektrodyFile.close();
		inFile.close();
		// petle
		for( int zew = 0; zew < iter_zew; ++zew ){
			
			for( int wew = 0; wew < iter_wew; ++wew){			
			
			// odnawianie elektrod
			for( int i = 0; i<6 ; i++ ){
				for( int x=nx_elektrody[2*i]; x < nx_elektrody[2*i+1]; x++){
					for( int y =ny_elektrody[2*i]; y < ny_elektrody[2*i+1]; y++){
						V[x][y][nz2] = V_const[i+1];
					}}}
				
			// równanie
			
			for( int x = 1; x < nx-1; ++x ){
				for( int y = 1; y < ny-1; ++y ){
					for( int z = 1; z < nz-1; ++z){
						Vn[x][y][z] =( 
							(V[x-1][y][z] + V[x+1][y][z])/dx2 +
							(V[x][y-1][z] + V[x][y+1][z])/dy2 +
							(V[x][y][z-1] + V[x][y][z+1])/dz2
						 )/dd;
					
					}}}

			// warunki brzegowe

			for( int x = 0; x < nx; ++x){
				for( int y = 0; y < ny; ++y){
					Vn[x][y][0] = Vn[x][y][1];
					Vn[x][y][nz-1] = Vn[x][y][nz-2];
				}}
			for( int y = 0; y < ny; ++y){
				for( int z = 0; z < nz; ++z){
					Vn[0][y][z] = Vn[1][y][z];
					Vn[nx-1][y][z] = Vn[nx-2][y][z];
				}}
			for( int x = 0; x < nx; ++x){
				for( int z = 0; z < nz; ++z){
					Vn[x][0][z] = Vn[x][1][z];
					Vn[x][ny-1][z] = Vn[x][ny-2][z];
				}}
			
			// przepisywanie
			for( int x = 0; x < nx; ++x ){
				for( int y = 0; y < ny; ++y ){
					for( int z = 1; z < nz; ++z){
						V[x][y][z] = Vn[x][y][z];
					}}}
					
			// koniec wew petli	
			}	

			// zapis do pliku


		//	cout<<"\rzew="<<zew+1<<" na "<<iter_zew << " control: " << V[nx/2][ny/2][nz1]<<flush;
		cout << "i=" << zew+1 << " " << V[nx/2][ny/2][nz1] << endl;
		}
		cout << endl;	

		for( int x = 0; x < nx; ++x){
			for( int y=0; y < ny; ++y){
				outFile << x << " " << y << " " << V[x][y][nz1] << endl;
			} outFile << endl;
			}
	
		outFile.close();
	
	}catch(exception& e){
	      cout << e.what() << endl;
	}
	
	return 0;
}

