/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Cuirasse.hpp
 * Author: Tberdy
 *
 * Created on 9 mars 2017, 23:04
 */

#ifndef CUIRASSE_HPP
#define CUIRASSE_HPP

#include "Navire.hpp"

class Cuirasse : public Navire {
public:
    Cuirasse();
    virtual ~Cuirasse();
    
    bool turn() override;
private:

};

#endif /* CUIRASSE_HPP */

