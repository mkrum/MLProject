#!/bin/sh


#compile all libraries and executables
make clean
cd ../dataHandling
make clean
make
cd ../NeuralNetwork
make clean
make
cd ../MultinomialLogisticRegression
make clean
make
cd ../MarkovLogicNetwork
make clean
make
cd ../DecisionTree
make clean
make
cd ../Menu
make

#tryna fam
./menu
