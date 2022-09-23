#pragma once
/*#include <iostream>
#include <string.h>
#include <stdio.h>
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
			string year, month, day;
			int i = 0;
			while (dateP != NULL) {
				if (i == 0) {
					year = dateP;
				}
				else if (i==1) {
					month = dateP;
				}
				else {
					day = dateP;
				}
				i++;

				dateP = strtok_s(NULL, seps, &next_token);
			}

			cout << year << endl;
			cout << month<< endl;
			cout << day << endl;

		}

};*/






