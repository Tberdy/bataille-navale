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
#include <string>
#include "../const.hpp"

struct Position {
    int lig;
    int col;
};

class Navire {
public:
    Navire();
    virtual ~Navire();
    
    int getType();
    int getSize();
    int getPuissance();
    std::string getImg(); 
    void setPos(std::vector<Position*> pos);
    
    bool move(char dir);
    virtual bool turn();
    virtual void fire();
protected:
    int m_type;
    int m_size;
    int m_puissance;
    char m_img;
    std::vector<Position*> m_tabPos;
    
    bool checkMove();
    bool checkTurn();
    
    void initPos();
};

#endif /* NAVIRE_HPP */

