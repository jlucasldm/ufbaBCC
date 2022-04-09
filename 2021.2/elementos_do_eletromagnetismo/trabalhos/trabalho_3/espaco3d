#include <iostream>
#include <cmath>
#include <iomanip> 

#define MS 11
#define HMS 5
#define DMS 3

using namespace std;

void print_matrices(double potencial[MS][MS][MS], double campo[MS][MS][MS][3], char* name) {
	cout << "Matrix de potencial eletrico (" << name << "): ";
	for(int x = 0; x < MS; x++) {
		cout << endl;
		for(int y = 0; y < MS; y++) {
			cout << endl; 
			for(int z = 0; z < MS; z++) {
				cout << potencial[x][y][z] << ", ";
			}
		}
	}
	cout << endl;
	cout << "Matrix de campo eletrico (" << name << "): ";
	for(int x = 0; x < MS; x++) {
		cout << endl;
		for(int y = 0; y < MS; y++) {
			cout << endl; 
			for(int z = 0; z < MS; z++) {
				cout << "(" << campo[x][y][z][0] << ", " << campo[x][y][z][1] << ", " << campo[x][y][z][2]<< "), ";
			}
		}
	}
	cout << endl << endl;
}

double distParaEsfera(int x, int y, int z, int cx, int cy, int cz, double r) {
	return sqrt(((x-cx)*(x-cx))+((y-cy)*(y-cy))+((z-cz)*(z-cz))) - r;
}

void esfera_condutora() {
	double potencial[MS][MS][MS];
	double campo[MS][MS][MS][3];
	for(int x = 0; x < MS; x++) {
		for(int y = 0; y < MS; y++) {
			for(int z = 0; z < MS; z++) {
				double q = 1.0 * pow(10.0, -9.0);
				double r = distParaEsfera(x, y, z, HMS, HMS, HMS, DMS);
				int rvec[3];
				double k;
				if(r > 0) {
					//Ponto está forá da esfera
					rvec[0] = x-HMS;
					rvec[1] = y-HMS;
					rvec[2] = z-HMS;
					k = 9.0 * pow(10.0, 9.0); 
				}else{
					//Ponto está dentro ou na superficie da esfera
					rvec[0] = HMS-x;
					rvec[1] = HMS-y;
					rvec[2] = HMS-z;
					k = 0;
				}
				potencial[x][y][z] = k*(q/abs(r));
				campo[x][y][z][0] = k*(q/pow(abs(r), 3.0))*rvec[0];
				campo[x][y][z][1] = k*(q/pow(abs(r), 3.0))*rvec[1];
				campo[x][y][z][2] = k*(q/pow(abs(r), 3.0))*rvec[2];
			}
		}
	}
	print_matrices(potencial, campo, (char*) "Esfera Condutora");
}

void casca_esferica_condutora() {
	double potencial[MS][MS][MS];
	double campo[MS][MS][MS][3];
	for(int x = 0; x < MS; x++) {
		for(int y = 0; y < MS; y++) {
			for(int z = 0; z < MS; z++) {
				double q = 1.0 * pow(10.0, -9.0);
				double r = distParaEsfera(x, y, z, HMS, HMS, HMS, DMS);
				int rvec[3];
				double k;
				if(r > 0) {
					//Ponto está forá da esfera
					rvec[0] = x-HMS;
					rvec[1] = y-HMS;
					rvec[2] = z-HMS;
					k = 9.0 * pow(10.0, 9.0); 
				}else if (r < 0){
					//Ponto está dentro da esfera
					rvec[0] = HMS-x;
					rvec[1] = HMS-y;
					rvec[2] = HMS-z;
					k = 9.0 * pow(10.0, 9.0);
				}else{
					//Ponto está na casca da esfera
					rvec[0] = 0;
					rvec[1] = 0;
					rvec[2] = 0;
					k = 0;
				}
				potencial[x][y][z] = k*(q/abs(r));
				campo[x][y][z][0] = k*(q/pow(abs(r), 3.0))*rvec[0];
				campo[x][y][z][1] = k*(q/pow(abs(r), 3.0))*rvec[1];
				campo[x][y][z][2] = k*(q/pow(abs(r), 3.0))*rvec[2];
			}
		}
	}
	print_matrices(potencial, campo, (char*) "Casca Esferica Condutora");
}

void esfera_isolante() {
	double potencial[MS][MS][MS];
	double campo[MS][MS][MS][3];
	for(int x = 0; x < MS; x++) {
		for(int y = 0; y < MS; y++) {
			for(int z = 0; z < MS; z++) {
				double q = 1.0 * pow(10.0, -9.0);
				double r = distParaEsfera(x, y, z, HMS, HMS, HMS, DMS);
				int rvec[3];
				double k;
				if(r > 0) {
					//Ponto está forá da esfera
					rvec[0] = x-HMS;
					rvec[1] = y-HMS;
					rvec[2] = z-HMS;
					k = 0; 
				}else{
					//Ponto está dentro ou na superficie da esfera
					r = 0;
					rvec[0] = HMS-x;
					rvec[1] = HMS-y;
					rvec[2] = HMS-z;
					k = 9.0 * pow(10.0, 9.0);
				}
				potencial[x][y][z] = k*(q/abs(r));
				campo[x][y][z][0] = k*(q/pow(abs(r), 3.0))*rvec[0];
				campo[x][y][z][1] = k*(q/pow(abs(r), 3.0))*rvec[1];
				campo[x][y][z][2] = k*(q/pow(abs(r), 3.0))*rvec[2];
			}
		}
	}
	print_matrices(potencial, campo, (char*) "Esfera Isolante");
}

int main() {
	cout << fixed << setprecision(2);
	int input = -1;
	while(input != 0) {
		cout << "Escolha um dos problemas a seguir: " << endl;
		cout << "1. Esfera condutora (3D)" << endl;
		cout << "2. Casca esfera condutora (3D)" << endl;
		cout << "3. Esfera isolante (3D)" << endl;
		cout << "Problema escolhido: ";
		cin >> input;
		cout << endl;
		switch (input) {
		case 1:
			esfera_condutora();
			break;
		case 2:
			casca_esferica_condutora();
			break;
		case 3:
			esfera_isolante();
			break;
		case 0:
			cout << "Saindo do programa..." << endl;
			return 0;
			break;
		default:
			input = -1;
			break;
		}
	}
	return 0;
}