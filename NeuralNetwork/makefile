FLAGS=-std=c++11 -static-libstdc++
LINK=-I ../dataHandling -L ../dataHandling

main: test libneural.a

test: networktest.cpp neuron.o network.o 
	g++ $(FLAGS) $^ -o $@ $(LINK) -ldataset

%.o: %.cpp
	g++ $(FLAGS) -c $^ $(LINK) -ldataset -o $@  

libneural.a: neuron.o network.o
	ar rcs $@ $^

clean:
	rm -rf test *.o
