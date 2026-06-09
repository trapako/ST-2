// Copyright 2025 UNN-CS
#include "tasks.h"
#include <cmath>
#include <utility>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

double earthRopeGap(double earthRadiusKm) {
    const double earthRadiusM = earthRadiusKm * 1000.0;
    const double initialLength = 2.0 * M_PI * earthRadiusM;
    const double newLength = initialLength + 1.0;
    const double newRadius = newLength / (2.0 * M_PI);
    return newRadius - earthRadiusM;
}

std::pair<double, double> poolCosts(
    double poolRadius, double pathWidth,
    double concreteCostPerSqM, double fenceCostPerM) {
    const double outerRadius = poolRadius + pathWidth;
    const double pathArea = M_PI * (outerRadius * outerRadius
                                    - poolRadius * poolRadius);
    const double concreteTotal = pathArea * concreteCostPerSqM;
    const double fenceLength = 2.0 * M_PI * outerRadius;
    const double fenceTotal = fenceLength * fenceCostPerM;
    return {concreteTotal, fenceTotal};
}
