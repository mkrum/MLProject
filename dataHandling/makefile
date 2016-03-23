main: test2

test2: test2.cpp dataset.o node.o
	g++ -g $^ -o $@

%.o: %.cpp
	g++ -g -c $^

clean:
	rm -rf test *.o
