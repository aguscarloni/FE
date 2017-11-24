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



typedef struct
{
    unsigned int color;
    int estado;
    unsigned int ID;
}puntito_t;


puntito_t matriz[20][16];
puntito_t figuras[7][4][16];
enum {BLOQUEADO,LIBRE,NO_BLOQUEADO};


void Generar_figuras(int seed);
/*
 * 
 */
int main(int argc, char** argv) {
    
    unsigned int seed;
    
    srand (time(NULL)%6);  // Hay que buscar un rand "real" que sea en t de ejec
  seed = rand() % 7 + 1;

  Generar_figuras(seed);
  

    return (EXIT_SUCCESS);
}

void Generar_figuras(int seed)
{



return;
}
