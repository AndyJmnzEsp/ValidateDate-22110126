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
	string StringDate;
	string StringDayPluss;

public:
	DateC(int year, int month, int day) {
		year = Year;
		month = Month;
		year = Year;
	}
	DateC() {

	}

	operator const char* () {
		ostringstream formattedDate;
		formattedDate << Month << "/" << Day << "/" << Year;
		StringDate = formattedDate.str();
		return StringDate.c_str();
	}

	DateC operator ++(int) {
		DateC dateO(*this);
		(*this).Day++;
		
		if ((*this).Day > 31 && (*this).Month == 12) {
			(*this).Year++;
			(*this).Month = 1;
			(*this).Day = 1;
			cout << "\n" << (*this).Year << "/" << (*this).Month << "/" << (*this).Day << endl;
			return dateO;
		}
		else if ((*this).Month == 2 && (*this).Day == 29 && (*this).Year % 4 == 0 && (*this).Year % 100 != 0 || (*this).Year % 400 == 0) {
			(*this).Day = Day;
			(*this).Month = 02;
			(*this).Year = Year;
			cout << "\n" << (*this).Year << "/" << (*this).Month << "/" << (*this).Day << endl;
			return dateO;
		}
		else if ((*this).Day == 29 && (*this).Month == 2) {
			(*this).Day = 1;
			(*this).Month = 03;
			cout << "\n" << (*this).Year << "/" << (*this).Month << "/" << (*this).Day << endl;
			return dateO;
		}
		else if ((*this).Day == 31 && (*this).Month == 4 || (*this).Month == 6 || (*this).Month == 9 || (*this).Month == 11) {
			(*this).Day = 1;
			(*this).Month++;
			cout << "\n" << (*this).Year << "/" << (*this).Month << "/" << (*this).Day << endl;
			return dateO;
		}
		else if ((*this).Day > 31 && (*this).Month == 1 || (*this).Month == 3 || (*this).Month == 5 || (*this).Month == 7 || (*this).Month == 8 || (*this).Month == 10 || (*this).Month == 12) {
			(*this).Day = 1;
			(*this).Month++;
			cout << "\n" << (*this).Year << "/" << (*this).Month << "/" << (*this).Day << endl;
			return dateO;
		}

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
					//MenuOperators();

				}
			}
		}
	}


	void ValidateYear() {
		if (Year % 4 == 0 && Year % 100 != 0 || Year % 400 == 0) {
			ValidateMonthLY();
		}
		else {
			ValidateMonth();
		}

	}
	void ValidateMonthLY() {
		if (Month < 1 || Month >= 13) {
			cout << "Invalid Date. Sorry.\n";
		}
		else {
			if (Month == 2) {
				//mes con 29 dias
				ValidateDayOfMonthLY();
			}
			else if (Month == 1 || Month == 3 || Month == 5 || Month == 7 || Month == 8 || Month == 10 || Month == 12) {
				//meses con 31 dias
				ValidateDayOfMonth31();
			}
			else if (Month == 4 || Month == 6 || Month == 9 || Month == 11 ) {
				//meses con 30 dias
				ValidateDayOfMonth30();

			}
		}
	}
	void ValidateMonth() {
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
				ValidateDayOfMonth31();
			}
			else if (Month == 4 || Month == 6 || Month == 9 || Month == 11) {
				//meses con 30 dias
				ValidateDayOfMonth30();

			}
		}
	}
	void ValidateDayOfMonthLY() {
		if (Day < 1 || Day > 29) {
			cout << "Invalid Date.\n";
		}
		else {
			cout << "Validate Date.\n";
		}
	}
	void ValidateDayOfMonth() {
		if (Day < 1 || Day > 28) {
			cout << "Invalid Date.\n";
		}
		else {
			cout << "Validate Date.\n";
		}
	}
	void ValidateDayOfMonth31() {
		if (Day < 1 || Day > 31) {
			cout << "Invalid Date.\n";
		}		
		else {
			cout << "Validate Date.\n";
		}
	}
	void ValidateDayOfMonth30() {
		if (Day < 1 || Day > 30) {
			cout << "Invalid Date.\n";
		}
		else {
			cout << "Validate Date.\n";
		}
	}

};
