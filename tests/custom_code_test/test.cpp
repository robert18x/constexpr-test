#include "constexpr_test.h"
#include "some_class.h"


TEST_SUITE(inheritence_test)

C_TEST_CASE(derived_class_test) {
    int value = 20;
    some_class s(value);
    C_ASSERT_EQ(s.get_int(), value);

    s.change_state();
    C_ASSERT_EQ(s.get_int(), value+1);
}

C_TEST_CASE(base_class_test) {
    some_class s;

    base* base_hander = dynamic_cast<base*>(&s);

    C_ASSERT_NE(base_hander, nullptr);
    C_ASSERT_EQ(base_hander->get_int(), 0);

    base_hander->change_state();
    C_ASSERT_EQ(base_hander->get_int(), 1);

    s.change_state();
    C_ASSERT_EQ(base_hander->get_int(), 2);
}

TEST_SUITE_END

int main() {

}
