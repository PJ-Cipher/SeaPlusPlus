#pragma once
#include "SeaChecker.h"
#include "Rules.h"
#include <map>
#include <string>

class InvertebrateChecker : public SeaChecker {
private:
    std::map<std::string, Rule> rules;

public:
    // Receives rules from outside
    InvertebrateChecker(std::map<std::string, Rule> r) : rules(r) {}

    std::string check(SeaCreature* creature) override;
};