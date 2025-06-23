#include "Tree.h"
#include "TreeNode.h"
#include <iostream>
#include <iomanip>
#include <queue>
using namespace std;

Tree::Tree()
	: m_anker{ nullptr }
	, m_CurrentNodeChronologicalID{ -1 }
{}

Tree::~Tree() {
    destroyTreeHelper(m_anker);
}

void Tree::destroyTreeHelper(TreeNode* node){
    if (node == nullptr) {
        return; 
    }
    destroyTreeHelper(node->getLeft());
    destroyTreeHelper(node->getRight());
        
    delete node;
}

/**
 * Rekursive Hilfsfunktion f�r die Suche nach einem Knoten mittels Namensvergleich.
 * Da der Name kein Alleinstellungsmerkmal ist, muss der gesamte Baum in Preorder durchlaufen und gepr�ft werden.
 * Eine Score ermittelt die Fundh�ufigkeit eines Namens.
 *
 * \param[in] node Aktueller Knoten im Baum
 * \param[in] Name String nach dem gesucht wird
 * \param[out] score Anzahl der gefundenen Knoten mit entsprechendem Namen
 */
void searchNode_RecHelper(TreeNode* node, std::string Name, int &score)
{
	if (node->getName() == Name)
	{
		node->print();
		score++;
	}
	if (node->getLeft() != nullptr)
		searchNode_RecHelper(node->getLeft(), Name, score);
	if (node->getRight() != nullptr)
		searchNode_RecHelper(node->getRight(), Name, score);
}

/**
 * Rekursive Suche nach Knoten (preorder)
 *
 * \string Name Der String der im Baum gesucht werden soll
 */
bool Tree::searchNode(std::string Name) 
{
	if (m_anker == nullptr) return false;
	
	int search_score = 0;
	searchNode_RecHelper(m_anker, Name, search_score);
	
	if(search_score > 0) return true;
	
	return false;
}


/**
 * Ausgabe aller Knoten in Tabellenform Levelorder-BST
 *
 */
void Tree::printAll() //Levelorder-BST
{
	if (m_anker == nullptr) {
        cout << "Der Baum ist leer" << endl;
        return;
    }

    int level = 0;

    queue<TreeNode*> q;
    q.push(m_anker);

    std::cout << " ID| Name\t| Age\t| Income\t| PostCode\t| OrderID\t| Level" << std::endl;
    std::cout << "---+------------+-------+---------------+---------------+---------------+------" << std::endl;


    int nodesAtCurrentLevel = 1; 

    while (!q.empty()) {
        TreeNode* node = q.front();

        cout << " " << node->getNodeChronologicalID() << "| "
             << node->getName() << "\t| "
             << node->getAge() << "\t| "
             << node->getIncome() << "\t\t| "
             << node->getPostCode() << "\t\t| "
             << node->getNodeOrderID() << " \t| "
             << level << endl;
        
        q.pop();

        // Enqueue left child
        if (node->getLeft() != nullptr) {
            q.push(node->getLeft());
        }

        // Enqueue right child
        if (node->getRight() != nullptr) {
            q.push(node->getRight());

        }
        nodesAtCurrentLevel--;

        if (nodesAtCurrentLevel == 0) {
            level++;
            nodesAtCurrentLevel = q.size();
        }
    }
}

void Tree::printLevelOrder() {
	std::queue<TreeNode*> q;
	int level = 0;

	if (m_anker == 0) {
		std::cout << "Baum ist Leer." << std::endl;
		return;
	}
	q.push(m_anker);
	TreeNode* Ptr = m_anker;
	while (!q.empty()) {
		int count = q.size();
		std::cout << "Niv. " << level << ": ";
		while (count > 0) {
			Ptr = q.front();
			if (Ptr->getLeft()) {
				//links-rot / mehrere schlussel
				if (Ptr->getLeft()->getRed()) {
					if (Ptr->getLeft()->getLeft())
						q.push(Ptr->getLeft()->getLeft());

					if (Ptr->getLeft()->getRight())
						q.push(Ptr->getLeft()->getRight());

					std::cout << "(" << Ptr->getLeft()->getNodeOrderID() << ", ";
				}
				else {
					q.push(Ptr->getLeft());
					std::cout << "(";
				}
			}
			else {
				std::cout << "(";
			}

			std::cout << Ptr->getNodeOrderID();

			if (Ptr->getRight()) {
				//rechts-rot / mehrere schlussel
				if (Ptr->getRight()->getRed()) {
					if (Ptr->getRight()->getLeft())
						q.push(Ptr->getRight()->getLeft());

					if (Ptr->getRight()->getRight())
						q.push(Ptr->getRight()->getRight());

					std::cout << ", " << Ptr->getRight()->getNodeOrderID() << ")";
				}
				else {
					q.push(Ptr->getRight());
					std::cout << ")";
				}
			}
			else
				std::cout << ")";
			q.pop();
			count--;
		}
		level++;
		std::cout << std::endl;
	}
}

