#Chess Makefile

CXX=g++
CFLAGS=-std=c++0x -g
OBJS=main.o player.o ai.o piece.o chessboard.o king.o knight.o queen.o rook.o bishop.o pawn.o

#Build everything
.PHONY: all
all: chess

#Load dependency information
-include $(OBJS:.o=.d)

#Build object files
%.o: %.cpp
	@echo "Building objects..."
	$(CXX) -c -o $@ $< $(CFLAGS) -MMD

#Build output binary
chess: $(OBJS)
	@echo "Building chess binary..."
	$(CXX) -o $@ $^

#Clean up old build files
.PHONY: clean
clean:
	@echo "Cleaning up build files..."
	rm -r *.o *.d chess
