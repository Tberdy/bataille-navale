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
    for (int i = 0 ; i < NB_LIG ; i++) {
        m_gridPlayer1.push_back(std::vector<Box*>(NB_COL, new Box()));
        m_gridPlayer2.push_back(std::vector<Box*>(NB_COL, new Box()));
    }
}

Game::~Game() {
}

void Game::loop() {
    int state = LOOP_IN_GAME;
    
    while (state != LOOP_END_OF_GAME && state != LOOP_GAME_OVER) {
    }
}

void Game::display(int player) {
    
}


