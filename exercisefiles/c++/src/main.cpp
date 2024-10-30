#include "converters/types.h"
#include "converters/temperature.h"
#include "converters/distance.h"
#include <iostream>
#include <array>

ConversionType getConversionType()
{
  int choice;
  std::array<ConversionType, 2> conversionTypes = {
      ConversionType::Temperature,
      ConversionType::Distance};

  while (true)
  {
    std::cout << "Select type of conversion:\n";
    std::cout << "[1] Temperature\n";
    std::cout << "[2] Distance\n";
    std::cout << "Enter choice: ";
    std::cin >> choice;

    if (choice > 0 && choice <= conversionTypes.size())
    {
      return conversionTypes[choice - 1];
    }

    std::cout << "Invalid choice. Please try again.\n";
  }
}

int main()
{
  ConversionType type = getConversionType();
  switch (type)
  {
  case ConversionType::Temperature:
    {
      TemperatureConversion::startFlow();
      break;
    }
  case ConversionType::Distance:
    {
      DistanceConversion::startFlow();
      break;
    }
  }
}