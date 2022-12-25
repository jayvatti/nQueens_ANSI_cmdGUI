.PHONY: all clean
all: run
objects := nQueens_ANSI.o main.o
CXX_FLAGS :='-std=c++17'

nQueens_ANSI_cmdGUI: $(objects) 
	g++ $(CXX_FLAGS) $(objects) -o nQueens_ANSI_cmdGUI
	@echo "ANSI_cmdGUI compiled!"

nQueens_ANSI.o: $(wildcard *.h) nQueens_ANSI.cpp 
	g++ $(CXX_FLAGS) -c  nQueens_ANSI.cpp
	@echo "nQueens_ANSI.o compiled"

main.o: main.cpp nQueens_ANSI.h
	g++ $(CXX_FLAGS) -c main.cpp
	@echo "main.o compiled"

clean:
	@echo "Cleaning files..."
	rm -f *.o
	rm nQueens_ANSI_cmdGUI

run: nQueens_ANSI_cmdGUI
	./nQueens_ANSI_cmdGUI
