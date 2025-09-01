#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    // ==================== ENTRADA ====================
    float c1, ep, c2, ef;
    
    cout << "=== SISTEMA DE CALIFICACIONES ===" << endl;
    cout << "Ingrese las notas del estudiante:" << endl;
    
    cout << "Primer Consolidado (C1): ";
    cin >> c1;
    
    cout << "Evaluaci�n Parcial (EP): ";
    cin >> ep;
    
    cout << "Segundo Consolidado (C2): ";
    cin >> c2;
    
    cout << "Evaluaci�n Final (EF): ";
    cin >> ef;
    
    // ==================== PROCESO ====================
    // Calcular promedio final usando la f�rmula
    // PF = C1(20%) + EP(25%) + C2(20%) + EF(35%)
    float pf = (c1 * 0.20) + (ep * 0.25) + (c2 * 0.20) + (ef * 0.35);
    
    // Determinar condici�n usando operador ternario
    string condicion = (pf >= 14) ? "APROBADO" : "DESAPROBADO";
    
    // ==================== SALIDA ====================
    cout << "\n=== RESULTADOS ===" << endl;
    cout << fixed << setprecision(2);
    cout << "Detalle de c�lculo:" << endl;
    cout << "C1 (20%): " << c1 << " x 0.20 = " << (c1 * 0.20) << endl;
    cout << "EP (25%): " << ep << " x 0.25 = " << (ep * 0.25) << endl;
    cout << "C2 (20%): " << c2 << " x 0.20 = " << (c2 * 0.20) << endl;
    cout << "EF (35%): " << ef << " x 0.35 = " << (ef * 0.35) << endl;
    cout << "------------------------" << endl;
    cout << "Promedio Final (PF): " << pf << endl;
    cout << "Condici�n: " << condicion << endl;
    
    // Mostrar mensaje adicional seg�n la condici�n
    if (pf >= 14) {
        cout << "�Felicitaciones! Has aprobado el curso." << endl;
    } else {
        cout << "Lo siento, necesitas mejorar para aprobar." << endl;
        cout << "Necesitas: " << (14.00 - pf) << " puntos adicionales." << endl;
    }
    
    return 0;
}
