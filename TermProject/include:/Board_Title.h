//
//  Board_Title.h
//  TermProject
//
//  Created by Shannon Abeda on 2020-03-26.
//  Copyright © 2020 Shannon Abeda. All rights reserved.
//

#ifndef Board_Title_h
#define Board_Title_h
#include <iostream>
#include <string>
#include <stdlib.h>
#include<list>
#include <vector>
#include<queue>
#include<set>
#include <functional>

using namespace std;

//Struct to store coordinates of board_title for a 3x3 array
struct coords {
    coords() { row = col = 0; }
    int row, col;
    void store(int r, int c) {
        static_cast<void>(row = r) , col = c;
    }

    int dist(const coords& c) {
        //cout << "element wise score: "<<abs(row - c.row) + abs(col - c.col);
        return abs(row - c.row) + abs(col - c.col);
    }

    void swap(coords& c) {
        int r, _c;
        static_cast<void>(r = c.row) , _c = c.col;
        static_cast<void>(c.row = row) , c.col = col;
        static_cast<void>(row = r) , col = _c;
    }

    const coords & operator = (const coords& c) {
        static_cast<void>(row = c.row) , col = c.col;
        return *this;
    }
};

class Board_Tile {

public:
    //Default constructor for inheritances
    Board_Tile() {}
    //Board_Title constructor
    //Stores values into a 2d array
    Board_Tile(const string& s, Board_Tile* b);
    //Board_title constructor
    //Sets the configuration
    Board_Tile(const Board_Tile & bt);
    //Bool operators to compare the current manhanttan distance + moves from start
    //Of an object to current
    bool operator < (const Board_Tile & bt) const;
    bool operator > (const Board_Tile & bt) const;
    //Bool operator to return true if the configuration is equal to the goal
    bool operator == (const Board_Tile & bt) const;
    //Copy assignment operator
    const Board_Tile& operator = (const Board_Tile &  b);
    //3x3 string array to store each value
    string config[3][3];
    //Swap titles depending on the goal
    void swap(char c, int r, int _c, Board_Tile* goal);
    //Return 'U' 'D' 'R' 'L'
    string discernMoves();
    //Setting a new configuration
    void setNewConf(Board_Tile* b) {*this = *b;}
    //Returns of a list of possible moves
    list<Board_Tile> nextConfigs(Board_Tile* b);
    //Calculates the Manhattan distance
    int Manhattan_Distance(const Board_Tile* goalconfig);
    //Number of moves from the start
    int numMoves () const{ return movesFromStart.length(); }
    //Returns the moves from the start
    string getMovesFromStart () const { return movesFromStart; }
    //Prints the configuration of the board
    void printBoard(const string board[3][3]);
    

private:
    //configurations to return
    list<Board_Tile> toRet;
    //Manhattan distances
    int manDistance;
    //Struct of 9 places
    coords coordinates[9];
    //Moves from the start
    string movesFromStart;
};
#endif /* Board_Title_h */

