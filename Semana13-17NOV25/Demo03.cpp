#include <iostream>

using namespace std;

int main(){

	int a = 42; // Variable normal
	int* ptr = &a;  // ptr guarda la dirección de a
	
	cout << "Valor de a = " << a << endl;
	cout << "Valor de ptr: " << ptr << endl;
	
	cout << "Valor de a = " << *ptr << endl;

	return 0;
}
