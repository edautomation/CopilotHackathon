#include <gtest/gtest.h>
#include "distance.h"

const double tolerance = 1e-3;

TEST(DistanceConversionTest, MetersToFeet) {
    EXPECT_NEAR(DistanceConversion::convertDistance(1.0, DistanceUnit::Meters, DistanceUnit::Feet), 3.28084, tolerance);
    EXPECT_NEAR(DistanceConversion::convertDistance(0.0, DistanceUnit::Meters, DistanceUnit::Feet), 0.0, tolerance);
    EXPECT_NEAR(DistanceConversion::convertDistance(100.0, DistanceUnit::Meters, DistanceUnit::Feet), 328.084, tolerance);
}

TEST(DistanceConversionTest, FeetToMeters) {
    EXPECT_NEAR(DistanceConversion::convertDistance(3.28084, DistanceUnit::Feet, DistanceUnit::Meters), 1.0, tolerance);
    EXPECT_NEAR(DistanceConversion::convertDistance(0.0, DistanceUnit::Feet, DistanceUnit::Meters), 0.0, tolerance);
    EXPECT_NEAR(DistanceConversion::convertDistance(328.084, DistanceUnit::Feet, DistanceUnit::Meters), 100.0, tolerance);
}

TEST(DistanceConversionTest, MetersToYards) {
    EXPECT_NEAR(DistanceConversion::convertDistance(1.0, DistanceUnit::Meters, DistanceUnit::Yards), 1.09361, tolerance);
    EXPECT_NEAR(DistanceConversion::convertDistance(0.0, DistanceUnit::Meters, DistanceUnit::Yards), 0.0, tolerance);
    EXPECT_NEAR(DistanceConversion::convertDistance(100.0, DistanceUnit::Meters, DistanceUnit::Yards), 109.361, tolerance);
}

TEST(DistanceConversionTest, YardsToMeters) {
    EXPECT_NEAR(DistanceConversion::convertDistance(1.09361, DistanceUnit::Yards, DistanceUnit::Meters), 1.0, tolerance);
    EXPECT_NEAR(DistanceConversion::convertDistance(0.0, DistanceUnit::Yards, DistanceUnit::Meters), 0.0, tolerance);
    EXPECT_NEAR(DistanceConversion::convertDistance(109.361, DistanceUnit::Yards, DistanceUnit::Meters), 100.0, tolerance);
}

TEST(DistanceConversionTest, FeetToYards) {
    EXPECT_NEAR(DistanceConversion::convertDistance(3.0, DistanceUnit::Feet, DistanceUnit::Yards), 1.0, tolerance);
    EXPECT_NEAR(DistanceConversion::convertDistance(0.0, DistanceUnit::Feet, DistanceUnit::Yards), 0.0, tolerance);
    EXPECT_NEAR(DistanceConversion::convertDistance(300.0, DistanceUnit::Feet, DistanceUnit::Yards), 100.0, tolerance);
}

TEST(DistanceConversionTest, YardsToFeet) {
    EXPECT_NEAR(DistanceConversion::convertDistance(1.0, DistanceUnit::Yards, DistanceUnit::Feet), 3.0, tolerance);
    EXPECT_NEAR(DistanceConversion::convertDistance(0.0, DistanceUnit::Yards, DistanceUnit::Feet), 0.0, tolerance);
    EXPECT_NEAR(DistanceConversion::convertDistance(100.0, DistanceUnit::Yards, DistanceUnit::Feet), 300.0, tolerance);
}
