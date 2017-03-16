/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Navire.hpp
 * Author: Tberdy
 *
 * Created on 9 mars 2017, 23:04
 */

#ifndef NAVIRE_HPP
#define NAVIRE_HPP

#include <vector>

#include "Navire.hpp"

class Navire {
public:
    Navire();
    virtual ~Navire();
    
    bool move();
    virtual bool turn();
    virtual void fire();
protected:
    int m_size;
    int m_puissance;
    
    bool checkMove();
    bool checkTurn();
};

#endif /* NAVIRE_HPP */

