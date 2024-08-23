#include "typewise-alert.h"
#include <stdio.h>
#include <map> 

BreachType inferBreach(double value, double lowerLimit, double upperLimit) {
  if(value < lowerLimit) {
    return TOO_LOW;
  }
  if(value > upperLimit) {
    return TOO_HIGH;
  }
  return NORMAL;
}

struct TemperatureLimits {
    int lowerLimit;
    int upperLimit;
};

BreachType classifyTemperatureBreach(CoolingType coolingType, double temperatureInC) {
    // Define a map to store temperature limits for each cooling type
    static const std::map<CoolingType, TemperatureLimits> coolingLimits = {
        {PASSIVE_COOLING, {0, 35}},
        {HI_ACTIVE_COOLING, {0, 45}},
        {MED_ACTIVE_COOLING, {0, 40}}
    };
    // Find the temperature limits for the given cooling type
    auto it = coolingLimits.find(coolingType);
    if (it != coolingLimits.end()) {
        const TemperatureLimits& limits = it->second;
        return inferBreach(temperatureInC, limits.lowerLimit, limits.upperLimit);
    }
}
