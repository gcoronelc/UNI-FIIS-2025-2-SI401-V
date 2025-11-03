// Problema02.cpp - Versión 2
// Programa que genera N puntos aleatorios y muestra estadísticas
// Arquitectura: Capa de Entrada - Capa de Proceso - Capa de Salida
// Autor: Curso de Programación C++
// Fecha: 2025

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "Punto.h"

using namespace std;

// ==========================================
// ESTRUCTURA PARA ALMACENAR RESULTADOS
// ==========================================
struct Resultados {
    Punto puntoMasCercano;
    Punto puntoMasLejano;
    float distanciaPromedio;
    int cantidadPrimerCuadrante;
    int cantidadSegundoCuadrante;
    int cantidadTercerCuadrante;
    int cantidadCuartoCuadrante;
    int cantidadOrigen;
    int cantidadEjeX;
    int cantidadEjeY;
};

// ==========================================
// PROTOTIPOS - CAPA DE ENTRADA
// ==========================================
int leerCantidadPuntos();
vector<Punto> generarPuntosAleatorios(int n);

// ==========================================
// PROTOTIPOS - CAPA DE PROCESO
// ==========================================
Resultados procesarDatos(vector<Punto>& puntos);
Punto buscarPuntoMasCercano(vector<Punto>& puntos);
Punto buscarPuntoMasLejano(vector<Punto>& puntos);
float calcularDistanciaPromedio(vector<Punto>& puntos);
void contarPuntosPorCuadrante(vector<Punto>& puntos, Resultados& resultado);

// ==========================================
// PROTOTIPOS - CAPA DE SALIDA
// ==========================================
void mostrarPuntosGenerados(vector<Punto>& puntos);
void mostrarResultados(Resultados& resultado);

// ==========================================
// FUNCIÓN PRINCIPAL
// ==========================================
int main() {
    // Inicializar generador de números aleatorios
    srand(time(0));
    
    // ========== CAPA DE ENTRADA ==========
    int n = leerCantidadPuntos();
    vector<Punto> puntos = generarPuntosAleatorios(n);
    
    // ========== CAPA DE PROCESO ==========
    Resultados resultado = procesarDatos(puntos);
    
    // ========== CAPA DE SALIDA ==========
    mostrarPuntosGenerados(puntos);
    mostrarResultados(resultado);
    
    return 0;
}

// ==========================================
// IMPLEMENTACIÓN - CAPA DE ENTRADA
// ==========================================

/**
 * Lee y valida la cantidad de puntos a generar
 * @return Cantidad de puntos (número positivo)
 */
int leerCantidadPuntos() {
    int n;
    
    cout << "========================================" << endl;
    cout << "  ANÁLISIS DE PUNTOS ALEATORIOS" << endl;
    cout << "========================================" << endl << endl;
    
    cout << "Ingrese la cantidad de puntos a generar: ";
    cin >> n;
    
    while (n <= 0) {
        cout << "Error: Debe ingresar un número positivo." << endl;
        cout << "Ingrese la cantidad de puntos: ";
        cin >> n;
    }
    
    return n;
}

/**
 * Genera un vector con N puntos aleatorios
 * Coordenadas en el rango [-100, 100]
 * @param n Cantidad de puntos a generar
 * @return Vector con los puntos generados
 */
vector<Punto> generarPuntosAleatorios(int n) {
    vector<Punto> puntos;
    
    for (int i = 0; i < n; i++) {
        int x = rand() % 201 - 100;
        int y = rand() % 201 - 100;
        Punto p(x, y);
        puntos.push_back(p);
    }
    
    return puntos;
}

// ==========================================
// IMPLEMENTACIÓN - CAPA DE PROCESO
// ==========================================

/**
 * Procesa todos los datos y genera los resultados
 * @param puntos Vector de puntos a analizar
 * @return Estructura con todos los resultados calculados
 */
Resultados procesarDatos(vector<Punto>& puntos) {
    Resultados resultado;
    
    // Procesar cada requisito
    resultado.puntoMasCercano = buscarPuntoMasCercano(puntos);
    resultado.puntoMasLejano = buscarPuntoMasLejano(puntos);
    resultado.distanciaPromedio = calcularDistanciaPromedio(puntos);
    contarPuntosPorCuadrante(puntos, resultado);
    
    return resultado;
}

/**
 * Busca el punto más cercano al origen
 * @param puntos Vector de puntos
 * @return Punto con menor distancia al origen
 */
