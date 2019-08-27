#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Tokens.h"
#include "Scanner.h"

int main(){
    
	Scanner escaner = crearEscaner();
    Token token = crearToken();
    int cantidadDeErrores = 0;
    int cantidadDeIdentificadores = 0;
    int cantidadDeConstantesEnteras = 0;
    token = escanear(escaner);

    while(esFDT(token)==0){
        switch (queTipoDeTokenEs(token))
        {
        case 0:
            printf("Error\n");
            cantidadDeErrores++;
            break;
        case 1:
            printf("Identificador\n");
            cantidadDeIdentificadores++;
            break;
        case 2:
            printf("Constante Entera\n");
            cantidadDeConstantesEnteras++;
            break;
        default:
		printf("asd");
            break;
        }
		token = escanear(escaner);
    }

    printf("---------------------------\n");
    printf("Totales:\n");
    printf("Identificadores %d\n",cantidadDeIdentificadores);
    printf("Constantes enteras %d\n",cantidadDeConstantesEnteras);
    printf("Errores %d\n",cantidadDeErrores);
	
    return 0;
}