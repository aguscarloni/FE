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
#define QFIGURAS 7
#define FILASOFF 4



typedef struct
{
    unsigned int color;
    int estado;
    unsigned int ID;
}puntito_t;


puntito_t matriz[FILASCONBORDE][COLUMNASCONBORDE];
puntito_t figuras[QFIGURAS][FILASOFF][COLUMNASCONBORDE];
enum {LIBRE,BLOQUEADO,NO_BLOQUEADO};


////             Prototipos                ////
void Generar_figuras(void);
void Generar_marco(void);
void Cargar_nueva_figura(void);

void Cargar_figura1(puntito_t **);
void Cargar_figura2(puntito_t **);
void Cargar_figura4(puntito_t **);
void Cargar_figura5(puntito_t **);
void Cargar_figura6(puntito_t **);
void Cargar_figura7(puntito_t **);


int main(int argc, char** argv) {
    

    
    Generar_marco();
  Generar_figuras();  //Tienen que ir antes de cargar, sino no carga nada
  Cargar_nueva_figura();
  

    return (EXIT_SUCCESS);
}

void Cargar_nueva_figura(void)
{
           unsigned int seed;
    srand (time(NULL)%6);  // Hay que buscar un rand "real" que sea en t de ejec
  seed = rand() % 7 + 1;
   
    
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

void Cargar_figura1(puntito_t ** mataux)
{
    
}
void Cargar_figura2(puntito_t ** mataux)
{
    
}
void Cargar_figura3(puntito_t ** mataux)
{

}
void Cargar_figura4(puntito_t ** mataux)
{
    
}
void Cargar_figura5(puntito_t ** mataux)
{
    
}
void Cargar_figura6(puntito_t **mataux)
{
    
}
void Cargar_figura7(puntito_t **mataux)
{
    
}