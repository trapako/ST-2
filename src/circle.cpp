// Copyright 2022 UNN-CS
#include "circle.h"
#include <cmath>
#include <stdexcept>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

Circle::Circle(double r) {
    setRadius(r);
}

void Circle::updateFromRadius() {
    ference = 2.0 * M_PI * radius;
    area = M_PI * radius * radius;
}

void Circle::updateFromFerence() {
    radius = ference / (2.0 * M_PI);
    area = M_PI * radius * radius;
}

void Circle::updateFromArea() {
    radius = std::sqrt(area / M_PI);
    ference = 2.0 * M_PI * radius;
}

void Circle::setRadius(double r) {
    if (r <= 0.0) throw std::invalid_argument("Radius must be positive");
    radius = r;
    updateFromRadius();
}

void Circle::setFerence(double c) {
    if (c <= 0.0) throw std::invalid_argument("Circumference must be positive");
    ference = c;
    updateFromFerence();
}

void Circle::setArea(double a) {
    if (a <= 0.0) throw std::invalid_argument("Area must be positive");
    area = a;
    updateFromArea();
}

double Circle::getRadius() const {
    return radius;
}

double Circle::getFerence() const {
    return ference;
}

double Circle::getArea() const {
    return area;
}
