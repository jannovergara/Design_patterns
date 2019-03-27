#pragma once
#include "HotDrink.h"

struct HotDrinkFactory
{
    // smart pointer that is automatically deleted when out of scope
    virtual unique_ptr<HotDrink> make() const = 0;
};