// Copyright 2025 UNN-CS Team
#ifndef INCLUDE_CIRCLE_H_
#define INCLUDE_CIRCLE_H_
#include <cstdint>
#include <cmath>

constexpr double pi = 3.1415926535;

class Circle {
 private:
    double radius;
    double ference;
    double area;

    void updateFerence();
    void updateArea();

 public:
    Circle() : radius(0.0), ference(0.0), area(0.0) {}
    explicit Circle(double r);

    void setRadius(double r);
    void setFerence(double f);
    void setArea(double a);

    double getRadius() const;
    double getFerence() const;
    double getArea() const;
};

#endif  // INCLUDE_CIRCLE_H_
