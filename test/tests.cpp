// Copyright 2025 UNN-CS Team
#include <gtest/gtest.h>
#include <cstdint>
#include "circle.h"
#include "tasks.h"

constexpr double epsilon = 1e-6;


TEST(CircleTest, DefaultConstructor) {
    Circle c;
    EXPECT_NEAR(c.getRadius(), 0.0, epsilon);
    EXPECT_NEAR(c.getFerence(), 0.0, epsilon);
    EXPECT_NEAR(c.getArea(), 0.0, epsilon);
}

TEST(CircleTest, PositiveRadiusConstructor) {
    Circle c(5.0);
    EXPECT_NEAR(c.getRadius(), 5.0, epsilon);
    EXPECT_NEAR(c.getFerence(), 2 * pi * 5.0, epsilon);
    EXPECT_NEAR(c.getArea(), pi * 25.0, epsilon);
}

TEST(CircleTest, ZeroRadiusConstructor) {
    Circle c(0.0);
    EXPECT_NEAR(c.getRadius(), 0.0, epsilon);
    EXPECT_NEAR(c.getFerence(), 0.0, epsilon);
    EXPECT_NEAR(c.getArea(), 0.0, epsilon);
}

TEST(CircleTest, NegativeRadiusConstructor) {
    Circle c(-10.0);
    EXPECT_NEAR(c.getRadius(), 0.0, epsilon);
    EXPECT_NEAR(c.getFerence(), 0.0, epsilon);
    EXPECT_NEAR(c.getArea(), 0.0, epsilon);
}

TEST(CircleTest, SetPositiveRadius) {
    Circle c;
    c.setRadius(10.0);
    EXPECT_NEAR(c.getRadius(), 10.0, epsilon);
    EXPECT_NEAR(c.getFerence(), 2 * pi * 10.0, epsilon);
    EXPECT_NEAR(c.getArea(), pi * 100.0, epsilon);
}

TEST(CircleTest, SetZeroRadius) {
    Circle c;
    c.setRadius(0.0);
    EXPECT_NEAR(c.getRadius(), 0.0, epsilon);
    EXPECT_NEAR(c.getFerence(), 0.0, epsilon);
    EXPECT_NEAR(c.getArea(), 0.0, epsilon);
}

TEST(CircleTest, SetNegativeRadius) {
    Circle c;
    c.setRadius(-5.0);
    EXPECT_NEAR(c.getRadius(), 0.0, epsilon);
    EXPECT_NEAR(c.getFerence(), 0.0, epsilon);
    EXPECT_NEAR(c.getArea(), 0.0, epsilon);
}

TEST(CircleTest, SetPositiveFerence) {
    Circle c;
    c.setFerence(31.4159265359);
    EXPECT_NEAR(c.getRadius(), 5.0, epsilon);
    EXPECT_NEAR(c.getFerence(), 31.4159265359, epsilon);
    EXPECT_NEAR(c.getArea(), pi * 25.0, epsilon);
}

TEST(CircleTest, SetZeroFerence) {
    Circle c;
    c.setFerence(0.0);
    EXPECT_NEAR(c.getRadius(), 0.0, epsilon);
    EXPECT_NEAR(c.getFerence(), 0.0, epsilon);
    EXPECT_NEAR(c.getArea(), 0.0, epsilon);
}

TEST(CircleTest, SetNegativeFerence) {
    Circle c;
    c.setFerence(-31.4159265359);
    EXPECT_NEAR(c.getRadius(), 0.0, epsilon);
    EXPECT_NEAR(c.getFerence(), 0.0, epsilon);
    EXPECT_NEAR(c.getArea(), 0.0, epsilon);
}

TEST(CircleTest, SetPositiveArea) {
    Circle c;
    c.setArea(78.5398163397);
    EXPECT_NEAR(c.getRadius(), 5.0, epsilon);
    EXPECT_NEAR(c.getFerence(), 2 * pi * 5.0, epsilon);
    EXPECT_NEAR(c.getArea(), 78.5398163397, epsilon);
}

TEST(CircleTest, SetZeroArea) {
    Circle c;
    c.setArea(0.0);
    EXPECT_NEAR(c.getRadius(), 0.0, epsilon);
    EXPECT_NEAR(c.getFerence(), 0.0, epsilon);
    EXPECT_NEAR(c.getArea(), 0.0, epsilon);
}

TEST(CircleTest, SetNegativeArea) {
    Circle c;
    c.setArea(-78.5398163397);
    EXPECT_NEAR(c.getRadius(), 0.0, epsilon);
    EXPECT_NEAR(c.getFerence(), 0.0, epsilon);
    EXPECT_NEAR(c.getArea(), 0.0, epsilon);
}

TEST(CircleTest, GetRadius) {
    Circle c(7.0);
    EXPECT_NEAR(c.getRadius(), 7.0, epsilon);
}

TEST(CircleTest, GetFerence) {
    Circle c(3.0);
    EXPECT_NEAR(c.getFerence(), 2 * pi * 3.0, epsilon);
}

TEST(CircleTest, GetArea) {
    Circle c(4.0);
    EXPECT_NEAR(c.getArea(), pi * 16.0, epsilon);
}

TEST(CircleTest, VeryLargeRadius) {
    Circle c(1e6);
    EXPECT_NEAR(c.getRadius(), 1e6, epsilon);
    EXPECT_NEAR(c.getFerence(), 2 * pi * 1e6, epsilon);
    EXPECT_NEAR(c.getArea(), pi * 1e12, epsilon);
}

TEST(CircleTest, VerySmallRadius) {
    Circle c(1e-6);
    EXPECT_NEAR(c.getRadius(), 1e-6, epsilon);
    EXPECT_NEAR(c.getFerence(), 2 * pi * 1e-6, epsilon);
    EXPECT_NEAR(c.getArea(), pi * 1e-12, epsilon);
}

TEST(CircleTest, SequentialRadiusChange) {
    Circle c;
    c.setRadius(2.0);
    EXPECT_NEAR(c.getRadius(), 2.0, epsilon);
    c.setRadius(4.0);
    EXPECT_NEAR(c.getRadius(), 4.0, epsilon);
    c.setRadius(0.0);
    EXPECT_NEAR(c.getRadius(), 0.0, epsilon);
}

TEST(CircleTest, SequentialFerenceChange) {
    Circle c;
    c.setFerence(12.5663706144);
    EXPECT_NEAR(c.getRadius(), 2.0, epsilon);
    c.setFerence(25.1327412287);
    EXPECT_NEAR(c.getRadius(), 4.0, epsilon);
    c.setFerence(0.0);
    EXPECT_NEAR(c.getRadius(), 0.0, epsilon);
}

TEST(CircleTest, SequentialAreaChange) {
    Circle c;
    c.setArea(12.5663706144);
    EXPECT_NEAR(c.getRadius(), 2.0, epsilon);
    c.setArea(50.2654824574);
    EXPECT_NEAR(c.getRadius(), 4.0, epsilon);
    c.setArea(0.0);
    EXPECT_NEAR(c.getRadius(), 0.0, epsilon);
}

TEST(EarthRopeTest, CalculateGap) {
    double gap = calculateEarthRopeGap();
    EXPECT_NEAR(gap, 0.1591549431, epsilon);
}

TEST(PoolCostTest, CalculateCost) {
    double cost = calculatePoolCost();
    EXPECT_NEAR(cost, 72256.6310325, epsilon);
}


