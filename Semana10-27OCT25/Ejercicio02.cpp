#include <iostream>

using namespace std;

class Venta{
	
public:

   double calcularVenta(double precio, int cantidad)	{
   	return (precio*cantidad);
   }
	
	
};


int main(){
	// Datos
	double precio = 45.8;
	int cant = 6;
	// Proceso
	Venta oVenta;
	double importe = oVenta.calcularVenta(precio, cant);
	// Reporte
	cout << "Venta: " << importe << endl;
	return 0;
	
}



