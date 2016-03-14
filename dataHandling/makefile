main: test

test: test.cpp dataset.o node.o
	g++ -g $^ -o $@

%.o: %.cpp
	g++ -g -c $^

clean:
	rm -rf test *.o
