#ifndef SCANNER_H_INCLUDED
#define SCANNER_H_INCLUDED

#include "Tokens.h"

struct Scanner{
     int estadoInicial;
	 int estadoActual;
	 int matriz[5][5];
};

typedef struct Scanner Scanner;

Scanner crearEscaner();
int obtenerColumna(char c);
Token escanear(Scanner escaner);

#endif