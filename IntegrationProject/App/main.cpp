#include <iostream>
#include <cmath>
#include "Integration.h" // Підключаємо твою динамічну бібліотеку

// Тестова функція для інтегрування: f(x) = x^2
// Точне значення інтеграла від 0 до 2 дорівнює 8/3
double testFunction(double x) {
    return x * x;
}

int main() {
    double a = 0.0; // Нижня межа
    double b = 2.0; // Верхня межа
    int n = 100;    // Кількість розбиттів

    double exactValue = 8.0 / 3.0; // Точне значення для порівняння

    std::cout << "--- Численне інтегрування f(x) = x^2 на [0, 2] ---\n";

    // Метод середніх прямокутників
    double rectResult = rectangle(testFunction, a, b, n);
    std::cout << "Метод прямокутників: " << rectResult 
              << " (Похибка: " << integrationError(exactValue, rectResult) << ")\n";

    // Метод трапецій
    double trapResult = trapezoid(testFunction, a, b, n);
    std::cout << "Метод трапецій:        " << trapResult 
              << " (Похибка: " << integrationError(exactValue, trapResult) << ")\n";

    // Метод Сімпсона
    double simpResult = simpson(testFunction, a, b, n);
    std::cout << "Метод Сімпсона:        " << simpResult 
              << " (Похибка: " << integrationError(exactValue, simpResult) << ")\n";

    return 0;
}