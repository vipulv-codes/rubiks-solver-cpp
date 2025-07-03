# Rubik’s Cube Solver in C++

A modular Rubik’s Cube solver written in modern C++, demonstrating multiple search strategies (DFS, BFS, IDDFS, IDA*) and heuristic acceleration via a precomputed corner pattern database.

---

## 🔍 Features

- **Cube Representations**  
  - 3D array  
  - 1D array  
  - 64-bit “bitboard”  

- **Solving Algorithms**  
  - Depth-First Search (DFS) with depth limit  
  - Breadth-First Search (BFS)  
  - Iterative Deepening DFS (IDDFS)  
  - Iterative Deepening A* (IDA*)  

- **Heuristic Acceleration**  
  - Corner Pattern Database (PDB) up to configurable depth  
  - Fast lookup of admissible heuristics for IDA*  

- **Performance Metrics**  
  - Built-in timers to measure solve times in milliseconds  

---