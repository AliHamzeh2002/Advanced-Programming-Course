CC=g++
STD=-std=c++11
CF=$(STD)
BUILD_DIR=build
BACKEND_DIR=backend
TEMPLATE_DIR=.template

all: $(BUILD_DIR) utaxi.out

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

utaxi.out: $(BUILD_DIR)/utaxi.o $(BUILD_DIR)/UtaxiWeb.o $(BUILD_DIR)/TripCostHandler.o $(BUILD_DIR)/UpdateTripHandler.o $(BUILD_DIR)/TripsTableHandler.o $(BUILD_DIR)/DeleteTripHandler.o $(BUILD_DIR)/NewTripHandler.o $(BUILD_DIR)/Handler.o $(BUILD_DIR)/SignupHandler.o $(BUILD_DIR)/TaxiManager.o $(BUILD_DIR)/DataManager.o $(BUILD_DIR)/Command.o $(BUILD_DIR)/Driver.o $(BUILD_DIR)/Passenger.o $(BUILD_DIR)/User.o $(BUILD_DIR)/Errors.o $(BUILD_DIR)/CSVReader.o $(BUILD_DIR)/Trip.o $(BUILD_DIR)/response.o $(BUILD_DIR)/request.o $(BUILD_DIR)/utilities.o $(BUILD_DIR)/server.o $(BUILD_DIR)/route.o $(BUILD_DIR)/template_parser.o
	$(CC) $(CF) $(BUILD_DIR)/utaxi.o $(BUILD_DIR)/UtaxiWeb.o $(BUILD_DIR)/TripCostHandler.o $(BUILD_DIR)/UpdateTripHandler.o $(BUILD_DIR)/TripsTableHandler.o $(BUILD_DIR)/DeleteTripHandler.o $(BUILD_DIR)/NewTripHandler.o $(BUILD_DIR)/Handler.o $(BUILD_DIR)/SignupHandler.o $(BUILD_DIR)/TaxiManager.o $(BUILD_DIR)/DataManager.o $(BUILD_DIR)/Command.o $(BUILD_DIR)/Driver.o $(BUILD_DIR)/Passenger.o $(BUILD_DIR)/User.o $(BUILD_DIR)/Errors.o $(BUILD_DIR)/CSVReader.o $(BUILD_DIR)/Trip.o $(BUILD_DIR)/response.o $(BUILD_DIR)/request.o $(BUILD_DIR)/utilities.o $(BUILD_DIR)/server.o $(BUILD_DIR)/route.o $(BUILD_DIR)/template_parser.o  -o utaxi.out

$(BUILD_DIR)/utaxi.o: utaxi.cpp webapp/WebConstants.hpp webapp/UtaxiWeb.hpp webapp/UtaxiWeb.cpp server/server.hpp utils/utilities.hpp utils/response.hpp utils/request.hpp utils/include.hpp
	$(CC) $(CF) -c utaxi.cpp -o $(BUILD_DIR)/utaxi.o

$(BUILD_DIR)/UtaxiWeb.o: webapp/WebConstants.hpp webapp/UtaxiWeb.hpp webapp/UtaxiWeb.cpp webapp/TripCostHandler.hpp webapp/TripCostHandler.cpp webapp/UpdateTripHandler.hpp webapp/UpdateTripHandler.cpp webapp/TripsTableHandler.hpp webapp/TripsTableHandler.cpp webapp/DeleteTripHandler.hpp webapp/DeleteTripHandler.cpp webapp/NewTripHandler.hpp webapp/NewTripHandler.hpp webapp/SignupHandler.hpp webapp/SignupHandler.cpp $(BACKEND_DIR)/TaxiManager.hpp $(BACKEND_DIR)/TaxiManager.cpp server/server.hpp utils/utilities.hpp utils/response.hpp utils/request.hpp utils/include.hpp
	$(CC) $(CF) -c webapp/UtaxiWeb.cpp -o $(BUILD_DIR)/UtaxiWeb.o

$(BUILD_DIR)/TripCostHandler.o: webapp/TripCostHandler.hpp webapp/TripCostHandler.cpp webapp/Handler.hpp webapp/Handler.cpp $(BACKEND_DIR)/TaxiManager.cpp $(BACKEND_DIR)/TaxiManager.hpp server/server.hpp utils/utilities.hpp utils/response.hpp utils/request.hpp utils/include.hpp
	$(CC) $(CF) -c webapp/TripCostHandler.cpp -o $(BUILD_DIR)/TripCostHandler.o

