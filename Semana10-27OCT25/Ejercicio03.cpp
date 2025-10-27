#include <iostream>
#include <iomanip>

using namespace std;

// Clase DTO (Data Transfer Object) para transferir datos de venta
class VentaDTO {
public:
    double precio;
    int cantidad;
    double importe;
    
    // Constructor por defecto
    VentaDTO() {
        precio = 0.0;
        cantidad = 0;
        importe = 0.0;
    }
    
    // Constructor con parámetros
    VentaDTO(double p, int c) {
        precio = p;
        cantidad = c;
        importe = 0.0;
    }
    
    // Método para mostrar los datos del DTO
    void mostrarDatos() {
        cout << fixed << setprecision(2);
        cout << "Precio unitario: S/ " << precio << endl;
        cout << "Cantidad: " << cantidad << " unidades" << endl;
        cout << "Importe total: S/ " << importe << endl;
    }
};


class Venta{
	
public:

	// Método que calcula el importe y retorna el DTO actualizado
	VentaDTO calcularVenta(VentaDTO dto) {
		// Calcular el importe
		dto.importe = dto.precio * dto.cantidad;
		// Retornar el DTO con el importe calculado
		return dto;
	}
	
};


int main(){
	// Datos
	VentaDTO dto(45.8,7);
	// Proceso
	Venta oVenta;
	dto = oVenta.calcularVenta(dto);
	// Reporte
	dto.mostrarDatos();
	return 0;
	
}



