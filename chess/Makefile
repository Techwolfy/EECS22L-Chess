#Chess Makefile

CXX=g++
CFLAGS=-std=c++0x
OBJS=player.o piece.o chessboard.o king.o

#Build everything
.PHONY: all
all: chess

%.o: %.cpp
	@echo "Building objects..."
	$(CXX) -c -o $@ $< $(CFLAGS) -MMD

chess: $(OBJS)
	@echo "Building chess binary..."
	$(CXX) -o $@ $^

.PHONY: clean
clean:
	@echo "Cleaning up build files..."
	rm -r *.o chess
