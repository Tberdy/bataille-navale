/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   Menu.cpp
 * Author: Tberdy
 *
 * Created on 9 mars 2017, 23:02
 */

#include "Menu.hpp"

Menu::Menu() : m_choix(0) {
}

Menu::~Menu() {

}

void Menu::afficher_regles() {
    Menu menu;
    const char*filename = "Regles.txt";
    std::ifstream ifs(filename);
    std::string line;
    while (std::getline(ifs, line))
        std::cout << line << std::endl;
    ifs.close();
    m_choix = xplt_getch();
    while (m_choix != 'r') {
        m_choix = xplt_getch();
    }
    xplt_clrscr();
    menu.afficher_menu();
}

void Menu::afficher_menu() {
    Menu menu;
    const char*filename = "graffic.txt";
    std::ifstream ifs(filename);
    std::string line;
    while (std::getline(ifs, line))
        std::cout << line << std::endl;
    ifs.close();
    m_choix = xplt_getch();

    switch (m_choix) {
        case '1':
            xplt_clrscr();
            Game* game;
            game = new Game();
            game->loop();
            m_choix = 0;
            break;
        case '2':
            xplt_clrscr();
            std::cout << "Charger partie" << std::endl;
            break;
        case '3':
            xplt_clrscr();
            menu.afficher_regles();
            break;
        case '4':
            exit(0);
            break;
    }

}