$(BUILD_DIR)/NewTripHandler.o: webapp/NewTripHandler.hpp webapp/NewTripHandler.cpp webapp/Handler.hpp webapp/Handler.cpp $(BACKEND_DIR)/TaxiManager.cpp $(BACKEND_DIR)/TaxiManager.hpp server/server.hpp utils/utilities.hpp utils/response.hpp utils/request.hpp utils/include.hpp
	$(CC) $(CF) -c webapp/NewTripHandler.cpp -o $(BUILD_DIR)/NewTripHandler.o

$(BUILD_DIR)/TripsTableHandler.o: webapp/TripsTableHandler.hpp webapp/TripsTableHandler.cpp webapp/Handler.hpp webapp/Handler.cpp webapp/WebConstants.hpp $(BACKEND_DIR)/TaxiManager.cpp $(BACKEND_DIR)/TaxiManager.hpp server/server.hpp utils/utilities.hpp utils/response.hpp utils/request.hpp utils/include.hpp
	$(CC) $(CF) -c webapp/TripsTableHandler.cpp -o $(BUILD_DIR)/TripsTableHandler.o

$(BUILD_DIR)/UpdateTripHandler.o: webapp/UpdateTripHandler.hpp webapp/UpdateTripHandler.cpp webapp/Handler.hpp webapp/Handler.cpp $(BACKEND_DIR)/TaxiManager.cpp $(BACKEND_DIR)/TaxiManager.hpp server/server.hpp utils/utilities.hpp utils/response.hpp utils/request.hpp utils/include.hpp
	$(CC) $(CF) -c webapp/UpdateTripHandler.cpp -o $(BUILD_DIR)/UpdateTripHandler.o

$(BUILD_DIR)/DeleteTripHandler.o: webapp/DeleteTripHandler.hpp webapp/DeleteTripHandler.cpp webapp/Handler.hpp webapp/Handler.cpp $(BACKEND_DIR)/TaxiManager.cpp $(BACKEND_DIR)/TaxiManager.hpp server/server.hpp utils/utilities.hpp utils/response.hpp utils/request.hpp utils/include.hpp
	$(CC) $(CF) -c webapp/DeleteTripHandler.cpp -o $(BUILD_DIR)/DeleteTripHandler.o

$(BUILD_DIR)/SignupHandler.o: webapp/SignupHandler.hpp webapp/SignupHandler.cpp webapp/Handler.hpp webapp/Handler.cpp $(BACKEND_DIR)/TaxiManager.cpp $(BACKEND_DIR)/TaxiManager.hpp server/server.hpp utils/utilities.hpp utils/response.hpp utils/request.hpp utils/include.hpp
	$(CC) $(CF) -c webapp/SignupHandler.cpp -o $(BUILD_DIR)/SignupHandler.o

$(BUILD_DIR)/Handler.o: webapp/Handler.hpp webapp/Handler.cpp $(BACKEND_DIR)/TaxiManager.cpp $(BACKEND_DIR)/TaxiManager.hpp server/server.hpp utils/utilities.hpp utils/response.hpp utils/request.hpp utils/include.hpp
	$(CC) $(CF) -c webapp/Handler.cpp -o $(BUILD_DIR)/Handler.o

$(BUILD_DIR)/TaxiManager.o: $(BACKEND_DIR)/TaxiManager.hpp $(BACKEND_DIR)/TaxiManager.cpp $(BACKEND_DIR)/Command.hpp $(BACKEND_DIR)/Command.cpp $(BACKEND_DIR)/Errors.hpp $(BACKEND_DIR)/Errors.cpp $(BACKEND_DIR)/Trip.hpp $(BACKEND_DIR)/Trip.cpp $(BACKEND_DIR)/Passenger.hpp $(BACKEND_DIR)/Passenger.cpp $(BACKEND_DIR)/Driver.hpp $(BACKEND_DIR)/Driver.cpp $(BACKEND_DIR)/DataManager.hpp $(BACKEND_DIR)/DataManager.cpp $(BACKEND_DIR)/Location.hpp $(BACKEND_DIR)/constants.hpp
	$(CC) $(CF) -c $(BACKEND_DIR)/TaxiManager.cpp -o $(BUILD_DIR)/TaxiManager.o

$(BUILD_DIR)/DataManager.o: $(BACKEND_DIR)/DataManager.hpp $(BACKEND_DIR)/DataManager.cpp $(BACKEND_DIR)/Command.hpp $(BACKEND_DIR)/Command.cpp $(BACKEND_DIR)/Errors.hpp $(BACKEND_DIR)/Errors.cpp $(BACKEND_DIR)/Trip.hpp $(BACKEND_DIR)/Trip.cpp $(BACKEND_DIR)/Passenger.hpp $(BACKEND_DIR)/Passenger.cpp $(BACKEND_DIR)/Driver.hpp $(BACKEND_DIR)/Driver.cpp $(BACKEND_DIR)/CSVReader.hpp $(BACKEND_DIR)/CSVReader.cpp $(BACKEND_DIR)/Location.hpp $(BACKEND_DIR)/constants.hpp
	$(CC) $(CF) -c $(BACKEND_DIR)/DataManager.cpp -o $(BUILD_DIR)/DataManager.o

