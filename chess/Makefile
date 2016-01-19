#Chess Makefile

CXX=g++
CFLAGS=-std=c++0x
OBJS=player.o chessboard.o piece.o king.o

#Build everything
.PHONY: all
all: chess

%.o: %.cpp
	@echo "Building objects..."
	$(CXX) -c -o $@ $< $(CFLAGS)

chess: $(OBJS)
	@echo "Building chess binary..."
	$(CXX) -o $@ $^

.PHONY: clean
clean:
	@echo "Cleaning up build files..."
	rm -r *.o chess
