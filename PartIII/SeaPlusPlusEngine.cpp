#include "SeaPlusPlusEngine.h"

std::string SeaPlusPlusEngine::evaluate(SeaCreature* creature) {
    if (creature->getType() == "vertebrate")
        return vertebrateChecker.check(creature);
    else
        return invertebrateChecker.check(creature);
}

std::string SeaPlusPlusEngine::evaluateBag(const Bag& bag) {
    return bagChecker.check(bag);
}