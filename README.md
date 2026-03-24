# SAT Solver in C++

A modular SAT Solver built in C++ using a structured, phase-based approach.
This project implements core concepts from Boolean logic and discrete mathematics, including CNF parsing and (upcoming) DPLL-based solving.

---

## 🚀 Features (Current)

* ✅ DIMACS CNF file parsing
* ✅ Clean modular architecture
* 🔜 DPLL algorithm (coming in next phases)
* 🔜 Unit propagation
* 🔜 Pure literal elimination

---

## 🧠 What is SAT?

The Boolean Satisfiability Problem (SAT) asks:

> Can a Boolean formula be satisfied by some assignment of TRUE/FALSE values?

Example:
(x₁ ∨ ¬x₂) ∧ (x₂ ∨ x₃)

---

## 📂 Project Structure

sat-solver/
│
├── src/
│   ├── main.cpp
│   ├── parser.cpp
│
├── include/
│   ├── parser.h
│
├── test/
│   ├── sample.cnf
│
└── README.md

---

## ⚙️ Compilation

### Linux / Mac

g++ -std=c++17 src/main.cpp src/parser.cpp -Iinclude -o sat_solver

### Windows

g++ -std=c++17 src/main.cpp src/parser.cpp -Iinclude -o sat_solver.exe

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

## 🛠️ Roadmap

* [x] Phase 1: CNF Parser
* [ ] Phase 2: Data Structures & Assignment System
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

## ⭐ Contributing

This is a learning-focused project, but suggestions and improvements are welcome!
