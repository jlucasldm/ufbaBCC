#include <iostream>
#include <cmath>
#include <iomanip> 

#define MS 11
#define HMS 5
#define DMS 3

using namespace std;

void print_matrices(double potencial[MS][MS], double campo[MS][MS][2], char* name) {
	cout << "Matrix de potencial eletrico (" << name << "): ";
	for(int x = 0; x < MS; x++) {
		cout << endl;
		for(int y = 0; y < MS; y++) {
			cout << potencial[x][y] << ", ";
		}
	}
	cout << endl;
	cout << "Matrix de campo eletrico (" << name << "): ";
	for(int x = 0; x < MS; x++) {
		cout << endl;
		for(int y = 0; y < MS; y++) {
			cout << "(" << campo[x][y][0] << ", " << campo[x][y][1] << "), ";
		}
	}
	cout << endl << endl;
}


void carga_isolada(){
	double potencial[MS][MS];
	double campo[MS][MS][2];
	for(int x = 0; x < MS; x++) {
		for(int y = 0; y < MS; y++) {
			double q = 1.0 * pow(10.0, -9.0);
			int rvec[2] = {HMS-x, HMS-y};
			double r = sqrt(((HMS-x)*(HMS-x))+((HMS-y)*(HMS-y)));
			double k = 9.0 * pow(10.0, 9.0);
			potencial[x][y] = k*(q/r);
			campo[x][y][0] = k*(q/pow(r, 3.0))*rvec[0];
			campo[x][y][1] = k*(q/pow(r, 3.0))*rvec[1];
		}
	}
	print_matrices(potencial, campo, (char*) "Carga Isolada");
}

void carga_dipolo(){
	double potencial[MS][MS];
	double campo[MS][MS][2];
	for(int x = 0; x < MS; x++) {
		for(int y = 0; y < MS; y++) {
			double q1 = 1.0 * pow(10.0, -9.0); // q1 em [2][5]
			double q2 = -1.0 * pow(10.0, -9.0); // q2 em [8][5] 
			int rvec1[2] = {(DMS-1)-x, HMS-y};
			int rvec2[2] = {(MS-DMS)-x, HMS-y};
			double r1 = sqrt((((DMS-1)-x)*((DMS-1)-x))+((HMS-y)*(HMS-y)));
			double r2 = sqrt((((MS-DMS)-x)*((MS-DMS)-x))+((HMS-y)*(HMS-y)));
			double k = 9.0 * pow(10.0, 9.0);
			potencial[x][y] = k*(q1/r1) + k*(q2/r2);
			campo[x][y][0] = k*(q1/pow(r1, 3.0))*rvec1[0] + k*(q2/pow(r2, 3.0))*rvec2[0];
			campo[x][y][1] = k*(q1/pow(r1, 3.0))*rvec1[1] + k*(q2/pow(r2, 3.0))*rvec2[1];
		}
	}
	print_matrices(potencial, campo, (char*) "Cargas Dipolo");
}

double distParaCirculo(int x, int y, int cx, int cy, double r) {
	return sqrt(((x-cx)*(x-cx))+((y-cy)*(y-cy))) - r;
}

void circulo_condutor() {
	double potencial[MS][MS];
	double campo[MS][MS][2];
	for(int x = 0; x < MS; x++) {
		for(int y = 0; y < MS; y++) {
			double q = 1.0 * pow(10.0, -9.0);
			double r = distParaCirculo(x, y, HMS, HMS, DMS);
			int rvec[2];
			double k;
			if(r > 0) {
				rvec[0] = x-HMS;
				rvec[1] = y-HMS;
				k = 9.0 * pow(10.0, 9.0);
			}else{
				rvec[0] = HMS-x;
				rvec[1] = HMS-y;
				k = (9.0 * pow(10.0, 9.0))/81.0; //Material = Agua
			}
			potencial[x][y] = k*(q/abs(r));
			campo[x][y][0] = k*(q/pow(abs(r), 3.0))*rvec[0];
			campo[x][y][1] = k*(q/pow(abs(r), 3.0))*rvec[1];
		}
	}
	print_matrices(potencial, campo, (char*) "Circulo Condutor");
}

