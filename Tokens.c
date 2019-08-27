#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "Tokens.h"

Token crearToken(){
    Token token;
    token.cantidadDeCaracteres = 10;
    token.caracteres = (char*)malloc(sizeof(char)*10);
    token.posicion = 0;
    return token;
}

Token concatenar(Token token,char caracter){
    if(token.posicion < (token.cantidadDeCaracteres-1)){
        token.caracteres[token.posicion] = caracter;
        token.caracteres[token.posicion+1]='\0';
        token.posicion++;
    }
    else{
        token.cantidadDeCaracteres = token.cantidadDeCaracteres*2;
        char* aux = (char*)malloc(sizeof(char)*token.cantidadDeCaracteres);
        for(int i=0; i<token.posicion; i++){
            aux[i]=token.caracteres[i];
        }
        aux[token.posicion]=caracter;
        aux[token.posicion+1]='\0';
        token.caracteres = aux;
        token.posicion++;
    }
    return token;
}

Token nuevoToken(){
    Token token = crearToken();
    return token;
}

int esUnCaracterDeIdentificador(char c){
    int esCaracterValido = 0;
    if(isupper(c) || islower(c) || isdigit(c)){
        esCaracterValido = 1;
    }
    return esCaracterValido;
}

int esUnCaracterDeConstanteEntera(char c){
    int esCaracterValido = 0;
    if(isdigit(c)){
        esCaracterValido = 1;
    }
    return esCaracterValido;
}

int esIdentificador(Token token){
    int identificador=1;
    for(int i=0; i<token.posicion; i++){
        if(!(esUnCaracterDeIdentificador(token.caracteres[i]))){
            identificador = 0;
        }
    }
    return identificador;
}

int esConstanteEntera(Token token){
    int identificador=1;
    for(int i=0; i<token.posicion; i++){
        if(!(esUnCaracterDeConstanteEntera(token.caracteres[i]))){
            identificador = 0;
        }
    }
    return identificador;
}

//identificador = 1, constant Entera = 2 , error = 0
int queTipoDeTokenEs(Token token){
    int tipo=0;
    if(esIdentificador(token)){
        tipo = 1;
    }
    if(esConstanteEntera(token)){
        tipo = 2;
    }
    return tipo;
}

int esFDT(Token token){
	int flag = 1;

	if( strcmp(token.caracteres,"fdt") > 0 || strcmp(token.caracteres,"fdt") < 0 ){
		flag = 0;
	}

    return flag;
}