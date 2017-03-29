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
    m_state = STATE_DISPLAY;
    m_memoryMove = KEY_NULL;
    m_grids.push_back(std::vector<std::vector<Box*> >());
    m_grids.push_back(std::vector<std::vector<Box*> >());

    for (int i = 0; i < NB_LIG; i++) {
        m_grids[PLAYER_ONE].push_back(std::vector<Box*>());
        m_grids[PLAYER_TWO].push_back(std::vector<Box*>());

        for (int j = 0; j < NB_COL; j++) {
            m_grids[PLAYER_ONE][i].push_back(new Box(i, j));
            m_grids[PLAYER_TWO][i].push_back(new Box(i, j));
        }
    }

    m_boats.push_back(std::vector<Navire*>());
    m_boats.push_back(std::vector<Navire*>());

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

    //display2(PLAYER_ONE);

    while (state != LOOP_END_OF_GAME && state != LOOP_GAME_OVER) {
        /// PLAYER 1

        if (m_state == STATE_DISPLAY)display2(PLAYER_ONE);
        resetCursor(PLAYER_ONE);
        /// select boat
        eventManager(PLAYER_ONE);
    }

}

char Game::keyToDir(char key) {
    switch (key) {
        case KEY_UP: return DIR_UP;
        case KEY_DOWN: return DIR_DOWN;
        case KEY_LEFT: return DIR_LEFT;
        case KEY_RIGHT: return DIR_RIGHT;
    }
    return DIR_UNKNOW;
}

int Game::other(int player) {
    return (player + 1) % 2;
}

bool Game::checkKeys(char move, int state) {
    switch (move) {
        case KEY_UP:
            if (state == STATE_SELECTION || state == STATE_SELECTED || state == STATE_ROTATION) return true;
            break;
        case KEY_DOWN:
            if (state == STATE_SELECTION || state == STATE_SELECTED || state == STATE_ROTATION) return true;
            break;
        case KEY_LEFT:
            if (state == STATE_SELECTION || state == STATE_SELECTED || state == STATE_ROTATION) return true;
            break;
        case KEY_RIGHT:
            if (state == STATE_SELECTION || state == STATE_SELECTED || state == STATE_ROTATION) return true;
            break;
        case KEY_SPACE:
            if (state == STATE_SELECTION) return true;
            break;
        case KEY_ESCAPE:
            if (state == STATE_SELECTED || state == STATE_ROTATION) return true;
            break;
        case KEY_TURN:
            if (state == STATE_SELECTED) return true;
            break;
        case KEY_FIRE:
            if (state == STATE_SELECTED) return true;
            break;
        case 'r':
            if (state == STATE_SELECTION)return true;
            break;
        default:
            return false;
    }
}

