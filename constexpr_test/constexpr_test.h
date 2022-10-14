#pragma once
#include "utilities.h"

namespace constexpr_test {
    template<auto> struct constexpr_test_executor { };
}

#define C_ASSERT_EQ(expected_value, actual_value) TEST_IMPL(expected_value, actual_value, ==)
#define C_ASSERT_NE(expected_value, actual_value) TEST_IMPL(expected_value, actual_value, !=)
#define C_ASSERT_GT(expected_value, actual_value) TEST_IMPL(expected_value, actual_value, >)
#define C_ASSERT_GE(expected_value, actual_value) TEST_IMPL(expected_value, actual_value, >=)
#define C_ASSERT_LT(expected_value, actual_value) TEST_IMPL(expected_value, actual_value, <)
#define C_ASSERT_LE(expected_value, actual_value) TEST_IMPL(expected_value, actual_value, <=)
#define C_ASSERT_TRUE(actual_value) TEST_IMPL(actual_value, true, ==)
#define C_ASSERT_FALSE(actual_value) TEST_IMPL(actual_value, false, ==)


#define TEST_IMPL(expected_value, actual_value, comparator)\
    if (not (expected_value comparator actual_value)) {\
        throw "error";\
    }\


#define TEST_SUITE(test_suite_name)\
    namespace test_suite_name {\
        template<auto> consteval void f() { }\
        template<auto> struct A {};\
        template struct A<(f<0

#define C_TEST_CASE(test_case_name) \
    >(), 0)>;\
    \
    class test_case_name {\
        template<auto expr_lambda>\
        static consteval bool test_impl() {\
            bool test_out = true;\
            expr_lambda(test_out);\
            return test_out;\
        }\
    \
      public:\
        template<auto expr_lambda>\
        static consteval void test() {\
            static_assert(test_impl<expr_lambda>(), XSTR(test_case_name));\
        }\
    };\
    \
    using execute ## test_case_name = constexpr_test::constexpr_test_executor<(test_case_name::test<[](bool& _CONSTEXPR_TEST_OUT_) /* user test code goes here */


#define TEST_SUITE_END \
    >(), 0)>;\
    }
