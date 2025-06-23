/*************************************************
* ADS Praktikum 1.1
* RingNode.h
* Erweiterung um Hilfsfunktionen gestattet.
*************************************************/
#pragma once
#include <string>

class RingNode{
	
private:
	//
	int m_oldAge;
	std::string m_description;
	std::string m_symbolischData;
	RingNode* m_next;
	//	
public:
	//
	RingNode() : m_oldAge(0), m_description(""), m_symbolischData(""), m_next(nullptr) {}
	RingNode(int age, std::string Beschreibung, std::string Data) : m_oldAge(age), m_description(Beschreibung), m_symbolischData(Data), m_next(nullptr) {}

	int getOldAge();
	void setOldAge(int m_setOldAge);
	
	std::string getDescription();
	void setDescription(std::string m_setDescription);

	std::string getSymbolicData();
	void setSymbolicData(std::string m_setSymbolicData);

	RingNode* getNext();
	void setNext(RingNode* m_setnext);
	//
};
