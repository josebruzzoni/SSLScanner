#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "Scanner.h"
#include <string.h> 

Scanner crearEscaner(){
  	  Scanner escaner;
	  escaner.estadoInicial = 0;
	  escaner.estadoActual = 0;
	  escaner.matriz[0][0] = 1;
	  escaner.matriz[0][1] = 2;
	  escaner.matriz[0][2] = 0;
	  escaner.matriz[0][3] = 4;
	  escaner.matriz[0][4] = 3;
	  escaner.matriz[1][0] = 1;
	  escaner.matriz[1][1] = 1;
	  escaner.matriz[1][2] = 4;
	  escaner.matriz[1][3] = 4;
	  escaner.matriz[1][4] = 4;
	  escaner.matriz[2][0] = 4;
	  escaner.matriz[2][1] = 2;
	  escaner.matriz[2][2] = 4;
	  escaner.matriz[2][3] = 4;
	  escaner.matriz[2][4] = 4;
	  escaner.matriz[3][0] = 4;
	  escaner.matriz[3][1] = 4;
	  escaner.matriz[3][2] = 4;
	  escaner.matriz[3][3] = 4;
	  escaner.matriz[3][4] = 3;
	  escaner.matriz[4][0] = 99;
	  escaner.matriz[4][1] = 99;
	  escaner.matriz[4][2] = 99;
	  escaner.matriz[4][3] = 99;
	  escaner.matriz[4][4] = 99;
	  
	  return escaner;
}


int obtenerColumna(char c){
	int columna = 4;
	if(isupper(c) || islower(c)){
		columna = 0;
	}
	else if(isdigit(c)){
		columna = 1;
	}
	else if(c == ' '){
		columna = 2;
	}
	else if(c == EOF){
		columna = 3;
	}

	return columna;
}

Token escanear(Scanner escaner){
	char c;
	Token token = crearToken();

	while(escaner.estadoActual != 4){
		c= getchar();
		int columna = obtenerColumna(c);
		escaner.estadoActual = escaner.matriz[escaner.estadoActual][columna];
		if(escaner.estadoActual == 1 || escaner.estadoActual == 2 || escaner.estadoActual == 3 ){
			token = concatenar(token,c);
		}
	}
	
	if(c != ' '){
		ungetc(c,stdin);
	}
	if(c == EOF){
		strcpy(token.caracteres,"fdt");
		token.cantidadDeCaracteres = 3;
		token.posicion = 0;
	}
	// corregir, ultimo token no lo retorna

	return token;
}