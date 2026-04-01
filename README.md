# SAT Solver in C++

A modular SAT Solver built in C++ using a structured, phase-based approach.
This project explores core concepts from Boolean logic, discrete mathematics, and algorithm design.

---

## 🚀 Features (Current)

* ✅ DIMACS CNF file parsing
* ✅ Assignment system (3-state logic)
* ✅ Clause evaluation engine
* ✅ Formula evaluation (SAT / UNSAT / UNDECIDED)
* 🔜 DPLL algorithm (next phase)
* 🔜 Unit propagation
* 🔜 Pure literal elimination

---

## 🧠 Core Concepts

### Boolean Satisfiability (SAT)

Given a Boolean formula, determine if there exists an assignment of variables that makes it TRUE.

Example:
(x₁ ∨ ¬x₂) ∧ (x₂ ∨ x₃)

---

### CNF (Conjunctive Normal Form)

A formula is in CNF if it is:

* AND of clauses
* Each clause is an OR of literals

Example:
1 -2 0 → (x₁ ∨ ¬x₂)

---

### Assignment System

Each variable can be:

| Value | Meaning    |
| ----- | ---------- |
| 1     | TRUE       |
| -1    | FALSE      |
| 0     | UNASSIGNED |

---

### Clause Evaluation

A clause can be:

* TRUE → at least one literal is TRUE
* FALSE → all literals are FALSE
* UNDECIDED → no TRUE yet, but some unassigned

---

### Formula Evaluation

* SAT (1) → all clauses TRUE
* UNSAT (-1) → at least one clause FALSE
* UNDECIDED (0) → otherwise

---

## 📂 Project Structure

sat-solver/
│
├── src/
│   ├── main.cpp
│   ├── parser.cpp
│   ├── solver.cpp
│
├── include/
│   ├── parser.h
│   ├── solver.h
│
├── test/
│   ├── sample.cnf
│
├── .gitignore
└── README.md

---

## ⚙️ Compilation

### Linux / Mac

g++ -std=c++17 src/main.cpp src/parser.cpp src/solver.cpp -Iinclude -o sat_solver

### Windows

g++ -std=c++17 src/main.cpp src/parser.cpp src/solver.cpp -Iinclude -o sat_solver.exe

---

## ▶️ Run

### Linux / Mac

./sat_solver test/sample.cnf

### Windows

sat_solver.exe test/sample.cnf

---

## 📘 DIMACS CNF Format

Example:
c Example CNF
p cnf 3 2
1 -2 0
2 3 0

Each line represents a clause:
1 -2 0 → (x₁ ∨ ¬x₂)

---

## 🧪 Current Output

Example:
Initial Formula State: 0

Meaning:

* 1 → SAT
* -1 → UNSAT
* 0 → UNDECIDED

---

## 🛠️ Roadmap

* [x] Phase 1: CNF Parser
* [x] Phase 2: Assignment & Evaluation System
* [ ] Phase 3: Basic DPLL Solver
* [ ] Phase 4: Unit Propagation
* [ ] Phase 5: Pure Literal Elimination
* [ ] Phase 6: CLI + Testing

---

## 💡 Tech Stack

* C++
* STL (Standard Template Library)

---

## 📌 Author

Moulik Choudhary
CSE Student | Robotics & Systems Enthusiast

---

## ⭐ Notes

This project is being built incrementally to emphasize:

* Clean architecture
* Algorithmic clarity
* Real-world engineering practices

---

## 🤝 Contributions

Open to suggestions, optimizations, and improvements!
