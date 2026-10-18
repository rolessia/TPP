#include <iostream>
#include "Differentiation.h" 

int main() {
    std::cout << "--- Проект 1: Неявне зв'язування (Implicit) ---\n";

    double x = 2.0;
    double h = 0.01;

    // Рахуємо значення функції f(x) = x^2 у точках (x), (x+h) та (x-h)
    double fx = x * x;                                  // 4.0
    double fx_plus_h = (x + h) * (x + h);               // 4.0401
    double fx_minus_h = (x - h) * (x - h);              // 3.9601

    std::cout << "Права різниця:        " << forwardDifference(fx_plus_h, fx, h) << "\n";
    std::cout << "Ліва різниця:         " << backwardDifference(fx, fx_minus_h, h) << "\n";
    std::cout << "Центральна різниця:   " << centralDifference(fx_plus_h, fx_minus_h, h) << "\n";
    std::cout << "Друга похідна:        " << secondDerivative(fx_plus_h, fx, fx_minus_h, h) << "\n";

    // Тестування граничної умови (захист від ділення на нуль)
    std::cout << "\n--- Edge Case: передача h = 0.0 ---\n";
    std::cout << "Результат (очікується 0): " << centralDifference(fx_plus_h, fx_minus_h, 0.0) << "\n";

    return 0;
}