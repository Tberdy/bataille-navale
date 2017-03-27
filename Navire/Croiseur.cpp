/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Croiseur.cpp
 * Author: Tberdy
 * 
 * Created on 9 mars 2017, 23:05
 */

#include "Croiseur.hpp"

Croiseur::Croiseur() {
    m_type = TYPE_CROISEUR;
    m_size = SIZE_CROISEUR;
    m_puissance = 4;
    m_img = IMG_CROISEUR;
    m_nbRocket = 0;
}

Croiseur::~Croiseur() {
}

