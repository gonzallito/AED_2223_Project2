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
    cout << " 2 - Information about an airport (Not Working)" << endl;
    cout << " 3 - Exit" << endl;
    cout << endl;
}

void Menu::option1MenuDisplay() const {

    cout << endl << endl << endl << "------------------------------------------" << endl;
    cout <<                         "|       F L I G H T S    M E N U         |" << endl;
    cout <<                         "------------------------------------------" << endl;

    cout << endl << " Choose input type:" << endl;

    cout << " 1 - Airport to Airport" << endl;
    cout << " 2 - Airport to City" << endl;
    cout << " 3 - Airport to coordinates" << endl;

    cout << " 4 - City to Airport" << endl;
    cout << " 5 - City to city" << endl;
    cout << " 6 - City to Coordinates" << endl;

    cout << " 7 - Coordinates to Airport" << endl;
    cout << " 8 - Coordinates to City" << endl;
    cout << " 9 - Coordinates to Coordinates" << endl;

    cout << " 0 - Back" << endl;
    cout << endl;
}

void Menu::option2MenuDisplay() const {

    cout << endl << endl << endl << "------------------------------------------" << endl;
    cout <<                         "|       A I R P O R T    M E N U         |" << endl;
    cout <<                         "------------------------------------------" << endl;

    cout << endl << " Choose input type:" << endl;
    cout << " 1 - How many flight depart from this airport?" << endl;
    cout << " 2 - From how many different companies?" << endl;
    cout << " 3 - For how many different destinies?" << endl;
    cout << " 4 - For many different countries?" << endl;
    cout << " 5 - How many airports, cities or countries are attainable using at most Y flights?" << endl;
    cout << " 0 - Back" << endl;
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
                    break;
                case 2:
                    runOption2Menu();
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
        option1MenuDisplay();
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
                    menuOption3();
                    break;
                case 4:
                    menuOption4();
                    break;
                case 5:
                    menuOption5();
                    break;
                case 6:
                    menuOption6();
                    break;
                case 7:
                    menuOption7();
                    break;
                case 8:
                    menuOption8();
                    break;
                case 9:
                    menuOption9();
                    break;
                case 0:
                    runMainMenu();
                    break;
                default:
                    cout << "\n Invalid input!\n";
            }
        }
    }
}

