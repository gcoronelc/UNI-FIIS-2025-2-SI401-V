#include <iostream>
#include <cmath>
using namespace std;

// ==========================================
// DECLARACIÓN DE LA CLASE
// ==========================================
class Punto {
private:
    // Atributos: las coordenadas del punto
    int x;
    int y;

public:
	
    // Constructor sin parámetros: crea un punto en el origen (0,0)
    // Tambien se llama constructor por defecto
    Punto() {
        x = 0;
        y = 0;
    }

    // Constructor con parámetros: crea un punto en la posición indicada
    Punto(int valorX, int valorY) {
        x = valorX;
        y = valorY;
    }

    // Método que indica en qué cuadrante está el punto
    string GetCuadrante() {
        // Si está en el origen
        if (x == 0 && y == 0) {
            return "Origen";
        }
        
        // Si está en los ejes
        if (x == 0) {
            return "Eje Y";
        }
        if (y == 0) {
            return "Eje X";
        }
        
        // Determinar el cuadrante
        if (x > 0 && y > 0) {
            return "Primer Cuadrante";
        } 
        else if (x < 0 && y > 0) {
            return "Segundo Cuadrante";
        } 
        else if (x < 0 && y < 0) {
            return "Tercer Cuadrante";
        } 
        else {
            return "Cuarto Cuadrante";
        }
    }

    // Método que calcula la distancia desde el origen
    // Usa la fórmula: distancia = raíz cuadrada de (x² + y²)
    float GetDistancia() {
        float distancia = sqrt(x * x + y * y);
        return distancia;
    }

    // Métodos para obtener los valores de x e y
    int getX() {
        return x;
    }

    int getY() {
        return y;
    }

    // Métodos para cambiar los valores de x e y
    void setX(int nuevoX) {
        x = nuevoX;
    }

    void setY(int nuevoY) {
        y = nuevoY;
    }
};
