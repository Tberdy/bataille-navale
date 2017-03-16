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

#include "Grid/GridNavire.hpp"
#include "Grid/GridDamage.hpp"

#include "Navire/Croiseur.hpp"
#include "Navire/Cuirasse.hpp"
#include "Navire/Destroyer.hpp"
#include "Navire/SousMarin.hpp"

class Game {
public:
    Game();
    virtual ~Game();
    
    void loop();
private:
};

#endif /* GAME_HPP */

