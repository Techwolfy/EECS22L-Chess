#Chess Makefile

CXX=g++
CFLAGS=-std=c++0x -g -Iinc
OBJS=player.o ai.o aischolar.o piece.o chessboard.o king.o knight.o queen.o rook.o bishop.o pawn.o
TESTS=test-piece test-bishop test-rook test-knight test-queen test-scholarsmate test-check

#Build everything
.PHONY: all
all: build bin/chess test

#Load dependency information
-include $(addprefix build/, $OBJS:.o=.d)


#Make build, test, and bin directories
.PHONY: build
build:
	@echo "Building objects..."
	mkdir -p build
	mkdir -p build/test
	mkdir -p bin

#Build object files
build/%.o: src/%.cpp | build
	$(CXX) -c -o $@ $< $(CFLAGS) -MMD

#Build output binary
bin/chess: build/main.o $(addprefix build/, $(OBJS))
	@echo "Building chess binary..."
	$(CXX) -o $@ $^


#Test individual objects
.PHONY: test
test: $(addprefix build/test/, $(TESTS)) | build
	@echo "Running tests..."
	for t in $^; do ./$$t; done

build/test/%: test/%.cpp $(addprefix build/, $(OBJS)) | build
	$(CXX) -o $@ $< $(addprefix build/, $(OBJS)) $(CFLAGS)


#Create release archives
.PHONY: release
release: | all
	tar cvzf Chess_V1.0.tar.gz --exclude=CVS README COPYRIGHT INSTALL bin/ doc/
	tar cvzf Chess_V1.0_src.tar.gz --exclude=CVS README COPYRIGHT INSTALL Makefile bin/ doc/ inc/ src/ test/


#Clean up old build and release files
.PHONY: clean
clean:
	@echo "Cleaning up build files..."
	rm -rf build/ bin/ *.tar.gz
