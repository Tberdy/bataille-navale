/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   EventManager.cpp
 * Author: Tberdy
 * 
 * Created on 15 mars 2017, 23:15
 */

#include "EventManager.hpp"

EventManager* EventManager::m_instance = nullptr;

EventManager::EventManager() {
    m_instance = nullptr;
}

EventManager::~EventManager() {
}

EventManager* EventManager::deleteInstance() {
    delete m_instance;
    m_instance = nullptr;
}

EventManager* EventManager::getInstance() {
    if (!EventManager::m_instance) {
        m_instance = new EventManager();
    }
    return m_instance;
}


