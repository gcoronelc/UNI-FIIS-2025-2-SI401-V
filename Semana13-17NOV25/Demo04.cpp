#include <iostream>

using namespace std;

void potencia(int* n){
	cout << "Valor de n: " << *n << "\n";
	cout << "Direccion de n: " << n << "\n";
	*n = (*n) * (*n);
	cout << "Valor de n al 2do: " << (*n) << "\n";
}

int main(){
	
	int a = 5;
	
	cout << "Valor de a: " << a << "\n";
	cout << "Direccion de a: " << &a << "\n";
	
	potencia(&a);
	cout << "Valor de a: " << a << "\n";
	
	
	return 0;
}


