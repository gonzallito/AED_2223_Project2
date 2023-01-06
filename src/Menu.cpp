//
// Created by simao on 12/27/2022.
//

#include <climits>
#include "Menu.h"

Menu::Menu(Data d) {
    this->d = d;
    this->displayLogo();
    this->buildGraph();
}

void Menu::displayLogo() const {
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
}

void Menu::mainMenu() const {

    cout << endl << endl << endl << "------------------------------------------" << endl;
    cout <<         "|           M A I N    M E N U           |" << endl;
    cout <<         "------------------------------------------" << endl;

    cout << endl << " Choose an option:" << endl;
    cout << " 1 - Best way to fly from one location to another" << endl;
    cout << " 2 - Information about an airport" << endl;
    cout << " 3 - Exit" << endl;
    cout << endl;
}

void Menu::option1Menu() const {

    cout << endl << endl << endl << "------------------------------------------" << endl;
    cout <<         "|       F L I G H T S    M E N U         |" << endl;
    cout <<         "------------------------------------------" << endl;

    cout << endl << " Choose input type:" << endl;
    cout << " 1 - Airport to Airport" << endl;
    cout << " 2 - City to city" << endl;
    cout << " 3 - Coordinates to Coordinates" << endl;
    cout << " 4 - Back" << endl;
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
                    runOption1Menu();
                case 2:
                    break;
                case 3:
                    exit(1);
                default:
                    cout << "\n Invalid input!\n";
            }
        }
    }
}

void Menu::runOption1Menu() {
    while(true) {
        option1Menu();
        cout << " > ";

        int option;
        cin >> option;

        if (valid()) {
            switch (option) {
                case 1:
                    menuOption1();
                    break;
                case 2:
                    menuOption2();
                    break;
                case 3:
                    //menuOption3();
                    break;
                case 4:
                    runMainMenu();
                    break;
                default:
                    cout << "\n Invalid input!\n";
            }
        }
    }
}

void Menu::buildGraph() {
    airlines.setN(d.getFlights().size());
    airlines.setHasDir(true);

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
    cout << "-----------------------------------------------------------------------------------------" << endl;

}

void Menu::menuOption1() {

    cout << endl << "Enter the Source Airport (ex: GKA)" << endl;
    cout << " > ";

    string airportSource;
    cin >> airportSource;

    cout << endl << "Enter the Target Airport (ex: VAI)" << endl;
    cout << " > ";

    string airportTarget;
    cin >> airportTarget;

    cout << endl << endl;

    //airlines.get_shortest_path("GKA", "VAI");    // ANSWER: GKA --- MAG --- VAI
    airlines.get_shortest_path_code(airportSource, airportTarget);
    airlines.printPath(airportSource, airportTarget, 1);

    cout << endl << endl;

}

void Menu::menuOption2() {

    cout << endl << "Enter the Source City" << endl;
    cout << " > ";

    string citySource;
    cin >> citySource;

    cout << endl << "Enter the Target City" << endl;
    cout << " > ";

    string cityTarget;
    cin >> cityTarget;

    cout << endl << endl;

    int max = INFINITY;
    int counter = 0;

    for (auto i : d.getAirportsMap()) {
        if (i.second == citySource) {
            auto auxCitySource = i.first;
            for (auto j: d.getAirportsMap()) {
                if (j.second == cityTarget) {
                    auto auxCityTarget = j.first;
                    if (airlines.get_shortest_path_code(auxCitySource, auxCityTarget) < max) {
                        max = airlines.get_shortest_path_code(auxCitySource, auxCityTarget);
                        airlines.printPath(auxCitySource, auxCityTarget, 2);
                        if (airlines.get_shortest_path_code(auxCitySource, auxCityTarget) != 0)
                            counter++;
                    }
                    else {
                        airlines.printPath(auxCitySource, auxCityTarget, 2);
                        if (airlines.get_shortest_path_code(auxCitySource, auxCityTarget) != 0)
                            counter++;
                    }
                }
            }
        }
    }

    if (counter > 1) {
        cout << endl << endl << "Do you want the best option? (y/n)" << endl;
        cout << " > ";
        string answer;
        cin >> answer;
        if (answer == "y") {
            for (auto i : d.getAirportsMap()) {
                if (i.second == citySource) {
                    auto auxCitySource = i.first;
                    for (auto j: d.getAirportsMap()) {
                        if (j.second == cityTarget) {
                            auto auxCityTarget = j.first;
                            if (airlines.get_shortest_path_code(auxCitySource, auxCityTarget) == max && airlines.get_shortest_path_code(auxCitySource, auxCityTarget) != 0) {
                                airlines.printPath(auxCitySource, auxCityTarget, 2);
                            }
                        }
                    }
                }
            }
        }
    }


    cout << endl << endl;
}




