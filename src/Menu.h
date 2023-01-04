//
// Created by simao on 12/27/2022.
//

#ifndef AED_2223_PROJECT2_MENU_H
#define AED_2223_PROJECT2_MENU_H

#include <iostream>
#include "Data.h"

using namespace std;

class Menu {
public:
    Menu();
    void mainMenu() const;
    bool valid();
    void runMainMenu();
    void menuOption1();
};


#endif //AED_2223_PROJECT2_MENU_H
