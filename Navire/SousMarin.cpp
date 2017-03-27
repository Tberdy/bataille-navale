/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   SousMarin.cpp
 * Author: Tberdy
 * 
 * Created on 9 mars 2017, 23:05
 */

#include "SousMarin.hpp"
#include "../Box.hpp"

SousMarin::SousMarin() {
    m_type = TYPE_SOUSMARIN;
    m_size = SIZE_SOUSMARIN;
    m_puissance = 1;
    m_img = IMG_SOUSMARIN;
    m_nbRocket = 0;
}

SousMarin::~SousMarin() {
}
/*
bool SousMarin::fire(Navire* cible) {
    if ()
}
*/