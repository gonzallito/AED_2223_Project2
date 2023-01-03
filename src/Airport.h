//
// Created by simao on 12/27/2022.
//

#ifndef AED_2223_PROJECT2_AIRPORT_H
#define AED_2223_PROJECT2_AIRPORT_H

#include <string>

using namespace std;

class Airport {
public:
    Airport(string code, string name, string city, string country, string latitude, string longitude);
    string getCode() const;
    string getName() const;
    string getCity() const;
    string getCountry() const;
    string getLatitude() const;
    string getLongitude() const;

private:
    string code;
    string name;
    string city;
    string country;
    string latitude;
    string longitude;
};


#endif //AED_2223_PROJECT2_AIRPORT_H
