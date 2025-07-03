#include <bits/stdc++.h>
#include <chrono> // Add this for timing

// #include "Model/RubiksCube3dArray.cpp"
// #include "Model/RubiksCube1dArray.cpp"
// #include "Model/RubiksCubeBitboard.cpp"
#include "RubiksCube.h"
#include "Solver/DFSSolver.h"
#include "Solver/BFSSolver.h"
#include "Solver/IDDFSSolver.h"
#include "Solver/IDAstarSolver.h"
#include "PatternDatabases/CornerDBMaker.h"

using namespace std;
using namespace std::chrono;

int main() {

    /*--- DFS Solver ---*/
    RubiksCubeBitboard cube_dfs;

    vector<RubiksCube::MOVE> shuffle_moves1 = cube_dfs.randomShuffleCube(6);

    cout << "Shuffling moves (DFS): ";
    for (auto move: shuffle_moves1) cout << cube_dfs.getMove(move) << " ";
    cout << "\n";
    cube_dfs.print();

    auto start_dfs = high_resolution_clock::now();
    DFSSolver<RubiksCubeBitboard, HashBitboard> dfsSolver(cube_dfs, 8);
    vector<RubiksCube::MOVE> solve_moves1 = dfsSolver.solve();
    auto end_dfs = high_resolution_clock::now();

    cout << "Solution (DFS): ";
    for (auto move: solve_moves1) cout << cube_dfs.getMove(move) << " ";
    cout << "\n";
    dfsSolver.rubiksCube.print();
    cout << "Time (DFS): " 
         << duration_cast<milliseconds>(end_dfs - start_dfs).count()
         << " ms\n";
    cout << "-----------------------------\n";


    /*--- BFS Solver ---*/
    RubiksCubeBitboard cube_bfs;

    vector<RubiksCube::MOVE> shuffle_moves2 = cube_bfs.randomShuffleCube(6);

    cout << "Shuffling moves (BFS): ";
    for (auto move: shuffle_moves2) cout << cube_bfs.getMove(move) << " ";
    cout << "\n";
    cube_bfs.print();

    auto start_bfs = high_resolution_clock::now();
    BFSSolver<RubiksCubeBitboard, HashBitboard> bfsSolver(cube_bfs);
    vector<RubiksCube::MOVE> solve_moves2 = bfsSolver.solve();
    auto end_bfs = high_resolution_clock::now();

    cout << "Solution (BFS): ";
    for (auto move: solve_moves2) cout << cube_bfs.getMove(move) << " ";
    cout << "\n";
    bfsSolver.rubiksCube.print(); 
    cout << "Time (BFS): " 
         << duration_cast<milliseconds>(end_bfs - start_bfs).count()
         << " ms\n";
    cout << "-----------------------------\n";

    
    /*--- IDDFS Solver ---*/
    RubiksCubeBitboard cube_iddfs;

    vector<RubiksCube::MOVE> shuffle_moves3 = cube_iddfs.randomShuffleCube(7);

    cout << "Shuffling moves (IDDFS): ";
    for (auto move: shuffle_moves3) cout << cube_iddfs.getMove(move) << " ";
    cout << "\n";
    cube_iddfs.print();

    auto start_iddfs = high_resolution_clock::now();
    IDDFSSolver<RubiksCubeBitboard, HashBitboard> iddfsSolver(cube_iddfs, 7);
    vector<RubiksCube::MOVE> solve_moves3 = iddfsSolver.solve();
    auto end_iddfs = high_resolution_clock::now();

    cout << "Solution (IDDFS): ";
    for (auto move: solve_moves3) cout << cube_iddfs.getMove(move) << " ";
    cout << "\n";
    iddfsSolver.rubiksCube.print();
    cout << "Time (IDDFS): " 
         << duration_cast<milliseconds>(end_iddfs - start_iddfs).count()
         << " ms\n";
    cout << "-----------------------------\n";


    /*--- IDA* Solver ---*/
    string fileName = "cornerDepthDB.txt";

    // Code to create Corner Database (comment out if already built)
    // CornerDBMaker dbMaker(fileName, 0x99);
    // dbMaker.bfsAndStore(9);      

    RubiksCubeBitboard cube_ida;

    vector<RubiksCube::MOVE> shuffleMoves4 = cube_ida.randomShuffleCube(13);

    cout << "Shuffling moves (IDA*): ";
    for (auto move: shuffleMoves4) cout << cube_ida.getMove(move) << " ";
    cout << "\n";
    cube_ida.print();

    auto start_ida = high_resolution_clock::now();
    IDAstarSolver<RubiksCubeBitboard, HashBitboard> idaStarSolver(cube_ida, fileName);
    vector<RubiksCube::MOVE> solve_moves4 = idaStarSolver.solve();
    auto end_ida = high_resolution_clock::now();

    cout << "Solution (IDA*): ";
    for (auto move: solve_moves4) cout << cube_ida.getMove(move) << " ";
    cout << "\n";
    idaStarSolver.rubiksCube.print();
    cout << "Time (IDA*): " 
         << duration_cast<milliseconds>(end_ida - start_ida).count()
         << " ms\n";
    cout << "-----------------------------\n";

    return 0;
}