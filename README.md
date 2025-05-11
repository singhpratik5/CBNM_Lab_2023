# CBNM Lab Coursework – 2023

This repository contains coursework submissions and programs written as part of the Computer Based Numerical Methods (CBNM) Lab at the University of Hyderabad in 2023.

## 📘 About the Course
CBNM Lab focuses on the practical implementation of numerical algorithms using C programming. It includes:
- Solving equations
- Interpolation
- Numerical integration/differentiation
- Linear algebraic operations
- Ordinary differential equations

## 📂 Contents
Each file is a C program that implements a standard numerical method:

| File | Description |
|------|-------------|
| `bisection.c` | Root-finding using the Bisection method |
| `newton_raphson.c` | Root-finding using Newton-Raphson method |
| `gauss_elimination.c` | Solving linear systems using Gaussian elimination |
| `trapezoidal.c` | Numerical integration using the Trapezoidal rule |
| `simpsons.c` | Simpson’s 1/3 rule for integration |
| `lagrange.c` | Lagrange interpolation |
| `euler_method.c` | Solving ODEs using Euler’s method |
| _and others_ | More numerical methods implemented in C |

> 📌 All programs were compiled and tested using GCC on Linux. Proper input validation and comments are included for clarity.

## 🔧 How to Run
```bash
gcc <filename>.c -o <output>
./<output>
