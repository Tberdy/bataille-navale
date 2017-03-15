/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Game.hpp
 * Author: Tberdy
 *
 * Created on 9 mars 2017, 23:03
 */

#ifndef GAME_HPP
#define GAME_HPP

#include <iostream>

class Game {
public:
    Game();
    Game(const Game& orig);
    virtual ~Game();
    
    void displayGrid();
private:
    int lig;
    int col;
};

#endif /* GAME_HPP */

