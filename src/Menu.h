//
// Created by simao on 12/27/2022.
//

#ifndef AED_2223_PROJECT2_MENU_H
#define AED_2223_PROJECT2_MENU_H

#include <iostream>
#include "Data.h"

using namespace std;

class Menu {
private:
    Data d;
    Graph airlines;
public:
    Menu(Data d);
    void displayLogo() const;
    void mainMenu() const;
    void option1MenuDisplay() const;
    void option2MenuDisplay() const;
    bool valid();
    void runMainMenu();
    void runOption1Menu();
    void runOption2Menu();
    void buildGraph();
    void menuOption1();
    void menuOption2();
    void menuOption3();
    void menuOption4();
    void menuOption5();
    void menuOption6();
    void menuOption7();
    void menuOption8();
    void menuOption9();
};


#endif //AED_2223_PROJECT2_MENU_H
