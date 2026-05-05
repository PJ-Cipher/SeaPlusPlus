Sea++ 🐟
CSE5008 Programming Assignment 2
NSW Fishing Regulation Checker — Command Line Application

What Is Sea++?
Sea++ is a command-line C++ application that helps NSW anglers determine whether their catch is legal to keep under current NSW Department of Primary Industries fishing regulations. The angler enters the species name, size, and whether the creature is carrying eggs — and Sea++ instantly tells them whether to keep it or throw it back.

How To Compile
Requirements

A C++ compiler supporting C++14 or later (g++ recommended)
Mac: xcode-select --install
Linux: sudo apt install g++
Windows: MinGW-w64 or WSL

Part II
bashcd PartII
g++ main.cpp App.cpp SeaPlusPlusEngine.cpp VertebrateChecker.cpp InvertebrateChecker.cpp -std=c++14 -o seaplusplus
./seaplusplus
Part III
bashcd PartIII
g++ main.cpp App.cpp SeaPlusPlusEngine.cpp VertebrateChecker.cpp InvertebrateChecker.cpp BagChecker.cpp CSVInfoSupplier.cpp -std=c++14 -o seaplusplus
./seaplusplus

Note: The saltwater_rules.csv file must be in the same folder as the compiled binary when running Part III.


How To Use

Run the program
Enter your name
Enter the species you caught (e.g. snapper, crab, lobster)
Enter the size in cm
Indicate whether it is carrying eggs (y or n)
Sea++ will tell you: KEEP or THROW BACK and why
If the catch is legal, you can add it to your bag
At the end of your session, Sea++ displays a full bag report checking your daily bag limits


Project Structure
SeaPlusPlus/
├── PartII/                         ← Base implementation (Part II)
│   ├── main.cpp
│   ├── App.h / App.cpp             ← Façade pattern
│   ├── SeaPlusPlusEngine.h/.cpp    ← Mediator + Singleton pattern
│   ├── SeaCreature.h               ← Abstract base class
│   ├── VertebrateCreature.h        ← Fish subclass
│   ├── InvertebrateCreature.h      ← Shellfish subclass
│   ├── SeaCreatureCreator.h        ← Factory Method (abstract)
│   ├── VertebrateCreatureCreator.h ← Factory Method (concrete)
│   ├── InvertebrateCreatureCreator.h
│   ├── CreatorHelper.h             ← Factory routing helper
│   ├── SeaChecker.h                ← Abstract checker base
│   ├── VertebrateChecker.h/.cpp    ← Fish rule checker
│   ├── InvertebrateChecker.h/.cpp  ← Shellfish rule checker
│   ├── Angler.h                    ← Represents the user
│   └── Rules.h                     ← Rule data struct
│
├── PartIII/                        ← Extended implementation (Part III)
│   ├── (all Part II files)
│   ├── Bag.h                       ← Stores multiple catches
│   ├── BagChecker.h/.cpp           ← Validates bag against limits
│   ├── SeaPlusPlusInfoSupplier.h   ← Abstract info supplier (Strategy)
│   ├── CSVInfoSupplier.h/.cpp      ← Loads rules from CSV file
│   └── saltwater_rules.csv         ← NSW fishing regulation data
│
├── UML/
│   ├── PartI_UML.png               ← UML diagram for Part II design
│   └── Part III_UML.png            ← UML diagram for Part III design
│
└── Reflection/
    └── Part IV.docx                ← Reflection document

Design Patterns Used
PatternWherePurposeFaçadeAppHides all system complexity behind a simple run() callMediatorSeaPlusPlusEngineRoutes creatures to the correct checker without App knowing the detailsSingletonSeaPlusPlusEngineEnsures only one engine instance exists at runtimeFactory MethodSeaCreatureCreator + subclassesDelegates creature creation to the appropriate concrete creatorStrategySeaPlusPlusInfoSupplierAllows rules to be loaded from different sources (CSV, etc.)

Species Supported
Saltwater Fish (Vertebrates)
SpeciesMin Size (cm)Bag Limit/daySnapper3010Flathead2710Whiting2720Bream2510Luderick2720Tailor3020Mulloway452Kingfish655Flounder2520Tuna453
Invertebrates
SpeciesMin Size (cm)Bag Limit/dayPrawnNone200Crab620Lobster104Abalone11.52SquidNone20Scallop550OctopusNone5

Regulations sourced from the NSW DPI Saltwater Bag and Size Limits


Part III Extensions
Extension 1 — Bag + BagChecker
Anglers can accumulate catches in a bag during their session. At the end, the BagChecker validates the entire bag against NSW daily bag limits and flags any species that has been over-caught.
Extension 2 — SeaPlusPlusInfoSupplier + CSVInfoSupplier
Fishing regulations are loaded from saltwater_rules.csv at runtime rather than being hardcoded. This means regulations can be updated by editing the CSV file without recompiling the application.
