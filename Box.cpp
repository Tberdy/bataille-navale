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

#include <system_error>
#include <iostream>

#include "Box.hpp"

Box::Box(int lig, int col) {
    m_boat = nullptr;
    m_visibility = false;
    m_lig = lig;
    m_col = col;
}

Box::~Box() {
}

bool Box::isFree() {
    return (m_boat == nullptr);
}
void Box::setFree()
{
    delete m_boat;
    m_boat=nullptr;
}
Navire* Box::getBoat() {
    if(m_boat == nullptr)
    {
        std::cerr << "Error : No boat on this box\n";
        exit(1);
    }
    return m_boat;
}

void Box::setBoat(Navire* boat) {
    m_boat = boat;
}

bool Box::isVisible() {
    return m_visibility;
}

void Box::setVisibility(bool visibility) {
    m_visibility = visibility;
}

int Box::getLig() {
    return m_lig;
}

int Box::getCol() {
    return m_col;
}

