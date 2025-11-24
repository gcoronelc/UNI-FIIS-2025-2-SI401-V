#include <iostream>
using namespace std;

// =========================================
// DECLARACION DE LA CLASE MATEMATICA
// =========================================

class Matematica {
public:
    double potencia(double x, int n);
    double factorial(int n);
    double serie(double x, int n);
};

// =========================================
// PROGRAMA PRINCIPAL
// =========================================

int main() {
    // SECCION: DECLARACION DE VARIABLES
    double x;
    int n;
    double resultado_serie;
    Matematica mat;
    
    // SECCION: LECTURA DE DATOS
    cout << "=======================================" << endl;
    cout << "  CALCULO DE SERIE MATEMATICA" << endl;
    cout << "  Serie: x - x^3/3! + x^5/5! - x^7/7! + ..." << endl;
    cout << "=======================================" << endl;
    cout << endl;
    
    cout << "Ingrese el valor de x: ";
    cin >> x;
    
    cout << "Ingrese el numero de terminos (n): ";
    cin >> n;
    
    // SECCION: PROCESO
    resultado_serie = mat.serie(x, n);
    
    // SECCION: REPORTE
    cout << endl;
    cout << "=======================================" << endl;
    cout << "  RESULTADOS" << endl;
    cout << "=======================================" << endl;
    cout << endl;
    cout << "Valor de x: " << x << endl;
    cout << "Numero de terminos (n): " << n << endl;
    cout << endl;
    cout << "Valor de la serie: " << resultado_serie << endl;
    cout << endl;
    cout << "=======================================" << endl;
    
    return 0;
}

// =========================================
// IMPLEMENTACION DE LA CLASE MATEMATICA
// =========================================

// Metodo: potencia
// Descripcion: Calcula x elevado a la potencia n
// Parametros: x (base), n (exponente)
// Retorna: x^n
double Matematica::potencia(double x, int n) {
    double resultado;
    int i;
    
    resultado = 1.0;
    
    for (i = 1; i <= n; i++) {
        resultado = resultado * x;
    }
    
    return resultado;
}

// Metodo: factorial
// Descripcion: Calcula el factorial de n
// Parametros: n (numero entero)
// Retorna: n!
double Matematica::factorial(int n) {
    double resultado;
    int i;
    
    resultado = 1.0;
    
    for (i = 1; i <= n; i++) {
        resultado = resultado * i;
    }
    
    return resultado;
}

// Metodo: serie
// Descripcion: Calcula la serie x - x^3/3! + x^5/5! - x^7/7! + ... + x^(2n-1)/(2n-1)!
// Parametros: x (valor base), n (numero de terminos)
// Retorna: valor de la serie
double Matematica::serie(double x, int n) {
    double suma;
    int i;
    int exponente;
    double numerador;
    double denominador;
    double termino;
    int signo;
    
    suma = 0.0;
    signo = 1;
    
    for (i = 1; i <= n; i++) {
        // Calcular exponente: 2i - 1
        exponente = 2 * i - 1;
        
        // Calcular numerador: x^exponente
        numerador = potencia(x, exponente);
        
        // Calcular denominador: exponente!
        denominador = factorial(exponente);
        
        // Calcular termino
        termino = numerador / denominador;
        
        // Aplicar signo alternante
        if (signo == 1) {
            suma = suma + termino;
        } else {
            suma = suma - termino;
        }
        
        // Cambiar signo para el siguiente termino
        signo = signo * -1;
    }
    
    return suma;
}
