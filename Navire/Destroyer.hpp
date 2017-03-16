/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Destroyer.hpp
 * Author: Tberdy
 *
 * Created on 9 mars 2017, 23:05
 */

#ifndef DESTROYER_HPP
#define DESTROYER_HPP

#include "Navire.hpp"

class Destroyer : public Navire {
public:
    Destroyer();
    virtual ~Destroyer();
    
    void fire() override;
private:

};

#endif /* DESTROYER_HPP */

