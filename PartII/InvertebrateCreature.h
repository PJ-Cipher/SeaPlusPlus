#pragma once
#include "SeaCreature.h"

class InvertebrateCreature : public SeaCreature {
public:
    InvertebrateCreature(std::string n, double s, bool eggs)
        : SeaCreature(n, s, eggs) {}

    std::string getType() const override { return "invertebrate"; }
};