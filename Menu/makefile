FLAGS=-std=c++11 -static-libstdc++
LINK=-I ../MarkovLogicNetwork -I../dataHandling -I ../MultiNomialLogisticRegression  -L ../dataHandling

main:menu

menu: menu.cpp ../MarkovLogicNetwork/mln.o ../MarkovLogicNetwork/insight.o ../MarkovLogicNetwork/kb.o ../MultiNomialLogisticRegression/multiNomLogReg.o
	g++ $(FLAGS) $^ -o $@ $(LINK) -ldataset

%.o: %.cpp
	g++ $(FLAGS) -c $^ $(LINK) -ldataset -o $@  
clean:
	rm -rf menu *.o
