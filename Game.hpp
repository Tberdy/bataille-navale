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

#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include "lib/XPlatform/XPlatform.h"

#include "Box.hpp"

#include "Navire/Navire.hpp"
#include "Navire/Croiseur.hpp"
#include "Navire/Cuirasse.hpp"
#include "Navire/Destroyer.hpp"
#include "Navire/SousMarin.hpp"

#include "const.hpp"

struct Cursor {
    int lig;
    int col;
};

class Game {
public:
    Game();
    virtual ~Game();
    
    void loop();
    
    void initBoat(int player);
private:
    std::vector<std::vector<std::vector<Box*> > > m_grids;
    std::vector<std::vector<std::vector<bool> > > m_damage;
    std::vector<std::vector<Navire*> > m_boats;
    std::vector<std::string> m_messageBus;
    std::vector<Cursor*> m_cursors;
    int m_state;
    
    bool checkKeys(char move, int action);
    void eventManager(int player);
    void display2(int player);
    
    void genBoat(int player, int type);
    bool findPlace(int player, int size, std::vector<Position*>& pos);
    bool checkIfPosValid(int player, const std::vector<Position*>& pos);
    
    void moveCursor(int player, int lig, int col);
    void resetCursor(int player);
};

#endif /* GAME_HPP */

