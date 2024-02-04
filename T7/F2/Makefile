cpp := g++ -std=c++11

all: utaxi.out

utaxi.out: utaxi.o IOHandler.o Command.o CSVReader.o Passenger.o Driver.o Trip.o Errors.o User.o TaxiManager.o DataManager.o
		$(cpp) utaxi.o IOHandler.o Command.o CSVReader.o Passenger.o Driver.o Trip.o Errors.o User.o TaxiManager.o DataManager.o -o utaxi.out

utaxi.o: utaxi.cpp IOHandler.hpp IOHandler.cpp
		$(cpp) -c utaxi.cpp -o utaxi.o

IOHandler.o: IOHandler.hpp IOHandler.cpp Command.hpp Command.cpp constants.hpp TaxiManager.hpp TaxiManager.cpp
		$(cpp) -c IOHandler.cpp -o IOHandler.o

TaxiManager.o: TaxiManager.hpp TaxiManager.cpp Command.hpp Command.cpp Errors.hpp Errors.cpp Trip.hpp Trip.cpp Passenger.hpp Passenger.cpp Driver.hpp Driver.cpp DataManager.hpp DataManager.cpp Location.hpp constants.hpp
		$(cpp) -c TaxiManager.cpp -o TaxiManager.o

DataManager.o: DataManager.hpp DataManager.cpp Command.hpp Command.cpp Errors.hpp Errors.cpp Trip.hpp Trip.cpp Passenger.hpp Passenger.cpp Driver.hpp Driver.cpp CSVReader.hpp CSVReader.cpp Location.hpp constants.hpp
		$(cpp) -c DataManager.cpp -o DataManager.o

Command.o: Command.hpp Command.cpp constants.hpp
		$(cpp) -c Command.cpp -o Command.o

Driver.o: Driver.hpp Driver.cpp User.hpp User.cpp constants.hpp
		$(cpp) -c Driver.cpp -o Driver.o

Passenger.o: Passenger.hpp Passenger.cpp User.hpp User.cpp constants.hpp
		$(cpp) -c Passenger.cpp -o Passenger.o
	
User.o: User.hpp User.cpp constants.hpp
		$(cpp) -c User.cpp -o User.o

Trip.o: Trip.hpp Trip.cpp Passenger.hpp Passenger.cpp Driver.hpp Driver.cpp Location.hpp constants.hpp
		$(cpp) -c Trip.cpp -o Trip.o

Errors.o: Errors.hpp Errors.cpp constants.hpp
		$(cpp) -c Errors.cpp -o Errors.o

CSVReader.o: CSVReader.hpp CSVReader.cpp Location.hpp constants.hpp
		$(cpp) -c CSVReader.cpp -o CSVReader.o
	
clean:
	rm -r *.o