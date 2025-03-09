// Copyright 2025 UNN-CS Team
#include "tasks.h"
#include <cmath>
#include "circle.h"

double calculateEarthRopeGap() {
    const double earthRadius = 6378100;
    Circle earth(earthRadius);

    double newFerence = earth.getFerence() + 1;

    Circle newCircle(0);
    newCircle.setFerence(newFerence);

    double gap = newCircle.getRadius() - earthRadius;
    return gap;
}

double calculatePoolCost() {
    const double poolRadius = 3;
    const double pathWidth = 1;
    const double concreteCost = 1000;
    const double fenceCost = 2000;

    Circle pool(poolRadius);
    Circle poolWithPath(poolRadius + pathWidth);

    double pathArea = poolWithPath.getArea() - pool.getArea();
    double fenceLength = poolWithPath.getFerence();

    double totalConcreteCost = pathArea * concreteCost;
    double totalFenceCost = fenceLength * fenceCost;

    return totalConcreteCost + totalFenceCost;
}
