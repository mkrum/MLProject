FLAGS=-std=c++11 -static-libstdc++ -pthread
LINK=-I ../MarkovLogicNetwork -I../dataHandling -L ../dataHandling

main:menu

menu: menu.cpp ../MarkovLogicNetwork/mln.o ../MarkovLogicNetwork/insight.o ../MarkovLogicNetwork/kb.o
	g++ $(FLAGS) $^ -o $@ $(LINK) -ldataset

%.o: %.cpp
	g++ $(FLAGS) -c $^ $(LINK) -ldataset -o $@  

clean:
	rm -rf menu *.o
