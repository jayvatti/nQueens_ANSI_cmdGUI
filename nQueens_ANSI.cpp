//
// Created by Jay Vatti on 12/15/22.
//

#include "nQueens_ANSI.h"
void nQueens_ANSI::run() {
    int currentRow = 0; //storing current row
    int currentColumn = 0; //storing current column

    std::cout<<SAVE_CURSOR_POSITION_ANSI_CODE;
    std::chrono::milliseconds sleepTime(50);

    bool backtracking = false, repeat = true; //bool variables used to check the backtracking and repeat

    chessBoard[currentRow][currentColumn] = 1; //initializing the first row,column on stack //chessBoard[0][0]
    int filled = 0;
    queenStack.emplace(currentRow, currentColumn);//pushing the first rowColumnStack on to the queenStack:
    while (repeat) {
        if (!solved) {
            std::cout<<LOAD_CURSOR_POSITION_ANSI_CODE;
            GUI();//Prints the GUI
            std::this_thread::sleep_for(sleepTime);
        }
        if (not(check_collision(currentRow, currentColumn)) && not(backtracking)) {
            filled++;
            if (filled == nQueens) { //checks if filled is equal to nQueens
                repeat = false;//stops the while loop
                solved = true;
            }
            else { //if filled != nQueens
                currentRow++; //goes to the next row
                currentColumn = 0; //starts at the first column
                chessBoard[currentRow][currentColumn] = 1; //the nextRow and column=0 is set to 1
                queenStack.emplace(currentRow, currentColumn);
            }
        }
        else if (currentColumn + 1 < nQueens) {
            chessBoard[queenStack.top().row_val][queenStack.top().col_val] = 0;//assigning chessBoard == 0
            queenStack.pop();//popping the current stack

            //going to the next column
            currentColumn++;
            chessBoard[currentRow][currentColumn] = 1; //setting the nextColumn == 1
            queenStack.emplace(currentRow, currentColumn);//pushing rowColumnStack on to the queenStack
            backtracking = false;//backtracking is set to false

        }
        else {
            filled -= 1; //decrements the filled

            chessBoard[queenStack.top().row_val][queenStack.top().col_val] = 0; //assigning the chessBoard to 0 if there is no more room to move
            queenStack.pop(); //popping from the stack

            //the top of the stack after popping is the current row and current column
            currentRow = queenStack.top().row_val;
            currentColumn = queenStack.top().col_val;
            backtracking = true;//backtracking is set to true
        }
    }
    std::cout<<LOAD_CURSOR_POSITION_ANSI_CODE;
    GUI();
}
nQueens_ANSI::nQueens_ANSI(int nQueens){ //initializing the value of nQueens
    nQueens_ANSI::nQueens = nQueens;
    //creating a new vector with the size (nxn);
    std::vector<std::vector<int>>chessBoard_dummy(nQueens, std::vector<int>(nQueens));
    for (int i = 0; i < nQueens; i++) {
        for (int j = 0; j < nQueens; j++){
            chessBoard_dummy[i][j] = 0;//populating the vector with 0s for all index
        }
    }
    nQueens_ANSI::chessBoard = chessBoard_dummy;//deepCopy //assigning it to the chessBoard which is in public of class Queens
}
void nQueens_ANSI::GUI() {
    std::cout<<"\n"<<"STEP COUNTER:"<<std::to_string(steps)<<"\n"<<std::endl;
    for (int row = 0; row < nQueens; row++) { // two for loops to print out the board
        std::cout<<std::string(nQueens, ' ' );
        for (int column = 0; column < nQueens; column++) {
            std::cout<<BG_WHITE_CURSOR;
            if (chessBoard[row][column] == 1) {
                std::cout<<RED_CURSOR_COLOR<<unicode_queen<<" "<<GREEN_CURSOR_COLOR;
            }
            else if(chessBoard[row][column] == 0) {
                std::cout<<EMPTY; //empty box if the value in the chessBoard === 0
            }
        }
        std::cout<<RESET<<std::endl;
    }
    steps++;//incrementing the steps to count the number of steps that took the program to complete
};

bool nQueens_ANSI::check_collision(int current_row, int current_column){
    //checkIfStraight
    //Column is constant. Row++ till the currentRow to check if there are any Queens in the currentRow
    for (int row = 0; row < current_row; row++) {
        if (chessBoard[row][current_column] == true) {return true;}
    }
    //back left diagonal
    //Row--, column--

    int checkRow = current_row;//initializing variables so that currentRow,currentColumn is not affected
    int checkColumn = current_column;

    while (checkRow >= 0 && checkColumn >= 0) { //repeats until row and column index >=0
        checkRow--;   //decrementing index each time to check the diagonal
        checkColumn--;
        if(checkRow > -1 && checkColumn > -1){
            if (chessBoard[checkRow][checkColumn] == true) {return true;}
        }
    }

    //back right diagonal
    //row -- ; column ++
    checkRow = current_row;
    checkColumn = current_column;
    while (checkRow >= 0 && checkColumn < nQueens) {
        checkRow--; //row >= 0 and stops if it less than or equal to 0
        checkColumn++;//column keeps incrementing until it reaches the last index
        if(checkRow > -1 && checkColumn <= nQueens){
            if (chessBoard[checkRow][checkColumn] == true) {return true;}
        }
    }
    //returns false if there is no collision
    return false;
}

