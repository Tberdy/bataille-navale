/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   Game.cpp
 * Author: Tberdy
 *
 * Created on 9 mars 2017, 23:03
 */

#include "Game.hpp"

Game::Game() {
    for (int i = 0; i < NB_LIG; i++) {
        m_gridPlayer1.push_back(std::vector<Box*>(NB_COL, new Box()));
        m_gridPlayer2.push_back(std::vector<Box*>(NB_COL, new Box()));
    }
}

Game::~Game() {
}

void Game::loop() {
    int state = LOOP_IN_GAME;
    int move = KEY_NULL;
    int move2 = 0;
    
    this->display(PLAYER_ONE);
    while (state != LOOP_END_OF_GAME && state != LOOP_GAME_OVER) {
        
        move2 = xplt_getch();
        printf("%i\n", move2);
    }
}

void Game::display(int player) {
    std::cout << " ";
    for (int i = 0; i < NB_LIG; i++) {
        if (i < 10) std::cout << "| " << i;
        else std::cout << "|" << i % 100;
    }
    std::cout << "|" << std::endl;
    for (int i = 0; i < 2 * NB_LIG + 1; i++) {
        if (i % 2) {
            std::cout << (char) ((i / 2) % 27 + 97);
            for (int j = 0; j < NB_COL; j++) {
                std::cout << "|  ";
            }
            std::cout << "|" << std::endl;
        } else {
            std::cout << " ";
            for (int j = 0; j < NB_COL; j++) {
                std::cout << "|--";
            }
            std::cout << "|" << std::endl;
        }
    }
}