void Menu::runOption2Menu() {
    while(true) {
        option2MenuDisplay();
        cout << " > ";

        int option;
        cin >> option;

        if (valid()) {
            switch (option) {
                case 1:
                    //menuOption1();
                    break;
                case 2:
                    break;
                case 3:
                    break;
                case 4:
                    break;
                case 5:
                    break;
                case 0:
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

    cout << endl << "Enter the Source Airport (ex: ORY)" << endl;
    cout << " > ";

    string airportSource;
    cin >> airportSource;

    cout << endl << "Enter the Target City (ex: London)" << endl;
    cout << " > ";

    string cityTarget;
    cin >> cityTarget;

    cout << endl << endl;

    int max = INFINITY;
    int counter = 0;

    for (auto j: d.getAirportsMap()) {
        if (j.second.getCity() == cityTarget) {
            auto auxCityTarget = j.first;
            if (airlines.get_shortest_path_code(airportSource, auxCityTarget) < max) {
                max = airlines.get_shortest_path_code(airportSource, auxCityTarget);
                airlines.printPath(airportSource, auxCityTarget, 2);
                if (airlines.get_shortest_path_code(airportSource, auxCityTarget) != 0)
                    counter++;
            }
            else {
                airlines.printPath(airportSource, auxCityTarget, 2);
                if (airlines.get_shortest_path_code(airportSource, auxCityTarget) != 0)
                    counter++;
            }
        }
    }

    if (counter > 1) {
        cout << endl << endl << "Do you want the best option? (y/n)" << endl;
        cout << " > ";
        string answer;
        cin >> answer;
        cout << endl << endl;
        if (answer == "y") {
            for (auto j: d.getAirportsMap()) {
                if (j.second.getCity() == cityTarget) {
                    auto auxCityTarget = j.first;
                    if (airlines.get_shortest_path_code(airportSource, auxCityTarget) == max && airlines.get_shortest_path_code(airportSource, auxCityTarget) != 0) {
                        airlines.printPath(airportSource, auxCityTarget, 2);
                    }
                }
            }
        }
    }
    cout << endl << endl;
}



void Menu::menuOption3() {

    cout << endl << "Enter the Source Airport (ex: ORY)" << endl;
    cout << " > ";

    string airportSource;
    cin >> airportSource;



    cout << endl << "Enter the Target Coordinates (ex: 51.510422, -0.159842) <-- London" << endl;
    cout << "latitude > ";
    double latTarget;
    cin >> latTarget;
    cout << endl << "longitude > ";
    double lonTarget;
    cin >> lonTarget;
    cout << endl << endl;



    cout << endl << "How far do you want the airport to be from the input location? (Km)" << endl;
    cout << " > ";
    double distanceInput;
    cin >> distanceInput;



    int max = INFINITY;
    int counter = 0;

    for (auto j: d.getAirportsMap()) {
        if (d.haversine(latTarget, lonTarget, stod(j.second.getLatitude()), stod(j.second.getLongitude())) < distanceInput) {
            auto auxCityTarget = j.first;
            if (airlines.get_shortest_path_code(airportSource, auxCityTarget) < max) {
                max = airlines.get_shortest_path_code(airportSource, auxCityTarget);
                airlines.printPath(airportSource, auxCityTarget, 2);
                if (airlines.get_shortest_path_code(airportSource, auxCityTarget) != 0)
                    counter++;
            }
            else {
                airlines.printPath(airportSource, auxCityTarget, 2);
                if (airlines.get_shortest_path_code(airportSource, auxCityTarget) != 0)
                    counter++;
            }
        }
    }

    if (counter > 1) {
        cout << endl << endl << "Do you want the best option? (y/n)" << endl;
        cout << " > ";
        string answer;
        cin >> answer;
        cout << endl << endl;
        if (answer == "y") {
            for (auto j: d.getAirportsMap()) {
                if (d.haversine(latTarget, lonTarget, stod(j.second.getLatitude()), stod(j.second.getLongitude())) < distanceInput) {
                    auto auxCityTarget = j.first;
                    if (airlines.get_shortest_path_code(airportSource, auxCityTarget) == max && airlines.get_shortest_path_code(airportSource, auxCityTarget) != 0) {
                        airlines.printPath(airportSource, auxCityTarget, 2);
                    }
                }
            }
        }
    }
    cout << endl << endl;
}



void Menu::menuOption4() {

    cout << endl << "Enter the Source City (ex: London)" << endl;
    cout << " > ";

    string citySource;
    cin >> citySource;

    cout << endl << "Enter the Target Airport (ex: ORY)" << endl;
    cout << " > ";

    string airportTarget;
    cin >> airportTarget;

    cout << endl << endl;

    int max = INFINITY;
    int counter = 0;

    for (auto i : d.getAirportsMap()) {
        if (i.second.getCity() == citySource) {
            auto auxCitySource = i.first;
                if (airlines.get_shortest_path_code(auxCitySource, airportTarget) < max) {
                    max = airlines.get_shortest_path_code(auxCitySource, airportTarget);
                    airlines.printPath(auxCitySource, airportTarget, 2);
                    if (airlines.get_shortest_path_code(auxCitySource, airportTarget) != 0)
                        counter++;
                }
                else {
                    airlines.printPath(auxCitySource, airportTarget, 2);
                    if (airlines.get_shortest_path_code(auxCitySource, airportTarget) != 0)
                        counter++;
                }
        }
    }

    if (counter > 1) {
        cout << endl << endl << "Do you want the best option? (y/n)" << endl;
        cout << " > ";
        string answer;
        cin >> answer;
        cout << endl << endl;
        if (answer == "y") {
            for (auto i: d.getAirportsMap()) {
                if (i.second.getCity() == citySource) {
                    auto auxCitySource = i.first;
                    if (airlines.get_shortest_path_code(auxCitySource, airportTarget) == max &&
                        airlines.get_shortest_path_code(auxCitySource, airportTarget) != 0) {
                        airlines.printPath(auxCitySource, airportTarget, 2);
                    }
                }
            }
        }
    }
    cout << endl << endl;
}



void Menu::menuOption5() {

    cout << endl << "Enter the Source City (ex: Paris)" << endl;
    cout << " > ";

    string citySource;
    cin >> citySource;

    cout << endl << "Enter the Target City (ex: London)" << endl;
    cout << " > ";

    string cityTarget;
    cin >> cityTarget;

    cout << endl << endl;

    int max = INFINITY;
    int counter = 0;

    for (auto i : d.getAirportsMap()) {
        if (i.second.getCity() == citySource) {
            auto auxCitySource = i.first;
            for (auto j: d.getAirportsMap()) {
                if (j.second.getCity() == cityTarget) {
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
        cout << endl << endl;
        if (answer == "y") {
            for (auto i : d.getAirportsMap()) {
                if (i.second.getCity() == citySource) {
                    auto auxCitySource = i.first;
                    for (auto j: d.getAirportsMap()) {
                        if (j.second.getCity() == cityTarget) {
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




void Menu::menuOption6() {

    cout << endl << "Enter the Source City (ex: Paris)" << endl;
    cout << " > ";

    string citySource;
    cin >> citySource;

    cout << endl << "Enter the Target Coordinates (ex: 51.510422, -0.159842) <-- London" << endl;
    cout << "latitude > ";
    double latTarget;
    cin >> latTarget;
    cout << endl << "longitude > ";
    double lonTarget;
    cin >> lonTarget;
    cout << endl << endl;



    cout << "How far do you want the airport to be from the input location? (Km)" << endl;
    cout << " > ";
    double distanceInput;
    cin >> distanceInput;


    cout << endl << endl;

    int max = INFINITY;
    int counter = 0;

    for (auto i : d.getAirportsMap()) {
        if (i.second.getCity() == citySource) {
            auto auxCitySource = i.first;
            for (auto j: d.getAirportsMap()) {
                if (d.haversine(latTarget, lonTarget, stod(j.second.getLatitude()), stod(j.second.getLongitude())) < distanceInput) {
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
        cout << endl << endl;
        if (answer == "y") {
            for (auto i : d.getAirportsMap()) {
                if (i.second.getCity() == citySource) {
                    auto auxCitySource = i.first;
                    for (auto j: d.getAirportsMap()) {
                        if (d.haversine(latTarget, lonTarget, stod(j.second.getLatitude()), stod(j.second.getLongitude())) < distanceInput) {
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



void Menu::menuOption7() {
    cout << endl << "Enter the Source Coordinates (ex: 48.835831, 2.394101) <-- Paris" << endl;
    cout << "latitude > ";
    double latSource;
    cin >> latSource;
    cout << endl << "longitude > ";
    double lonSource;
    cin >> lonSource;



    cout << endl << "How far do you want the airports to be from the input location? (Km)" << endl;
    cout << " > ";
    double distanceInput;
    cin >> distanceInput;

    cout << endl << endl;



    cout << endl << "Enter the Target Airport (ex: LTN)" << endl;
    cout << " > ";

    string airportTarget;
    cin >> airportTarget;

    cout << endl << endl;



    int max = INFINITY;
    int counter = 0;

    for (auto i : d.getAirportsMap()) {
        //cout << d.haversine(latSource, lonSource, stod(i.second.getLatitude()), stod(i.second.getLongitude())) << endl;
        if (d.haversine(latSource, lonSource, stod(i.second.getLatitude()), stod(i.second.getLongitude())) < distanceInput) {
            auto auxCitySource = i.first;
            if (airlines.get_shortest_path_code(auxCitySource, airportTarget) < max) {
                max = airlines.get_shortest_path_code(auxCitySource, airportTarget);
                airlines.printPath(auxCitySource, airportTarget, 2);
                if (airlines.get_shortest_path_code(auxCitySource, airportTarget) != 0)
                    counter++;
            } else {
                airlines.printPath(auxCitySource, airportTarget, 2);
                if (airlines.get_shortest_path_code(auxCitySource, airportTarget) != 0)
                    counter++;
            }
        }
    }

    if (counter > 1) {
        cout << endl << endl << "Do you want the best option? (y/n)" << endl;
        cout << " > ";
        string answer;
        cin >> answer;
        cout << endl << endl;
        if (answer == "y") {
            for (auto i: d.getAirportsMap()) {
                if (d.haversine(latSource, lonSource, stod(i.second.getLatitude()), stod(i.second.getLongitude())) < distanceInput) {
                    auto auxCitySource = i.first;
                    if (airlines.get_shortest_path_code(auxCitySource, airportTarget) == max &&
                        airlines.get_shortest_path_code(auxCitySource, airportTarget) != 0) {
                        airlines.printPath(auxCitySource, airportTarget, 2);
                    }
                }
            }
        }
    }
    cout << endl << endl;
}





void Menu::menuOption8() {

    cout << endl << "Enter the Source Coordinates (ex: 48.835831, 2.394101) <-- Paris" << endl;
    cout << "latitude > ";
    double latSource;
    cin >> latSource;
    cout << endl << "longitude > ";
    double lonSource;
    cin >> lonSource;


    cout << endl << "How far do you want the Source Airport to be from the input location? (Km)" << endl;
    cout << " > ";
    double distanceInput1;
    cin >> distanceInput1;




    cout << endl << "Enter the Target City (ex: London)" << endl;
    cout << " > ";

    string cityTarget;
    cin >> cityTarget;

    cout << endl << endl;



    int max = INFINITY;
    int counter = 0;

    for (auto i : d.getAirportsMap()) {
        //cout << d.haversine(latSource, lonSource, stod(i.second.getLatitude()), stod(i.second.getLongitude())) << endl;
        if (d.haversine(latSource, lonSource, stod(i.second.getLatitude()), stod(i.second.getLongitude())) < distanceInput1) {
            auto auxCitySource = i.first;
            for (auto j: d.getAirportsMap()) {
                if (j.second.getCity() == cityTarget) {
                    //cout << d.haversine(latTarget, lonTarget, stod(j.second.getLatitude()), stod(j.second.getLongitude())) << endl;
                    //cout << distanceInput << endl;
                    //cout << i.first << " - " << j.first << endl;
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
        cout << endl << endl;
        if (answer == "y") {
            for (auto i : d.getAirportsMap()) {
                if (d.haversine(latSource, lonSource, stod(i.second.getLatitude()), stod(i.second.getLongitude())) < distanceInput1) {
                    auto auxCitySource = i.first;
                    for (auto j: d.getAirportsMap()) {
                        if (j.second.getCity() == cityTarget) {
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





void Menu::menuOption9() {

    cout << endl << "Enter the Source Coordinates (ex: 48.835831, 2.394101) <-- Paris" << endl;
    cout << "latitude > ";
    double latSource;
    cin >> latSource;
    cout << endl << "longitude > ";
    double lonSource;
    cin >> lonSource;


    cout << endl << "How far do you want the Source Airport to be from the input location? (Km)" << endl;
    cout << " > ";
    double distanceInput1;
    cin >> distanceInput1;




    cout << endl << "Enter the Target Coordinates (ex: 51.510422, -0.159842) <-- London" << endl;
    cout << "latitude > ";
    double latTarget;
    cin >> latTarget;
    cout << endl << "longitude > ";
    double lonTarget;
    cin >> lonTarget;

    cout << endl << "How far do you want the Target Airport to be from the input location? (Km)" << endl;
    cout << " > ";
    double distanceInput2;
    cin >> distanceInput2;

    cout << endl << endl;



    int max = INFINITY;
    int counter = 0;

    for (auto i : d.getAirportsMap()) {
        //cout << d.haversine(latSource, lonSource, stod(i.second.getLatitude()), stod(i.second.getLongitude())) << endl;
        if (d.haversine(latSource, lonSource, stod(i.second.getLatitude()), stod(i.second.getLongitude())) < distanceInput1) {
            auto auxCitySource = i.first;
            for (auto j: d.getAirportsMap()) {
                if (d.haversine(latTarget, lonTarget, stod(j.second.getLatitude()), stod(j.second.getLongitude())) < distanceInput2) {
                    //cout << d.haversine(latTarget, lonTarget, stod(j.second.getLatitude()), stod(j.second.getLongitude())) << endl;
                    //cout << distanceInput << endl;
                    //cout << i.first << " - " << j.first << endl;
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
        cout << endl << endl;
        if (answer == "y") {
            for (auto i : d.getAirportsMap()) {
                if (d.haversine(latSource, lonSource, stod(i.second.getLatitude()), stod(i.second.getLongitude())) < distanceInput1) {
                    auto auxCitySource = i.first;
                    for (auto j: d.getAirportsMap()) {
                        if (d.haversine(latTarget, lonTarget, stod(j.second.getLatitude()), stod(j.second.getLongitude())) < distanceInput2) {
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
