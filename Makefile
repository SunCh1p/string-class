.PHONY: all clean

CXX := g++
CXXFLAGS := -Wall -c -g
LDFLAGS :=
# Create the directory structure for object files

all: clean main
	@echo "RUNNING PROGRAM"
	@echo ----------------------------------
	./main.exe
	@echo ----------------------------------

main: obj/main.o obj/string.o
	@echo "Linking"
	$(CXX) $(LDFLAGS) -o $@ $^

obj/string.o: src/util/string.cc
	$(CXX) $(CXXFLAGS) -o $@ $^

obj/main.o: src/main.cc
	$(CXX) $(CXXFLAGS) -o $@ $^


clean:
	@echo "Cleaning"
	del /Q obj\*.o
	del /Q main.exe