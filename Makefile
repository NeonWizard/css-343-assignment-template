# -g : inclue debugging symbols

# $@ : the target
# $^ : all dependencies
# $< : first dependency

CXXFLAGS := -Wall -Wno-missing-braces -Wno-sign-compare -Werror -g -std=c++11
CXX := g++

all: clang-tidy run memtest

main: main.cpp stack.cpp stack.h
	echo
	echo "*** compiling to create an executable called main"
	$(CXX) $(CXXFLAGS) main.cpp stack.cpp -o main

run: main
	echo
	echo "*** running main"
	./main

clang-tidy: *.cpp *.h
	echo
	echo "*** running clang-tidy using options from .clang-tidy"
	clang-tidy --version
	clang-tidy *.cpp *.h -- -std=c++11 -x c++

clang-format: *.cpp *.h
	echo
	echo "*** running clang-format to format all files in-place"
	clang-format -style='{ColumnLimit: 80, IndentWidth: 4}' -i *.cpp *.h

gdb: main
	gdb -ex=r --args main

clean:
	rm -f *.o main valgrind.*

memtest: main
	echo
	echo "*** memory testing with valgrind"
	rm -f valgrind.log
	valgrind --leak-check=full --log-file=valgrind.log ./main > /dev/null
	cat valgrind.log

.SILENT: all main run clang-tidy clang-format memtest
