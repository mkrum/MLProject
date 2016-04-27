FLAGS=-std=c++11 -static-libstdc++
LINK=-I../MarkovLogicNetwork -L../MarkovLogicNetwork -I../dataHandling -L../dataHandling  -I../MultinomialLogisticRegression -L../MultinomialLogisticRegression 

main:menu

menu: menu.cpp
	g++ $(FLAGS) $^ -o $@ $(LINK) -ldataset -lmln -lmnlr

%.o: %.cpp
	g++ $(FLAGS) -c $^ $(LINK) -ldataset -o $@  
clean:
	rm -rf menu *.o
