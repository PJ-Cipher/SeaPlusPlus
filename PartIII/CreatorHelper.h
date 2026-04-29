#pragma once
#include "VertebrateCreatureCreator.h"
#include "InvertebrateCreatureCreator.h"
#include <set>
#include <cctype>
#include <memory>

inline std::unique_ptr<SeaCreature> buildCreature(
    const std::string& name, double size, bool hasEggs)
{
    std::set<std::string> invertebrates = {
        "prawn", "crab", "lobster", "abalone",
        "squid", "octopus", "scallop", "mussel", "oyster"
    };

    std::string lower = name;
    for (char& c : lower) c = tolower(c);

    std::unique_ptr<SeaCreatureCreator> creator;
    if (invertebrates.count(lower))
        creator = std::make_unique<InvertebrateCreatureCreator>();
    else
        creator = std::make_unique<VertebrateCreatureCreator>();

    return creator->create(name, size, hasEggs);
}