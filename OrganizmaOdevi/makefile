hepsi: derle calistir
	

derle:
	g++ -I ./include/ -o ./lib/Hucre.o -c ./src/Hucre.cpp
	g++ -I ./include/ -o ./lib/Queue.o -c ./src/Queue.cpp
	g++ -I ./include/ -o ./lib/Doku.o -c ./src/Doku.cpp
	g++ -I ./include/ -o ./lib/Radix.o -c ./src/Radix.cpp
	g++ -I ./include/ -o ./lib/BST.o -c ./src/BST.cpp
	g++ -I ./include/ -o ./lib/Organ.o -c ./src/Organ.cpp
	g++ -I ./include/ -o ./lib/Sistem.o -c ./src/Sistem.cpp
	g++ -I ./include/ -o ./lib/Sistem_listesi.o -c ./src/Sistem_listesi.cpp
	g++ -I ./include/ -o ./lib/Organizma.o -c ./src/Organizma.cpp
	g++ -I ./include/ -o ./lib/Kontrol.o -c ./src/Kontrol.cpp
	
	g++ -c ./src/test.cpp -o ./lib/test.o
	
	g++ ./lib/Hucre.o ./lib/Queue.o ./lib/Doku.o ./lib/Radix.o ./lib/BST.o ./lib/Organ.o ./lib/Sistem.o ./lib/Sistem_listesi.o ./lib/Organizma.o ./lib/Kontrol.o ./lib/test.o -o ./bin/test

calistir:
	./bin/test