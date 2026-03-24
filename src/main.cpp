#include <iostream>
#include "../include/parser.h"

int main() {
    CNFParser parser;

    if (!parser.parseFile("test/sample.cnf")) {
        return 1;
    }

    std::cout << "Parsed CNF:\n";

    for (const auto& clause : parser.clauses) {
        for (int lit : clause) {
            std::cout << lit << " ";
        }
        std::cout << "\n";
    }

    return 0;
}