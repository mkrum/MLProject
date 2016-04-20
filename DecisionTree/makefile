FLAGS=-std=c++11 -static-libstdc++
LINK=-I ../dataHandling -L ../dataHandling

main:test

test: dtTest.cpp
	g++ $(FLAGS) $^ -o $@ $(LINK) -ldataset  

%.o: %.cpp
	g++ $(FLAGS) -c $^ $(LING) -ldataset -o $@  

clean:
	rm -rf test *.o
