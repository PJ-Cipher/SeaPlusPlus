#include "SeaPlusPlusEngine.h"

std::string SeaPlusPlusEngine::evaluate(SeaCreature* creature) {
    if (creature->getType() == "vertebrate")
        return vertebrateChecker.check(creature);
    else
        return invertebrateChecker.check(creature);
}