/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   Game.cpp
 * Author: Tberdy
 *
 * Created on 9 mars 2017, 23:03
 */

#include "Game.hpp"

Game::Game() {
    std::cout << "start constructor" << std::endl;
    m_grids.push_back(std::vector<std::vector<Box*> >());
    m_grids.push_back(std::vector<std::vector<Box*> >());
    
    
    for (int i = 0 ; i < NB_LIG ; i++) {
        m_grids[PLAYER_ONE].push_back(std::vector<Box*>());
        m_grids[PLAYER_TWO].push_back(std::vector<Box*>());
        
        for (int j = 0 ; j < NB_COL ; j++) {
            m_grids[PLAYER_ONE][i].push_back(new Box());
            m_grids[PLAYER_TWO][i].push_back(new Box());
        } 
    }
    
    m_boats.push_back(std::vector<Navire*>());
    m_boats.push_back(std::vector<Navire*>());
    
    initBoat(PLAYER_ONE);
    initBoat(PLAYER_TWO);
    std::cout << "construct done !!" << std::endl;
}

Game::~Game() {
}

void Game::loop() {
    int state = LOOP_IN_GAME;
    char move = KEY_NULL;
    
    display(PLAYER_ONE);
    display(PLAYER_TWO);
    //while (state != LOOP_END_OF_GAME && state != LOOP_GAME_OVER) {
        
        /// PLAYER 1
        
        
        /// select boat
        /*
        do {
            move = xplt_getch();
        } while (!checkKeys(move, ACTION_SELECT_BOAT));
        */
        
        
        
    //}
}

bool Game::checkKeys(char move, int action) {
    switch (move) {
        case KEY_UP:
        case KEY_DOWN:
        case KEY_LEFT:
        case KEY_RIGHT:
        case KEY_SPACE:
            return (action == ACTION_SELECT_BOAT);
        case KEY_ESCAPE:
        case KEY_FIRE:
        case KEY_TURN:
            return (action == ACTION_SELECT_ACTION);
        default:
            return false;
    }
}

void Game::display(int player) {
    std::cout << " ";
    for (int i = 0; i < NB_COL; i++) {
        if (i < 10) std::cout << "| " << i;
        else std::cout << "|" << i % 100;
    }
    std::cout << "|" << std::endl;
    for (int i = 0; i < 2 * NB_LIG + 1; i++) {
        if (i % 2) {
            std::cout << (char) ((i / 2) % 27 + 97);
            for (int j = 0; j < NB_COL; j++) {
                std::cout << "|";
                
                if (m_grids[player][(i-1)/2][j]->isFree()) {
                    std::cout << "  ";
                } else {
                    std::cout << m_grids[player][(i-1)/2][j]->getBoat()->getImg();
                }
                
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

void Game::initBoat(int player) {
    std::cout << "start initBoat" << std::endl;
    for (int i = 0 ; i < NB_CUIRASSE ; i++) {
        genBoat(player, TYPE_CUIRASSE);
    }
    for (int i = 0 ; i < NB_CROISEUR ; i++) {
        genBoat(player, TYPE_CROISEUR);
    }
    for (int i = 0 ; i < NB_DESTROYER ; i++) {
        genBoat(player, TYPE_DESTROYER);
    }
    for (int i = 0 ; i < NB_SOUSMARIN ; i++) {
        genBoat(player, TYPE_SOUSMARIN);
    }
}

void Game::genBoat(int player, int type) {
    std::cout << "start genBoat" << std::endl;
    Navire* boat = nullptr;
    switch (type) {
        case TYPE_CUIRASSE:
            boat = new Cuirasse();
            break;
        case TYPE_CROISEUR:
            boat = new Croiseur();
            break;
        case TYPE_DESTROYER:
            boat = new Destroyer();
            break;
        case TYPE_SOUSMARIN:
            boat = new SousMarin();
            break;
    }
    
    int size = boat->getSize();
    
    std::vector<Position*> pos(size, nullptr);
    for (int i = 0 ; i < pos.size() ; i++) {
        pos[i] = new Position;
    }
    
    while(!findPlace(player, size, pos)) {
        std::cout << "Processing..." << std::endl;
    }
    
    for (auto elm : pos) {
        m_grids[player][elm->lig][elm->col]->setBoat(boat);
    }

    m_boats[player].push_back(boat);
}  

bool Game::findPlace(int player, int size, std::vector<Position*>& pos) {
    int dir = rand() % 4;
    
    pos[0]->lig = rand() % NB_LIG;
    pos[0]->col = rand() % NB_COL;
    
    for (int i = 1 ; i < size ; i++) {
        switch (dir) {
            case DIR_UP:
                pos[i]->lig = pos[i-1]->lig - 1;
                pos[i]->col = pos[0]->col;
                break;
            case DIR_DOWN:
                pos[i]->lig = pos[i-1]->lig + 1;
                pos[i]->col = pos[0]->col;
                break;
            case DIR_LEFT:
                pos[i]->lig = pos[0]->lig;
                pos[i]->col = pos[i-1]->col - 1;
                break;
            case DIR_RIGHT:
                pos[i]->lig = pos[0]->lig;
                pos[i]->col = pos[i-1]->col + 1;
                break;
        }
    }
    
    return checkIfPosValid(player, pos);
}

bool Game::checkIfPosValid(int player, const std::vector<Position*>& pos) {
    for (auto elm : pos) {
        if (elm->lig < 0 || elm->lig >= NB_LIG) return false;
        if (elm->col < 0 || elm->col >= NB_COL) return false; 
        
        if (!m_grids[player][elm->lig][elm->col]->isFree()) return false;
    }
    
    return true;
}

void Game::debug_displayPos(const std::vector<Position*>& pos) {
    for (auto elm : pos) {
        std::cout << std::endl << "Boat box = " << elm->lig << " " << elm->col << std::endl << std::endl;
    }
    
}

