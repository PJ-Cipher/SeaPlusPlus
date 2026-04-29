#pragma once
#include "SeaCreatureCreator.h"
#include "InvertebrateCreature.h"

class InvertebrateCreatureCreator : public SeaCreatureCreator {
public:
    std::unique_ptr<SeaCreature> create(
        const std::string& name,
        double size,
        bool hasEggs) const override
    {
        return std::make_unique<InvertebrateCreature>(name, size, hasEggs);
    }
};