void Game::eventManager(int player) {

    char move = KEY_NULL;

    //States of the game
    if (m_state == STATE_DISPLAY) {
        m_state = STATE_SELECTION;
    }
    //Cursor selection
    if (m_state == STATE_SELECTION) {
        resetCursor(player);
        do {
            move = xplt_getch();


        } while (!checkKeys(move, STATE_SELECTION));
        switch (move) {
            case KEY_UP:
                if (m_cursors[player]->lig > 0) moveCursor(player, m_cursors[player]->lig - 1, m_cursors[player]->col);
                break;
            case KEY_DOWN:
                if (m_cursors[player]->lig < NB_LIG - 1) moveCursor(player, m_cursors[player]->lig + 1, m_cursors[player]->col);
                break;
            case KEY_LEFT:
                if (m_cursors[player]->col > 0)moveCursor(player, m_cursors[player]->lig, m_cursors[player]->col - 1);
                break;
            case KEY_RIGHT:
                if (m_cursors[player]->col < NB_COL - 1)moveCursor(player, m_cursors[player]->lig, m_cursors[player]->col + 1);
                break;
            case KEY_SPACE:
                xplt_gotoligcol(30, 0);
                std::cout << "\"" << m_grids[player][m_cursors[player]->lig][m_cursors[player]->col]->getBoat()->getImg() << "\"";
                m_state = STATE_SELECTED;
                resetCursor(player);
                break;
            case 'r':
                m_state = STATE_DISPLAY;
            default:
                break;
        }



    }

    //A boat is selected
    if (m_state == STATE_SELECTED) {
        do {
            move = xplt_getch();
        } while (!checkKeys(move, STATE_SELECTED));

        switch (move) {

            case KEY_UP:
                m_state = STATE_MOVE;
                m_memoryMove = keyToDir(move);
                break;
            case KEY_DOWN:
                m_state = STATE_MOVE;
                m_memoryMove = keyToDir(move);
                break;
            case KEY_LEFT:
                m_state = STATE_MOVE;
                m_memoryMove = keyToDir(move);
                break;
            case KEY_RIGHT:
                m_state = STATE_MOVE;
                m_memoryMove = keyToDir(move);
                break;
            case KEY_TURN:
                m_state = STATE_ROTATION;
                break;
            case KEY_FIRE:
                m_state = STATE_FIRE;
            case KEY_ESCAPE:
                //go back to slection
                m_state = STATE_SELECTION;
                break;

            default:
                std::cerr << "001 - Invalid command.";
                break;
        }

    }
    //A boat will move
    if (m_state == STATE_MOVE) {
        //The command is taken from the memory
        Position* targetPos = new Position;

        //Mapping between the mouvement selected and the direction of the boat 
        std::cout << std::endl << "move : " << m_memoryMove << "dir: " << (int) m_grids[player][m_cursors[player]->lig][m_cursors[player]->col]->getBoat()->getDir();
        if (m_memoryMove == m_grids[player][m_cursors[player]->lig][m_cursors[player]->col]->getBoat()->getDir()) {
            targetPos = m_grids[player][m_cursors[player]->lig][m_cursors[player]->col]->getBoat()->getFrontPosition();
        } else {
            if (m_memoryMove == m_grids[player][m_cursors[player]->lig][m_cursors[player]->col]->getBoat()->getOppositeDir()) {
                targetPos = m_grids[player][m_cursors[player]->lig][m_cursors[player]->col]->getBoat()->getOppositeFrontPosition();
            } else {
                //Invalid direction
                //m_messageBus += "\nLa direction choisie n'est pas correcte. Effectuez une rotation d'abord.";
                m_state = STATE_DISPLAY;
                return;
            }
        }
        switch (m_memoryMove) {
            case DIR_UP:
                targetPos->lig--;
                std::cout << "step 0 : " << targetPos->lig << " " << targetPos->col;
                break;
            case DIR_DOWN:
                targetPos->lig++;
                std::cout << "step 0 : " << targetPos->lig << " " << targetPos->col;
                break;
            case DIR_LEFT:
                targetPos->col--;
                std::cout << "step 0 : " << targetPos->lig << " " << targetPos->col;
                break;
            case DIR_RIGHT:
                targetPos->lig++;
                std::cout << "step 0 : " << targetPos->lig << " " << targetPos->col;
                break;
            default:
                std::cerr << "002 - Invalid direction.";
                break;
        }
        //Verification that the case is still in the grid
        if (targetPos->col > 0 && targetPos->col < NB_COL - 1 && targetPos->lig > 0 && targetPos->lig < NB_LIG) {
            std::cout << "step 1 : " << targetPos->lig << "," << targetPos->col << std::endl;
            //The case in front of the boat is free
            if (m_grids[player][targetPos->lig][targetPos->col]->isFree()) {

                std::cout << "step a1" << std::endl;
                for (auto o : m_grids[player][m_cursors[player]->lig][m_cursors[player]->col]->getBoat()->getPos()) {
                    std::cout << "[" << o->lig << "," << o->col << "]" << std::endl;
                }
                Position* momentumPos = m_grids[player][m_cursors[player]->lig][m_cursors[player]->col]->getBoat()->getOppositeFrontPosition();
                std::vector <Position*> newPosTab(m_grids[player][m_cursors[player]->lig][m_cursors[player]->col]->getBoat()->getPos());
                for (auto pos : newPosTab) {
                    if (pos->col == momentumPos->col && pos->lig == momentumPos->lig) {
                        pos->col = targetPos->col;
                        pos->lig = targetPos->lig;
                    }
                }
                std::cout << "step a2" << std::endl;
                for (auto o : m_grids[player][m_cursors[player]->lig][m_cursors[player]->col]->getBoat()->getPos()) {
                    std::cout << "[" << o->lig << "," << o->col << "]" << std::endl;
                }
                std::cout << "step a3" << std::endl;
                Navire* boatTmp = m_grids[player][m_cursors[player]->lig][m_cursors[player]->col]->getBoat();
                m_grids[player][targetPos->lig][targetPos->col]->setBoat(boatTmp);
                m_grids[player][momentumPos->lig][momentumPos->col]->setFree();
                m_state = STATE_DISPLAY;
            } else {
                std::cout << "step 2 : " << m_grids[player][targetPos->lig][targetPos->col]->getBoat()->getImg() << std::endl;
            }
        } else {
            //Incorrect mouvement
            m_state = STATE_DISPLAY;
        }


        std::cout << "step final" << std::endl;
        system("pause");
        m_state = STATE_DISPLAY;
    }
    //Rotation
    if (m_state == STATE_ROTATION) {
        do {
            move = xplt_getch();
        } while (!checkKeys(move, STATE_SELECTED));
        switch (move) {
            case KEY_UP:
                //rotation up
                //if(rotation made) m_stage=STATE_END_OF_ACTION;
                break;
            case KEY_DOWN:
                //rotation down
                break;
            case KEY_LEFT:
                //rotation left
                break;
            case KEY_RIGHT:
                //rotation right
                break;
            case KEY_ESCAPE:
                //go back to slection
                m_state = STATE_SELECTION;
                break;

            default:
                break;
        }

    }

    //Fire
    if (m_state == STATE_FIRE) {
        do {
            move = xplt_getch();
        } while (!checkKeys(move, STATE_SELECTED));
        switch (move) {
            case KEY_UP:
                //selection up
                break;
            case KEY_DOWN:
                //selection down
                break;
            case KEY_LEFT:
                //slection left
                break;
            case KEY_RIGHT:
                //selection right
                break;
            case KEY_SPACE:
                //fire !
                //if fire done : m_state=STATE_END_OF_ACTION;
                break;
            case KEY_ESCAPE:
                //go back to slection
                m_state = STATE_SELECTION;
                break;

            default:
                break;
        }

    }

    //States of boat
    for (int i = 0; i < NB_LIG; i++) {


        for (int j = 0; j < NB_COL; j++) {
            if (!m_grids[player].at(i).at(j)->isFree()) {
                //State of m_grids[player].at(i).at(j)->getBoat() and switch
                //mouvement en 2 temps du cuirassé
                //munition de fusée éclairante
            }
        }
    }
}

