#include "constexpr_test.h"
#include <compare>
#include <memory>
#include <optional>
#include <string>
#include <string_view>
#include <variant>

constexpr int square(int num) {
    return num * num;
}

TEST_SUITE(test_non_constexpr_variables_which_are_constexpr_constructable)

C_TEST_CASE(function_invoking) {
    C_ASSERT_EQ(square(2), 4);
    C_ASSERT_NE(square(2), 5);

    int i = 4;
    C_ASSERT_EQ(square(i), i * i);
}

C_TEST_CASE(unique_ptr_variables) {
    int i = 100;
    auto i_ptr = std::make_unique<int>(i);
    C_ASSERT_EQ(*i_ptr, i);

    struct S {
        constexpr auto operator<=>(const S&) const = default;
        int i;
        bool b;
    };
    auto s1 = std::make_unique<S>();
    s1->i = 1;
    s1->b = true;

    auto s2 = std::make_unique<S>(*s1);
    C_ASSERT_NE(s1, nullptr);
    C_ASSERT_NE(s2, nullptr);
    C_ASSERT_EQ(*s1, *s2);
}

C_TEST_CASE(optional_variables) {
    std::optional<int> opt = std::nullopt;
    C_ASSERT_EQ(opt, std::nullopt);

    int value = 10;
    opt = value;
    C_ASSERT_TRUE(opt.has_value());
    C_ASSERT_EQ(opt.value(), value);
}

C_TEST_CASE(string_variables) {
    std::string_view view("text");
    std::string str(view);

    C_ASSERT_FALSE(view.empty());
    C_ASSERT_FALSE(str.empty());

    C_ASSERT_EQ(view, str);
}

TEST_SUITE_END



TEST_SUITE(assertion_macro_test)

C_TEST_CASE(test_all_assertions_via_macros) {
    C_ASSERT_EQ(1, 1);
    C_ASSERT_NE(1, 0);
    C_ASSERT_GT(10, 5);
    C_ASSERT_LT(5, 10);
    C_ASSERT_TRUE(true);
    C_ASSERT_FALSE(false);

    C_ASSERT_GE(10, 5);
    C_ASSERT_GE(10, 10);

    C_ASSERT_LE(5, 10);
    C_ASSERT_LE(5, 5);

    C_ASSERT_NOTHROW([] {}());
}

TEST_SUITE_END

int main() {
    return 0;
}
