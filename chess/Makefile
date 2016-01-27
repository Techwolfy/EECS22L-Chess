#Chess Makefile

CXX=g++
CFLAGS=-std=c++0x -g -Iinc
OBJS=main.o player.o ai.o piece.o chessboard.o king.o knight.o queen.o rook.o bishop.o pawn.o

#Build everything
.PHONY: all
all: build test bin/chess

#Load dependency information
-include $(addprefix build/, $OBJS:.o=.d)


#Make build and bin directories
.PHONY: build
build:
	@echo "Building objects..."
	mkdir -p build
	mkdir -p bin

#Build object files
build/%.o: src/%.cpp | build
	$(CXX) -c -o $@ $< $(CFLAGS) -MMD

#Test individual objects
.PHONY: test
test: $(addprefix build/, $(OBJS)) | build
	@echo "WARNING: Tests have not yet been created. Continuing..."

#Build output binary
bin/chess: $(addprefix build/, $(OBJS)) | test
	@echo "Building chess binary..."
	$(CXX) -o $@ $^


#Create release archives
.PHONY: release
release: | all
	tar cvzf Chess_Alpha.tar.gz --exclude=CVS README COPYRIGHT INSTALL bin/ doc/
	tar cvzf Chess_Alpha_src.tar.gz --exclude=CVS README COPYRIGHT INSTALL Makefile bin/ doc/ inc/ src/ test/


#Clean up old build and release files
.PHONY: clean
clean:
	@echo "Cleaning up build files..."
	rm -rf build/ bin/ *.tar.gz

