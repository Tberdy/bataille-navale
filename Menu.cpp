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

Menu::Menu() : m_choix(0)
{
    pConsole = Console::getInstance();
}

Menu::Menu(const Menu& orig) {

}

Menu::~Menu() {

}

void Menu::afficher_menu() {
    bool quit = false;
    while(quit ==false)
    {
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
            break;
        /*case '2' :
            system("cls");
            std::cout << "Charger partie" << std::endl;
            system("cls");
            break;*/
        case '3' :
            system("cls");
            quit=true;
            break;
        default:
            break;
        }

}
}

