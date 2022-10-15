#pragma once

#define C_EXPECT_EQ(actual_value, expected_value) C_EXPECT_IMPL(actual_value, expected_value, ==)
#define C_EXPECT_NE(actual_value, expected_value) C_EXPECT_IMPL(actual_value, expected_value, !=)
#define C_EXPECT_GT(actual_value, expected_value) C_EXPECT_IMPL(actual_value, expected_value, >)
#define C_EXPECT_GE(actual_value, expected_value) C_EXPECT_IMPL(actual_value, expected_value, >=)
#define C_EXPECT_LT(actual_value, expected_value) C_EXPECT_IMPL(actual_value, expected_value, <)
#define C_EXPECT_LE(actual_value, expected_value) C_EXPECT_IMPL(actual_value, expected_value, <=)
#define C_EXPECT_TRUE(actual_value) C_EXPECT_IMPL(actual_value, true, ==)
#define C_EXPECT_FALSE(actual_value) C_EXPECT_IMPL(actual_value, false, ==)


#define C_EXPECT_IMPL(actual_value, expected_value, comparator)\
    do {\
        if (not (actual_value comparator expected_value)) {\
            _CONSTEXPR_TEST_OUT_ = false;\
        }\
    } while (false)
