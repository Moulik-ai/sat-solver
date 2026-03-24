#include "../include/parser.h"
#include <fstream>
#include <sstream>
#include <iostream>

bool CNFParser::parseFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: Cannot open file\n";
        return false;
    }

    std::string line;

    while (std::getline(file,line)) {
        if (line.empty() || line[0] == 'c') continue;

        if (line[0] == 'p') {
            std::stringstream ss(line);
            std:: string temp;
            int numClauses;

            ss >> temp >> temp >> numVariables >> numClauses;
        } else {
            std::stringstream ss(line);
            int literal;
            std::vector<int> clause;

            while (ss >> literal && literal != 0) {
                clause.push_back(literal);
            }

            if (!clause.empty()) {
                clauses.push_back(clause);
            }
        }
    }

    file.close();
    return true;
}