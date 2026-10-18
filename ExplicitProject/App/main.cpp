#include <iostream>
#include <windows.h>

// Оголошуємо типи вказівників на функції напарника
// Три функції приймають три double (fx_plus_h/fx/fx_minus_h та h)
typedef double (*DiffFunc3)(double, double, double);
// Одна функція (друга похідна) приймає чотири double
typedef double (*DiffFunc4)(double, double, double, double);

int main() {
    std::cout << "--- Проект 2: Явне зв'язування (Explicit) ---\n";

    // Завантажуємо DLL під час виконання програми
    HMODULE hLib = LoadLibrary(TEXT("Differentiation.dll"));
    
    if (hLib == NULL) {
        std::cerr << "Помилка: не вдалося завантажити Differentiation.dll\n";
        return 1;
    }

    // Отримуємо адреси функцій з DLL за їхніми іменами
    DiffFunc3 forwardDiff = (DiffFunc3)GetProcAddress(hLib, "forwardDifference");
    DiffFunc3 backwardDiff = (DiffFunc3)GetProcAddress(hLib, "backwardDifference");
    DiffFunc3 centralDiff = (DiffFunc3)GetProcAddress(hLib, "centralDifference");
    DiffFunc4 secondDiff = (DiffFunc4)GetProcAddress(hLib, "secondDerivative");

    // Перевіряємо, чи всі функції знайдено
    if (!forwardDiff || !backwardDiff || !centralDiff || !secondDiff) {
        std::cerr << "Помилка: не вдалося знайти функції у DLL.\n";
        FreeLibrary(hLib);
        return 1;
    }

    // 4. Використовуємо функції
    double x = 2.0;
    double h = 0.01;

    // Обчислюємо значення функції f(x) = x^2 для передачі в функції диференціювання
    double fx = x * x;                            
    double fx_plus_h = (x + h) * (x + h);            
    double fx_minus_h = (x - h) * (x - h);           

    std::cout << "Права різниця:        " << forwardDiff(fx_plus_h, fx, h) << "\n";
    std::cout << "Ліва різниця:         " << backwardDiff(fx, fx_minus_h, h) << "\n";
    std::cout << "Центральна різниця:   " << centralDiff(fx_plus_h, fx_minus_h, h) << "\n";
    std::cout << "Друга похідна:        " << secondDiff(fx_plus_h, fx, fx_minus_h, h) << "\n";

    // Тестування граничної умови (h = 0.0)
    std::cout << "\n--- Edge Case: передача h = 0.0 ---\n";
    std::cout << "Результат (очікується 0): " << centralDiff(fx_plus_h, fx_minus_h, 0.0) << "\n";

    // Звільняємо бібліотеку
    FreeLibrary(hLib);

    return 0;
}