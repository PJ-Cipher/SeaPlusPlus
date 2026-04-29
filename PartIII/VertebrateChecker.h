#pragma once
#include "SeaChecker.h"
#include "Rules.h"
#include <map>
#include <string>

class VertebrateChecker : public SeaChecker {
private:
    std::map<std::string, Rule> rules;

public:
    VertebrateChecker(std::map<std::string, Rule> r) : rules(r) {}

    std::string check(SeaCreature* creature) override;
};