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
    m_grids.push_back(std::vector<std::vector<Box*> >());
    m_grids.push_back(std::vector<std::vector<Box*> >());

    m_damage.push_back(std::vector <std::vector<bool> >());
    m_damage.push_back(std::vector <std::vector<bool> >());

    for (int i = 0; i < NB_LIG; i++) {
        m_grids[PLAYER_ONE].push_back(std::vector<Box*>());
        m_grids[PLAYER_TWO].push_back(std::vector<Box*>());

        m_damage[PLAYER_ONE].push_back(std::vector<bool>(NB_COL, false));
        m_damage[PLAYER_TWO].push_back(std::vector<bool>(NB_COL, false));

        for (int j = 0; j < NB_COL; j++) {
            m_grids[PLAYER_ONE][i].push_back(new Box());
            m_grids[PLAYER_TWO][i].push_back(new Box());
        }
    }

    m_boats.push_back(std::vector<Navire*>());
    m_boats.push_back(std::vector<Navire*>());

    m_damage.push_back(std::vector < std::vector<bool> >());
    m_damage.push_back(std::vector < std::vector<bool> >());

    initBoat(PLAYER_ONE);
    initBoat(PLAYER_TWO);

    for (int i = 0; i < 5; i++) {
        m_messageBus.push_back("");
    }
    
    m_cursors.push_back(new Cursor);
    m_cursors.push_back(new Cursor);
    m_cursors[PLAYER_ONE]->lig = 7;
    m_cursors[PLAYER_ONE]->col = 7;
    m_cursors[PLAYER_TWO]->lig = 7;
    m_cursors[PLAYER_TWO]->col = 7;
    
}

Game::~Game() {
}

void Game::loop() {
    int state = LOOP_IN_GAME;
    

    while (state != LOOP_END_OF_GAME && state != LOOP_GAME_OVER) {
        /// PLAYER 1
        
        display2(PLAYER_ONE);
        /// select boat
        selectBoat(PLAYER_ONE);
    }
}

bool Game::checkKeys(char move, int action) {
    switch (move) {
        case KEY_UP:
            switch(action)
            {
                case ACTION_SELECT_BOAT:
                    moveCursor(PLAYER_ONE,m_cursors[PLAYER_ONE]->lig-1,m_cursors[PLAYER_ONE]->col);
                    break;
                    
            }
            break;
        case KEY_DOWN:
            switch(action)
            {
                case ACTION_SELECT_BOAT:
                    moveCursor(PLAYER_ONE,m_cursors[PLAYER_ONE]->lig+1,m_cursors[PLAYER_ONE]->col);
                    break;
                    
            }
            break;
        case KEY_LEFT:
            switch(action)
            {
                case ACTION_SELECT_BOAT:
                    moveCursor(PLAYER_ONE,m_cursors[PLAYER_ONE]->lig,m_cursors[PLAYER_ONE]->col-1);
                    break;
                    
            }
            break;
        case KEY_RIGHT:
            switch(action)
            {
                case ACTION_SELECT_BOAT:
                    moveCursor(PLAYER_ONE,m_cursors[PLAYER_ONE]->lig,m_cursors[PLAYER_ONE]->col+1);
                    break;
                    
            }
            break;
        case KEY_SPACE:
            switch(action)
            {
                case ACTION_SELECT_BOAT:
                    
                    break;
                    
            }
        case KEY_ESCAPE:
        case KEY_FIRE:
        case KEY_TURN:
            return (action == ACTION_SELECT_ACTION);
        default:
            return false;
    }
}

void Game::selectBoat(int player) {
    bool isBoat = false;
    char move = KEY_NULL;
    resetCursor(player);
    while (!isBoat) {
        do {
            move = xplt_getch();
        } while (!checkKeys(move, ACTION_SELECT_BOAT));
 
    }
}

void Game::display2(int player) {
    std::cout << " ";
    for (int i = 0; i < NB_COL; i++) {
        if (i < 10) std::cout << "| " << i;
        else std::cout << "|" << i % 100;
    }
    std::cout << "|     ";
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

                if (m_grids[player][(i - 1) / 2][j]->isFree()) {
                    std::cout << "  ";
                } else {
                    std::cout << m_grids[player][(i - 1) / 2][j]->getBoat()->getImg();
                }

            }
            std::cout << "|    ";
            std::cout << (char) ((i / 2) % 27 + 97);
            for (int j = 0; j < NB_COL; j++) {
                std::cout << "|";

                if (!m_damage[player][(i - 1) / 2][j]) {
                    std::cout << "  ";
                } else {
                    std::cout << IMG_DAMAGE << IMG_DAMAGE;
                }

            }
            std::cout << "|" << std::endl;
        } else {
            std::cout << " ";
            for (int j = 0; j < NB_COL; j++) {
                std::cout << "|--";
            }
            std::cout << "|     ";
            for (int j = 0; j < NB_COL; j++) {
                std::cout << "|--";
            }
            std::cout << "|" << std::endl;
        }
    }

    std::cout << "--------------------------------------------------------------------------------------------------" << std::endl;
    for (auto elm : m_messageBus) {
        std::cout << "| " << elm << std::endl;
    }
    std::cout << "--------------------------------------------------------------------------------------------------" << std::endl;
}

void Game::initBoat(int player) {
    for (int i = 0; i < NB_CUIRASSE; i++) {
        genBoat(player, TYPE_CUIRASSE);
    }
    for (int i = 0; i < NB_CROISEUR; i++) {
        genBoat(player, TYPE_CROISEUR);
    }
    for (int i = 0; i < NB_DESTROYER; i++) {
        genBoat(player, TYPE_DESTROYER);
    }
    for (int i = 0; i < NB_SOUSMARIN; i++) {
        genBoat(player, TYPE_SOUSMARIN);
    }
}

void Game::genBoat(int player, int type) {
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
    for (int i = 0; i < pos.size(); i++) {
        pos[i] = new Position;
    }

    while (!findPlace(player, size, pos)) {
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

    for (int i = 1; i < size; i++) {
        switch (dir) {
            case DIR_UP:
                pos[i]->lig = pos[i - 1]->lig - 1;
                pos[i]->col = pos[0]->col;
                break;
            case DIR_DOWN:
                pos[i]->lig = pos[i - 1]->lig + 1;
                pos[i]->col = pos[0]->col;
                break;
            case DIR_LEFT:
                pos[i]->lig = pos[0]->lig;
                pos[i]->col = pos[i - 1]->col - 1;
                break;
            case DIR_RIGHT:
                pos[i]->lig = pos[0]->lig;
                pos[i]->col = pos[i - 1]->col + 1;
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

void Game::moveCursor(int player, int lig, int col) {
    xplt_gotoligcol((lig+1)*2, (col+1)*3);
    m_cursors[player]->lig = lig;
    m_cursors[player]->col = col;
}

void Game::resetCursor(int player) {
    xplt_gotoligcol((m_cursors[player]->lig + 1)*2, (m_cursors[player]->col +1)*3);
}
