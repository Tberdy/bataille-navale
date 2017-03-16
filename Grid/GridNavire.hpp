/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   GridNavire.hpp
 * Author: Tberdy
 *
 * Created on 9 mars 2017, 23:06
 */

#ifndef GRIDNAVIRE_HPP
#define GRIDNAVIRE_HPP

#include "Grid.hpp"

class GridNavire : public Grid {
public:
    GridNavire();
    virtual ~GridNavire();
    
    void displayGrid() override;
private:

};

#endif /* GRIDNAVIRE_HPP */

