#include "weight.h"
#include <gtest/gtest.h>

TEST(WeightConversionTest, KilogramToPound) { EXPECT_NEAR(WeightConversion::convertWeight(1.0, WeightUnit::Kilogram, WeightUnit::Pound), 2.20462, 0.0001); }

TEST(WeightConversionTest, PoundToKilogram) { EXPECT_NEAR(WeightConversion::convertWeight(1.0, WeightUnit::Pound, WeightUnit::Kilogram), 0.453592, 0.0001); }

TEST(WeightConversionTest, OunceToKilogram) { EXPECT_NEAR(WeightConversion::convertWeight(1.0, WeightUnit::Ounce, WeightUnit::Kilogram), 0.0283495, 0.0001); }

TEST(WeightConversionTest, KilogramToOunce) { EXPECT_NEAR(WeightConversion::convertWeight(1.0, WeightUnit::Kilogram, WeightUnit::Ounce), 35.274, 0.0001); }

TEST(WeightConversionTest, PoundToOunce) { EXPECT_NEAR(WeightConversion::convertWeight(1.0, WeightUnit::Pound, WeightUnit::Ounce), 16.0, 0.0001); }

TEST(WeightConversionTest, OunceToPound) { EXPECT_NEAR(WeightConversion::convertWeight(1.0, WeightUnit::Ounce, WeightUnit::Pound), 0.0625, 0.0001); }

TEST(WeightConversionTest, SameUnitConversion) { EXPECT_DOUBLE_EQ(WeightConversion::convertWeight(1.0, WeightUnit::Kilogram, WeightUnit::Kilogram), 1.0); }
