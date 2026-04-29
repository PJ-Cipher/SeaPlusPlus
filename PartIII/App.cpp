#include "App.h"
#include "SeaPlusPlusEngine.h"
#include "CreatorHelper.h"
#include "Bag.h"
#include <iostream>
#include <string>
#include <cctype>

bool App::isValidSize(double size) {
    return size > 0 && size < 500;
}

bool App::isValidName(const std::string& name) {
    for (char c : name) {
        if (!isalpha(c)) return false;
    }
    return !name.empty();
}

void App::run() {
    std::cout << "=========================================\n";
    std::cout << "          Welcome to Sea++\n";
    std::cout << "    NSW Fishing Regulation Checker\n";
    std::cout << "=========================================\n";

    // Greet the angler
    std::string anglerName;
    std::cout << "\nBefore we start, what is your name? ";
    std::cin >> anglerName;
    Angler angler(anglerName);
    std::cout << "Welcome, " << angler.getName() << "!\n";

    // The angler's bag for this session
    Bag bag;

    char again = 'y';
    while (again == 'y' || again == 'Y') {

        // Get species name with validation
        std::string name;
        bool validName = false;
        while (!validName) {
            std::cout << "\nWhat did you catch? (e.g. snapper, crab): ";
            std::cin >> name;
            if (isValidName(name)) {
                validName = true;
            } else {
                std::cout << "  Invalid name. Letters only please.\n";
            }
        }

        // Get size with validation
        double size = 0;
        bool validSize = false;
        while (!validSize) {
            std::cout << "How long is it in cm? ";
            if (std::cin >> size) {
                if (isValidSize(size)) {
                    validSize = true;
                } else {
                    std::cout << "  Invalid size. Must be between 0 and 500.\n";
                }
            } else {
                std::cout << "  Please enter a number.\n";
                std::cin.clear();
                std::cin.ignore(1000, '\n');
            }
        }

        // Get eggs status
        char eggsInput;
        std::cout << "Is it carrying eggs? (y/n): ";
        std::cin >> eggsInput;
        bool hasEggs = (eggsInput == 'y' || eggsInput == 'Y');

        // Create the creature using Factory Method
        auto creature = buildCreature(name, size, hasEggs);
        std::cout << "\n[Detected as: " << creature->getType() << "]\n";

        // Check individual creature via engine
        std::string verdict = SeaPlusPlusEngine::instance().evaluate(creature.get());
        std::cout << "Verdict: " << verdict << "\n";

        // If legal, offer to add to bag
        if (verdict.find("KEEP") != std::string::npos) {
            char addToBag;
            std::cout << "Add to your bag? (y/n): ";
            std::cin >> addToBag;
            if (addToBag == 'y' || addToBag == 'Y') {
                bag.addCatch(std::move(creature));
                std::cout << "Added! Bag now has "
                          << bag.getCount() << " catch(es).\n";
            }
        }

        std::cout << "\nCheck another catch? (y/n): ";
        std::cin >> again;
    }

    // Show the bag summary
    bag.display();

    // Check the whole bag against limits
    std::cout << SeaPlusPlusEngine::instance().evaluateBag(bag) << "\n";

    std::cout << "Thanks for fishing with Sea++, "
              << angler.getName() << "! Tight lines!\n";
}