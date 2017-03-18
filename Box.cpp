/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Box.cpp
 * Author: Tberdy
 * 
 * Created on 18 mars 2017, 18:30
 */

#include "Box.hpp"

Box::Box() {
    m_boat = nullptr;
    m_visibility = false;
}

Box::~Box() {
}

bool Box::isFree() {
    return (m_boat == nullptr);
}

Navire* Box::getBoat() {
    return m_boat;
}

void Box::setBoat(Navire* boat) {
    m_boat = boat;
}




