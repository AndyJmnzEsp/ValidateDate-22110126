#include "Programa.h"
#include <iostream>
#include <string>
#include "inputManager.cpp"
using namespace std;

int main() {
	inputManager menu = inputManager();
	menu.Run();



	/*
	string a�o;

	cout << "ingrese un a�o \n";
	cin >> a�o;
	
	int year = stoi(a�o);

	//A�O BICIESTO
	if (year % 4 == 0 && year %100 != 0 || year %400 == 0) {
		//tipo de a�o
		cout << "El a�o es biciesto";
	}
	else {
		c202out << "no es a�o biciesto";
	}

	//FEBRERO

		
	Clase fecha que reciba una fecha en string  ("2022/09/21")  y se validara la fecha, que cumpla con los dias del mes
	los meses del a�o, todos sean numeros, a�os viciestos, etc.
	Para separar se usa "SLIP", separando por "/" o "-" 
	Usar variables privadas (Ya que lleva un proceso de validacion de los datos

	Unsigned int Uint 
	Date a ("")*/
}