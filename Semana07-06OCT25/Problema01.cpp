#include <iostream>
using namespace std;

bool esPrimo(int n){
	// Validación
	if(n<=1) return false;
	// Proceso
	bool primo = true; // Se asume que es primo, punto de partida;
	for(int i=2;i<n;i++){
		if(n%i==0){
			primo = false;
			break;
		}
	}
	// Reporte
	return primo;	
} 

int main(){
	// Datos
	int n7 = 7;
	int n6 = 6;
	int n2 = 2;
	int n1 = 1;
	// Proceso
	int primo7 = esPrimo(n7);
	int primo6 = esPrimo(n6);
	int primo2 = esPrimo(n2);
	int primo1 = esPrimo(n1);
	// Reporte
	cout << "Reporte" << endl;
	cout << "=================" << endl;
	cout << n7 << " es primo? " << primo7 << endl;
	cout << n6 << " es primo? " << primo6 << endl;
	cout << n2 << " es primo? " << primo2 << endl;
	cout << n1 << " es primo? " << primo1 << endl;
	
	return 0;
}
