#include <iostream>
using namespace std;

float terminoN(int n){
	return (3.0/n);
}

float sumatoria(int n){
	// Variables
	float s;
	// Proceso
	s = 0;
	for(int i=1; i <= n; i++){
		s += terminoN(i);
	}
	// Reporte
	return s;
}

int main(){
	// Variables
	float sumatoria_;
	int n;
	// Datos
	cout << "Valor para N: "; cin >> n;
	// Proceso
	sumatoria_ = sumatoria(n);
	// Reporte
	cout << endl;
	cout << "Reporte" << endl;
	cout << "==================" << endl;
	cout << "N: " << n << endl;
	cout << "Sumatoria: " << sumatoria_ << endl; 
	return 0;
}
