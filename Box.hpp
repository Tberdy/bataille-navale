/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Box.hpp
 * Author: Tberdy
 *
 * Created on 18 mars 2017, 18:30
 */

#ifndef BOX_HPP
#define BOX_HPP

#include "Navire/Navire.hpp"
#include "Navire/Croiseur.hpp"
#include "Navire/Cuirasse.hpp"
#include "Navire/Destroyer.hpp"
#include "Navire/SousMarin.hpp"

class Box {
public:
    Box(int lig, int col);
    virtual ~Box();
    
    bool isFree();
    Navire* getBoat();
    void setBoat(Navire* boat);
    bool isVisible();
    void setVisibility(bool visibility);
    int getLig();
    int getCol();
private:
    Navire* m_boat;
    bool m_visibility;
    int m_lig;
    int m_col;
};

#endif /* BOX_HPP */

