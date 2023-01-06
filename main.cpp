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

    return 0;
}
