#include "constexpr_test.h"
#include <memory>
#include <optional>
#include <string_view>
#include <string>

constexpr int square(int num) {
    return num * num;
}

TEST_SUITE(compilation_tests)

C_TEST_CASE(test_non_constexpr_variables_which_are_constexpr_constructable) {
    C_ASSERT_EQ(square(2), 4);
    C_ASSERT_NE(square(2), 5);

    int i = 4;
    C_ASSERT_EQ(square(i), i*i);

    auto i_ptr = std::make_unique<int>(i);
    C_ASSERT_EQ(*i_ptr, i);

    std::optional<int> val = std::nullopt;
    C_ASSERT_EQ(val, std::nullopt);

    val = i;
    C_ASSERT_TRUE(val.has_value());
    C_ASSERT_EQ(val.value(), i);

    std::string_view text("text");
    std::string text_str(text);
    C_ASSERT_EQ(text, text_str);
    C_ASSERT_FALSE(text_str.empty());
}

C_TEST_CASE(assert_macro_test) {
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
}

TEST_SUITE_END

int main() {

}

