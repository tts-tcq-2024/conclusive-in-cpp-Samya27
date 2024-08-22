#include "typewise-alert.h"
#include <cstdio> // For printf
#include <unordered_map> // For std::unordered_map
#include <stdio.h>

void checkAndAlert(
    AlertTarget alertTarget, BatteryCharacter batteryChar, double temperatureInC) {

  BreachType breachType = classifyTemperatureBreach(
    batteryChar.coolingType, temperatureInC
  );

  switch(alertTarget) {
    case TO_CONTROLLER:
      sendToController(breachType);
      break;
    case TO_EMAIL:
      sendToEmail(breachType);
      break;
  }
}

void sendToController(BreachType breachType) {
  const unsigned short header = 0xfeed;
  printf("%x : %x\n", header, breachType);
}

void sendToEmail(BreachType breachType) {
    const char* recipient = "a.b@c.com";

    // Map BreachType to messages
    static const std::unordered_map<BreachType, const char*> messages = {
        {TOO_LOW, "Hi, the temperature is too low"},
        {TOO_HIGH, "Hi, the temperature is too high"}
    };

    // Find the message for the given breachType
    auto it = messages.find(breachType);
    if (it != messages.end()) {
        // Print the email content if a message was found
        printf("To: %s\n", recipient);
        printf("%s\n", it->second);
    }
    // If breachType is NORMAL or not found, do nothing
}
