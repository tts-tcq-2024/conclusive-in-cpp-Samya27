#include <gtest/gtest.h>
#include "typewise-alert.h"

TEST(TypeWiseAlertTestSuite, TestClassifiesTemperatureBreach) {
    EXPECT_EQ(classifyTemperatureBreach(PASSIVE_COOLING, 25), NORMAL);
    EXPECT_EQ(classifyTemperatureBreach(PASSIVE_COOLING, 50), TOO_HIGH);
    EXPECT_EQ(classifyTemperatureBreach(HI_ACTIVE_COOLING, 60), TOO_HIGH);
    EXPECT_EQ(classifyTemperatureBreach(HI_ACTIVE_COOLING, 35), NORMAL);
    EXPECT_EQ(classifyTemperatureBreach(MED_ACTIVE_COOLING, -1), TOO_LOW);
    EXPECT_EQ(classifyTemperatureBreach(MED_ACTIVE_COOLING, 20), NORMAL);
}
TEST(TypeWiseAlertTestSuite,TestInfersBreachAccordingToLimits) {
    EXPECT_EQ(inferBreach(14, 20, 40), TOO_LOW);
    EXPECT_EQ(inferBreach(30, 20, 40), NORMAL);
    EXPECT_EQ(inferBreach(50, 20, 40), TOO_HIGH);
}
