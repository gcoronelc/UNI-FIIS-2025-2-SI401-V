#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
	
    // ==================== ENTRADA ====================
    // Inicializar generador de números aleatorios
    srand(time(0));
    
    // Generar 4 números aleatorios entre 0 y 10
    int num1 = rand() % 11;  // 0 a 10
    int num2 = rand() % 11;  // 0 a 10
    int num3 = rand() % 11;  // 0 a 10
    int num4 = rand() % 11;  // 0 a 10
    
    cout << "Números generados: " << num1 << ", " << num2 << ", " << num3 << ", " << num4 << endl;
    
    // ==================== PROCESO ====================
    // Encontrar el menor usando operador ternario y estructuras condicionales
    int menor = num1; // Punto de partida
    menor = (num2 < menor) ? num2 : menor;
    menor = (num3 < menor) ? num3 : menor;
    menor = (num4 < menor) ? num4 : menor;
    
    // Verificar si todos son iguales
    bool todosIguales = (num1 == num2) && (num2 == num3) && (num3 == num4);
    
    // ==================== SALIDA ====================
    if (todosIguales) {
        cout << "Todos los números son iguales: " << num1 << endl;
    } else {
        cout << "El menor número es: " << menor << endl;
    }
    
    return 0;
}
