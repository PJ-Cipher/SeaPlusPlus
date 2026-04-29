#pragma once
#include "Angler.h"

// Facade — the only thing the user interacts with directly
class App {
private:
    // Validates that the size entered is a positive number
    bool isValidSize(double size);

    // Validates that the species name only has letters
    bool isValidName(const std::string& name);

public:
    void run();
};