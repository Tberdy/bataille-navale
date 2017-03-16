/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   EventManager.hpp
 * Author: Tberdy
 *
 * Created on 15 mars 2017, 23:15
 */

#ifndef EVENTMANAGER_HPP
#define EVENTMANAGER_HPP

#include <vector>

#include "Task.hpp"

class EventManager {
public:
    static EventManager* getInstance();
    static EventManager* deleteInstance();
private:
    EventManager();
    virtual ~EventManager();
    
    static EventManager* m_instance;
    
    std::vector<Task*> m_storage;
};

#endif /* EVENTMANAGER_HPP */