void Tree::printLevelOrder(int niveau) {
	std::queue<TreeNode*> q;
	int level = 0;

	if (m_anker == 0) {
		std::cout << "Baum ist Leer." << std::endl;
		return;
	}
	q.push(m_anker);
	TreeNode* Ptr = m_anker;
	while (!q.empty()) {
		int count = q.size();
		if (level == niveau)
			std::cout << "Niveau " << level << ": ";
		while (count > 0) {
			Ptr = q.front();
			if (Ptr->getLeft()) {
				//links-rot
				if (!Ptr->getLeft()->getRed()) {
					if (Ptr->getLeft()->getLeft())
						q.push(Ptr->getLeft()->getLeft());
					if (Ptr->getLeft()->getRight())
						q.push(Ptr->getLeft()->getRight());
					if (level == niveau)
						std::cout << "(" << Ptr->getLeft()->getNodeOrderID() << ", ";
				}
				else {
					q.push(Ptr->getLeft());
					if (level == niveau){
						std::cout << "(";
					}
				}
			}
			else {
				if (level == niveau){
					std::cout << "(";
				}
			}
			if (level == niveau)
				std::cout << Ptr->getNodeOrderID();
			if (Ptr->getRight()) {
				//rechts-rot
				if (Ptr->getRight()->getRed()) {
					if (Ptr->getRight()->getLeft())
						q.push(Ptr->getRight()->getLeft());

					if (Ptr->getRight()->getRight())
						q.push(Ptr->getRight()->getRight());
					if (level == niveau)
						std::cout << ", " << Ptr->getRight()->getNodeOrderID() << ")";
				}
				else {
					q.push(Ptr->getRight());
					if (level == niveau)
						std::cout << ")";
				}
			}
			else
				if (level == niveau)
					std::cout << ")";
			q.pop();
			count--;
		}
		level++;
		std::cout <<std::endl;
	}
}

bool Tree::addNode(std::string Name, int Age, double Income, int PostCode){
	int set_id = Age + Income + PostCode;
    TreeNode* newNode = new TreeNode(set_id, ++m_CurrentNodeChronologicalID, Name, Age, Income, PostCode);
	
	//wurzel ist immer schwarz
	if(m_anker == nullptr){
		m_anker = newNode;
		m_anker->setRed(false);
		newNode->setLeft(nullptr);
    	newNode->setRight(nullptr);
		return true;
	}

	TreeNode* current = m_anker;
	TreeNode* parent = nullptr;

	while(current != nullptr){
	
		parent = current;
		//check if full/4-er then split
		split4Node(current);
		
		if(newNode->getNodeOrderID() < current->getNodeOrderID()){
            current = current->getLeft();
        }
        else{
            current = current->getRight();
        }
    }

	newNode->setParent(parent);

	if(newNode->getNodeOrderID() < parent->getNodeOrderID()){
		//set left
        parent->setLeft(newNode);
    }
    else{
		//set right
        parent->setRight(newNode);
    }

    newNode->setLeft(nullptr);
    newNode->setRight(nullptr);
	
	TreeNode* ptr = newNode;
	while(ptr->getParent() != nullptr){
		//if two red on one side then balance
        if(ptr->getParent() != nullptr && ptr->getRed() && ptr->getParent()->getRed()){
            balance(ptr->getParent());
        }
        if(ptr->getParent() != nullptr){
			ptr = ptr->getParent();
		}
    }
	
	m_anker->setRed(false);

	return true;
}