Punto buscarPuntoMasCercano(vector<Punto>& puntos) {
    Punto masCercano = puntos[0];
    float menorDistancia = puntos[0].GetDistancia();
    
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
 * Busca el punto más lejano del origen
 * @param puntos Vector de puntos
 * @return Punto con mayor distancia al origen
 */
Punto buscarPuntoMasLejano(vector<Punto>& puntos) {
    Punto masLejano = puntos[0];
    float mayorDistancia = puntos[0].GetDistancia();
    
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
 * @param puntos Vector de puntos
 * @return Distancia promedio
 */
float calcularDistanciaPromedio(vector<Punto>& puntos) {
    float suma = 0;
    
    for (int i = 0; i < puntos.size(); i++) {
        suma += puntos[i].GetDistancia();
    }
    
    return suma / puntos.size();
}

/**
 * Cuenta cuántos puntos hay en cada cuadrante
 * @param puntos Vector de puntos
 * @param resultado Estructura donde se guardan los contadores
 */
void contarPuntosPorCuadrante(vector<Punto>& puntos, Resultados& resultado) {
    // Inicializar contadores
    resultado.cantidadPrimerCuadrante = 0;
    resultado.cantidadSegundoCuadrante = 0;
    resultado.cantidadTercerCuadrante = 0;
    resultado.cantidadCuartoCuadrante = 0;
    resultado.cantidadOrigen = 0;
    resultado.cantidadEjeX = 0;
    resultado.cantidadEjeY = 0;
    
    // Contar puntos
    for (int i = 0; i < puntos.size(); i++) {
        string cuadrante = puntos[i].GetCuadrante();
        
        if (cuadrante == "Primer Cuadrante") {
            resultado.cantidadPrimerCuadrante++;
        } 
        else if (cuadrante == "Segundo Cuadrante") {
            resultado.cantidadSegundoCuadrante++;
        } 
        else if (cuadrante == "Tercer Cuadrante") {
            resultado.cantidadTercerCuadrante++;
        } 
        else if (cuadrante == "Cuarto Cuadrante") {
            resultado.cantidadCuartoCuadrante++;
        } 
        else if (cuadrante == "Origen") {
            resultado.cantidadOrigen++;
        } 
        else if (cuadrante == "Eje X") {
            resultado.cantidadEjeX++;
        } 
        else if (cuadrante == "Eje Y") {
            resultado.cantidadEjeY++;
        }
    }
}

// ==========================================
// IMPLEMENTACIÓN - CAPA DE SALIDA
// ==========================================

/**
 * Muestra en pantalla todos los puntos generados
 * @param puntos Vector de puntos a mostrar
 */
void mostrarPuntosGenerados(vector<Punto>& puntos) {
    cout << "\n========================================" << endl;
    cout << "  PUNTOS GENERADOS" << endl;
    cout << "========================================" << endl;
    
    for (int i = 0; i < puntos.size(); i++) {
        cout << "Punto " << (i + 1) << ": (" 
             << puntos[i].getX() << ", " 
             << puntos[i].getY() << ")" << endl;
    }
}

/**
 * Muestra en pantalla todos los resultados del análisis
 * @param resultado Estructura con los resultados procesados
 */
void mostrarResultados(Resultados& resultado) {
    cout << "\n========================================" << endl;
    cout << "  RESULTADOS DEL ANÁLISIS" << endl;
    cout << "========================================" << endl << endl;
    
    // 1. Punto más cercano
    cout << "1. PUNTO MÁS CERCANO AL ORIGEN:" << endl;
    cout << "   Coordenadas: (" << resultado.puntoMasCercano.getX() 
         << ", " << resultado.puntoMasCercano.getY() << ")" << endl;
    cout << "   Distancia: " << resultado.puntoMasCercano.GetDistancia() << endl;
    cout << "   Cuadrante: " << resultado.puntoMasCercano.GetCuadrante() << endl << endl;
    
    // 2. Punto más lejano
    cout << "2. PUNTO MÁS LEJANO DEL ORIGEN:" << endl;
    cout << "   Coordenadas: (" << resultado.puntoMasLejano.getX() 
         << ", " << resultado.puntoMasLejano.getY() << ")" << endl;
    cout << "   Distancia: " << resultado.puntoMasLejano.GetDistancia() << endl;
    cout << "   Cuadrante: " << resultado.puntoMasLejano.GetCuadrante() << endl << endl;
    
    // 3. Distancia promedio
    cout << "3. DISTANCIA PROMEDIO DE TODOS LOS PUNTOS:" << endl;
    cout << "   Promedio: " << resultado.distanciaPromedio << endl << endl;
    
    // 4. Cantidad por cuadrante
    cout << "4. CANTIDAD DE PUNTOS POR CUADRANTE:" << endl;
    cout << "   Primer Cuadrante:  " << resultado.cantidadPrimerCuadrante << " puntos" << endl;
    cout << "   Segundo Cuadrante: " << resultado.cantidadSegundoCuadrante << " puntos" << endl;
    cout << "   Tercer Cuadrante:  " << resultado.cantidadTercerCuadrante << " puntos" << endl;
    cout << "   Cuarto Cuadrante:  " << resultado.cantidadCuartoCuadrante << " puntos" << endl;
    cout << "   En el Origen:      " << resultado.cantidadOrigen << " puntos" << endl;
    cout << "   En el Eje X:       " << resultado.cantidadEjeX << " puntos" << endl;
    cout << "   En el Eje Y:       " << resultado.cantidadEjeY << " puntos" << endl;
    
    cout << "\n========================================" << endl;
}
