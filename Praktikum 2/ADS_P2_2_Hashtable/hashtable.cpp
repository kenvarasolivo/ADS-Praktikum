#include "hashtable.h"
#include <iostream>

using namespace std;

HashTable::HashTable(int size, double threshold, int methode) 
{
	this->size = size;
    this->threshold_rehashing = threshold;
    this->m_sondierMethode = methode;
    this->elements = 0;
    this->collisionCount = 0;
    this->hashTable = new vector<int>(size, -1);
}

HashTable::~HashTable()
{
	delete hashTable;
}

int get_next_prime(int x)
{
	x = x + 1;
	bool found = true;
	while (true)
	{
		found = true;
		for (int i = 2; i <= sqrt(x); i++)
		{
			if (x % i == 0)
			{
				found = false;
				break;
			}
		}
		if (found)
		{
			return x;
		}
		x += 1;
	}
}

int get_last_prime(int x)
{
	x = x - 1;
	bool found = true;
	while (true)
	{
		found = true;
		for (int i = 2; i <= sqrt(x); i++)
		{
			if (x % i == 0)
			{
				found = false;
				break;
			}
		}
		if (found)
		{
			return x;
		}
		x -= 1;
	}
}

// Berechnung des Hashwertes 
int HashTable::hashValue(int item) 
{
	int i = 0;
	int index;

	switch (m_sondierMethode)
	{
	case (1):
		// Lineares Sondieren
		do{
		index = (item + i) % size;
		if(hashTable->at(index) != -1){
			collisionCount++;
            i++;
		}
		}while(hashTable->at(index) != -1);
		return index;
		break;
	case (2):
		// Quadr. Sondieren
		do{
		index = (item + i * i) % size;
		if(hashTable->at(index) != -1){
			collisionCount++;
            i++;
		}
		}while(hashTable->at(index) != -1);
		return index;
		break;
	case (3):
		{
			// Doppeltes Hashing
			int R = get_last_prime(size);
			do{
			index = (item + i * (R - item % R)) % size;
			if(hashTable->at(index) != -1){
				collisionCount++;
            	i++;
			}
			}while(hashTable->at(index) != -1);
			return index;
			break;
		}
	default:
		break;
	}
	return 1;
}
	

void HashTable::rehashing()
{
	int newSize = get_next_prime(size * 2);
    vector<int>* newTable = new vector<int>(newSize, -1);
    int oldSize = size;
    size = newSize;
    elements = 0;
    collisionCount = 0;
    vector<int>* oldTable = hashTable;
    hashTable = newTable;

    for (int i = 0; i < oldSize; i++) {
        if (oldTable->at(i) != -1) {
            insert(oldTable->at(i));
        }
    }
    delete oldTable;
}

int HashTable::insert(int item) 
{
	if (elements + 1 >= threshold_rehashing*size) {
        rehashing();
    }

    int index = hashValue(item);
	hashTable->at(index)= item;
	elements++;
    
    return index;
}


int HashTable::at(int i) 
{
	return hashTable->at(i);
}

int HashTable::getCollisionCount() 
{
	return this->collisionCount;
}

int HashTable::getSize() 
{
	return this->size;
}

int HashTable::getElements() 
{
	return this->elements;
}