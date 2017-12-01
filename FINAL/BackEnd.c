/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "BackEnd.h"

//Declaracion estructura necesaria para funciones internas
typedef struct 
{
    unsigned int x;
    unsigned int y;
}punto_t;

//Definiciones de variables 
puntito_t matriz_de_juego[FILASCONBORDE][COLUMNASCONBORDE]; //global


unsigned long int puntaje;

unsigned long int tiempo_jugado;

//Prototipos funciones internas
int bajar_bloque (void);



//********************************BAJAR BLOQUE***************************************
/* 
 * Funciona en un thread aparte que corre cada determinado tiempo para que el bloque de tetris baje.
 * Devuelve un 0 si la figura puede seguir bajando. 
 * Devuelve un 1 si la figura no puede bajar mas y en este caso se debera generar una nueva figura 
 * para que comience a bajar. SI ESTA FUNCION DEVUELVE 1 HAY QUE LLAMAR A CARGAR NUEVA FIGURA
 */

int bajar_bloque (void)
{
    //creo un puntero a la matriz de juego y me paro en la ultima posicion
    puntito_t (*pmat)[COLUMNASCONBORDE];  
    
    //Creo un arreglo de puntos donde se cuardaran las coordenadas de los bloques que hay que mover
    //Los inicializo en 0 para no generar inconvenientes despues
    punto_t arr_bajaria [4] = {{0,0},{0,0},{0,0},{0,0}};  
    
    
    unsigned int i,j;   //Incdices para moverme en la matriz
    unsigned int iarr = 0;   //Incdice para moverme en el arreglo de puntos
    unsigned char flag = 0; //Creo un flag que indica si puede o no seguir bajando la figura
    
    
    //Polleo la matriz
    for(i=(FILASCONBORDE-1);i>=0;i--)   
    {
        for(j=(COLUMNASCONBORDE-1);j>=0;j--)
        {
            if((pmat[i][j]).estado == NO_BLOQUEADO)
            {
                if((pmat[i+1][j]).estado == BLOQUEADO)  //Verifico lsi el bloque puede bajar
                {
                    (pmat[i][j]).estado = BLOQUEADO;    //si no puede, lo bloqueo
                    flag = 1;   //Seteo un flag que indica que la figura no puede bajar mas
                }
                else //Si la posicion de abajo no esta bloqueada, ese punto puede serguir bajando
                {
                    //guardo las coordenadas del bloque para que lo haga cuando termine de pollear 
                    //En caso de que el flag no este encendido
                    (arr_bajaria[iarr]).x = i;
                    (arr_bajaria[iarr]).y = j;
                    iarr++;
                    
                    (pmat[i][j]).estado = BAJARIA;
                    
                }
            }
        }
    }
    
    if(flag == 0)
    {
        unsigned int i1 = 0;    //Creo indice para moverme en el arreglo
        while (i1 < iarr)       //voy a modificar tantos bloques como se haya movido iarr
        {
            //Libero la posicion en la que estaba 
            (pmat[(arr_bajaria[i1]).x][(arr_bajaria[i1]).y]).estado = LIBRE;    
            
            //Lo posiciono en la siguiente (solo altera el x porque la columna es la misma)
            (pmat[((arr_bajaria[i1]).x)+1][(arr_bajaria[i1]).y]).estado = NO_BLOQUEADO; 
            
        }
    }
    else 
    {
        unsigned int i1 = 0;    //Creo indice para moverme en el arreglo
        while (i1 < iarr)       //voy a modificar tantos bloques como se haya movido iarr
        {
            //Bloqueo todos los puntos ya que en algun lugar no puedo bajar mas 
            (pmat[(arr_bajaria[i1]).x][(arr_bajaria[i1]).y]).estado = BLOQUEADO;    
            
        }
    }
    
    
    return flag;
}




/********************************** MOVER BLOQUE DER******************************************
 * debe ser llamada cuando en la computadora se aprietan las flechas <- o -> o el joystick se mueve lateralmente
 * no devuelve nada, simplemente se mueve si puede o no se mueve si no puede
 */

