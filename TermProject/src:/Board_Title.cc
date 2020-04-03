//
//  Board_Title.cpp
//  TermProject
//
//  Created by Shannon Abeda on 2020-03-26.
//  Copyright © 2020 Shannon Abeda. All rights reserved.
//

#include <stdio.h>
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

//******************************************************
//Intializing a board title
// Determining the manhattan distance of *b
//*****************************************************
Board_Tile::Board_Tile(const string& s, Board_Tile* b) {
    int tmp;

    toRet.empty();
    manDistance = 0;
    if (b) {
        manDistance = Manhattan_Distance(b);
    }

    for (int i = 0; i<3; i++)
        for (int j = 0; j < 3; j++) {
            config[i][j] = s[(i * 3) + j];
            char alia =s[(i * 3) + j];
            tmp = atoi(&alia);
            coordinates[tmp].store(i, j);
        }
}
//**************************************************
// Copy constructor
//****************************************************
Board_Tile::Board_Tile(const Board_Tile & bt) {
    manDistance = bt.manDistance;

          for (int i = 0; i<9; i++)
              coordinates[i] = bt.coordinates[i];
          for (int i = 0; i<3; i++)
              for (int j = 0; j<3; j++)
                  config[i][j] = bt.config[i][j];

          movesFromStart = "";
          movesFromStart += bt.movesFromStart;
}
//*********************************************************
// Copy assignment operator 
//*************************************************************
const Board_Tile& Board_Tile::operator=(const Board_Tile&b) {
            manDistance = b.manDistance;

           for (int i = 0; i<9; i++)
               coordinates[i] = b.coordinates[i];
           for (int i = 0; i<3; i++)
               for (int j = 0; j<3; j++)
                   config[i][j] = b.config[i][j];

           movesFromStart="";
           movesFromStart += b.movesFromStart;

           return *this;
}
//*********************************************************
// Bool operator to determine to final configuration
//*********************************************************
bool Board_Tile::operator==(const Board_Tile & bt) const {
        bool same = 1;
           for (int i = 0; i < 3; i++)
               for (int j = 0; j < 3; j++)
                   if (config[i][j] != bt.config[i][j])
                       same = 0;

           if (same && (manDistance==bt.manDistance) && (movesFromStart.length() == bt.movesFromStart.length()))
               return 1;

           return 0;
}

//*********************************************************
// Bool operator to determine to final configuration
//*********************************************************
bool Board_Tile::operator <(const Board_Tile & bt) const {
     return (manDistance + movesFromStart.length()) < (bt.manDistance + bt.movesFromStart.length());
}

//*********************************************************
// Bool operator to determine to final configuration
//*********************************************************
bool Board_Tile::operator>(const Board_Tile &bt) const {
    return (manDistance+movesFromStart.length()) > (bt.manDistance+bt.movesFromStart.length());
}

//*************************************************
//Function to determine the moves
//*************************************************
string Board_Tile::discernMoves() {
    string moves = "";

    if (coordinates[0].row != 0)
        moves += 'U';
    if (coordinates[0].col != 2)
        moves += 'R';
    if (coordinates[0].row != 2)
        moves += 'D';
    if (coordinates[0].col != 0)
        moves += 'L';

    return moves;
}
//**********************************************************************
// Function to swap titles depending on the 'U', 'D', 'R' or 'L'
//********************************************************************
void Board_Tile::swap(char const c, int r, int _c, Board_Tile *goal) {
    
        string temp;//temporary for swapping
    
        if (c == 'U') {
            temp = config[r-1][_c];
            config[r-1][_c] = config[r][_c];
            config[r][_c] = temp;

            coordinates[0].swap(coordinates[atoi(temp.c_str())]);

            movesFromStart += c;
            Manhattan_Distance(goal);
            toRet.insert(toRet.end(), *this);
            movesFromStart.pop_back();

            temp = config[r][_c];
            config[r][_c] = config[r-1][_c];
            config[r-1][_c] = temp;

            coordinates[0].swap(coordinates[atoi(temp.c_str())]);
        }

        if (c == 'R') {
            temp = config[r][_c + 1];
            config[r][_c + 1] = config[r][_c];
            config[r][_c] = temp;

            coordinates[0].swap(coordinates[atoi(temp.c_str())]);

            movesFromStart += c;
            Manhattan_Distance(goal);
            toRet.insert(toRet.end(),*this);
            movesFromStart.pop_back();

            temp = config[r][_c];
            config[r][_c] = config[r][_c + 1];
            config[r][_c + 1] = temp;

            coordinates[0].swap(coordinates[atoi(temp.c_str())]);
        }
        if (c == 'D') {
            temp = config[r + 1][_c];
            config[r + 1][_c] = config[r][_c];
            config[r][_c] = temp;

            coordinates[0].swap(coordinates[atoi(temp.c_str())]);

            movesFromStart += c;
            Manhattan_Distance(goal);
            toRet.insert(toRet.end(),*this);
            movesFromStart.pop_back();

            temp = config[r][_c];
            config[r][_c] = config[r + 1][_c];
            config[r + 1][_c] = temp;

            coordinates[0].swap(coordinates[atoi(temp.c_str())]);
        }
        if (c == 'L') {
            temp = config[r][_c - 1];
            config[r][_c - 1] = config[r][_c];
            config[r][_c] = temp;

            coordinates[0].swap(coordinates[atoi(temp.c_str())]);
            movesFromStart += c;
            Manhattan_Distance(goal);
            toRet.insert(toRet.end(),*this);
            movesFromStart.pop_back();

            temp = config[r][_c];
            config[r][_c] = config[r][_c - 1];
            config[r][_c - 1] = temp;

            coordinates[0].swap(coordinates[atoi(temp.c_str())]);

        }
        
    }

//*****************************************************
// Functions creates the nextConfigurations
//
//*****************************************************

list<Board_Tile> Board_Tile::nextConfigs(Board_Tile *b) {
        toRet.clear();
          int r = coordinates[0].row, c = coordinates[0].col;
          string moves = discernMoves();
          int size = moves.length();
          while (size--) {
              swap((moves.at(size)),  r, c,b);
              moves.resize(size);
          }


          return toRet;
}
//***************************************************************
// Functions finds the manhanttan distances of a board title
// and returns its score value.
//***************************************************************
int Board_Tile::Manhattan_Distance(const Board_Tile *goalconfig) {
    int score = 0;
    for (int i = 0; i<9; i++) {
        score += coordinates[i].dist(goalconfig->coordinates[i]);
    }
    manDistance = score;
    printBoard(config);
    return score;
}

//************************************************************
//Function to print board configurartion when intialized
//***********************************************************
void Board_Tile::printBoard(const string board[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++)
            cout << "======";
        cout << endl;
        for (int j = 0; j < 3; j++) {
            cout << "|  " << board[i][j] << " |";
        }
        cout << endl;

    }
    for (int j = 0; j < 3; j++)
        cout << "======";
    cout << endl;
}
