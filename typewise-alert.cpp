#include "typewise-alert.h"
//#include "Identify_Temp_Breach.h"
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
    const char* recepient = "a.b@c.com";
    if(breachType=TOO_LOW) {
        printf("To: %s\n", recepient);
        printf("Hi, the temperature is too low\n");
    }
    elseif(breachType = TOO_HIGH){
        printf("To: %s\n", recepient);
        printf("Hi, the temperature is too high\n");
    }
    else{
        //do nothing
    }
  }
}
