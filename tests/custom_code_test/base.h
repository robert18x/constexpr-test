#pragma once

class base {
    public:
    virtual constexpr int get_int() final {
        return i;
    }

    constexpr virtual void change_state() = 0;

    protected:
    int i = 0;
};
