#include "CSVInfoSupplier.h"
#include <fstream>    // for reading files
#include <sstream>    // for splitting lines
#include <iostream>

// Reads a CSV file with this format:
// species,minSize,bagLimit
// snapper,30,10
// crab,6,20

std::map<std::string, Rule> CSVInfoSupplier::loadRules() {
    std::map<std::string, Rule> rules;

    // Try to open the file
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "ERROR: Could not open rules file: " << filename << "\n";
        return rules;  // return empty rules if file not found
    }

    std::string line;

    // Skip the first line (the header: species,minSize,bagLimit)
    std::getline(file, line);

    // Read every line after that
    while (std::getline(file, line)) {
        // Skip empty lines
        if (line.empty()) continue;

        std::stringstream ss(line);
        std::string name, minSizeStr, bagLimitStr;

        // Split the line by commas
        std::getline(ss, name,       ',');
        std::getline(ss, minSizeStr, ',');
        std::getline(ss, bagLimitStr,',');

        // Convert strings to numbers
        Rule r;
        r.minSize  = std::stod(minSizeStr);
        r.bagLimit = std::stoi(bagLimitStr);

        rules[name] = r;
    }

    file.close();
    std::cout << "[Loaded " << rules.size() << " rules from " << filename << "]\n";
    return rules;
}