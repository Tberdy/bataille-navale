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
#include "console.h"

class Menu {
public:
    Menu();
    Menu(const Menu& orig);
    virtual ~Menu();
    void afficher_menu();
    void afficher_regles();
private:
    int m_choix;
    Console* pConsole;
};

#endif /* MENU_HPP */

