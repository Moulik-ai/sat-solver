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

int Solver::chooseVariable() {
    for (int i = 1; i < assignment.size(); i++) {
        if (assignment[i] == 0) return i;
    }
    return -1;

}

bool Solver::dpll() {

    if (!unitPropogation()) return false;
    int state = evaluateFormula();

    if (state == 1) return true;
    if (state == -1) return false;

    int var = chooseVariable();

    if (var == -1) return false;

    assignment[var] = 1;
    if (dpll()) return true;

    assignment[var] = -1;
    if(dpll()) return true;

    assignment[var] = 0;

    return false;
}

bool Solver::unitPropogation() {
    bool changed = true;

    while (changed) {
        changed = false;

        for (const auto& clause : clauses) {
            int unassignedCount = 0;
            int lastUnassignedLit = 0;
            bool clauseTrue = false;

            for (int lit : clause) {
                int val = evaluateLiteral(lit);

                if (val == 1) {
                    clauseTrue = true;
                    break;

                }

                if (val == 0) {
                    unassignedCount++;
                    lastUnassignedLit = lit;
                }
            }

            if (clauseTrue) continue;

            if (unassignedCount == 0) {
                return false;

            }

            if (unassignedCount == 1) {
                int var= abs(lastUnassignedLit);
                int value = (lastUnassignedLit > 0) ? 1 : -1;

                if (assignment[var] == 0) {
                    assignment[var] = value;
                    changed = true;
                }
            }
        }
    }
    return true;
}