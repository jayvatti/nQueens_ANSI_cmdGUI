//
// Created by Jay Vatti on 12/15/22.
//
#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <thread>
#include "rowCol_stack.h"
#include "ANSI_cmdGUI.h"
#pragma once
class nQueens_ANSI {
public:
    int nQueens; //number of queens and (nxn)
    int steps = 0; //number of steps //GUI
    bool solved = false;
    std::string unicode_queen = "\u2655"; //unicode for the Queen //GUI

    explicit nQueens_ANSI(int nQueens); //default initializer
    std::vector<std::vector<int>> chessBoard;  //chessBoard 2D vector
    std::stack<class rowCol_stack>queenStack; //stack that stores rowColumnStack which has row and column

    bool check_collision(int current_row, int current_column);//checks if there is a collision and returns true if there is a collision
    void run();//runs the program
    void GUI();//GUI for the program

};

