#pragma once
#include "SeaCreature.h"

class VertebrateCreature : public SeaCreature {
public:
    VertebrateCreature(std::string n, double s, bool eggs)
        : SeaCreature(n, s, eggs) {}

    std::string getType() const override { return "vertebrate"; }
};