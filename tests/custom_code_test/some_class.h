#pragma once
#include "base.h"

class some_class : public base {
    public:
    constexpr some_class() {
        i = 0;
    }
    constexpr some_class(int i) {
        this->i = i;
    }

    constexpr void change_state() override {
        ++i;
    }
};
