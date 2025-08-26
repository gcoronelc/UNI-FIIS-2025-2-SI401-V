#include <iostream>  // Para entrada y salida de datos
#include <cmath>     // Para funciones matemáticas como sqrt() y pow()

using namespace std;

int main() {
    // ==========================================
    // a) BLOQUE DE VARIABLES
    // ==========================================
    double x, y, z;  // Variables para almacenar los valores
    
    cout << "=== CALCULADORA: z = sqrt(x + y^3) ===" << endl;
    cout << endl;
    
    // ==========================================
    // b) BLOQUE DE LECTURA DE DATOS
    // ==========================================
    cout << "Ingrese el valor de x: ";
    cin >> x;
    
    cout << "Ingrese el valor de y: ";
    cin >> y;
    
    // ==========================================
    // c) BLOQUE DE PROCESO (CÁLCULOS)
    // ==========================================
    // Primero calculamos y^3 (y elevado al cubo)
    double y_cubo = pow(y, 3);
    
    // Luego sumamos x + y^3
    double suma = x + y_cubo;
    
    // Finalmente calculamos la raíz cuadrada (si es posible)
    if (suma >= 0) {
        z = sqrt(suma);
    }
    
    // ==========================================
    // d) BLOQUE DE SALIDA DE RESULTADOS
    // ==========================================
    cout << endl;
    
    // Verificamos si se pudo realizar el cálculo
    if (suma < 0) {
        cout << "=== ERROR ===" << endl;
        cout << "No se puede calcular la raiz cuadrada de un numero negativo!" << endl;
        cout << "Valor de x: " << x << endl;
        cout << "Valor de y: " << y << endl;
        cout << "y^3 = " << y_cubo << endl;
        cout << "x + y^3 = " << suma << " (negativo)" << endl;
    } else {
        cout << "=== RESULTADOS ===" << endl;
        cout << "Valor de x: " << x << endl;
        cout << "Valor de y: " << y << endl;
        cout << "y^3 = " << y_cubo << endl;
        cout << "x + y^3 = " << suma << endl;
        cout << "z = sqrt(" << suma << ") = " << z << endl;
    }
    
    return 0; // Indica que el programa terminó correctamente
}
