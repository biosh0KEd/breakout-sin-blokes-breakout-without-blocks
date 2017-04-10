// Efraín Girón Romero 15300102
#include "stdafx.h"
#include <iostream>
#include <Windows.h>
#include <conio.h>

using namespace std;

//Función con la que nos posiciónamos en cualquier parte del programa
//Function to move us somewhere in the console.
void gotoxy(int x, int y) {
	HANDLE hcon;
	hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X = x;
	dwPos.Y = y;
	SetConsoleCursorPosition(hcon, dwPos);
}

//Funcion para terminar el juego
//Function to end the game
void terminarJuego() {
	int a;
	gotoxy(0, 0);
	//Ciclo para borrar toda la pantalla de la consola
	//Loop to erase all the display's console
	for (int x = 0; x < 25; x++) {
			cout << "                                                                                                                                                               " << endl;
	}
	gotoxy(35, 12);
	cout << "!!!Perdiste, se acabo el juego" << endl;
	cin >> a;
	exit(0);
}

class elementoARebotar {
private:
	//Enteros x, y conrdenadas que el elemento va a tomar
	//Integers x and y are the coordenates of the element.
	//Enteros numx, numy variables que determinan el movimiento del elemento
	//Integers numx and numy are the variables used to determine the element direction
	int x, y, numx, numy;
	string mensaje = "!!Perdiste";
public:
	elementoARebotar(int a, int b, int c, int d) {
		x = a;
		y = b;
		numx = c;
		numy = d;
	}
	//Funciones para mostrar las variables.
	//Functions to show the variables
	int viewX() {
		return x;
	}
	int viewY() {
		return y;
	}
	int viewNumy() {
		return numy;
	}
	//Función para asignar el valor de la variable de movimiento en el eje y
	//Function to assign the axis y variable's value
	void setNumy(int b) {
		numy = b;
	}
	//Funcion para que el elemento rebote por la pantalla
	//Bounce function
	void rebotar()
	{
		//Condicionales que determinan el limite que tiene el elemento
		//Determinig conditions of the element's limit 
		if (x >= 78) {
			numx = -1;
		}
		if (x <= 0) {
			numx = 1;
		}
		if (y >= 24) {
			terminarJuego();
		}
		if (y <= 0) {
			numy = 1;
		}
		//Operaciones que provocan el movimiento
		//Operations that generate the movement
		x = x + numx;
		y = y + numy;
		gotoxy(x, y);
		cout << ":)";
	}
	//Función para borrar el elemento
	//Functions to erase the element
	void borrarElemento() {
		gotoxy(x, y);
		cout << "  ";
	}
};

class elementoAMover {
private:
	//Coordenadas
	//Coordenates
	int x, y;
public:
	//Función para asignar el valor de x
	//Function to assign the x coordenate's value
	void setX(int a) {
		x = a;
	}
	//Función para asignar el valor de y
	//Function to assign the y coordenate's value
	void setY(int b) {
		y = b;
	}
	//Función para mostrar el valor de y
	//Function to show the coordenate y value
	int viewX() {
		return x;
	}
	//Función para mover el elemento
	//Function to move the element
	void mover() {
		if (_kbhit()) {
			int tecla = _getch();
			//Condicionales para mover el elemento con las teclas
			//Conditions to move the element with the keywords 
			switch (tecla) {
			case 77: //Derecha Right
				x = x + 6;
				break;
			case 75: //Izquierda Left
				x = x - 6;
				break;
			}
		}
		//Condicionales para definir el limite del borde
		//Conditions to define the limit border
		if (x > 72) {
			y = 20;
			x = 0;
		}
		if (x < 0) {
			y = 20;
			x = 72;
		}
		gotoxy(x, y);
		cout << "-------";
	}
	//Función para que se borre el elemento
	//Function to erase the element from the console
	void borrarElemento() {
		gotoxy(x, y);
		cout << "        ";
	}
};

int main() 
{
	elementoARebotar Caracter(45, 20, 1, -1);
	elementoAMover Barra;
	int mx, my, rx, rNumy;
	Barra.setX(7);
	Barra.setY(20);
	bool repetir = true;
	while (repetir == true) {
		mx = Caracter.viewX();
		my = Caracter.viewY();
		rx = Barra.viewX();		
		rNumy = Caracter.viewNumy();
		//Condicionales para que rebote el elemento en la barra
		//Conditions to make the element bounce in the bar
		if (my == 19 && mx >= rx && mx <= rx + 7) {
			if (rNumy == 1) {
				Caracter.setNumy(-1);
			}
		}
		Caracter.rebotar();
		Barra.mover();
		Sleep(120);
		Caracter.borrarElemento();
		Barra.borrarElemento();
	}
	return 0;
}