int Tree::proofRBCriterion(TreeNode* node){
	if(node == nullptr){
		return -1;
	}
	int leftHeight = 0;
    int rightHeight = 0;

	if(node->getLeft() == nullptr && node->getRight() == nullptr){
		return 0;
	}
	
	if(node->getLeft() != nullptr) leftHeight = proofRBCriterion(node->getLeft());
	if(node->getRight() != nullptr) rightHeight = proofRBCriterion(node->getRight());

	if(node->getLeft() != nullptr && node->getRight() != nullptr){
		if(node->getLeft()->getRed() && node->getRight()->getRed()){
			if(leftHeight != rightHeight) return -1;
			else return 1;
		}

		if(node->getLeft()->getRed() && !node->getRight()->getRed()){
			if(leftHeight + 1 != rightHeight) return -1;
			else return 1;
		}

		if(!node->getLeft()->getRed() && node->getRight()->getRed()){
			if(leftHeight != rightHeight + 1) return -1;
			else return 1;
		}	

		if(!node->getLeft()->getRed() && !node->getRight()->getRed()){
			if(leftHeight == rightHeight){
				return leftHeight;
			}else{
				return -1;
			}
		}
	}
		if(node->getLeft() != nullptr && node->getRight() == nullptr){
			if(node->getLeft()->getRed()){
				return leftHeight;
			}
			else{
				return leftHeight + 1;
			}
		}

		if(node->getLeft() == nullptr && node->getRight() != nullptr){
			if(node->getRight()->getRed()){
				return rightHeight;
			}
			else{
				return rightHeight + 1;
			}
		}
		return -1;
}

void Tree::balance(TreeNode* node){
	if(node->getParent() != nullptr && node->getRight() != nullptr){
		//rotate left
		if (node->getNodeOrderID() > node->getParent()->getNodeOrderID() && node->getRight()->getRed()){
			rotateTreeLeft(node->getParent());
			node->setRed(false);
			node->getLeft()->setRed(true);
			return;
		}
		//rotate left-right
		else if (node->getNodeOrderID() < node->getParent()->getNodeOrderID() && node->getRight()->getRed()){
			rotateTreeLeft(node);
			rotateTreeRight(node->getParent()->getParent());
			node->getParent()->setRed(false);
			node->getParent()->getRight()->setRed(true);
			return;
		}
	}

	if(node->getParent() != nullptr && node->getLeft() != nullptr){
		//rotate right
		if(node->getNodeOrderID() < node->getParent()->getNodeOrderID() && node->getLeft()->getRed()){
			rotateTreeRight(node->getParent());
			node->setRed(false);
			node->getRight()->setRed(true);
			return;
		}
		//rotate right-left
		else if (node->getNodeOrderID() > node->getParent()->getNodeOrderID() && node->getLeft()->getRed()){
			rotateTreeRight(node);
			rotateTreeLeft(node->getParent()->getParent());
			node->getParent()->setRed(false);
			node->getParent()->getLeft()->setRed(true);
			return;
		}
	}
}

bool Tree::split4Node(TreeNode* node){
    if (node == nullptr || node->getRed()) {
        return false;
    }

    TreeNode* leftChild = node->getLeft();
    TreeNode* rightChild = node->getRight();

	//When both child is red/4-er knoten
    if (leftChild != nullptr && rightChild != nullptr && leftChild->getRed() && rightChild->getRed()) {
        node->setRed(true);         
        leftChild->setRed(false);    
        rightChild->setRed(false);  
        return true;
    }

    return false;
}

bool Tree::rotateTreeRight(TreeNode* node){
	TreeNode* leftChild = node->getLeft();
    if (leftChild == nullptr){
		return false;
	}  
 
    node->setLeft(leftChild->getRight());
    if (leftChild->getRight() != nullptr) {
        leftChild->getRight()->setParent(node);
    }

    leftChild->setParent(node->getParent());
    if (node->getParent() == nullptr) {
        m_anker = leftChild; 
    } 
	
	//node is right child
	else if (node == node->getParent()->getRight()) {
        node->getParent()->setRight(leftChild);
    } 
	
	//node is left child
	else {
        node->getParent()->setLeft(leftChild);
    }

    leftChild->setRight(node);
    node->setParent(leftChild);
    return true;
}

bool Tree::rotateTreeLeft(TreeNode* node){
	TreeNode* rightChild = node->getRight();
    if (rightChild == nullptr){ 
		return false; 
	}

    node->setRight(rightChild->getLeft());
    if (rightChild->getLeft() != nullptr) {
        rightChild->getLeft()->setParent(node);
    }

    rightChild->setParent(node->getParent());

    if (node->getParent() == nullptr) {
        m_anker = rightChild;

	//node is left child
    } else if (node == node->getParent()->getLeft()) {
        node->getParent()->setLeft(rightChild);
    } 
	
	//node is right child
	else {
        node->getParent()->setRight(rightChild);
    }

    rightChild->setLeft(node);
    node->setParent(rightChild);
    return true;
}