#pragma once

namespace constexpr_test {
    class utilities {
        template<typename T, auto = (T{}(), 0)>
        static constexpr bool is_constexpr_impl(T, int) { return true; }
        static constexpr bool is_constexpr_impl(auto, auto) { return false; }
        public:
        static constexpr bool is_constexpr(auto expr) { return is_constexpr_impl(expr, 0); }
    };
}
