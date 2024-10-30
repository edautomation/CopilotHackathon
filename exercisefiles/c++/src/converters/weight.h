#ifndef WEIGHT_H
#define WEIGHT_H

#include <string>

enum class WeightUnit {
    Kilogram,
    Gram,
    Pound,
    Ounce
};

namespace WeightConversion {
    void startFlow();
    double getSourceValue();
    WeightUnit getWeightUnit(const std::string_view &sourceOrTarget);
    double convertWeight(double value, WeightUnit from, WeightUnit to);
};
#endif // WEIGHT_H