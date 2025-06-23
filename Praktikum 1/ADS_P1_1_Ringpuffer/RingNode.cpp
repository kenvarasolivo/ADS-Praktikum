/*************************************************
* ADS Praktikum 1.1
* RingNode.cpp
* Erweiterung um Hilfsfunktionen gestattet.
*************************************************/
#include "RingNode.h"

////////////////////////////////////
// Ihr Code hier:
int RingNode::getOldAge(){
    return m_oldAge;
}

void RingNode::setOldAge(int m_setOldAge){
    m_oldAge = m_setOldAge;
}
	
std::string RingNode::getDescription(){
    return m_description;
}

void RingNode::setDescription(std::string m_setDescription){
    m_description = m_setDescription;
}

std::string RingNode::getSymbolicData(){
    return m_symbolischData;
}

void RingNode::setSymbolicData(std::string m_setSymbolicData){
    m_symbolischData = m_setSymbolicData;
}

RingNode* RingNode::getNext(){
    return m_next;
}

void RingNode::setNext(RingNode* m_setnext){
    m_next = m_setnext;
}
// 
////////////////////////////////////