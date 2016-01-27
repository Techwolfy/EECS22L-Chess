#Chess Makefile

CXX=g++
CFLAGS=-std=c++0x -g -Iinc
OBJS=main.o player.o ai.o piece.o chessboard.o king.o knight.o queen.o rook.o bishop.o pawn.o

#Build everything
.PHONY: all
all: dir bin/chess

#Load dependency information
-include $(addprefix build/, $OBJS:.o=.d)

#Make build and bin directories
dir:
	mkdir -p build
	mkdir -p bin

#Build object files
build/%.o: src/%.cpp | dir
	@echo "Building objects..."
	$(CXX) -c -o $@ $< $(CFLAGS) -MMD

#Build output binary
bin/chess: $(addprefix build/, $(OBJS))
	@echo "Building chess binary..."
	$(CXX) -o $@ $^

#Clean up old build files
.PHONY: clean
clean:
	@echo "Cleaning up build files..."
	rm -r build/ bin/
