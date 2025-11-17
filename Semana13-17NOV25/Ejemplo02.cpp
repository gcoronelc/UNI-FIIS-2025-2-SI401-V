/*
Arreglos Dinamicos
*/

#include <iostream>
using namespace std;

int main(){
	
	//configuracion
  setlocale(LC_ALL, "spanish");
  
  // Variables
  int notas[] = {16,17,20,14,18};
  int *puntero;
  
  // Recorriendo el arreglo con el puntero
  //puntero = notas;
  puntero = &notas[0];
  for(int i=0; i<5; i++){
  	cout << "Notas[" << i << "] = " << *puntero << endl;
  	puntero++;
	}
	cout << endl;
	
	system("pause");
	return 0;
}
