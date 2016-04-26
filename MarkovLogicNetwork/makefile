FLAGS=-std=c++11 -static-libstdc++ 
LINK=-I ../dataHandling -L ../dataHandling

main:test

test: test.cpp mln.o insight.o kb.o
	g++ $(FLAGS) $^ -o $@ $(LINK) -ldataset

%.o: %.cpp
	g++ $(FLAGS) -c $^ $(LINK) -ldataset -o $@  

clean:
	rm -rf test *.o
