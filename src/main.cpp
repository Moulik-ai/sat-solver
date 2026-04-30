#include <iostream>
#include "../include/parser.h"
#include "../include/solver.h"

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: ./sat_solver <cnf_file>\n";
        return 1;
    }

    CNFParser parser;

    if (!parser.parseFile(argv[1])) {
        return 1;
    }

    Solver solver(parser.clauses, parser.numVariables);

    bool result = solver.dpll();

    if (result) {
        std::cout << "SAT\n";
        solver.printAssignment();
    } else {
        std::cout << "UNSAT\n";
    }
    return 0;
}