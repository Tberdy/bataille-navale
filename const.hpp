/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   const.hpp
 * Author: Tberdy
 *
 * Created on 19 mars 2017, 14:29
 */

#ifndef CONST_HPP
#define CONST_HPP

#define NB_LIG 15
#define NB_COL 15

#define TYPE_CUIRASSE 0
#define TYPE_CROISEUR 1
#define TYPE_DESTROYER 2
#define TYPE_SOUSMARIN 3

#define NB_CUIRASSE 1
#define NB_CROISEUR 2
#define NB_DESTROYER 3
#define NB_SOUSMARIN 4

#define SIZE_CUIRASSE 7
#define SIZE_CROISEUR 5
#define SIZE_DESTROYER 3
#define SIZE_SOUSMARIN 1

#define IMG_CUIRASSE '*'
#define IMG_CROISEUR 'o'
#define IMG_DESTROYER '+'
#define IMG_SOUSMARIN 's'
#define IMG_DAMAGE 'x'
#define IMG_HIDDEN '.'

#define DIR_UP 0
#define DIR_DOWN 1
#define DIR_LEFT 2
#define DIR_RIGHT 3
#define DIR_UNKNOW 4

#define LOOP_IN_GAME 0
#define LOOP_END_OF_GAME 1
#define LOOP_GAME_OVER 2

#define PLAYER_ONE 0
#define PLAYER_TWO 1

#define KEY_NULL '\0'
#define KEY_UP 'z'
#define KEY_DOWN 's'
#define KEY_LEFT 'q'
#define KEY_RIGHT 'd'
#define KEY_SPACE 'h'
#define KEY_ESCAPE 'p'
#define KEY_FIRE 'f'
#define KEY_TURN 't'

#define STATE_DISPLAY 0
#define STATE_SELECTION 1
#define STATE_SELECTED 2

#endif /* CONST_HPP */

