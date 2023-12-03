all:
	g++ -DNDEBUG src/helper.cpp src/validation.cpp src/board.cpp src/init.cpp src/moves.cpp src/makemove.cpp src/main.cpp src/perft.cpp -o chessengine