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
#include <vector>
#include <string>

#include "Box.hpp"

#include "Navire/Navire.hpp"
#include "Navire/Croiseur.hpp"
#include "Navire/Cuirasse.hpp"
#include "Navire/Destroyer.hpp"
#include "Navire/SousMarin.hpp"

#define NB_LIG 15
#define NB_COL 15

#define LOOP_IN_GAME 0
#define LOOP_END_OF_GAME 1
#define LOOP_GAME_OVER 2

class Game {
public:
    Game();
    virtual ~Game();
    
    void loop();
private:
    std::vector<std::vector<Box*> > m_gridPlayer1;
    std::vector<std::vector<Box*> > m_gridPlayer2;
    
    void display(int player);
    void genBoat();
};

#endif /* GAME_HPP */

