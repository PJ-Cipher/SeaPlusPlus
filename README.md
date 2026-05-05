
# Sea++ 🐟
### CSE5008 Programming Assignment 2
**NSW Fishing Regulation Checker — Command Line Application**

---

## What Is Sea++?

Sea++ is a command-line C++ application that helps NSW anglers determine whether their catch is legal to keep under current NSW Department of Primary Industries fishing regulations. The angler enters the species name, size, and whether the creature is carrying eggs — and Sea++ instantly tells them whether to keep it or throw it back.

---

## How To Compile

### Part II
cd PartII
g++ main.cpp App.cpp SeaPlusPlusEngine.cpp VertebrateChecker.cpp InvertebrateChecker.cpp -std=c++14 -o seaplusplus
./seaplusplus

### Part III
cd PartIII
g++ main.cpp App.cpp SeaPlusPlusEngine.cpp VertebrateChecker.cpp InvertebrateChecker.cpp BagChecker.cpp CSVInfoSupplier.cpp -std=c++14 -o seaplusplus
./seaplusplus

Note: saltwater_rules.csv must be in the same folder as the binary when running Part III.

---

## How To Use

1. Run the program
2. Enter your name
3. Enter the species you caught (e.g. snapper, crab, lobster)
4. Enter the size in cm
5. Indicate whether it is carrying eggs (y or n)
6. Sea++ will tell you: KEEP or THROW BACK and why
7. If legal, add it to your bag
8. At the end of your session, Sea++ shows a full bag report

---

## Design Patterns Used

| Pattern         | Where                      | Purpose                                              |
|-----------------|----------------------------|------------------------------------------------------|
| Facade          | App                        | Hides all complexity behind a simple run() call      |
| Mediator        | SeaPlusPlusEngine          | Routes creatures to the correct checker              |
| Singleton       | SeaPlusPlusEngine          | Ensures only one engine instance exists              |
| Factory Method  | SeaCreatureCreator         | Delegates creature creation to correct subclass      |
| Strategy        | SeaPlusPlusInfoSupplier    | Allows rules to be loaded from different sources     |

---

## Species Supported

Fish: snapper, flathead, whiting, bream, luderick, tailor, mulloway, kingfish, flounder, tuna
Invertebrates: prawn, crab, lobster, abalone, squid, scallop, octopus

Regulations sourced from NSW DPI Saltwater Bag and Size Limits.

---

## Part III Extensions

Extension 1 - Bag + BagChecker:
Anglers accumulate catches in a bag. BagChecker validates the bag against daily limits.

Extension 2 - SeaPlusPlusInfoSupplier + CSVInfoSupplier:
Rules are loaded from saltwater_rules.csv at runtime instead of being hardcoded.

---
