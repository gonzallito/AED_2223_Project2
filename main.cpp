#include <iostream>
#include "src/Menu.h"
#include "src/Data.h"
#include "src/graph.h"

int main() {

    Data d;
    d.readFlights();
    d.readAirports();

    Menu menu(d);
    menu.runMainMenu();
/*
    Data d;
    d.readFlights();
    d.readAirports();
    d.printHash();
    Graph airlines(d.getFlights().size(), true);

    for (auto i : d.getFlights()) {
        double a1 = 0;
        double a2 = 0;
        double b1 = 0;
        double b2 = 0;
        //cout << i.getSource() << " - " << i.getTarget() << " - " << i.getAirline() << endl;
        for (auto j : d.getAirport()) {
            if (j.getCode() == i.getSource()) {
                a1 = stod(j.getLatitude());
                a2 = stod(j.getLongitude());
            }
            if (j.getCode() == i.getTarget()) {
                b1 = stod(j.getLatitude());
                b2 = stod(j.getLongitude());
            }
        }
        airlines.addEdge(i.getSource(), i.getTarget(), d.haversine(a1, a2, b1, b2), i.getAirline());
    }


    //airlines.get_shortest_path("MAG", "HGU");
    //airlines.get_shortest_path("YFS", "YHY");
    //airlines.get_shortest_path("GKA", "DAU");
    airlines.get_shortest_path("GKA", "VAI");


    //airlines.printGraph();*/
    return 0;
}
