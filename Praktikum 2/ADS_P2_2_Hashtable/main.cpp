#define CATCH_CONFIG_RUNNER
#include "catch.h"
#include <iostream>
#include"hashtable.h"
using namespace std;

int main() {
    Catch::Session().run();
    HashTable H(1000, 0.6, 3);

    // Seed the random number generator
    srand(std::time(0));

    // Insert 200 random numbers between 1000 and 1500
    for(int i = 0; i < 200; i++){
        // Generate a random number between 1000 and 1500 (inclusive)
        int randomNumber = 1000 + rand() % 501;
        H.insert(randomNumber);
    }
    cout << "Collision count: " << H.getCollisionCount() <<endl;
    system("pause");
    return 0;
}