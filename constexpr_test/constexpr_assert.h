#pragma once

#define C_ASSERT_EQ(actual_value, expected_value) C_ASSERT_IMPL(actual_value, expected_value, ==)
#define C_ASSERT_NE(actual_value, expected_value) C_ASSERT_IMPL(actual_value, expected_value, !=)
#define C_ASSERT_GT(actual_value, expected_value) C_ASSERT_IMPL(actual_value, expected_value, >)
#define C_ASSERT_GE(actual_value, expected_value) C_ASSERT_IMPL(actual_value, expected_value, >=)
#define C_ASSERT_LT(actual_value, expected_value) C_ASSERT_IMPL(actual_value, expected_value, <)
#define C_ASSERT_LE(actual_value, expected_value) C_ASSERT_IMPL(actual_value, expected_value, <=)
#define C_ASSERT_TRUE(actual_value) C_ASSERT_IMPL(actual_value, true, ==)
#define C_ASSERT_FALSE(actual_value) C_ASSERT_IMPL(actual_value, false, ==)

namespace constexpr_test {
    template <int length>
    struct constexpr_error_string {
        char error_string[length+1];
        constexpr constexpr_error_string(const char (&s)[length]) : error_string() {
            for (int i = 0; i < length; ++i) {
                error_string[i] = s[i];
            }
        }
    };

    template <auto length>
    constexpr_error_string(const char (&)[length]) -> constexpr_error_string<length>;

    template <auto>
    constexpr void fail_compilation() { throw R"(Error - search for "CONSTEXPR_TEST_ERROR" in compiler output for more info)"; }
}

#define C_ASSERT_IMPL(actual_value, expected_value, comparator)\
    do\
    {\
        if (not (actual_value comparator expected_value)){\
            fail_compilation<constexpr_error_string{"CONSTEXPR_TEST_ERROR - Assertion failed: " #actual_value " " #comparator " " #expected_value}>();\
        }\
    } while (false)
