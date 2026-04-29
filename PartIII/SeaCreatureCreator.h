#pragma once
#include "SeaCreature.h"
#include <memory>
#include <string>

// Abstract Creator (Factory Method pattern)
class SeaCreatureCreator {
public:
    virtual ~SeaCreatureCreator() = default;

    virtual std::unique_ptr<SeaCreature> create(
        const std::string& name,
        double size,
        bool hasEggs) const = 0;
};