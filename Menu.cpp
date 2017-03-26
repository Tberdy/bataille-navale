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
#include "Game.hpp"
#include "Menu.hpp"
#include "console.h"
#include "iostream"
#include <windows.h>
#include<fstream>
#include <cstdlib>
#include <ctime>
#include "conio.h"
#include <cstdlib>

Menu::Menu() : m_choix(0)
{
    pConsole = Console::getInstance();
}

Menu::Menu(const Menu& orig) {

}

Menu::~Menu() {

}

void Menu::afficher_regles(){
    Menu menu;
    const char*filename ="Regles.txt";
    std::ifstream ifs (filename);
    std::string line;
    while (std::getline(ifs,line))
    std::cout<<line<<std::endl;
    ifs.close();
    m_choix=getch();
    if (m_choix=='r'){
    system("cls");
    menu.afficher_menu();
    }
}

void Menu::afficher_menu() {
    Menu menu;
    const char*filename ="graffic.txt";
    std::ifstream ifs (filename);
    std::string line;
    while (std::getline(ifs,line))
    std::cout<<line<<std::endl;
    ifs.close();
    m_choix=getch();

        switch(m_choix)
        {
        case '1' :
            system("cls");
            srand(time(NULL));
            Game* game;
            game = new Game();
            game->loop();
            m_choix=0;
            break;
        case '2' :
            system("cls");
            std::cout << "Charger partie" << std::endl;

            break;
        case '3' :
            system("cls");
            menu.afficher_regles();

            break;
        case '4' :
            exit(0);
            break;
        }

}


