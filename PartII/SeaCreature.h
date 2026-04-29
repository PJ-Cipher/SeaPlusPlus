#pragma once
#include <string>

class SeaCreature {
protected:
    std::string name;
    double size;
    bool hasEggs;

public:
    SeaCreature(std::string n, double s, bool eggs)
        : name(n), size(s), hasEggs(eggs) {}

    std::string getName()        const { return name; }
    double      getSize()        const { return size; }
    bool        isCarryingEggs() const { return hasEggs; }

    virtual std::string getType() const = 0;

    virtual ~SeaCreature() {}
};