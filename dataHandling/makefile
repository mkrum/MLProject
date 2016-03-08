main: test

test: test.cpp readCsv.o node.o
	g++ -g test.cpp readCsv.o node.o -o $@
    
%.o: %.c
	g++ -g -c $^

