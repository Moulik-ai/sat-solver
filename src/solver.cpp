#include "../include/solver.h"
#include <cstdlib>

Solver::Solver(const std::vector<std::vector<int>>& cls, int numVars) {
    clauses = cls;
    assignment.resize(numVars + 1, 0);
}

int Solver::evaluateLiteral(int literal) {
    int var = std::abs(literal);
    int val = assignment[var];

    if (val == 0) return 0;

    if (literal > 0) return val;
    else return -val;
}

int Solver::evaluateClause(const std::vector<int>& clause) {
    bool hasUnassigned = false;

    for (int lit : clause) {
        int val = evaluateLiteral(lit);

        if (val == 1) return 1;
        if (val == 0) hasUnassigned = true;
    }

    if (hasUnassigned) return 0;
    return -1;
}

int Solver::evaluateFormula() {
    bool allTrue = true;

    for (const auto& clause : clauses) {
        int val = evaluateClause(clause);

        if (val == -1) return -1;
        if (val == 0) allTrue = false;
    }

    return allTrue ? 1 : 0;
}