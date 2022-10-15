#pragma once

#define C_ASSERT_EQ(actual_value, expected_value) C_ASSERT_IMPL(actual_value, expected_value, ==)
#define C_ASSERT_NE(actual_value, expected_value) C_ASSERT_IMPL(actual_value, expected_value, !=)
#define C_ASSERT_GT(actual_value, expected_value) C_ASSERT_IMPL(actual_value, expected_value, >)
#define C_ASSERT_GE(actual_value, expected_value) C_ASSERT_IMPL(actual_value, expected_value, >=)
#define C_ASSERT_LT(actual_value, expected_value) C_ASSERT_IMPL(actual_value, expected_value, <)
#define C_ASSERT_LE(actual_value, expected_value) C_ASSERT_IMPL(actual_value, expected_value, <=)
#define C_ASSERT_TRUE(actual_value) C_ASSERT_IMPL(actual_value, true, ==)
#define C_ASSERT_FALSE(actual_value) C_ASSERT_IMPL(actual_value, false, ==)


#define C_ASSERT_IMPL(actual_value, expected_value, comparator)\
    do {\
        if (not (actual_value comparator expected_value)) {\
            throw "Error in '" XSTR(actual_value) " " XSTR(comparator) " " XSTR(expected_value) "'" ;\
        }\
    } while (false)
