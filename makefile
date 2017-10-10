main: main.o calculator.o
	g++ main.o calculator.o -o main
	
main.o: main.cc calculator.h
	g++ -c main.cc
	
calculator.o: calculator.cc calculator.h
	g++ -c calculator.cc