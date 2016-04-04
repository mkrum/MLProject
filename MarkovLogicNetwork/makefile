main:test

test: test.cpp mln.o dataset.o node.o
	g++ $^ -o $@

%.o: %.cpp
	g++ -c $^  
