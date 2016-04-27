FLAGS=-std=c++11 -static-libstdc++ -pthread
LINK=-I ../dataHandling -L ../dataHandling

main:test libmln.a

test: test.cpp mln.o insight.o kb.o
	g++ $(FLAGS) $^ -o $@ $(LINK) -ldataset

%.o: %.cpp
	g++ $(FLAGS) -c $^ $(LINK) -ldataset -o $@  

libmln.a: mln.o insight.o kb.o
	ar rcs $@ $^

clean:
	rm -rf test *.o
