#pragma once
#include "utilities.h"
#include "constexpr_assertions.h"


namespace constexpr_test {
    template<auto> struct constexpr_test_executor { };
}


#define TEST_SUITE(test_suite_name)\
    namespace constexpr_test::test_suite_name {\
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
