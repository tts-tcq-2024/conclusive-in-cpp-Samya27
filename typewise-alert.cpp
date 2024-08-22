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
    const char* message = nullptr;

    // Determine the message based on the breachType
    switch (breachType) {
        case TOO_LOW:
            message = "Hi, the temperature is too low";
            break;
        case TOO_HIGH:
            message = "Hi, the temperature is too high";
            break;
        default:
            // Do nothing or handle unexpected BreachType if necessary
            return;
    }

    // Send the email if a message was set
    if (message) {
        printf("To: %s\n", recipient);
        printf("%s\n", message);
    }
}
