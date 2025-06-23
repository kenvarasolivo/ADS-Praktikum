/*************************************************
* ADS Praktikum 1.1
* Ring.cpp
* Erweiterung um Hilfsfunktionen gestattet.
*************************************************/
// Ring .cpp
#include "Ring.h"
#include <string>
#include <iostream>

// Ihr Code hier:
void Ring::addNewNode(std::string beschreibung, std::string data){
    RingNode* newNode = new RingNode(0, beschreibung, data);

    //empty
    if(m_anker == nullptr){
        m_anker = newNode;
        m_anker->setNext(newNode);
        m_countNodes++;
    }

    //not full
    else if(m_countNodes < 6 && m_anker != nullptr){
        RingNode* lastNode = m_anker->getNext();
        m_anker->setNext(newNode);
        newNode->setNext (lastNode);
        m_anker = newNode;
        m_countNodes++;
    }

    //full
    else if(m_countNodes == 6 && m_anker != nullptr){
        RingNode* lastNode = m_anker->getNext();
        m_anker->setNext(newNode);
        newNode->setNext (lastNode->getNext());
        m_anker = newNode;
        delete lastNode;
    }

    //set new age for every node
    RingNode* add = m_anker->getNext();
    while (add != m_anker){
        add->setOldAge(add->getOldAge() + 1);
        add = add->getNext();
    }
}

bool Ring::search (std::string data){
    //empty
    if (m_anker == nullptr) {
        std::cout << std::endl;
        std::cout << "+ Datensatz ist leer" << std::endl;
        return false;
    }

    RingNode* search = m_anker;

    //data search
    do{
        if(search->getSymbolicData() == data){ //found
            std::cout << "+ Gefunden in Backup: Alter " << search->getOldAge() << ", Beschreibung: " << search->getDescription()
                      << ", Daten: " << search->getSymbolicData() << std::endl;
            return true;
        }
        search = search->getNext();
    }while(search != m_anker);

    //not found
    std::cout << "+ Datensatz konnte nicht gefunden werden." << std::endl;
    return false;
}

void Ring::print(){
    //if empty
    if (m_anker == nullptr) {
        std::cout << "+ Datensatz ist leer" << std::endl; 
    }
    else{
        printRecursive(m_anker->getNext());
    }
}

void Ring::printRecursive(RingNode* current){
    //if empty
    if (current == nullptr) {
        return; 
    }
    
    //youngest first till oldest
    if (current->getNext() != m_anker->getNext()) {
        printRecursive(current->getNext()); 
    }
    std::cout << "Alter: " << current->getOldAge() << ", Beschreibung: " << current->getDescription() 
              << ", Daten: " << current->getSymbolicData() << std::endl;
    std::cout << "--------------------------" << std::endl;
}
//
////////////////////////////////////