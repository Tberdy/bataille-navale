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
    for(auto pos : m_tabPos)
    {
        delete pos;
    }
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
char Navire::getDir()
{
    return m_dir;
}
void Navire::setDir(char dir)
{
    m_dir=dir;
}

Position* Navire::getMiddle() {
    return m_tabPos[(m_tabPos.size() - 1) / 2];
}

char Navire::getOppositeDir()
{
    switch(m_dir)
    {
        case KEY_UP: return KEY_DOWN;
        case KEY_DOWN : return KEY_UP;
        case KEY_LEFT : return KEY_RIGHT;
        case KEY_RIGHT : return KEY_LEFT;
    }
}
void Navire::setPos(std::vector<Position*> pos) {
    for (int i = 0; i < pos.size(); i++) {
        m_tabPos.push_back(pos[i]);
    }
}

void Navire::changePos(std::vector<Position*> pos) {
    for (int i = 0 ; i < pos.size() ; i++) {
        delete m_tabPos[i];
        m_tabPos[i] = pos[i];
    }
}


std::vector<Position*> Navire::getPos()
{
    return m_tabPos;
}
Position* Navire::getFrontPosition() {
    Position* frontPos = new Position;
    frontPos->col = m_tabPos.at(0)->col;
    frontPos->lig = m_tabPos.at(0)->lig;
    for (auto pos : m_tabPos) {
        switch (m_dir) {
            case DIR_UP:
                if (pos->lig < frontPos->lig) {
                    frontPos->lig = pos->lig;
                    frontPos->col = pos->col;
                }
                break;
            case DIR_DOWN:
                if (pos->lig > frontPos->lig) {
                    frontPos->lig = pos->lig;
                    frontPos->col = pos->col;
                }
                break;
            case DIR_LEFT:
                if (pos->col < frontPos->col) {
                    frontPos->lig = pos->lig;
                    frontPos->col = pos->col;
                }
                break;
            case DIR_RIGHT:
                if (pos->col > frontPos->col) {
                    frontPos->lig = pos->lig;
                    frontPos->col = pos->col;
                }
                break;
            default:
                std::cerr << "Error - getFrontPosition : Invalid m_dir";
                break;
        }
    }
    return frontPos;
}
Position* Navire::getOppositeFrontPosition() {
    Position* frontPos = new Position;
    frontPos->col = m_tabPos.at(0)->col;
    frontPos->lig = m_tabPos.at(0)->lig;
    for (auto pos : m_tabPos) {
        switch (m_dir) {
            case DIR_DOWN:
                if (pos->lig < frontPos->lig) {
                    frontPos->lig = pos->lig;
                    frontPos->col = pos->col;
                }
                break;
            case DIR_UP:
                if (pos->lig > frontPos->lig) {
                    frontPos->lig = pos->lig;
                    frontPos->col = pos->col;
                }
                break;
            case DIR_RIGHT:
                if (pos->col < frontPos->col) {
                    frontPos->lig = pos->lig;
                    frontPos->col = pos->col;
                }
                break;
            case DIR_LEFT:
                if (pos->col > frontPos->col) {
                    frontPos->lig = pos->lig;
                    frontPos->col = pos->col;
                }
                break;
            default:
                std::cerr << "Error - getFrontPosition : Invalid m_dir";
                break;
        }
    }
    return frontPos;
}
std::vector<Position*> Navire::generatePositionsTo(char dir) {
    std::vector<Position*> newPosTab;
    std::cout << "Original : \n";
    for (auto o : m_tabPos) {
        std::cout << "[" << o->lig << "," << o->col << "]\n";
    }
    for (auto pos : m_tabPos) {
        Position* newPos = new Position();
        newPos->lig = pos->lig;
        newPos->col = pos->col;
        if (dir == KEY_DOWN || dir == KEY_UP)newPos->lig = pos->lig + 2 * (dir % 2) - 1;
        if (dir == KEY_LEFT || dir == KEY_RIGHT)newPos->col = pos->col + 2 * (dir % 2) - 1;
        newPosTab.push_back(newPos);
    }
    std::cout << "New : \n";
    for (auto o : newPosTab) {
        std::cout << "[" << o->lig << "," << o->col << "]\n";
    }
    return newPosTab;
}

bool Navire::isPosDamage(int lig, int col) {
    for (auto pos : m_tabPos) {
        if (lig == pos->lig && col == pos->col) return pos->damage;
    }
    std::cerr << "Error : Boat pointer is corrupted\n";
    exit(1);
}

bool Navire::checkMove() {

}

bool Navire::turn() {

}

bool Navire::checkTurn() {

}

void Navire::initPos() {
    for (int i = 0; i < m_size; i++) {
        m_tabPos.push_back(nullptr);
    }
}

bool Navire::hasRocket() {
    return (m_nbRocket > 0);
}

void Navire::useRocket() {
    m_nbRocket--;
}


