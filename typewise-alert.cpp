#include "typewise-alert.h"
#include <cstdio> 
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
    
    // Array of messages
    static const char* messages[] = {
        "Hi, the temperature is too low",  // Message for TOO_LOW
        "Hi, the temperature is too high", // Message for TOO_HIGH
        nullptr                           // No message for NORMAL
    };

    // Ensure breachType is within valid range
    if (breachType < TOO_LOW || breachType > NORMAL) {
        return; // Handle unexpected breachType
    }

    const char* message = messages[breachType];
    if (message) {
        printf("To: %s\n", recipient);
        printf("%s\n", message);
    }
}
