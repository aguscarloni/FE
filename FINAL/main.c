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
#include <string.h>

/////            MACROS            /////
#define FILASCONBORDE 20
#define COLUMNASCONBORDE 16
#define QFIGURAS 7
#define FILASOFF 4



typedef struct
{
    unsigned int color;
    int estado;
    unsigned int ID;
}puntito_t;


puntito_t matriz_de_juego[FILASCONBORDE][COLUMNASCONBORDE];
puntito_t figuras[QFIGURAS][FILASOFF][COLUMNASCONBORDE];
enum {LIBRE,BLOQUEADO,NO_BLOQUEADO};


////             Prototipos                ////
void Generar_figuras(void);
void Generar_marco(void);
void Cargar_nueva_figura(void);

void Cargar_figura1(puntito_t [FILASOFF][COLUMNASCONBORDE]);
void Cargar_figura2(puntito_t [FILASOFF][COLUMNASCONBORDE]);
void Cargar_figura3(puntito_t [FILASOFF][COLUMNASCONBORDE]);
void Cargar_figura4(puntito_t [FILASOFF][COLUMNASCONBORDE]);
void Cargar_figura5(puntito_t [FILASOFF][COLUMNASCONBORDE]);
void Cargar_figura6(puntito_t [FILASOFF][COLUMNASCONBORDE]);
void Cargar_figura7(puntito_t [FILASOFF][COLUMNASCONBORDE]);


int main(int argc, char** argv) {
    
    int i, j,k;
    
    Generar_marco();
    /*
    for(i=0;i<FILASCONBORDE;i++)
    {
        printf("\n");
        for(j=0;j<COLUMNASCONBORDE;j++)
        {
            if(matriz_de_juego[i][j].estado==NO_BLOQUEADO)
                printf("|*|\t");
            else 
                printf("\t");
        }
    }
       */
    
  Generar_figuras();  //Tienen que ir antes de cargar, sino no carga nada
 /*
  for(k=0;k<QFIGURAS;k++)
  {   
      printf("\n");
  for(i=0;i<FILASOFF;i++)
    {
        printf("\n");
        for(j=0;j<COLUMNASCONBORDE;j++)
        {
            if(figuras[k][i][j].estado==NO_BLOQUEADO)
                printf("|*|\t");
            else 
                printf("\t");
        }
    }
  }*/
  Cargar_nueva_figura();
      
    for(i=0;i<FILASCONBORDE;i++)
    {
        printf("\n");
        for(j=0;j<COLUMNASCONBORDE;j++)
        {
            if(matriz_de_juego[i][j].estado==NO_BLOQUEADO)
                printf("|*|\t");
            else 
                printf("\t");
        }
    }
       
  

    return (EXIT_SUCCESS);
}

void Cargar_nueva_figura(void)
{
           unsigned int seed;
    srand (time(NULL));  // Hay que buscar un rand "real" que sea en t de ejec
  seed = rand() % 7 + 1;  // NetBeans recomienda getrandom
  
  
  memcpy((void *)matriz_de_juego,(void *)(figuras+seed),sizeof(figuras[seed]));
   
    
}

//Después se le puede agregar un random para el color,etc
void Generar_figuras(void)
{
    int i=0;
    
    
    Cargar_figura1(figuras[i++]);
    Cargar_figura2(figuras[i++]);
    Cargar_figura3(figuras[i++]);
    Cargar_figura4(figuras[i++]);
    Cargar_figura5(figuras[i++]);
    Cargar_figura6(figuras[i++]);
    Cargar_figura7(figuras[i++]);

        

return;
}

void Generar_marco(void)
{
    int i,j;
    
    /* Hay que ver si cerramos el marco en la parte superior de la pantalla ON
     * Cerrar la parte OFF  me parece al pedo*/
       for(i=0;i<FILASCONBORDE;i++)
        matriz_de_juego[i][0].estado=NO_BLOQUEADO;
    
    for(i=0;i<FILASCONBORDE;i++)
        matriz_de_juego[i][COLUMNASCONBORDE-1].estado=NO_BLOQUEADO;
    
    for(j=0;j<COLUMNASCONBORDE;j++)
        matriz_de_juego[0][j].estado=NO_BLOQUEADO;
    
    for(j=0;j<COLUMNASCONBORDE;j++)
        matriz_de_juego[FILASCONBORDE-1][j].estado=NO_BLOQUEADO;
    
    
    
    
}

void Cargar_figura1(puntito_t mataux[FILASOFF][COLUMNASCONBORDE])
{
    int j;
    for(j=6;j<10;j++)
        mataux[0][j].estado=NO_BLOQUEADO;
}
void Cargar_figura2(puntito_t mataux[FILASOFF][COLUMNASCONBORDE])
{
        int j;
        mataux[0][7].estado=NO_BLOQUEADO;
        for(j=7;j<10;j++)
        mataux[1][j].estado=NO_BLOQUEADO;
}
void Cargar_figura3(puntito_t mataux[FILASOFF][COLUMNASCONBORDE])
{
        int j;
        mataux[0][9].estado=NO_BLOQUEADO;
        for(j=7;j<10;j++)
        mataux[1][j].estado=NO_BLOQUEADO;
}
void Cargar_figura4(puntito_t mataux[FILASOFF][COLUMNASCONBORDE])
{
            
        mataux[0][7].estado=NO_BLOQUEADO;
        mataux[0][8].estado=NO_BLOQUEADO;
        mataux[1][7].estado=NO_BLOQUEADO;
        mataux[1][8].estado=NO_BLOQUEADO;
        
}
void Cargar_figura5(puntito_t mataux[FILASOFF][COLUMNASCONBORDE])
{
            int j;
        mataux[0][8].estado=NO_BLOQUEADO;
        for(j=7;j<10;j++)
        mataux[1][j].estado=NO_BLOQUEADO;
}
void Cargar_figura6(puntito_t mataux[FILASOFF][COLUMNASCONBORDE])
{
        mataux[0][9].estado=NO_BLOQUEADO;
        mataux[0][8].estado=NO_BLOQUEADO;
        mataux[1][7].estado=NO_BLOQUEADO;
        mataux[1][8].estado=NO_BLOQUEADO;
        
}
void Cargar_figura7(puntito_t mataux[FILASOFF][COLUMNASCONBORDE])
{
        mataux[0][7].estado=NO_BLOQUEADO;
        mataux[0][6].estado=NO_BLOQUEADO;
        mataux[1][7].estado=NO_BLOQUEADO;
        mataux[1][8].estado=NO_BLOQUEADO;
         
}