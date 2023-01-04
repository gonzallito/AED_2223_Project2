//
// Created by simao on 12/27/2022.
//

#ifndef AED_2223_PROJECT2_DATA_H
#define AED_2223_PROJECT2_DATA_H

#include <vector>
#include <cmath>
#include "Airline.h"
#include "Airport.h"
#include "Flight.h"
#include "graph.h"

class Data {

private:
    vector<Airline> airlines;
    vector<Airport> airports;
    vector<Flight> flights;
    Graph airlinesGraph;

public:
    Data();
    bool readAirlines();
    bool readAirports();
    bool readFlights();
    vector<Airline> getAirline() const;
    vector<Airport> getAirport() const;
    vector<Flight> getFlights() const;
    void printAirlines();
    double haversine(double lat1, double lon1, double lat2, double lon2);
};


#endif //AED_2223_PROJECT2_DATA_H
