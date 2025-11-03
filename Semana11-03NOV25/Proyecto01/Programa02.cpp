// Problema02.cpp
// Programa que genera N puntos aleatorios y muestra estadísticas
// Autor: Curso de Programación C++
// Fecha: 2025

#include <iostream>
#include <vector>
#include <cstdlib>   // Para rand() y srand()
#include <ctime>     // Para time()
#include "Punto.h"   // Incluimos nuestra clase Punto

using namespace std;

// ==========================================
// PROTOTIPOS DE FUNCIONES
// ==========================================

// Genera un vector con N puntos aleatorios
vector<Punto> generarPuntosAleatorios(int n);

// Encuentra el punto más cercano al origen
Punto encontrarPuntoMasCercano(vector<Punto> puntos);

// Encuentra el punto más lejano del origen
Punto encontrarPuntoMasLejano(vector<Punto> puntos);

// Calcula la distancia promedio de todos los puntos
float calcularDistanciaPromedio(vector<Punto> puntos);

// Cuenta cuántos puntos hay en cada cuadrante
void contarPuntosPorCuadrante(vector<Punto> puntos);

// ==========================================
// FUNCIÓN PRINCIPAL
// ==========================================

int main() {
    int n;
    
    // Inicializar generador de números aleatorios
    srand(time(0));
    
    cout << "========================================" << endl;
    cout << "  ANÁLISIS DE PUNTOS ALEATORIOS" << endl;
    cout << "========================================" << endl << endl;
    
    // Solicitar cantidad de puntos
    cout << "Ingrese la cantidad de puntos a generar: ";
    cin >> n;
    
    // Validar que sea un número positivo
    if (n <= 0) {
        cout << "Error: Debe ingresar un número positivo." << endl;
        return 1;
    }
    
    cout << endl;
    
    // 1. Generar el vector de puntos aleatorios
    cout << "Generando " << n << " puntos aleatorios..." << endl;
    vector<Punto> puntos = generarPuntosAleatorios(n);
    
    // Mostrar los puntos generados
    cout << "\nPuntos generados:" << endl;
    for (int i = 0; i < puntos.size(); i++) {
        cout << "Punto " << (i + 1) << ": (" 
             << puntos[i].getX() << ", " 
             << puntos[i].getY() << ")" << endl;
    }
    
    cout << "\n========================================" << endl;
    cout << "  RESULTADOS DEL ANÁLISIS" << endl;
    cout << "========================================" << endl << endl;
    
    // 2. Punto más cercano al origen
    Punto masCercano = encontrarPuntoMasCercano(puntos);
    cout << "1. PUNTO MÁS CERCANO AL ORIGEN:" << endl;
    cout << "   Coordenadas: (" << masCercano.getX() << ", " << masCercano.getY() << ")" << endl;
    cout << "   Distancia: " << masCercano.GetDistancia() << endl;
    cout << "   Cuadrante: " << masCercano.GetCuadrante() << endl << endl;
    
    // 3. Punto más lejano del origen
    Punto masLejano = encontrarPuntoMasLejano(puntos);
    cout << "2. PUNTO MÁS LEJANO DEL ORIGEN:" << endl;
    cout << "   Coordenadas: (" << masLejano.getX() << ", " << masLejano.getY() << ")" << endl;
    cout << "   Distancia: " << masLejano.GetDistancia() << endl;
    cout << "   Cuadrante: " << masLejano.GetCuadrante() << endl << endl;
    
    // 4. Distancia promedio
    float promedio = calcularDistanciaPromedio(puntos);
    cout << "3. DISTANCIA PROMEDIO DE TODOS LOS PUNTOS:" << endl;
    cout << "   Promedio: " << promedio << endl << endl;
    
    // 5. Cantidad de puntos por cuadrante
    cout << "4. CANTIDAD DE PUNTOS POR CUADRANTE:" << endl;
    contarPuntosPorCuadrante(puntos);
    
    cout << "\n========================================" << endl;
    
    return 0;
}

// ==========================================
// IMPLEMENTACIÓN DE FUNCIONES
// ==========================================

/**
 * Genera un vector con N puntos aleatorios
 * Las coordenadas están en el rango [-100, 100]
 * 
 * @param n Cantidad de puntos a generar
 * @return Vector con los puntos generados
 */
