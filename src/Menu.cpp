//
// Created by simao on 12/27/2022.
//

#include <climits>
#include "Menu.h"

Menu::Menu() {}

void Menu::mainMenu() const {
    cout << endl;
    cout << " ========================================" << endl;
    cout << " ||           Air Transports           ||" << endl;
    cout << " ========================================" << endl;
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
        cout << " >";

        int option;
        cin >> option;

        if (valid()) {
            switch (option) {

                case 3:
                    exit(1);
                default:
                    cout << "\n Invalid input!\n";
            }
        }
    }
}




