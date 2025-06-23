/*************************************************
* ADS Praktikum 1.1
* main.cpp
* 
*************************************************/
#define CATCH_CONFIG_RUNNER

#include <iostream>
#include <string>
#include "Ring.h"
#include "catch.h"

using namespace std;

void print_menu()
{
    cout << "====================================" << endl
        << " SuperBackUp-Organizer over 9000, by. Son Goku" << endl
        << "====================================" << endl
        << "1) Backup anlegen" << endl
        << "2) Backup suchen" << endl
        << "3) Alle Backups ausgeben" << endl
        << "4) Programm beenden" << endl
        << "?> ";
}

int main()
{
	int result = Catch::Session().run();
	// Ihr Code hier:

	int choice;
    Ring test; 

	do {
		print_menu();
		cin >> choice;
        cin.ignore();
        cout << endl;

		switch (choice) {
		    case 1: {
			    string beschreibung;
                string daten;

                cout << "Beschreibung ?> ";
                getline(cin, beschreibung);

                cout << "Daten ?> ";
                getline(cin, daten);

                test.addNewNode(beschreibung, daten);

                cout << "+Ihr Datensatz wurde hinzugefuegt.";
                cout << endl << endl << endl;
			    break;
            }
		    case 2: {
			    string daten;

                cout << "+Nach welchen Daten soll gesucht werden?";
                getline(cin, daten);
    
                test.search(daten);
                cout << endl << endl;
			    break;
            }
		    case 3: {
			    test.print();
                cout << endl << endl;
			    break;
		    }
        }
	} while (choice != 4);
	//
	///////////////////////////////////////
	system("Pause");
	return result;
}