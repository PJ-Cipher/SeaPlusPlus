#pragma once
#include "SeaCreature.h"
#include <vector>
#include <memory>
#include <string>
#include <iostream>

// Holds all the creatures an angler has caught today
class Bag {
private:
    // unique_ptr means the bag OWNS the creatures
    // When the bag is destroyed, the creatures are too — no memory leaks
    std::vector<std::unique_ptr<SeaCreature>> catches;

public:
    // Add a creature to the bag
    void addCatch(std::unique_ptr<SeaCreature> creature) {
        catches.push_back(std::move(creature));
    }

    // How many creatures are in the bag total
    int getCount() const {
        return catches.size();
    }

    // Show everything in the bag
    void display() const {
        if (catches.empty()) {
            std::cout << "Your bag is empty.\n";
            return;
        }

        std::cout << "\n--- Your Bag (" << catches.size() << " catches) ---\n";
        for (size_t i = 0; i < catches.size(); i++) {
            std::cout << (i + 1) << ". "
                      << catches[i]->getName()
                      << " (" << catches[i]->getSize() << " cm, "
                      << catches[i]->getType() << ")\n";
        }
    }

    // Give the BagChecker access to read the catches
    const std::vector<std::unique_ptr<SeaCreature>>& getCatches() const {
        return catches;
    }
};