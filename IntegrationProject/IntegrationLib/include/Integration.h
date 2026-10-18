#pragma once

// Макроси для експорту/імпорту символів
#ifdef INTEGRATION_EXPORTS
#define INTEGRATION_API extern "C" __declspec(dllexport)
#else
#define INTEGRATION_API extern "C" __declspec(dllimport)
#endif
// Визначаємо тип для вказівника на математичну функцію для зручності
typedef double (*MathFunction)(double);
// Оголошення експортованих функцій
INTEGRATION_API double rectangle(MathFunction f, double a, double b, int n);
INTEGRATION_API double trapezoid(MathFunction f, double a, double b, int n);
INTEGRATION_API double simpson(MathFunction f, double a, double b, int n);
INTEGRATION_API double integrationError(double exact, double approx);