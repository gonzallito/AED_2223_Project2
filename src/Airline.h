//
// Created by simao on 12/27/2022.
//

#ifndef AED_2223_PROJECT2_AIRLINE_H
#define AED_2223_PROJECT2_AIRLINE_H

#include <string>

using namespace std;

class Airline {

private:
    string code;
    string name;
    string callSign;
    string country;

public:
    Airline(string code, string name, string callSign, string country);
    string getCode() const;
    string getName() const;
    string getCallSign() const;
    string getCountry() const;

    Airline();
};


#endif //AED_2223_PROJECT2_AIRLINE_H
