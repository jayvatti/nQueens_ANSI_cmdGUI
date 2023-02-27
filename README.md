# nQueens_ANSI_cmdGUI

The N-Queens problem is a puzzle in which the task is to place n queens on an n-by-n chessboard such that no two queens can attack each other.

## User Inputs
The user should input an integer greater than 3, which will be used as the size of the chessboard and the number of queens on the board. The program has been designed with a makefile, so the user can simply navigate to the program's directory and enter the command "make run" on the command line. This will compile and run the program.

## User Outputs
The program outputs the positions of the queens on the chessboard such that no two queens are attacking each other.


The output uses ANSI Escpae Codes along with Unicode character for the queen to show the animation. 
The ANSI codes are used to save the current cursor position, move the cursor to a specific position, and clear the console. This allows the program to create a visual representation of the chessboard and the queen positions in a user-friendly manner.


In this program, ANSI Escape Codes and Unicode characters are used to create a visual representation of the chessboard and queen positions. The ANSI codes are utilized to save the current cursor position, move the cursor to a particular position, and clear the console. By doing so, the program creates a user-friendly animation of the chessboard and queen positions. 


The program first prompts the user to input the size of the chessboard and the number of queens. Then, it creates an instance of the "nQueens_ANSI" class and assigns the number of queens to it. After this, the program uses the ANSI codes to move the cursor and provide visual cues for the chessboard and queen positions. 

The output includes the number of queens, the grid size, and the final queen positions, displayed using Unicode characters.


![ANSI_NQUEENS](https://user-images.githubusercontent.com/97709855/221447199-d7cf30db-d4c5-45a4-9514-3d00f8a3bd95.gif)
