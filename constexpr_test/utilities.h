#pragma once

#define XSTR(a) STR(a)
#define STR(a) #a

namespace constexpr_test {
    class utilities {
        template<typename T, auto = (T{}(), 0)>
        constexpr static bool is_constexpr_impl(T, int) { return true; }
        constexpr static bool is_constexpr_impl(auto, auto) { return false; }
        public:
        constexpr static bool is_constexpr(auto expr) { return is_constexpr_impl(expr, 0); }
    };
}