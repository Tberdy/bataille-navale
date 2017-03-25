/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Navire.cpp
 * Author: Tberdy
 * 
 * Created on 9 mars 2017, 23:04
 */

#include "Navire.hpp"

Navire::Navire() {
}

Navire::~Navire() {
}

int Navire::getType() {
    return m_type;
}

int Navire::getSize() {
    return m_size;
}

int Navire::getPuissance() {
    return m_puissance;
}

std::string Navire::getImg() {
    std::string s;
    s = s + m_img + m_img;
    return s;
}

void Navire::setPos(std::vector<Position*> pos) {
    for (int i = 0 ; i < pos.size() ; i++) {
        m_tabPos.push_back(pos[i]);
    }
}

bool Navire::move(char dir) {
    std::vector<Position*> newPos;
    for(auto pos : new)
    {
        
    }
}

bool Navire::checkMove() {

}

bool Navire::turn() {

}

bool Navire::checkTurn() {

}

void Navire::fire() {

}

void Navire::initPos() {
    for (int i = 0 ; i < m_size ; i++) {
        m_tabPos.push_back(nullptr);
    }
}

