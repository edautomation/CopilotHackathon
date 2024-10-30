#include "weight.h"
#include <cstdio>
#include <unordered_map>

namespace /* private */ {
std::string getWeightUnitSign(WeightUnit unit) {
    std::unordered_map<WeightUnit, std::string> unitSigns = {
            {WeightUnit::Kilogram, "kg"},
            {WeightUnit::Pound, "lb"},
            {WeightUnit::Ounce, "oz"}};

    return unitSigns.at(unit);
}
} // namespace

namespace WeightConversion {
void startFlow() {
    double sourceValue = getSourceValue();
    WeightUnit from = getWeightUnit("source");
    WeightUnit to = getWeightUnit("target");

    double targetValue = convertWeight(sourceValue, from, to);

    printf("%.2f%s is %.2f%s\n", sourceValue, getWeightUnitSign(from).c_str(),
                 targetValue, getWeightUnitSign(to).c_str());
}

double getSourceValue() {
    double value;
    printf("Enter the value to be converted: ");
    scanf("%lf", &value);
    return value;
}

WeightUnit getWeightUnit(const std::string_view &sourceOrTarget) {
    int choice;
    printf("Select %s weight unit:\n", std::string(sourceOrTarget).c_str());
    printf("[1] Kilogram\n");
    printf("[2] Pound\n");
    printf("[3] Ounce\n");
    printf("Enter choice: ");
    scanf("%d", &choice);

    switch (choice) {
    case 1:
        return WeightUnit::Kilogram;
    case 2:
        return WeightUnit::Pound;
    case 3:
        return WeightUnit::Ounce;
    default:
        return WeightUnit::Kilogram; // Default to Kilogram
    }
}

double convertWeight(double value, WeightUnit from, WeightUnit to) {

    if (from == to) {
        return value; // No conversion needed if units are the same
    }

    // Convert from source unit to Kilogram first
    double valueInKilogram;
    switch (from) {
    case WeightUnit::Kilogram:
        valueInKilogram = value;
        break;
    case WeightUnit::Pound:
        valueInKilogram = value * 0.45359237;
        break;
    case WeightUnit::Ounce:
        valueInKilogram = value * 0.028349523125;
        break;
    default:
        valueInKilogram = value;
        break;
    }

    // Convert from Kilogram to target unit
    double convertedValue;
    switch (to) {
    case WeightUnit::Kilogram:
        convertedValue = valueInKilogram;
        break;
    case WeightUnit::Pound:
        convertedValue = valueInKilogram / 0.45359237;
        break;
    case WeightUnit::Ounce:
        convertedValue = valueInKilogram / 0.028349523125;
        break;
    default:
        convertedValue = valueInKilogram;
        break;
    }

    return convertedValue;
}
} // namespace WeightConversion