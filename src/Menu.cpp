//
// Created by simao on 12/27/2022.
//

#include <climits>
#include "Menu.h"

Menu::Menu() {}

void Menu::mainMenu() const {
    cout << endl;
    cout << "+---------------------------------------------------------------------------------+" << endl;
    cout << "|              _        _______                                   _               |\n"
            "|        /\\   (_)      |__   __|                                 | |              |\n"
            "|       /  \\   _ _ __     | |_ __ __ _ _ __  ___ _ __   ___  _ __| |_ ___         |\n"
            "|      / /\\ \\ | | '__|    | | '__/ _` | '_ \\/ __| '_ \\ / _ \\| '__| __/ __|        |\n"
            "|     / ____ \\| | |       | | | | (_| | | | \\__ \\ |_) | (_) | |  | |_\\__ \\        |\n"
            "|    /_/    \\_\\_|_|       |_|_|  \\__,_|_| |_|___/ .__/ \\___/|_|   \\__|___/        |\n"
            "|                                               | |                               |\n"
            "|                                               |_|                               |\n"
            "+---------------------------------------------------------------------------------+"
            << endl;
    cout << endl;

    cout << " Choose an option:" << endl;
    cout << " 1 - Best way to fly from one location to another" << endl;
    cout << " 2 - Information about an airport" << endl;
    cout << " 3 - Exit" << endl;
    cout << endl;
}

bool Menu::valid() {
    if (cin.good()) return true;
    else {
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        cout << "\n Invalid input!\n";
        return false;
    }
}

void Menu::runMainMenu() {
    while(true) {
        mainMenu();
        cout << " > ";

        int option;
        cin >> option;

        if (valid()) {
            switch (option) {
                case 1:
                    menuOption1();
                case 2:
                    exit(1);

                case 3:
                    exit(1);
                default:
                    cout << "\n Invalid input!\n";
            }
        }
    }
}

void Menu::menuOption1() {
    Data d;
    d.readFlights();
    d.readAirports();

    Graph airlines(d.getFlights().size(), true);

    cout << endl << endl << "-----------------------------------------------------------------------------------------" << endl;
    cout << "Wait a moment... We are processing the data from the files! (This may take a while)" << endl << endl;

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

    cout << "Process Completed!" << endl;
    cout << "-----------------------------------------------------------------------------------------" << endl << endl << endl;

    cout << "Enter the Source Airport" << endl;
    cout << " > ";

    string airportSource;
    cin >> airportSource;

    cout << endl << "Enter the Target Airport" << endl;
    cout << " > ";

    string airportTarget;
    cin >> airportTarget;

    cout << endl << endl;

    //airlines.get_shortest_path("GKA", "VAI");    // ANSWER: GKA --- MAG --- VAI
    airlines.get_shortest_path(airportSource, airportTarget);

    cout << endl << endl;

}




