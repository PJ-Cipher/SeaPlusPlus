#pragma once
#include "SeaPlusPlusInfoSupplier.h"
#include <string>

// Concrete Strategy — loads rules from a CSV file
class CSVInfoSupplier : public SeaPlusPlusInfoSupplier {
private:
    std::string filename;  // path to the CSV file

public:
    CSVInfoSupplier(const std::string& file) : filename(file) {}

    std::map<std::string, Rule> loadRules() override;
};