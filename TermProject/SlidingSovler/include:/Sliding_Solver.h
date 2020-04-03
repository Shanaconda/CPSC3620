//
//  Sliding_Solver.h
//  TermProject
//
//  Created by Shannon Abeda on 2020-03-26.
//  Copyright © 2020 Shannon Abeda. All rights reserved.
//

#ifndef Sliding_Solver_h
#define Sliding_Solver_h
#include <iostream>
#include <string>
#include <stdlib.h>
#include<list>
#include <vector>
#include<queue>
#include<set>
#include <functional>
#include "Board_Title.h"

using namespace std;

class Sliding_Solver {
    public:
    //Default constructor
    Sliding_Solver(const string s);
    //Method to solve the puzzle
    void Solve_Puzzle();
    //Outputs the results
    void output();
    //Outputs the goal configurations
    void printBoard(const string board);
    //Virtual deconstructor to prevent memory leakage
    virtual ~Sliding_Solver() {
        delete obj;
        delete Goal;
    }
    
    private:
    //Start board from user input
    string startBoard;
    //Goal board either from user input or default 123456780
    string goalBoard;
    //Queue to store results
    priority_queue <Board_Tile, vector<Board_Tile>,
    greater<Board_Tile>> tileQueue;
    //List of possible configurations
    list<Board_Tile> nextConfs;
    
    // dummy pointer to temporarily store data from the priority queue
    Board_Tile *obj;
    // pointer to intialize a goal if user wishes to change the default goal
    Board_Tile * Goal; 
};

#endif /* Sliding_Solver_h */
