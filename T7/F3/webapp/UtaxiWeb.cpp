#include "UtaxiWeb.hpp"

using namespace std;

UtaxiWeb::UtaxiWeb(int server_port, string data_file_address):server(server_port){
    taxi_manager = new TaxiManager(data_file_address);
}

void UtaxiWeb::run(){
    server.get("/msg_show.js", new ShowFile("static/js/msg_show.js", "text/js"));
    server.get("/mystyle.css", new ShowFile("static/css/mystyle.css", "text/css"));
    server.get("/signup.jpg", new ShowImage("static/imgs/signup.jpg"));
    server.get("/new-trip.jpg", new ShowImage("static/imgs/new-trip.jpg"));
    server.get("/trip-tables.jpg", new ShowImage("static/imgs/trip-tables.jpg"));
    server.get("/", new ShowPage("static/html/homepage.html"));
    server.get("/signup", new ShowPage("static/html/signup.html"));
    server.post("/signup-authentication", new SignupHandler(taxi_manager));
    server.get("/new-trip-form", new ShowPage("static/html/trip-form.html"));
    server.post("/new-trip-maker", new NewTripHandler(taxi_manager));
    server.post("/calc-cost", new TripCostHandler(taxi_manager));
    server.get("/delete-trip-form", new ShowPage("static/html/delete-trip-form.html"));
    server.post("/delete-trip", new DeleteTripHandler(taxi_manager));
    server.get("/driver-authentication-form", new ShowPage("static/html/driver-authentication.html"));
    server.post("/trips-table", new TripsTableHandler(taxi_manager));
    server.post("/accept-trip", new UpdateTripHandler(taxi_manager, ACCEPT_COMMAND));
    server.post("/finish-trip", new UpdateTripHandler(taxi_manager, FINISH_COMMAND));
    server.run();
}