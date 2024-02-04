cpp := g++ -std=c++11

all: main

main: main.o Library.o LibraryMember.o Student.o Professor.o Document.o Book.o Reference.o Magazine.o
	$(cpp) main.o Library.o LibraryMember.o Student.o Professor.o Document.o Book.o Reference.o Magazine.o -o main

main.o: main.cpp Library.cpp Library.hpp
	$(cpp) -c main.cpp -o main.o

Library.o: Library.cpp LibraryMember.cpp Student.cpp Professor.cpp Document.cpp Book.cpp Reference.cpp Magazine.cpp Library.hpp LibraryMember.hpp Student.hpp Professor.hpp Document.hpp Book.hpp Reference.hpp Magazine.hpp constants.hpp
	$(cpp) -c Library.cpp -o Library.o

LibraryMember.o: LibraryMember.cpp Document.cpp LibraryMember.hpp Document.hpp constants.hpp
	$(cpp) -c LibraryMember.cpp -o LibraryMember.o

Student.o: LibraryMember.cpp Student.cpp LibraryMember.hpp Student.hpp constants.hpp
	$(cpp) -c Student.cpp -o Student.o

Professor.o: LibraryMember.cpp Professor.cpp LibraryMember.hpp Professor.hpp constants.hpp
	$(cpp) -c Professor.cpp -o Professor.o

Document.o: Document.cpp Document.hpp constants.hpp
	$(cpp) -c Document.cpp -o Document.o

Reference.o: Document.cpp Reference.cpp Document.hpp Reference.hpp constants.hpp
	$(cpp) -c Reference.cpp -o Reference.o

Book.o: Document.cpp Book.cpp Document.hpp Book.hpp constants.hpp
	$(cpp) -c Book.cpp -o Book.o

Magazine.o: Document.cpp Magazine.cpp Document.hpp Magazine.hpp constants.hpp
	$(cpp) -c Magazine.cpp -o Magazine.o