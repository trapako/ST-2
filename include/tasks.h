#ifndef INCLUDE_TASKS_H_
#define INCLUDE_TASKS_H_

#include <utility>

double earthRopeGap(double earthRadiusKm);

std::pair<double, double> poolCosts(double poolRadius, double pathWidth,
                                    double concreteCostPerSqM, double fenceCostPerM);

#endif  // INCLUDE_TASKS_H_
