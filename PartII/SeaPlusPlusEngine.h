#pragma once
#include "SeaCreature.h"
#include "VertebrateChecker.h"
#include "InvertebrateChecker.h"
#include <string>

class SeaPlusPlusEngine {
private:
    VertebrateChecker   vertebrateChecker;
    InvertebrateChecker invertebrateChecker;

    SeaPlusPlusEngine() {}
    SeaPlusPlusEngine(const SeaPlusPlusEngine&) = delete;
    SeaPlusPlusEngine& operator=(const SeaPlusPlusEngine&) = delete;

public:
    static SeaPlusPlusEngine& instance() {
        static SeaPlusPlusEngine engine;
        return engine;
    }

    std::string evaluate(SeaCreature* creature);
};