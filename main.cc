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
#include "ClientClick.h"
using namespace std;

typedef void(*pfunc)();

map<string,pfunc> functionMap;
ClientClick *client;

void ping()
{
	client = new ClientClick();
	cout << "okay" << endl;
	client->stuurPing();
}

void initAll()
{
	functionMap.insert(make_pair("ping",*ping));
}

int main(int argc, char *argv[])
{
	bool stoppen = false;
	initAll();
	while(!stoppen) {
	// Druk het keuzemenu af
			cout << "\nKies actie:" << endl;
			cout << "\nping: Ping BeagleBone." << endl;
			cout << "\nmessage: Stuur message." << endl;
			cout << "\tstop: Stop programma." << endl;
	// Vraag de gebruiker om zijn keuze
	cout << "Uw keuze: " << flush;
				string  keuze = "";	cin >> keuze;
				if(keuze.compare("stop")== 0)
				{
					stoppen = true;
					break;
				}
				if(keuze.compare("message")== 0)
				{
					cout << "\nStuur je eigen message:" << endl;
					string  message = "";	cin >> message;

				}
				map<string,pfunc>::const_iterator iter = functionMap.find(keuze);
				if(iter == functionMap.end()){
					cout << "\nFunctie niet gevonden, sorry." << endl;
				}
				else{
					iter->second();
				}

				//(*iter)();
	}
	cout << "Tot ziens!"<< endl;
	return 0;
}
