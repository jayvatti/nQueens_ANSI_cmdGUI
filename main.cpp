#include <iostream>
#include "nQueens_ANSI.h"
int main() {
    std::cout<<SAVE_CURSOR_POSITION_ANSI_CODE<<"----------- N QUEENS -----------"<<std::endl;
    int nQueens; //number of Queens (n x n)
    bool keepGoing = true; //is true for invalid input
    while(keepGoing){
        std::cout<<"Enter N Queens:";
        std::cin>>nQueens;
        if (nQueens > 3 && nQueens < 100) {
            keepGoing = false; //is false if there is a valid input
        }
    }
    nQueens_ANSI q1(nQueens);//assigning queens
    for(int space = 0; space<nQueens + 2; space++){std::cout<<std::endl;}
    for(int cursor = 0; cursor < nQueens + 2; cursor++){std::cout<<CURSOR_UP_ONE_CELL_ANSI_CODE;}
    q1.run();//.run() solves nQueens //
    std::cout<<std::endl;
    for(int i = 0; i < nQueens + 6; i++){std::cout<<CURSOR_UP_ONE_CELL_ANSI_CODE;}
    std::cout<<CLS_ANSI_CODE;
    std::cout<< "------SOLVED--------"<<"\n"<<"Number of Queens:"<<q1.nQueens<<std::endl;
    std::cout<<"GRID SIZE: "<<q1.nQueens<<" X "<<q1.nQueens<<std::endl;
    q1.steps-=1;
    q1.GUI();
    std::cout << "--------------------" << std::endl;
}

