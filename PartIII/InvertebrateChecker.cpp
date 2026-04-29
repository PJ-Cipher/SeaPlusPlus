#include "InvertebrateChecker.h"
#include <sstream>
#include <cctype>

InvertebrateChecker::InvertebrateChecker() {
    rules["prawn"]   = {  0.0, 200 };
    rules["crab"]    = {  6.0,  20 };
    rules["lobster"] = { 10.0,   4 };
    rules["abalone"] = { 11.5,   2 };
    rules["squid"]   = {  0.0,  20 };
    rules["scallop"] = {  5.0,  50 };
    rules["octopus"] = {  0.0,   5 };
}

std::string InvertebrateChecker::check(SeaCreature* creature) {
    if (creature->isCarryingEggs())
        return "THROW BACK - Carrying eggs. Release it immediately!";

    std::string name = creature->getName();
    for (char& c : name) c = tolower(c);

    if (rules.count(name) == 0)
        return "UNKNOWN SPECIES - No rule found. Check the NSW DPI website.";

    Rule r = rules[name];
    std::ostringstream result;

    if (r.minSize > 0 && creature->getSize() < r.minSize) {
        result << "THROW BACK - Too small! "
               << creature->getName() << " must be at least "
               << r.minSize << " cm. Yours is "
               << creature->getSize() << " cm.";
    } else {
        result << "KEEP - Legal! Your "
               << creature->getName()
               << ". Daily bag limit: " << r.bagLimit << ".";
    }
    return result.str();
}