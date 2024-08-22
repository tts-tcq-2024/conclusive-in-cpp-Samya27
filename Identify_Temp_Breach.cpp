#include "typewise-alert.h"
#include <stdio.h>

BreachType inferBreach(double value, double lowerLimit, double upperLimit) {
  if(value < lowerLimit) {
    return TOO_LOW;
  }
  if(value > upperLimit) {
    return TOO_HIGH;
  }
  return NORMAL;
}

class TemperatureLimits {
    int lowerLimit;
    int upperLimit;

    TemperatureLimits(int lowerLimit, int upperLimit) {
        this.lowerLimit = lowerLimit;
        this.upperLimit = upperLimit;
    }
}

BreachType inferBreach(double temperatureInC, int lowerLimit, int upperLimit) {
    // Assume this function is already defined
    // Example: return BreachType.TOO_HIGH if temperatureInC > upperLimit, etc.
    return new BreachType();
}

BreachType classifyTemperatureBreach(CoolingType coolingType, double temperatureInC) {
    Map<CoolingType, TemperatureLimits> coolingLimits = new HashMap<>();
    coolingLimits.put(CoolingType.PASSIVE_COOLING, new TemperatureLimits(0, 35));
    coolingLimits.put(CoolingType.HI_ACTIVE_COOLING, new TemperatureLimits(0, 45));
    coolingLimits.put(CoolingType.MED_ACTIVE_COOLING, new TemperatureLimits(0, 40));

    TemperatureLimits limits = coolingLimits.get(coolingType);
    return inferBreach(temperatureInC, limits.lowerLimit, limits.upperLimit);
}