void circulo_isolante() {
	double potencial[MS][MS];
	double campo[MS][MS][2];
	for(int x = 0; x < MS; x++) {
		for(int y = 0; y < MS; y++) {
			double q = 1.0 * pow(10.0, -9.0);
			double r = distParaCirculo(x, y, HMS, HMS, DMS);
			int rvec[2];
			double k;
			if(r > 0) {
				rvec[0] = x-HMS;
				rvec[1] = y-HMS;
				k = 9.0 * pow(10.0, 9.0);
			}else{
				rvec[0] = 0;
				rvec[1] = 0;
				k = (9.0 * pow(10.0, 9.0))/3.0; //Material = Borracha
				r = 0.0; //O circulo é a carga?
			}
			potencial[x][y] = k*(q/r);
			campo[x][y][0] = k*(q/pow(r, 3.0))*rvec[0];
			campo[x][y][1] = k*(q/pow(r, 3.0))*rvec[1];
		}
	}
	print_matrices(potencial, campo, (char*) "Circulo Isolante");
}

void semiplano_condutor() {
	double potencial[MS][MS];
	double campo[MS][MS][2];
	for(int x = 0; x < MS; x++) {
		for(int y = 0; y < MS; y++) {
			double q = 1.0 * pow(10.0, -9.0);
			double r = abs(x-HMS);
			int rvec[2];
			double k;
			if(r > 0) {
				k = 9.0 * pow(10.0, 9.0);
			}else{
				k = (9.0 * pow(10.0, 9.0))/81.0; //Material = Agua
			}
			potencial[x][y] = k*(q/r);
			campo[x][y][0] = k*(q/pow(r, 3.0))*rvec[0];
			campo[x][y][1] = k*(q/pow(r, 3.0))*rvec[1];
		}
	}
	print_matrices(potencial, campo, (char*) "Semiplano Infinito Condutor");
}

void semiplano_isolante() {
	double potencial[MS][MS];
	double campo[MS][MS][2];
	for(int x = 0; x < MS; x++) {
		for(int y = 0; y < MS; y++) {
			double q = 1.0 * pow(10.0, -9.0);
			double r = abs(x-HMS);
			int rvec[2];
			double k;
			if(r > 0) {
				k = 9.0 * pow(10.0, 9.0);
			}else{
				k = (9.0 * pow(10.0, 9.0))/3.0; //Material = Borracha
			}
			potencial[x][y] = k*(q/r);
			campo[x][y][0] = k*(q/pow(r, 3.0))*rvec[0];
			campo[x][y][1] = k*(q/pow(r, 3.0))*rvec[1];
		}
	}
	print_matrices(potencial, campo, (char*) "Semiplano Infinito Isolante");
}

int main(){
	cout << fixed << setprecision(2);
	int input = -1;
	while(input != 0) {
		cout << "Escolha um dos problemas a seguir: " << endl;
		cout << "1. Carga Isolada (2D)" << endl;
		cout << "2. Cargas Dipolo (2D)" << endl;
		cout << "3. Círculo condutor com carga na circunferência (2D)" << endl;
		cout << "4. Círculo isolante com carga na superfície (2D)" << endl;
		cout << "5. Semiplano infinito condutor com densidade de cargas na superfície (2D)" << endl;
		cout << "6. Semiplano infinito isolante com densidade de cargas na superfície (2D)" << endl;
		cout << "Problema escolhido: ";
		cin >> input;
		cout << endl;
		switch (input) {
		case 1:
			carga_isolada();
			break;
		case 2:
			carga_dipolo();
			break;
		case 3:
			circulo_condutor();
			break;
		case 4:
			circulo_isolante();
			break;
		case 5:
			semiplano_condutor();
			break;
		case 6:
			semiplano_isolante();
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