#ifndef TOKENS_H_INCLUDED
#define TOKENS_H_INCLUDED

struct Tokens{
    char* caracteres;
    int cantidadDeCaracteres;
    int posicion; 
};

typedef struct Tokens Token;

Token crearToken();
Token concatenar(Token token,char caracter);
Token nuevoToken();
int esUnCaracterDeIdentificador(char c);
int esUnCaracterDeConstanteEntera(char c);
int esIdentificador(Token token);
int esConstanteEntera(Token token);
int queTipoDeTokenEs(Token token);
int esFDT(Token token);

#endif