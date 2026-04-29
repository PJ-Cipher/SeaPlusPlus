#pragma once
#include "Bag.h"
#include "Rules.h"
#include <map>
#include <string>

// Validates that a bag doesn't exceed daily bag limits
class BagChecker {
private:
    // Maps species name to its rule (same format as the checkers use)
    std::map<std::string, Rule> rules;

public:
    // Constructor takes the rules to validate against
    BagChecker(std::map<std::string, Rule> r) : rules(r) {}

    // Returns a report on the whole bag
    std::string check(const Bag& bag);
};