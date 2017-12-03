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
    //creo un puntero a la matriz de juego 
    puntito_t (*pmat)[COLUMNASCONBORDE] = matriz_de_juego;  
    
    //Creo un arreglo de puntos donde se cuardaran las coordenadas de los bloques que hay que mover
    //Los inicializo en 0 para no generar inconvenientes despues
    punto_t arr_bajaria [4] = {{0,0},{0,0},{0,0},{0,0}};  
    
    
    unsigned int i,j;   //Incdices para moverme en la matriz
    unsigned int iarr = 0;   //Incdice para moverme en el arreglo de puntos
    unsigned char flag = 0; //Creo un flag que indica si puede o no seguir bajando la figura
    
    
    //Polleo la matriz
    for(i=(FILASCONBORDE-1);i>=0;i--)   
    {
        for(j=(COLUMNAS);j>=1;j--)  //no polleo marcos
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
    //creo un puntero a la matriz de juego 
    puntito_t (*pmat)[COLUMNASCONBORDE] = matriz_de_juego;  
    
    //Creo un arreglo de puntos donde se cuardaran las coordenadas de los bloques que hay que mover
    //Los inicializo en 0 para no generar inconvenientes despues
    punto_t arr_moveria [4] = {{0,0},{0,0},{0,0},{0,0}};  
    
    
    unsigned int i,j;   //Incdices para moverme en la matriz
    unsigned int iarr = 0;   //Incdice para moverme en el arreglo de puntos
    unsigned int flag_mover=0;  //Flag que indica si se puede mover o no 
    
    
    //Polleo la matriz
    for(i=(FILASCONBORDE-1);i>=0;i--)   
    {
        for(j=COLUMNAS;j>=1;j--)    //no polleo marcos
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
    puntito_t (*pmat)[COLUMNASCONBORDE] = matriz_de_juego;  
    
    //Creo un arreglo de puntos donde se cuardaran las coordenadas de los bloques que hay que mover
    //Los inicializo en 0 para no generar inconvenientes despues
    punto_t arr_moveria [4] = {{0,0},{0,0},{0,0},{0,0}};  
    
    
    unsigned int i,j;   //Incdices para moverme en la matriz
    unsigned int iarr = 0;   //Incdice para moverme en el arreglo de puntos
    unsigned int flag_mover=0;  //Flag que indica si se puede mover o no 
    
    
    //Polleo la matriz
    for(i=(FILASCONBORDE-1);i>=0;i--)   
    {
        for(j=(COLUMNAS);j>=1;j--)    //no polleo marcos
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



/**************************************FILA COMPLETA*********************************/
/*Funcion que verifica si una fila esta completa y corre los objetos hacia abajo.
 devuelve el puntaje obtenido por la cantidad de filas completadas*/
unsigned int fila_completa (void)
{
    //creo un puntero a la matriz de juego y me paro en la ultima posicion
    puntito_t (*pmat)[COLUMNASCONBORDE] = matriz_de_juego;  
     
    
    
    unsigned int i,j;   //Incdices para moverme en la matriz
    unsigned int puntaje = 0;  
    unsigned int contador = 0;  //contador que utilizare para chequear si toda la fila esta completa
    unsigned int fil_bajar = 0; //contador de filas que deben bajar los bloques
    unsigned int arr_fil[4]= {0,0,0,0}; //La maxima cantidad de filas que se pueden bloquear en una jugada son 4
    unsigned char iarr = 0, iarr2 = 0; //Indice para moverme en el arreglo que guardo los js
    
    
    //Polleo la matriz
    //Comienzo a pollear desde la anteultima fila porque la ultima es un marco y siempre esta completa
    for(i=(FILASCONBORDE-2);i>=0;i--)  
    {
        for(j=(COLUMNAS);j>=1;j--)    //no polleo marcos
        {
            if((pmat[i][j]).estado == BLOQUEADO)
            {
                contador++;   
            }
        }
        //Chequeo si la fila esta completamente bloqueada
        if(contador == COLUMNASCONBORDE)
        {
            fil_bajar++;
            arr_fil[iarr] = i;
            iarr++;
            puntaje +=100;  //otorgo 100 puntos por cada fila desbloqueada
        }
    }
    
    //Otorgo puntos extra por desbloquear la cantidad de  filas desbloqueadas a la vez
    puntaje *= contador;
    
    while(contador--)
    {
        //Polleo la matriz bajando los elementos que debo desde la fila indicada en el arreglo
        //en caso de que ya se haya desplazado la matriz seria necesario desplazarse de la 
        //fila indicada la cantidaad de veces que se haya movido. Se sabe que es necesario ya que 
        //Como se pollea de abajo hacia arriba, el proximo elemento del arreglo necesariamente
        //Indica una fila superior a la que se bajo y por lo tanto hay que bajarla
        for(i=arr_fil[iarr2] + iarr ;i>=0;i--)  
        {
            for(j=(COLUMNAS);j>=1;j--)    //no polleo los marcos (pos 16 y 0)
            {
                if((pmat[i][j]).estado == BLOQUEADO )    
                {
                    //si esta bloqueado lo corro hacia abajo y libero su espacio
                    (pmat[i+1][j]).estado = BLOQUEADO;
                    (pmat[i][j]).estado = LIBRE;                    
                }
                if((pmat[i][j]).estado == NO_BLOQUEADO )    
                {
                    //si esta bloqueado lo corro hacia abajo y libero su espacio
                    (pmat[i+1][j]).estado = NO_BLOQUEADO;
                    (pmat[i][j]).estado = LIBRE;                    
                }
                
                            
            
            }
        }
    }
    
    return puntaje;
}
 