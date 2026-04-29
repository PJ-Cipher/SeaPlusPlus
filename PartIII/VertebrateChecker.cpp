#include "VertebrateChecker.h"
#include <sstream>
#include <cctype>

VertebrateChecker::VertebrateChecker() {
    rules["snapper"]  = { 30.0, 10 };
    rules["flathead"] = { 27.0, 10 };
    rules["whiting"]  = { 27.0, 20 };
    rules["bream"]    = { 25.0, 10 };
    rules["luderick"] = { 27.0, 20 };
    rules["tailor"]   = { 30.0, 20 };
    rules["mulloway"] = { 45.0,  2 };
    rules["kingfish"] = { 65.0,  5 };
    rules["flounder"] = { 25.0, 20 };
    rules["tuna"]     = { 45.0,  3 };
}

std::string VertebrateChecker::check(SeaCreature* creature) {
    if (creature->isCarryingEggs())
        return "THROW BACK - Carrying eggs. Release it immediately!";

    std::string name = creature->getName();
    for (char& c : name) c = tolower(c);

    if (rules.count(name) == 0)
        return "UNKNOWN SPECIES - No rule found. Check the NSW DPI website.";

    Rule r = rules[name];
    std::ostringstream result;

    if (creature->getSize() < r.minSize) {
        result << "THROW BACK - Too small! "
               << creature->getName() << " must be at least "
               << r.minSize << " cm. Yours is "
               << creature->getSize() << " cm.";
    } else {
        result << "KEEP - Legal size! Your "
               << creature->getName() << " ("
               << creature->getSize() << " cm). "
               << "Daily bag limit: " << r.bagLimit << ".";
    }
    return result.str();
}