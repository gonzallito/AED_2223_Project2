//
// Created by simao on 12/28/2022.
//

#ifndef AED_2223_PROJECT2_FLIGHT_H
#define AED_2223_PROJECT2_FLIGHT_H

#include <string>

using namespace std;

class Flight {
public:
    Flight(string source, string target, string airline);
    string getSource() const;
    string getTarget() const;
    string getAirline() const;

private:
    string source;
    string target;
    string airline;
};


#endif //AED_2223_PROJECT2_FLIGHT_H
