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
	char dateCS[11];

public:
	DateC() {
	}

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
			else if (i == 1) {
				month = dateP;
			}
			else {
				day = dateP;
			}
			i++;

			dateP = strtok_s(NULL, seps, &next_token);
		}
		ParseToInt(year, month, day);
	}

	void ParseToInt(string yearPTI, string monthPTI, string dayPTI) {
		int contadorY = 0; int contadorM = 0; int contadorD = 0;
		bool okey = true;

		for (int i = 0; i < yearPTI.length(); i++) {
			if (yearPTI[i] < 48 || yearPTI[i] > 57) {
				okey = false;
				cout << "Invalid Date. Sorry.\n";
				break;
			}
			else {
				okey = true;
			}
		}
		if (okey = true) {
			for (int i = 0; i < monthPTI.length(); i++) {
				if (monthPTI[i] < 48 || monthPTI[i] > 57) {
					cout << "Invalid Date. Sorry.\n";
					okey = false;
					break;
				}
				else {
					okey = true;
				}
			}
			if (okey = true) {
				for (int i = 0; i < dayPTI.length(); i++) {
					if (dayPTI[i] < 48 || dayPTI[i] > 57) {
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
					Year = stoi(yearPTI);
					Month = stoi(monthPTI);
					Day = stoi(dayPTI);
					ValidateYear();

				}
			}
		}
	}

	void ValidateYear() {
		if (Year % 4 == 0 && Year % 100 != 0 || Year % 400 == 0) {
			//cout << "El año es biciesto\n";
			ValidateMonthLY();
		}
		else {
			//cout << "no es año biciesto";
			ValidateMonth();
		}

	}
	void ValidateMonthLY() {
		if (Month < 1 || Month >= 13) {
			cout << "Invalid Date. Sorry.\n";
			//revisar que el mes corresponda
		}
		else {
			if (Month == 2) {
				//mes con 29 dias
				ValidateDayOfMonthLY();
			}
			else if (Month == 1 || Month == 3 || Month == 5 || Month == 7 || Month == 8 || Month == 10 || Month == 12) {
				//meses con 31 dias
				ValidateMonths31();
			}
			else if (Month == 4 || Month == 6 || Month == 9 || Month == 11 ) {
				//meses con 30 dias
				ValidateMonths30();

			}
		}
	}
	void ValidateMonth() {
		cout << Month << endl;
		if (Month  < 1 || Month >= 13) {
			cout << "Invalid Date.\n";
		}
		else {
			if (Month == 2) {
				//mes con 28 dias
				ValidateDayOfMonth();
			}
			else if (Month == 1 || Month == 3 || Month == 5 || Month == 7 || Month == 8 || Month == 10 || Month == 12) {
				//meses con 31 dias
				ValidateMonths31();
			}
			else if (Month == 4 || Month == 6 || Month == 9 || Month == 11) {
				//meses con 30 dias
				ValidateMonths30();

			}
		}
	}
	void ValidateDayOfMonthLY() {
		if (Day < 1 || Day > 29) {
			cout << "Invalid Date.\n";
		}
	}
	void ValidateDayOfMonth() {
		if (Day < 1 || Day > 28) {
			cout << "Invalid Date.\n";
		}
	}
	void ValidateMonths31() {
		if (Day < 1 || Day > 31) {
			cout << "Invalid Date.\n";
		}
	}
	void ValidateMonths30() {
		if (Day < 1 || Day > 30) {
			cout << "Invalid Date.\n";
		}
	}
};
