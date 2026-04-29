#pragma once
#include "Rules.h"
#include <map>
#include <string>

// Abstract base class (Strategy pattern)
// Defines that rules CAN be loaded — subclasses decide HOW
class SeaPlusPlusInfoSupplier {
public:
    virtual ~SeaPlusPlusInfoSupplier() = default;

    // Load rules and return them as a map of species name -> Rule
    virtual std::map<std::string, Rule> loadRules() = 0;
};