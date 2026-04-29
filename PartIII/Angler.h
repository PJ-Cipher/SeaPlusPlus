#pragma once
#include <string>

// Represents the person using the app
// Stores their name so the app can greet them personally
class Angler {
private:
    std::string name;

public:
    Angler(std::string n) : name(n) {}

    std::string getName() const { return name; }
};