$(BUILD_DIR)/Command.o: $(BACKEND_DIR)/Command.hpp $(BACKEND_DIR)/Command.cpp $(BACKEND_DIR)/constants.hpp
	$(CC) $(CF) -c $(BACKEND_DIR)/Command.cpp -o $(BUILD_DIR)/Command.o

$(BUILD_DIR)/Driver.o: $(BACKEND_DIR)/Driver.hpp $(BACKEND_DIR)/Driver.cpp $(BACKEND_DIR)/User.hpp $(BACKEND_DIR)/User.cpp $(BACKEND_DIR)/constants.hpp
	$(CC) $(CF) -c $(BACKEND_DIR)/Driver.cpp -o $(BUILD_DIR)/Driver.o

$(BUILD_DIR)/Passenger.o: $(BACKEND_DIR)/Passenger.hpp $(BACKEND_DIR)/Passenger.cpp $(BACKEND_DIR)/User.hpp $(BACKEND_DIR)/User.cpp $(BACKEND_DIR)/constants.hpp
	$(CC) $(CF) -c $(BACKEND_DIR)/Passenger.cpp -o $(BUILD_DIR)/Passenger.o
        
$(BUILD_DIR)/User.o: $(BACKEND_DIR)/User.hpp $(BACKEND_DIR)/User.cpp $(BACKEND_DIR)/constants.hpp
	$(CC) $(CF) -c $(BACKEND_DIR)/User.cpp -o $(BUILD_DIR)/User.o

$(BUILD_DIR)/Trip.o: $(BACKEND_DIR)/Trip.hpp $(BACKEND_DIR)/Trip.cpp $(BACKEND_DIR)/Passenger.hpp $(BACKEND_DIR)/Passenger.cpp $(BACKEND_DIR)/Driver.hpp $(BACKEND_DIR)/Driver.cpp $(BACKEND_DIR)/Location.hpp $(BACKEND_DIR)/constants.hpp
	$(CC) $(CF) -c $(BACKEND_DIR)/Trip.cpp -o $(BUILD_DIR)/Trip.o

$(BUILD_DIR)/Errors.o: $(BACKEND_DIR)/Errors.hpp $(BACKEND_DIR)/Errors.cpp $(BACKEND_DIR)/constants.hpp
	$(CC) $(CF) -c $(BACKEND_DIR)/Errors.cpp -o $(BUILD_DIR)/Errors.o

$(BUILD_DIR)/CSVReader.o: $(BACKEND_DIR)/CSVReader.hpp $(BACKEND_DIR)/CSVReader.cpp $(BACKEND_DIR)/Location.hpp $(BACKEND_DIR)/constants.hpp
	$(CC) $(CF) -c $(BACKEND_DIR)/CSVReader.cpp -o $(BUILD_DIR)/CSVReader.o
        
$(BUILD_DIR)/template_parser.o: utils/template_parser.cpp utils/template_parser.hpp utils/request.cpp utils/request.hpp utils/utilities.hpp utils/utilities.cpp
	$(CC) $(CF) -c utils/template_parser.cpp -o $(BUILD_DIR)/template_parser.o

$(BUILD_DIR)/response.o: utils/response.cpp utils/response.hpp utils/include.hpp
	$(CC) $(CF) -c utils/response.cpp -o $(BUILD_DIR)/response.o

$(BUILD_DIR)/request.o: utils/request.cpp utils/request.hpp utils/include.hpp utils/utilities.hpp
	$(CC) $(CF) -c utils/request.cpp -o $(BUILD_DIR)/request.o

$(BUILD_DIR)/utilities.o: utils/utilities.cpp utils/utilities.hpp
	$(CC) $(CF) -c utils/utilities.cpp -o $(BUILD_DIR)/utilities.o

$(BUILD_DIR)/server.o: server/server.cpp server/server.hpp server/route.hpp utils/utilities.hpp utils/response.hpp utils/request.hpp utils/include.hpp utils/template_parser.hpp utils/template_parser.cpp
	$(CC) $(CF) -c server/server.cpp -o $(BUILD_DIR)/server.o

$(BUILD_DIR)/route.o: server/route.cpp server/route.hpp utils/utilities.hpp utils/response.hpp utils/request.hpp utils/include.hpp
	$(CC) $(CF) -c server/route.cpp -o $(BUILD_DIR)/route.o

.PHONY: clean
clean:
	rm -rf $(BUILD_DIR) $(TEMPLATE_DIR) *.o *.out &> /dev/null