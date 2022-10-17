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
    template<int n>
    struct Str {
	char data[n];
	constexpr Str(char const (&s)[n]): data{} { for(int i=0; s[i]; ++i) data[i] = s[i]; }
    };

    template<auto n>
    Str(char const (&)[n]) -> Str<n>;

    template<auto>
    constexpr void fail() { throw 0; }
}

#define C_ASSERT_IMPL(actual_value, expected_value, comparator)\
    do {\
        if (not (actual_value comparator expected_value)) {\
	    fail<Str{"Assertion failed: " #actual_value " " #comparator " " #expected_value}>(); \
        }\
    } while (false)
