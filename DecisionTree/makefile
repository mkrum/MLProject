FLAGS=-std=c++11 -static-libstdc++
LINK=-I ../dataHandling -L ../dataHandling

all:test

test: dtTest.cpp main.cpp
	g++ $(FLAGS) $^ -o $@ $(LINK) -ldataset 

%.o: %.cpp
	g++ $(FLAGS) -c $^ $(LINK) -ldataset -o $@  

clean:
	rm -rf test *.o
