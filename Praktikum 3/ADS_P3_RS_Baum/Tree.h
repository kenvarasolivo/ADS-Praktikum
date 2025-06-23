/*************************************************
* ADS Praktikum 3
* Tree.h
* Erweiterung um Hilfsattribute und -funktionen gestattet, wenn erforderlich.
*************************************************/
#pragma once
#include <string>
#include "TreeNode.h"
#include "catch.h"


class Tree {
	
private: 
	TreeNode * m_anker;
	int m_CurrentNodeChronologicalID;
			
public:
	Tree();
	~Tree();
		void destroyTreeHelper(TreeNode* node);
	bool addNode(std::string Name, int Age, double Income, int PostCode);	
	bool searchNode(std::string);
	void printAll();
	int proofRBCriterion(TreeNode* node);
		void printLevelOrder();
		void printLevelOrder(int niveau);
		void balance (TreeNode* node);
		bool split4Node (TreeNode* tree);
		bool rotateTreeRight (TreeNode* node);
		bool rotateTreeLeft (TreeNode* node);
		
	// friend-Funktionen sind f�r die Tests erforderlich und m�ssen unangetastet bleiben! 
	friend TreeNode * get_anker(Tree& TN);
};

void searchNode_RecHelper(TreeNode* node, std::string Name, int &score);
