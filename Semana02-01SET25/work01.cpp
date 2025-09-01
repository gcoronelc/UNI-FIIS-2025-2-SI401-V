#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    // Inicializar la semilla
    std::srand(std::time(0));
    
    // Generar números entre 1 y 10
    for (int i = 0; i < 10; ++i) {
        int num = std::rand() % 10 + 1;
        std::cout << num << " ";
    }
    std::cout << std::endl;
    
    return 0;
}
