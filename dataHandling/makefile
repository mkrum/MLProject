main: test

test: test.cpp dataset.o node.o
	g++ -std=c++11 -static-libstdc++ -g $^ -o $@

%.o: %.cpp
	g++ -std=c++11 -static-libstdc++ -g -c $^

clean:
	rm -rf test *.o
