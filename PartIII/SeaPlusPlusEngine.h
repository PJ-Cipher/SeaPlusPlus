#pragma once
#include "SeaCreature.h"
#include "Bag.h"
#include "BagChecker.h"
#include "VertebrateChecker.h"
#include "InvertebrateChecker.h"
#include "CSVInfoSupplier.h"
#include <string>

class SeaPlusPlusEngine {
private:
    VertebrateChecker   vertebrateChecker;
    InvertebrateChecker invertebrateChecker;
    BagChecker          bagChecker;

    SeaPlusPlusEngine()
        : vertebrateChecker(CSVInfoSupplier("saltwater_rules.csv").loadRules()),
          invertebrateChecker(CSVInfoSupplier("saltwater_rules.csv").loadRules()),
          bagChecker(CSVInfoSupplier("saltwater_rules.csv").loadRules())
    {}

    SeaPlusPlusEngine(const SeaPlusPlusEngine&) = delete;
    SeaPlusPlusEngine& operator=(const SeaPlusPlusEngine&) = delete;

public:
    static SeaPlusPlusEngine& instance() {
        static SeaPlusPlusEngine engine;
        return engine;
    }

    // Check a single creature
    std::string evaluate(SeaCreature* creature);

    // Check a whole bag
    std::string evaluateBag(const Bag& bag);
};