/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   Menu.hpp
 * Author: Tberdy
 *
 * Created on 9 mars 2017, 23:02
 */

#ifndef MENU_HPP
#define MENU_HPP

#include <iostream>
#include <fstream>

#include "Game.hpp"
#include "lib/XPlatform/XPlatform.h"



class Menu {
public:
    Menu();
    virtual ~Menu();
    void afficher_menu();
    void afficher_regles();
private:
    int m_choix;
};

#endif /* MENU_HPP */

