#include <iostream>
#include <string>
using namespace std;

int main() {
    // =========================
    // Variables
    // =========================
    long long x1, y1, x2, y2;              // Esquinas opuestas
    long long xmin, xmax, ymin, ymax;      // Extremos normalizados
    long long cntPerimetro = 0;
    long long cntInterior = 0;
    string outPerimetro = "";              // Acumuladores de salida
    string outInterior  = "";
    string tmp;                            // auxiliar para formateo

    // =========================
    // Lectura
    // =========================
    cout << "Punto 1: "; cin >> x1 >> y1;
    cout << "Punto 2: "; cin >> x2 >> y2;

    // =========================
    // Proceso
    // =========================
    // Normalizar X
    if (x1 <= x2) { xmin = x1; xmax = x2; }
    else          { xmin = x2; xmax = x1; }
    // Normalizar Y
    if (y1 <= y2) { ymin = y1; ymax = y2; }
    else          { ymin = y2; ymax = y1; }

    // Construir perímetro (solo acumulación en cadenas)
    for (long long x = xmin; x <= xmax; x = x + 1) {
        for (long long y = ymin; y <= ymax; y = y + 1) {
            if (x == xmin || x == xmax || y == ymin || y == ymax) {
                tmp = "(" + to_string(x) + "," + to_string(y) + ")\t";
                outPerimetro = outPerimetro + tmp;
                cntPerimetro = cntPerimetro + 1;
            }
        }
        outPerimetro = outPerimetro + "\n";
    }

    // Construir interior si existe
    if ((xmax - xmin) >= 2 && (ymax - ymin) >= 2) {
        for (long long x = xmin + 1; x <= xmax - 1; x = x + 1) {
            for (long long y = ymin + 1; y <= ymax - 1; y = y + 1) {
                tmp = "(" + to_string(x) + "," + to_string(y) + ")\t";
                outInterior = outInterior + tmp;
                cntInterior = cntInterior + 1;
            }
            outInterior = outInterior + "\n";
        }
    }

    // =========================
    // Reporte
    // =========================
    cout << "Perimetro:\n";
    cout << outPerimetro;
    cout << "Total perimetro: " << cntPerimetro << " puntos\n";

    cout << "Interior:\n";
    cout << outInterior;
    cout << "Total interior: " << cntInterior << " puntos\n";

    return 0;
}

