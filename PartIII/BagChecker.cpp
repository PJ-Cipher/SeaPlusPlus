#include "BagChecker.h"
#include <sstream>
#include <cctype>

std::string BagChecker::check(const Bag& bag) {
    if (bag.getCount() == 0) {
        return "Bag is empty - nothing to check.";
    }

    // Count how many of each species are in the bag
    std::map<std::string, int> counts;
    for (const auto& creature : bag.getCatches()) {
        std::string name = creature->getName();
        for (char& c : name) c = tolower(c);
        counts[name]++;
    }

    // Build the report
    std::ostringstream report;
    report << "\n=== BAG REPORT ===\n";

    bool anyOverLimit = false;

    // Go through each species the angler caught
    for (const auto& pair : counts) {
        std::string species = pair.first;
        int count = pair.second;

        // Look up the rule for this species
        if (rules.count(species) == 0) {
            report << "- " << species << ": " << count
                   << " (no rule found)\n";
            continue;
        }

        Rule r = rules[species];

        if (count > r.bagLimit) {
            report << "- " << species << ": " << count
                   << " caught, limit is " << r.bagLimit
                   << " - OVER LIMIT! Release " << (count - r.bagLimit) << ".\n";
            anyOverLimit = true;
        } else {
            report << "- " << species << ": " << count
                   << " caught, limit is " << r.bagLimit
                   << " - OK\n";
        }
    }

    if (anyOverLimit) {
        report << "\nWARNING: You have exceeded daily bag limits!\n";
    } else {
        report << "\nAll within daily limits. Enjoy your catch!\n";
    }

    return report.str();
}