#pragma once
#include "SeaCreatureCreator.h"
#include "VertebrateCreature.h"

class VertebrateCreatureCreator : public SeaCreatureCreator {
public:
    std::unique_ptr<SeaCreature> create(
        const std::string& name,
        double size,
        bool hasEggs) const override
    {
        return std::make_unique<VertebrateCreature>(name, size, hasEggs);
    }
};