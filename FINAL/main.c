/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: german
 *
 * Created on November 24, 2017, 11:19 AM
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/////            MACROS            /////
#define FILASCONBORDE 20
#define COLUMNASCONBORDE 16
#define FIGURAS 7
#define FILASOFF 4


typedef struct
{
    unsigned int color;
    int estado;
    unsigned int ID;
}puntito_t;


puntito_t matriz[FILASCONBORDE][COLUMNASCONBORDE];
puntito_t figuras[FIGURAS][FILASOFF][COLUMNASCONBORDE];
enum {LIBRE,BLOQUEADO,NO_BLOQUEADO};


////             Prototipos                ////
void Generar_figuras(void);
Void Generar_marco(void);
/*
 * 
 */
int main(int argc, char** argv) {
    

    
    Generar_marco();


  Generar_figuras();
  

    return (EXIT_SUCCESS);
}

void Generar_figuras(void)
{
        unsigned int seed;
    srand (time(NULL)%6);  // Hay que buscar un rand "real" que sea en t de ejec
  seed = rand() % 7 + 1;


return;
}

void Generar_marco(void)
{
    int i,j;
    
    /* Hay que ver si cerramos el marco en la parte superior de la pantalla ON
     * Cerrar la parte OFF  me parece al pedo
     * for(i=0;i<FILASCONBORDE;i++)
        matriz[i][0].estado=BLOQUEADO;
    */
    for(i=0;i<FILASCONBORDE;i++)
        matriz[i][COLUMNASCONBORDE-1].estado=BLOQUEADO;
    
    for(j=0;j<COLUMNASCONBORDE;j++)
        matriz[0][j].estado=BLOQUEADO;
    
    for(j=0;j<COLUMNASCONBORDE;j++)
        matriz[FILASCONBORDE-1][0].estado=BLOQUEADO;
    
    
    
    
}