//
//  main.cpp
//  TermProject
//
//  Created by Shannon Abeda on 2020-03-26.
//  Copyright © 2020 Shannon Abeda. All rights reserved.
//
#include <iostream>
#include "Board_Title.h"
#include "Sliding_Solver.h"
#include <string>
#include <stdlib.h>
#include<list>
#include <vector>
#include<queue>
#include<set>
#include <functional>

using namespace std;

//Function to intialize user inut
string Init();

int main(int argc, const char * argv[]) {
    bool x = 1;
       while (x) {
           Sliding_Solver s(Init());
           s.Solve_Puzzle();
           s.output();
           cout << "\n\n\nWould you like to simulate again ? Enter 1 for yes, 0 for no.:   ";    
           cin >> x;
       }
    return 0;
}

string Init() {


    string stri;
    char temp;

    bool ok=0;
    bool chk[9] = { 0,0,0,0,0,0,0,0,0 };

    while (!ok) {
        cout << "\n\nEnter values in the 3x3 grid, for the following positions for start board:\n\n";

        stri = "";
        ok = 1;
        for (int i = 0; i<9; i++)
            chk[i] = 0;

        for (int i = 0; i<3; i++) {
            for (int j = 0; j<3; j++) {
                cout << "Row " << i + 1 << " Column " << j + 1 << ": ";
                cin >> temp;
                if (atoi(&temp) < 9 && atoi(&temp) >= 0)
                    stri.operator+=(temp);
                else static_cast<void>(cout << "\n\nIncorrent input, please try again for: "), j--;
            }
        }

        for (int i = 0; i < 9; i++) {
            int tmp;
            char c = stri[i];
            tmp = atoi(&c);
            chk[tmp] = 1;
        }
        for (int i = 0; i<9; i++)
            if (chk[i] == 0) {
                ok = 0;
                cout << "\n\nError: there's a duplicate entry, please re-enter the grid values.";
                break;
            }
    }

    return stri;
}
