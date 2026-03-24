#ifndef PARSER_H
#define PARSER_H

#include <vector>
#include <string>

class CNFParser {
    public:
    std::vector<std::vector<int>> clauses;
    int numVariables;

    bool parseFile(const std::string& filename);
};
#endif