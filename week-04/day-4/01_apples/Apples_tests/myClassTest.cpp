#include <gtest/gtest.h>
#include "myClass.h"

TEST(appleTest, TestIfItPrints)
{
    ASSERT_EQ(getApple(), "apple");
}