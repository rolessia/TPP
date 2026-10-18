#pragma once

#ifdef DIFFERENTIATION_EXPORTS
    #define DIFF_API extern "C" __declspec(dllexport)
#else
    #define DIFF_API extern "C" __declspec(dllimport)
#endif

DIFF_API double forwardDifference(double fx_plus_h, double fx, double h);
DIFF_API double backwardDifference(double fx, double fx_minus_h, double h);
DIFF_API double centralDifference(double fx_plus_h, double fx_minus_h, double h);
DIFF_API double secondDerivative(double fx_plus_h, double fx, double fx_minus_h, double h);