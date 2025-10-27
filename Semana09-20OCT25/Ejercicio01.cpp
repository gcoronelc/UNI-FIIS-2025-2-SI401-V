#include <iostream>

using namespace std;

// Clase para operaciones matemáticas
class Matematica {
public:
    // Método para calcular el factorial de un número
    long long calcularFactorial(int n) {
        // Validar que el número sea no negativo
        if (n < 0) {
            return -1;
        }
        
        // Caso base: 0! = 1 y 1! = 1
        if (n == 0 || n == 1) {
            return 1;
        }
        
        // Calcular factorial iterativamente
        long long resultado = 1;
        for (int i = 2; i <= n; i++) {
            resultado *= i;
        }
        
        return resultado;
    }
    
    // Método para calcular el MCD usando el algoritmo euclidiano
    int calcularMCD(int a, int b) {
        // Trabajar con valores absolutos
        a = abs(a);
        b = abs(b);
        
        // Validar que no ambos sean cero
        if (a == 0 && b == 0) {
            return -1;
        }
        
        // Algoritmo euclidiano
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        
        return a;
    }
    
    // Método recursivo alternativo para MCD (opcional)
    int calcularMCDRecursivo(int a, int b) {
        a = abs(a);
        b = abs(b);
        
        if (b == 0) {
            return a;
        }
        return calcularMCDRecursivo(b, a % b);
    }
};


// Programa principal

int main() {
    // Crear objeto de la clase
    Matematica calc;
    
    cout << "========================================" << endl;
    cout << "   CALCULADORA DE FACTORIAL Y MCD" << endl;
    cout << "========================================" << endl;
    
    // Demostración del cálculo de factorial
    cout << "\n--- CÁLCULO DE FACTORIAL ---" << endl;
    int num1 = 5;
    int num2 = 10;
    int num3 = 0;
    
    cout << "Factorial de " << num1 << " = " << calc.calcularFactorial(num1) << endl;
    cout << "Factorial de " << num2 << " = " << calc.calcularFactorial(num2) << endl;
    cout << "Factorial de " << num3 << " = " << calc.calcularFactorial(num3) << endl;
    
    // Demostración del cálculo de MCD
    cout << "\n--- CÁLCULO DE MCD (Algoritmo Euclidiano) ---" << endl;
    int a1 = 48, b1 = 18;
    int a2 = 100, b2 = 35;
    int a3 = 270, b3 = 192;
    
    cout << "MCD(" << a1 << ", " << b1 << ") = " << calc.calcularMCD(a1, b1) << endl;
    cout << "MCD(" << a2 << ", " << b2 << ") = " << calc.calcularMCD(a2, b2) << endl;
    cout << "MCD(" << a3 << ", " << b3 << ") = " << calc.calcularMCD(a3, b3) << endl;
    
    // Demostración del MCD recursivo
    cout << "\n--- MCD RECURSIVO ---" << endl;
    cout << "MCD(" << a1 << ", " << b1 << ") = " << calc.calcularMCDRecursivo(a1, b1) << endl;
    
    // Ejemplo interactivo (opcional)
    cout << "\n--- EJEMPLO INTERACTIVO ---" << endl;
    int numero, num_a, num_b;
    
    cout << "Ingrese un número para calcular su factorial: ";
    cin >> numero;
    cout << "Factorial de " << numero << " = " << calc.calcularFactorial(numero) << endl;
    
    cout << "\nIngrese dos números para calcular su MCD:" << endl;
    cout << "Número 1: ";
    cin >> num_a;
    cout << "Número 2: ";
    cin >> num_b;
    cout << "MCD(" << num_a << ", " << num_b << ") = " << calc.calcularMCD(num_a, num_b) << endl;
    
    cout << "\n========================================" << endl;
    cout << "   Programa finalizado" << endl;
    cout << "========================================" << endl;
    
    return 0;
}
