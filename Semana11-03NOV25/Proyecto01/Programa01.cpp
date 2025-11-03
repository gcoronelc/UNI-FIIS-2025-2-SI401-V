// Programa01.cpp

#include <iostream>
#include "Punto.h"
using namespace std;

// ==========================================
// PROGRAMA PRINCIPAL DE PRUEBA
// ==========================================
int main() {
    cout << "=== PRUEBA DE LA CLASE PUNTO ===" << endl << endl;

    // Crear un punto en el origen usando el constructor sin parámetros
    Punto p1;
    cout << "Punto 1: (" << p1.getX() << ", " << p1.getY() << ")" << endl;
    cout << "Cuadrante: " << p1.GetCuadrante() << endl;
    cout << "Distancia al origen: " << p1.GetDistancia() << endl << endl;

    // Crear un punto en (3, 4) usando el constructor con parámetros
    Punto p2(3, 4);
    cout << "Punto 2: (" << p2.getX() << ", " << p2.getY() << ")" << endl;
    cout << "Cuadrante: " << p2.GetCuadrante() << endl;
    cout << "Distancia al origen: " << p2.GetDistancia() << endl << endl;

    // Crear un punto en (-5, 2)
    Punto p3(-5, 2);
    cout << "Punto 3: (" << p3.getX() << ", " << p3.getY() << ")" << endl;
    cout << "Cuadrante: " << p3.GetCuadrante() << endl;
    cout << "Distancia al origen: " << p3.GetDistancia() << endl << endl;

    // Modificar un punto usando setters
    p3.setX(0);
    p3.setY(5);
    cout << "Punto 3 modificado: (" << p3.getX() << ", " << p3.getY() << ")" << endl;
    cout << "Cuadrante: " << p3.GetCuadrante() << endl;
    cout << "Distancia al origen: " << p3.GetDistancia() << endl << endl;

    return 0;
}
