#include <gtest/gtest.h>
#include "typewise-alert.h"

TEST(TypeWiseAlertTestSuite,InfersBreachAccordingToLimits) {
    EXPECT_EQ(inferBreach(14, 20, 40), TOO_LOW);
    EXPECT_EQ(inferBreach(30, 20, 40), TOO_LOW);
    EXPECT_EQ(inferBreach(50, 20, 40), TOO_HIGH);
}
