#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {

	// ==================== VARIABLES ====================
    float cateto1, cateto2;
    bool datosCorrectos = true;
    float hipotenuza = 0, perimetro = 0, area = 0;
    
    // ==================== ENTRADA ====================
    cout << "LECTURA DE DATOS" << endl;
	cout << "================================================" << endl;
    cout << "Cateto 1: "; cin >> cateto1;
    cout << "Cateto 2: "; cin >> cateto2;
	
	// ==================== PROCESO ====================
	datosCorrectos = (cateto1>0) && (cateto2>0);
	if(datosCorrectos){
		hipotenuza = sqrt( pow(cateto1,2) + pow(cateto2,2) );
		perimetro = cateto1 + cateto2 + hipotenuza;
		area = cateto1 * cateto2 / 2;
	}
	
		
	// ==================== PROCESO ====================
	cout << fixed << setprecision(2);
	cout << "\n\nREPORTE" << endl;
	cout << "================================================" << endl;
	if(datosCorrectos){
		cout << "Cateto 1:" << cateto1 << endl;
		cout << "Cateto 2:" << cateto2 << endl;
		cout << "Hipotenuza:" << hipotenuza << endl;
		cout << "Perimetro:" << perimetro << endl;
		cout << "Area:" << area << endl;
	} else {
		cout << "Ingresa valor mayores que cero." << endl;
	}
	return 0;
	
}
