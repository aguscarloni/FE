/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BackEnd.h
 * Author: german
 *
 * Created on November 24, 2017, 11:51 AM
 */


#ifndef BACKEND_H
#define BACKEND_H




typedef struct
{
    unsigned int color;
    unsigned int LED;
    int estado;
    unsigned int ID; 
    
}puntito_t;


//Defines Globales necesarios
/////            MACROS            /////
#define FILASCONBORDE 20
#define COLUMNASCONBORDE 16
#define QFIGURAS 7
#define FILASOFF 4
#define MAXID   10000

enum {LIBRE,BLOQUEADO,NO_BLOQUEADO,BAJARIA,MOVERIA};
enum {ON,OFF};

//Declaraciones de variables globales
//Variables Globales
extern unsigned long int puntaje;
extern unsigned long int tiempo_jugado;
extern puntito_t matriz_de_juego[FILASCONBORDE][COLUMNASCONBORDE]; 
#endif /* BACKEND_H */

