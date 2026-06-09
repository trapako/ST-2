// Copyright 2025 UNN-CS
#include <gtest/gtest.h>
#include "circle.h"
#include "tasks.h"
#include <cmath>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

const double EPS = 1e-9;

TEST(CircleTest, ConstructorAndGetters) {
    Circle c(5.0);
    EXPECT_NEAR(c.getRadius(), 5.0, EPS);
    EXPECT_NEAR(c.getFerence(), 2.0 * M_PI * 5.0, EPS);
    EXPECT_NEAR(c.getArea(), M_PI * 25.0, EPS);
}

TEST(CircleTest, SetRadius) {
    Circle c(1.0);
    c.setRadius(3.0);
    EXPECT_NEAR(c.getRadius(), 3.0, EPS);
    EXPECT_NEAR(c.getFerence(), 2.0 * M_PI * 3.0, EPS);
    EXPECT_NEAR(c.getArea(), M_PI * 9.0, EPS);
}

TEST(CircleTest, SetFerence) {
    Circle c(1.0);
    c.setFerence(2.0 * M_PI * 4.0);
    EXPECT_NEAR(c.getRadius(), 4.0, EPS);
    EXPECT_NEAR(c.getArea(), M_PI * 16.0, EPS);
}

TEST(CircleTest, SetArea) {
    Circle c(1.0);
    c.setArea(M_PI * 9.0);
    EXPECT_NEAR(c.getRadius(), 3.0, EPS);
    EXPECT_NEAR(c.getFerence(), 2.0 * M_PI * 3.0, EPS);
}

TEST(CircleTest, NegativeRadiusThrows) {
    Circle c(1.0);
    EXPECT_THROW(c.setRadius(-5.0), std::invalid_argument);
    EXPECT_THROW(c.setRadius(0.0), std::invalid_argument);
}

TEST(CircleTest, NegativeFerenceThrows) {
    Circle c(1.0);
    EXPECT_THROW(c.setFerence(-10.0), std::invalid_argument);
    EXPECT_THROW(c.setFerence(0.0), std::invalid_argument);
}

TEST(CircleTest, NegativeAreaThrows) {
    Circle c(1.0);
    EXPECT_THROW(c.setArea(-1.0), std::invalid_argument);
    EXPECT_THROW(c.setArea(0.0), std::invalid_argument);
}

TEST(CircleTest, VerySmallRadius) {
    Circle c(1e-6);
    EXPECT_NEAR(c.getRadius(), 1e-6, EPS);
    EXPECT_NEAR(c.getFerence(), 2.0 * M_PI * 1e-6, EPS);
    EXPECT_NEAR(c.getArea(), M_PI * 1e-12, EPS);
}

TEST(CircleTest, ConsistencyAfterMultipleSets) {
    Circle c(2.0);
    c.setRadius(5.0);
    c.setFerence(20.0);
    c.setArea(30.0);
    double r = c.getRadius();
    EXPECT_NEAR(c.getFerence(), 2.0 * M_PI * r, EPS);
    EXPECT_NEAR(c.getArea(), M_PI * r * r, EPS);
}

TEST(EarthRopeTest, StandardRadius) {
    double gap = earthRopeGap(6378.1);
    double expected = 1.0 / (2.0 * M_PI);
    EXPECT_NEAR(gap, expected, EPS);
}

TEST(EarthRopeTest, IndependenceOfRadius) {
    double gap1 = earthRopeGap(6378.1);
    double gap2 = earthRopeGap(1.0);
    double gap3 = earthRopeGap(0.001);
    EXPECT_NEAR(gap1, gap2, EPS);
    EXPECT_NEAR(gap1, gap3, EPS);
}

TEST(EarthRopeTest, ZeroRadius) {
    double gap = earthRopeGap(0.0);
    double expected = 1.0 / (2.0 * M_PI);
    EXPECT_NEAR(gap, expected, EPS);
}

// ---------- Тесты для задачи "Бассейн" ----------
TEST(PoolCostsTest, DefaultValues) {
    auto [concrete, fence] = poolCosts(3.0, 1.0, 1000.0, 2000.0);
    double outer = 4.0;
    double expectedConcrete = M_PI * (outer*outer - 9.0) * 1000.0;
    double expectedFence = 2.0 * M_PI * outer * 2000.0;
    EXPECT_NEAR(concrete, expectedConcrete, EPS);
    EXPECT_NEAR(fence, expectedFence, EPS);
}

TEST(PoolCostsTest, ZeroWidth) {
    auto [concrete, fence] = poolCosts(5.0, 0.0, 1000.0, 2000.0);
    EXPECT_NEAR(concrete, 0.0, EPS);
    double expectedFence = 2.0 * M_PI * 5.0 * 2000.0;
    EXPECT_NEAR(fence, expectedFence, EPS);
}

TEST(PoolCostsTest, DifferentPrices) {
    auto [concrete, fence] = poolCosts(2.0, 1.5, 500.0, 1500.0);
    double outer = 3.5;
    double expectedConcrete = M_PI * (outer*outer - 4.0) * 500.0;
    double expectedFence = 2.0 * M_PI * outer * 1500.0;
    EXPECT_NEAR(concrete, expectedConcrete, EPS);
    EXPECT_NEAR(fence, expectedFence, EPS);
}

TEST(PoolCostsTest, LargeRadius) {
    auto [concrete, fence] = poolCosts(100.0, 10.0, 1000.0, 2000.0);
    double outer = 110.0;
    double expectedConcrete = M_PI * (outer*outer - 10000.0) * 1000.0;
    double expectedFence = 2.0 * M_PI * outer * 2000.0;
    EXPECT_NEAR(concrete, expectedConcrete, EPS);
    EXPECT_NEAR(fence, expectedFence, EPS);
}

TEST(PoolCostsTest, VeryNarrowPath) {
    auto [concrete, fence] = poolCosts(3.0, 0.1, 1000.0, 2000.0);
    double outer = 3.1;
    double expectedConcrete = M_PI * (outer*outer - 9.0) * 1000.0;
    double expectedFence = 2.0 * M_PI * outer * 2000.0;
    EXPECT_NEAR(concrete, expectedConcrete, EPS);
    EXPECT_NEAR(fence, expectedFence, EPS);
}
