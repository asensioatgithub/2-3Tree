all: ttTree

ttTree: ttTree.o main.o
	g++ -g ttTree.o main.o -o ttTree

ttTree.o: ttTree.cpp ttTree.h
	g++ -c -g ttTree.cpp

main.o: main.cpp ttTree.h
	g++ -c -g main.cpp

run: 
	./ttTree

clean:
	rm -rf *o *~ ttTree