vector<Punto> generarPuntosAleatorios(int n) {
    vector<Punto> puntos;
    
    for (int i = 0; i < n; i++) {
        // Generar coordenadas aleatorias entre -100 y 100
        int x = rand() % 201 - 100;  // rand() % 201 da valores [0, 200], restamos 100
        int y = rand() % 201 - 100;
        
        // Crear el punto y agregarlo al vector
        Punto p(x, y);
        puntos.push_back(p);
    }
    
    return puntos;
}

/**
 * Encuentra el punto más cercano al origen (0, 0)
 * 
 * @param puntos Vector de puntos a analizar
 * @return El punto con menor distancia al origen
 */
Punto encontrarPuntoMasCercano(vector<Punto> puntos) {
    Punto masCercano = puntos[0];
    float menorDistancia = puntos[0].GetDistancia();
    
    // Recorrer todos los puntos buscando el más cercano
    for (int i = 1; i < puntos.size(); i++) {
        float distanciaActual = puntos[i].GetDistancia();
        
        if (distanciaActual < menorDistancia) {
            menorDistancia = distanciaActual;
            masCercano = puntos[i];
        }
    }
    
    return masCercano;
}

/**
 * Encuentra el punto más lejano del origen (0, 0)
 * 
 * @param puntos Vector de puntos a analizar
 * @return El punto con mayor distancia al origen
 */
Punto encontrarPuntoMasLejano(vector<Punto> puntos) {
    Punto masLejano = puntos[0];
    float mayorDistancia = puntos[0].GetDistancia();
    
    // Recorrer todos los puntos buscando el más lejano
    for (int i = 1; i < puntos.size(); i++) {
        float distanciaActual = puntos[i].GetDistancia();
        
        if (distanciaActual > mayorDistancia) {
            mayorDistancia = distanciaActual;
            masLejano = puntos[i];
        }
    }
    
    return masLejano;
}

/**
 * Calcula la distancia promedio de todos los puntos al origen
 * 
 * @param puntos Vector de puntos a analizar
 * @return Distancia promedio
 */
float calcularDistanciaPromedio(vector<Punto> puntos) {
    float suma = 0;
    
    // Sumar todas las distancias
    for (int i = 0; i < puntos.size(); i++) {
        suma += puntos[i].GetDistancia();
    }
    
    // Calcular el promedio
    float promedio = suma / puntos.size();
    
    return promedio;
}

/**
 * Cuenta y muestra cuántos puntos hay en cada cuadrante
 * 
 * @param puntos Vector de puntos a analizar
 */
void contarPuntosPorCuadrante(vector<Punto> puntos) {
    // Contadores para cada ubicación
    int primerCuadrante = 0;
    int segundoCuadrante = 0;
    int tercerCuadrante = 0;
    int cuartoCuadrante = 0;
    int enOrigen = 0;
    int enEjeX = 0;
    int enEjeY = 0;
    
    // Contar puntos en cada cuadrante
    for (int i = 0; i < puntos.size(); i++) {
        string cuadrante = puntos[i].GetCuadrante();
        
        if (cuadrante == "Primer Cuadrante") {
            primerCuadrante++;
        } 
        else if (cuadrante == "Segundo Cuadrante") {
            segundoCuadrante++;
        } 
        else if (cuadrante == "Tercer Cuadrante") {
            tercerCuadrante++;
        } 
        else if (cuadrante == "Cuarto Cuadrante") {
            cuartoCuadrante++;
        } 
        else if (cuadrante == "Origen") {
            enOrigen++;
        } 
        else if (cuadrante == "Eje X") {
            enEjeX++;
        } 
        else if (cuadrante == "Eje Y") {
            enEjeY++;
        }
    }
    
    // Mostrar resultados
    cout << "   Primer Cuadrante:  " << primerCuadrante << " puntos" << endl;
    cout << "   Segundo Cuadrante: " << segundoCuadrante << " puntos" << endl;
    cout << "   Tercer Cuadrante:  " << tercerCuadrante << " puntos" << endl;
    cout << "   Cuarto Cuadrante:  " << cuartoCuadrante << " puntos" << endl;
    cout << "   En el Origen:      " << enOrigen << " puntos" << endl;
    cout << "   En el Eje X:       " << enEjeX << " puntos" << endl;
    cout << "   En el Eje Y:       " << enEjeY << " puntos" << endl;
}
