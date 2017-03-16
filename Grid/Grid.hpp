/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Grid.hpp
 * Author: Tberdy
 *
 * Created on 9 mars 2017, 23:05
 */

#ifndef GRID_HPP
#define GRID_HPP

#define NB_LIG 15
#define NB_COL 15

#include <iostream>

class Grid {
public:
    Grid();
    virtual ~Grid();
    
    virtual void displayGrid() = 0;
private:

};

#endif /* GRID_HPP */

