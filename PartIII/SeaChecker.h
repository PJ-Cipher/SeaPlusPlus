#pragma once
#include "SeaCreature.h"
#include <string>

class SeaChecker {
public:
    virtual std::string check(SeaCreature* creature) = 0;
    virtual ~SeaChecker() {}
};