/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   main.cpp
 * Author: Tberdy
 *
 * Created on 9 mars 2017, 22:58
 */

#include <cstdlib>
#include <ctime>

#include "Menu.hpp"

int main(int argc, char** argv) {
    srand(time(NULL));
    Menu menu;
    menu.afficher_menu();
    return 0;
}

