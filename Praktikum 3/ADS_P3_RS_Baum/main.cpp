/*************************************************
* ADS Praktikum 3
* main.cpp
*
*************************************************/
#define CATCH_CONFIG_RUNNER
#include <iostream>
#include "Tree.h"
#include "catch.h"

using namespace std;

void mainscreen_addTreeCSV(Tree*& ref)
{
	char j;
	cout << "+ Moechten Sie die Daten aus der Datei ExportZielanalyse.csv "
		"importieren(j / n) ? >";
	cin >> j;
	if (j == 'j')
	{
		ifstream csvread;
		csvread.open("ExportZielanalyse.csv", ios::in);
		if (!csvread.is_open())
		{
			cout << "Fehler beim Lesen!" << endl;
			return;
		}
		else
		{
			string name, age, postcode, income;

			while (!csvread.eof())
			{
				getline(csvread, name, ';');
				getline(csvread, age, ';');
				getline(csvread, income, ';');
				getline(csvread, postcode, '\n');
				if (name == "" || age == "" || income == "" || postcode == "") {
					continue;
				}
				ref->addNode(name, stoi(age), stod(income), stoi(postcode));
			}
			csvread.close();
		}
		cout << "+ Daten wurden dem Baum hinzugefuegt." << endl;
	}
}

void case_1(Tree*& ref){
	int Alter, plz;
	string Name;
    double Income;
	cout << "+ Bitte geben Sie die den Datensatz ein:\n"
                << "Name ?> ";
            getline(cin, Name);
            cout << "Alter ?>";
            cin >> Alter;
            cout << "Einkommen ?>";
            cin >> Income;
            cout << "PLZ ? >";
            cin >> plz;
            ref->addNode(Name, Alter, Income, plz);
            cout << "+ Ihr Datensatz wurde eingefuegt" << endl;
}
void case_3(Tree*& ref){
	string Name;
	cout << "+ Bitte geben Sie den zu suchenden Datensatz an" << endl;
            cout << " Name ?> ";
            getline(cin, Name);
            ref->searchNode(Name);
}

void case_5(Tree*& ref){
	int Niveau;
	cout << "+ Bitte geben Sie das Niveau ein\n";
	cout << "Niveau ?> ";
    cin >> Niveau;
	cin.ignore();
    ref->printLevelOrder(Niveau);
}

int main() {

	int result = Catch::Session().run();

	///////////////////////////////////////
	// Ihr Code hier:

	Tree* Baum = new Tree();
    int wahl;
    do {
        cout << "===================================\n";
        cout << " ADS-Rot-Schwarz-Baum Praktikum\n";
        cout << "===================================\n";
        cout << "1) Datensatz einfuegen, manuell\n"
             << "2) Datensatz einfuegen, CSV Datei\n"
             << "3) Suchen\n"
             << "4) Ausgabe in Levelorder\n"
             << "5) Ausgabe in Levelorder (mit Niveauauswahl)\n"
             << "6) Beenden\n"
             << "?> ";
        cin >> wahl;
		cin.ignore();
        if (wahl == 1) {
            case_1(Baum);
        }
        else if (wahl == 2) {
            mainscreen_addTreeCSV(Baum);
        }
        else if (wahl == 3) {
            case_3(Baum);
        }
        else if (wahl == 4) {
            cout << "Ausgabe in Levelorder als binärer Suchbaum :\n\n";
            Baum->printAll();
			cout << "\n";
            cout << "Ausgabe in Level order als 234-Baum:\n\n";
            Baum->printLevelOrder();;
        }
        else if (wahl == 5) {
            case_5(Baum);
        }
    }while (wahl != 6);

	//
	///////////////////////////////////////
	system("PAUSE");

	return result;
}
