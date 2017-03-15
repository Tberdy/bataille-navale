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
    lig=15;
    col=15;
}

Game::Game(const Game& orig) {
}

Game::~Game() {
}

void Game::displayGrid()
{
    std::cout << " ";
    for(int i = 0; i<lig; i++)
    {
        if(i<10) std::cout << "| " << i;
        else std::cout << "|" << i%100;
    }
    std::cout << "|" << std::endl;
    for(int i = 0;i<2*lig+1 ;i++)
    {


        if(i%2)
        {
            std::cout << (char)((i/2)%27+97) ;
            for(int j=0;j<col;j++)
            {
                std::cout << "|  ";
            }
            std::cout << "|" << std::endl;
        }
        else
        {
            std::cout << " ";
            for(int j=0;j<col;j++)
            {
                std::cout << "|--";
            }
            std::cout << "|" << std::endl;
        }

    }


}