void Game::fire(int player, Navire* attaquant, Box* cible) {
    if (attaquant->hasRocket()) {
        makeVisible(player, cible);
        attaquant->useRocket();
    }
    if (cible->isFree()) return;

    if (attaquant->getType() == TYPE_SOUSMARIN && cible->getBoat()->getType() != TYPE_SOUSMARIN) return;

    cible->getBoat()->getPos();
    for (int i = 0; i < cible->getBoat()->getSize(); i++) {
        if (cible->getBoat()->getPos()[i]->lig == cible->getLig() && cible->getBoat()->getPos()[i]->col == cible->getCol()) {
            cible->getBoat()->getPos()[i]->damage = true;
        }
    }
}

void Game::makeVisible(int player, Box* cible) {
    int lig = cible->getLig() - 1;
    int col = cible->getCol() - 1;
    int ligEnd = lig + 4;
    int colEnd = col + 4;

    for (int i = lig; i < ligEnd; i++) {
        for (int j = col; j < colEnd; j++) {
            if (i >= 0 && i < NB_LIG && j >= 0 && j < NB_COL) {
                m_grids[other(player)][i][j]->setVisibility(true);
            }
        }
    }


    cible->setVisibility(true);

}

void Game::display2(int player) {
    xplt_clrscr();
    xplt_gotoligcol(0, 0);
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

                if (m_grids[other(player)][(i - 1) / 2][j]->isFree()) {
                    if (m_grids[other(player)][(i - 1) / 2][j]->isVisible()) {
                        std::cout << "  ";
                    } else {
                        std::cout << IMG_HIDDEN << IMG_HIDDEN;
                    }
                } else {
                    if (m_grids[other(player)][(i - 1) / 2][j]->getBoat()->isPosDamage((i - 1) / 2, j)) {
                        std::cout << IMG_DAMAGE << IMG_DAMAGE;
                    } else {
                        std::cout << IMG_HIDDEN << IMG_HIDDEN;
                    }
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
    char dir;
    while (!findPlace(player, size, pos, dir)) {
    }
    boat->setDir(dir);
    boat->setPos(pos);
    for (auto elm : pos) {
        m_grids[player][elm->lig][elm->col]->setBoat(boat);
    }

    m_boats[player].push_back(boat);
}

bool Game::findPlace(int player, int size, std::vector<Position*>& pos, char& dir) {
    dir = rand() % 4;

    pos[0]->lig = rand() % NB_LIG;
    pos[0]->col = rand() % NB_COL;
    pos[0]->damage = false;

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
        pos[i]->damage = false;
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
    xplt_gotoligcol((lig + 1)*2, (col + 1)*3);
    m_cursors[player]->lig = lig;
    m_cursors[player]->col = col;
}

void Game::resetCursor(int player) {
    xplt_gotoligcol((m_cursors[player]->lig + 1)*2, (m_cursors[player]->col + 1)*3);
}
