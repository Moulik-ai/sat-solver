#ifndef SOLVER_H
#define SOLVER_H
#include <vector>

class Solver {
    public:
    std::vector<std::vector<int>> clauses;
    std::vector<int> assignment;

    Solver(const std::vector<std::vector<int>>& cls, int numVars);

    int evaluateLiteral(int literal);
    int evaluateClause(const std::vector<int>& clause);
    int evaluateFormula();

};
#endif