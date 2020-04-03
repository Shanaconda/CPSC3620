//
//  Sliding_Solver.cpp
//  TermProject
//
//  Created by Shannon Abeda on 2020-03-26.
//  Copyright © 2020 Shannon Abeda. All rights reserved.
//

#include <iostream>
#include <string>
#include <stdlib.h>
#include <list>
#include <vector>
#include <queue>
#include <set>
#include <functional>
#include "Board_Title.h"
#include "Sliding_Solver.h"

//********************************************
//Default constructor
//Parameters: string to intialize the board
//********************************************
Sliding_Solver::Sliding_Solver(const string s) {
    obj = new Board_Tile("012345678", 0);
    nextConfs.clear();
    tileQueue.empty();
    startBoard = s;
    goalBoard = "123456780";

    //Output the goal configurartion
    printBoard(goalBoard);

    //If user wishes to change the goal configuration
    //Else configuration is 123456780
    cout << "\n\nThe current goal board is the above arrangement of tiles.\n\n";
    cout<<"\n\nWould you like to use some other goal configuration ? \nEnter y / n:   ";
    char inp;
    cin >> inp;
    if (inp == 'y') {


        string stri;
        char temp;

        bool ok = 0;
        bool chk[9] = { 0,0,0,0,0,0,0,0,0 };

        while (!ok) {
            cout << "Please enter values in the 3x3 grid, for the following positions for goal board:\n\n";

            stri = "";
            ok = 1;
            for (int i = 0; i<9; i++)
                chk[i] = 0;

            for (int i = 0; i<3; i++) {
                for (int j = 0; j<3; j++) {
                    cout << "Row " << i + 1 << " Column " << j + 1 << ": ";
                    cin >> temp;
                    if (atoi(&temp) < 9 && atoi(&temp) >= 0)
                        static_cast<void>(stri.operator+=(temp)), cout << "\n\n\n";
                    //Error checking to make sure input is between 0-9
                    else static_cast<void>(cout << "\n\nIncorrect input, please try again.\n"), j--;
                }
            }

            for (int i = 0; i < 9; i++) {
                int tmp;
                char c = stri.c_str()[i];
                tmp = atoi(&c);
                chk[tmp] = 1;
            }
            //Double checking error input
            for (int i = 0; i<9; i++)
                if (chk[i] == 0) {
                    ok = 0;
                    cout << "\nError: there's a duplicate entry, please re-enter the grid values.\n";
                    system("pause");
                    break;
                }
        }

        goalBoard = stri;

    }

    Goal = new Board_Tile(goalBoard, 0);

    Board_Tile tmp(startBoard, 0);
    tileQueue.push(tmp);
}


//*****************************************************************
//Function to solve the puzzle
//Checks each possible configuration and lowest cost using
//Manhattan distance
//Outputs each possible configuration
//*****************************************************************
void Sliding_Solver::Solve_Puzzle() {
    
    list<Board_Tile> visited;
    visited.clear();
    bool solved = 0;
    while (tileQueue.size()) {


        *obj = (tileQueue.top());
        tileQueue.pop();
        Board_Tile b;
        b.printBoard(obj->config);
        if (!obj->Manhattan_Distance(Goal))
            break;
        visited.push_back(*obj);
        visited.sort();
        visited.unique();


        nextConfs=obj->nextConfigs(Goal);
        

        while (nextConfs.size() && !solved) {
            *obj = *(nextConfs.begin());

                obj->Manhattan_Distance(Goal);
                tileQueue.push(*obj);
            nextConfs.pop_front();
        }
    }
}

//**********************************************************************
// Outputs the ending results from the puzzle
//**********************************************************************
void Sliding_Solver::output() {
    cout << "Start Board        Goal Board        Number of Moves" <<endl;;
    cout << startBoard << "            " << goalBoard << "        ";
    cout << obj->numMoves() << "            "<< obj->getMovesFromStart() << endl;

}
//*************************************************
// Prints the goal configuration 123456780
//**************************************************
void Sliding_Solver::printBoard(const string board) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++)
            cout << "======";
        cout << endl;
        for (int j = 0; j < 3; j++) {
            cout << "|  " << board[(i*3)+j] << " |";
        }
        cout << endl;

    }
    for (int j = 0; j < 3; j++)
        cout << "======";
    cout << endl;
}
