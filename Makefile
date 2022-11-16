CXX=clang++
INCLUDES=-Iincludes/
CXX_FLAGS=-std=c++20 -g -Wall -Wextra -Werror -pedantic $(INCLUDES)

exec: bin/exec
tests: bin/tests

bin/exec: entry/main.cpp src/data-parser.cpp src/graph.cpp
	${CXX} ${CXX_FLAGS} entry/main.cpp src/data-parser.cpp src/graph.cpp -o bin/exec

.DEFAULT_GOAL := exec
.PHONY: clean exec tests

clean:
	rm -fr bin/* obj/*