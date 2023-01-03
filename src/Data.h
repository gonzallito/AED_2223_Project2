//
// Created by simao on 12/27/2022.
//

#ifndef AED_2223_PROJECT2_DATA_H
#define AED_2223_PROJECT2_DATA_H

#include <vector>
#include "Airline.h"
#include "Airport.h"
#include "Flight.h"

class Data {
public:
    Data();
    bool readAirlines();
    bool readAirports();
    bool readFlights();
    vector<Airline> getAirline() const;
    vector<Airport> getAirport() const;
    vector<Flight> getFlights() const;

private:
    vector<Airline> airlines;
    vector<Airport> airports;
    vector<Flight> flights;
};


#endif //AED_2223_PROJECT2_DATA_H
