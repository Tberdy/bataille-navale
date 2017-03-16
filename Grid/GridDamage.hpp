/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   GridDamage.hpp
 * Author: Tberdy
 *
 * Created on 9 mars 2017, 23:06
 */

#ifndef GRIDDAMAGE_HPP
#define GRIDDAMAGE_HPP

#include "Grid.hpp"

class GridDamage : public Grid {
public:
    GridDamage();
    virtual ~GridDamage();
    
    void displayGrid() override;
private:

};

#endif /* GRIDDAMAGE_HPP */

