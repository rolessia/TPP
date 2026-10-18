#include "Integration.h"
#include <cmath>

extern "C" {
    double rectangle(MathFunction f, double a, double b, int n) {
        double h = (b - a) / n;
        double sum = 0.0;
        for (int i = 0; i < n; ++i) {
            sum += f(a + i * h + h / 2.0); 
        }
        return sum * h;
    }

    double trapezoid(MathFunction f, double a, double b, int n) {
        double h = (b - a) / n;
        double sum = (f(a) + f(b)) / 2.0;
        for (int i = 1; i < n; ++i) {
            sum += f(a + i * h);
        }
        return sum * h;
    }

    double simpson(MathFunction f, double a, double b, int n) {
        if (n % 2 != 0) n++; 
        double h = (b - a) / n;
        double sum = f(a) + f(b);
        for (int i = 1; i < n; ++i) {
            double x = a + i * h;
            sum += f(x) * ((i % 2 == 0) ? 2.0 : 4.0);
        }
        return sum * h / 3.0;
    }

    double integrationError(double exact, double approx) {
        return std::abs(exact - approx);
    }
}