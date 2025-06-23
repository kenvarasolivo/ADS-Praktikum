/*************************************************
* ADS Praktikum 1.1
* Ring.h
* Erweiterung um Hilfsfunktionen gestattet.
*************************************************/
// Ring .h
#pragma once
#include <string>
#include "catch.h"
#include"RingNode.h"

class Ring{
	
	private:
		// Ihr Code hier:	
		int m_countNodes;
		RingNode* m_anker;
		//
		////////////////////////////////////
	public:
		// Ihr Code hier:
		Ring() : m_countNodes(0), m_anker(nullptr) {}
		void addNewNode(std::string beschreibung, std::string data);
		bool search (std::string data);
		void print();

		void printRecursive(RingNode* current);

		//
		////////////////////////////////////
		// friend Funktionen müssen unangetastet bleiben! 
		friend RingNode * get_anker(Ring& r);
		friend int get_countNodes(Ring& r);
};
