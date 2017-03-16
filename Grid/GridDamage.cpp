/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   GridDamage.cpp
 * Author: Tberdy
 * 
 * Created on 9 mars 2017, 23:06
 */

#include "GridDamage.hpp"

GridDamage::GridDamage() {
}

GridDamage::~GridDamage() {
}

void GridDamage::displayGrid() {
    std::cout << " ";
    for (int i = 0; i < NB_LIG; i++) {
        if (i < 10) std::cout << "| " << i;
        else std::cout << "|" << i % 100;
    }
    std::cout << "|" << std::endl;
    for (int i = 0; i < 2 * NB_LIG + 1; i++) {
        if (i % 2) {
            std::cout << (char) ((i / 2) % 27 + 97);
            for (int j = 0; j < NB_COL; j++) {
                std::cout << "|  ";
            }
            std::cout << "|" << std::endl;
        } else {
            std::cout << " ";
            for (int j = 0; j < NB_COL; j++) {
                std::cout << "|--";
            }
            std::cout << "|" << std::endl;
        }
    }
}