void mover_bloque_der (void)
{
    //creo un puntero a la matriz de juego y me paro en la ultima posicion
    puntito_t (*pmat)[COLUMNASCONBORDE];  
    
    //Creo un arreglo de puntos donde se cuardaran las coordenadas de los bloques que hay que mover
    //Los inicializo en 0 para no generar inconvenientes despues
    punto_t arr_moveria [4] = {{0,0},{0,0},{0,0},{0,0}};  
    
    
    unsigned int i,j;   //Incdices para moverme en la matriz
    unsigned int iarr = 0;   //Incdice para moverme en el arreglo de puntos
    unsigned int flag_mover=0;  //Flag que indica si se puede mover o no 
    
    
    //Polleo la matriz
    for(i=(FILASCONBORDE-1);i>=0;i--)   
    {
        for(j=(COLUMNASCONBORDE-1);j>=0;j--)
        {
            if((pmat[i][j]).estado == NO_BLOQUEADO)
            {
                if((pmat[i][j+1]).estado == BLOQUEADO)  //Verifico si el bloque puede moverse der
                {
                    flag_mover = 1;   //Seteo un flag que indica que la figura no puede moverse mas
                }
                else //Si la posicion del costado no esta bloqueada, ese punto puede serguir moviendose
                {
                    //guardo las coordenadas del bloque para que lo haga cuando termine de pollear 
                    //En caso de que el flag no este encendido
                    (arr_moveria[iarr]).x = i;
                    (arr_moveria[iarr]).y = j;
                    iarr++;
                    
                    (pmat[i][j]).estado = MOVERIA;
                    
                }
            }
        }
    }
    
    if(flag_mover == 0)   //Se puede desplazar
    {
        unsigned int i1 = 0;    //Creo indice para moverme en el arreglo
        while (i1 < iarr)       //voy a modificar tantos bloques como se haya movido iarr
        {
            //Libero la posicion en la que estaba 
            (pmat[(arr_moveria[i1]).x][(arr_moveria[i1]).y]).estado = LIBRE;    
            
            //Lo posiciono en la siguiente (solo altera el x porque la columna es la misma)
            (pmat[(arr_moveria[i1]).x][((arr_moveria[i1]).y)+1]).estado = NO_BLOQUEADO;  //Muevo todo hacia la derecha
            
        }
    }
   //En caso de que el flag este en 1, ningun bloque debe moverse por lo que todo sigue igual. No hace nada
    
}


/***********************************MOEVR BLOQUE IZQ***************************************/

void mover_bloque_izq (void)
{
    //creo un puntero a la matriz de juego y me paro en la ultima posicion
    puntito_t (*pmat)[COLUMNASCONBORDE];  
    
    //Creo un arreglo de puntos donde se cuardaran las coordenadas de los bloques que hay que mover
    //Los inicializo en 0 para no generar inconvenientes despues
    punto_t arr_moveria [4] = {{0,0},{0,0},{0,0},{0,0}};  
    
    
    unsigned int i,j;   //Incdices para moverme en la matriz
    unsigned int iarr = 0;   //Incdice para moverme en el arreglo de puntos
    unsigned int flag_mover=0;  //Flag que indica si se puede mover o no 
    
    
    //Polleo la matriz
    for(i=(FILASCONBORDE-1);i>=0;i--)   
    {
        for(j=(COLUMNASCONBORDE-1);j>=0;j--)
        {
            if((pmat[i][j]).estado == NO_BLOQUEADO)
            {
                if((pmat[i][j-1]).estado == BLOQUEADO)  //Verifico si el bloque puede moverse IZQ
                {
                    flag_mover = 1;   //Seteo un flag que indica que la figura no puede moverse mas
                }
                else //Si la posicion del costado no esta bloqueada, ese punto puede serguir moviendose
                {
                    //guardo las coordenadas del bloque para que lo haga cuando termine de pollear 
                    //En caso de que el flag no este encendido
                    (arr_moveria[iarr]).x = i;
                    (arr_moveria[iarr]).y = j;
                    iarr++;
                    
                    (pmat[i][j]).estado = MOVERIA;
                    
                }
            }
        }
    }
    
    if(flag_mover == 0)   //Se puede desplazar
    {
        unsigned int i1 = 0;    //Creo indice para moverme en el arreglo
        while (i1 < iarr)       //voy a modificar tantos bloques como se haya movido iarr
        {
            //Libero la posicion en la que estaba 
            (pmat[(arr_moveria[i1]).x][(arr_moveria[i1]).y]).estado = LIBRE;    
            
            //Lo posiciono en la siguiente (solo altera el x porque la columna es la misma)
            (pmat[(arr_moveria[i1]).x][((arr_moveria[i1]).y)-1]).estado = NO_BLOQUEADO;  //Muevo todo hacia la derecha
            
        }
    }
   //En caso de que el flag este en 1, ningun bloque debe moverse por lo que todo sigue igual. No hace nada
    
}