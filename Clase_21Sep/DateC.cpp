#include "DateC.h"
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <sstream>
using namespace std;

class DateC {
private:
	int Day;
	int Month;
	int Year;

public:
	DateC() {}

	void Split(char dateCS[11]) {
		char* dateP;
		char seps[] = "-/";
		char* next_token = NULL;

		dateP = strtok_s(dateCS, seps, &next_token);
		string
			year, month, day;
		int i = 0;
		while (dateP != NULL) {
			if (i == 0) {
				year = dateP;
			}
			else if (i == 1) {
				month = dateP;
			}
			else {
				day = dateP;
			}
			i++;

			dateP = strtok_s(NULL, seps, &next_token);
		}

		//ahora cambiarlo a int
		ParseToInt(year, month, day);



		/*cout << year << endl;
		cout << month << endl;
		cout << day << endl;*/

	}

	void ParseToInt(string year, string month, string day) {
		int dayI = 0; int monthI = 0; int yearI = 0;
		int contadorY = 0; int contadorM = 0; int contadorD = 0;
		bool okey = true;

		for (int i = 0; i < year.length(); i++) {
			if (year[i] < 48 || year[i] > 57) {
				okey = false;
				cout << "Invalid Date. Sorry.\n";
				break;
			}
			else {
				okey = true;
			}
		}
		if (okey = true) {
			for (int i = 0; i < month.length(); i++) {
				if (month[i] < 48 || month[i] > 57) {
					cout << "Invalid Date. Sorry.\n";
					okey = false;
					break;
				}
				else {
					okey = true;
				}
			}
			if (okey = true) {
				for (int i = 0; i < day.length(); i++) {
					if (day[i] < 48 || day[i] > 57) {
						cout << "Invalid Date. Sorry.\n";
						okey = false;
						break;
					}
					else {
						okey = true;
					}
				}
				if (okey = true) {
					//validaaaaar
					cout << "a validar";
				}
			}
		}

		
		


	}



};
