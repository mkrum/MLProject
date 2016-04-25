FLAGS=-std=c++11 -static-libstdc++
LINK=-I ../dataHandling -I ./eigen-eigen-07105f7124f9 -L ../dataHandling

main: test
	
test: test.cpp multiNomLogReg.o
	g++ $(FLAGS) $^ $(LINK) -ldataset -o $@

multiNomLogReg.o: multiNomLogReg.cpp
	g++ $(FLAGS) -c $^ $(LINK) -ldataset -o $@

clean:
	rm -rf test *.o



