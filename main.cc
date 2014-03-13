/*
 * main.cc

 *
 *  Created on: 12 mrt. 2014
 *      Author: Stef
 */
#include <iostream>     // voor: std::cin, std::cout, std::cerr
#include <fstream>      // voor: std::ostream
#include <string>       // voor: std::string
#include<map>
using namespace std;

typedef void(*pfunc)();

map<string,pfunc> functionMap;


void ping()
{
	cout << "okay" << endl;
}

void initMap()
{
	functionMap.insert(make_pair("ping",*ping));
}

int main(int argc, char *argv[])
{
	bool stoppen = false;
	initMap();
	while(!stoppen) {
	// Druk het keuzemenu af
			cout << "\nKies actie:" << endl;
			cout << "\nPing BeagleBone" << endl;
			cout << "\tStop" << endl;
	// Vraag de gebruiker om zijn keuze
	cout << "Uw keuze: " << flush;
				string  keuze = "";	cin >> keuze;
				map<string,pfunc>::const_iterator iter = functionMap.find(keuze);
				if(iter == functionMap.end()){
					cout << "\nFunctie niet gevonden, sorry." << endl;
				}
				else{
					iter->second();
				}

				//(*iter)();
	}
	return 0;
}
