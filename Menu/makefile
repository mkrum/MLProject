FLAGS=-std=c++11 -static-libstdc++ -pthread
LINK=-I../MarkovLogicNetwork -L../MarkovLogicNetwork -I../dataHandling -L../dataHandling  -I../MultinomialLogisticRegression -I ./eigen -L../MultinomialLogisticRegression -I../NeuralNetwork -L../NeuralNetwork -I ../DecisionTree  

main:menu

menu: menu.cpp ../DecisionTree/dt.h ../DecisionTree/TreeNode.h ../DecisionTree/Tree.h
	g++ $(FLAGS) $^ -o $@ $(LINK) -ldataset -lmln -lmnlr -lneural

%.o: %.cpp
	g++ $(FLAGS) -c $^ $(LINK) -ldataset -o $@  
clean:
	rm -rf menu *.o
