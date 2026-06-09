// Copyright 2022 UNN-CS
#ifndef INCLUDE_CIRCLE_H_
#define INCLUDE_CIRCLE_H_

#include <cstdint>

class Circle {
 private:
  double radius;   // радиус
  double ference;  // длина окружности
  double area;     // площадь

  // Вспомогательные методы (будут реализованы в .cpp)
  void updateFromRadius();
  void updateFromFerence();
  void updateFromArea();

 public:
  explicit Circle(double r);          // конструктор

  void setRadius(double r);
  void setFerence(double c);
  void setArea(double a);

  double getRadius() const;
  double getFerence() const;
  double getArea() const;
};

#endif  // INCLUDE_CIRCLE_H_
