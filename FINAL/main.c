/////           INCLUDES           /////
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "BackEnd.h"

/////            MACROS            /////
#define FILASCONBORDE 20
#define COLUMNASCONBORDE 16
#define QFIGURAS 7
#define NFIGURAS 4     //Martin:Para cada rotacion posible de la pieza
#define FILASOFF 4
#define MAXID   10000

/////            TYPEDEF           /////
typedef struct {
  int i;
  int j;
} position_t;

typedef struct {
  unsigned int color;
  unsigned int LED;
  int estado;
  unsigned int ID;
  unsigned int figuras;
  position_t next_position;
} puntito_t;


puntito_t matriz_de_juego[FILASCONBORDE][COLUMNASCONBORDE];
puntito_t figuras[QFIGURAS][NFIGURAS][FILASOFF][COLUMNASCONBORDE];

enum {LIBRE,BLOQUEADO,NO_BLOQUEADO};
enum {ON,OFF};

/////          PROTOTIPOS         /////
void Generar_figuras(void);
void Generar_marco(void);
void Cargar_nueva_figura(void);

void Cargar_figura_1_1(puntito_t [FILASOFF][COLUMNASCONBORDE]);
void Cargar_figura_1_2(puntito_t [FILASOFF][COLUMNASCONBORDE]);
void Cargar_figura_1_3(puntito_t [FILASOFF][COLUMNASCONBORDE]);
void Cargar_figura_1_4(puntito_t [FILASOFF][COLUMNASCONBORDE]);

void Cargar_figura_2_1(puntito_t [FILASOFF][COLUMNASCONBORDE]);
void Cargar_figura_2_2(puntito_t [FILASOFF][COLUMNASCONBORDE]);
void Cargar_figura_2_3(puntito_t [FILASOFF][COLUMNASCONBORDE]);
void Cargar_figura_2_4(puntito_t [FILASOFF][COLUMNASCONBORDE]);

void Cargar_figura_3_1(puntito_t [FILASOFF][COLUMNASCONBORDE]);
void Cargar_figura_3_2(puntito_t [FILASOFF][COLUMNASCONBORDE]);
void Cargar_figura_3_3(puntito_t [FILASOFF][COLUMNASCONBORDE]);
void Cargar_figura_3_4(puntito_t [FILASOFF][COLUMNASCONBORDE]);

void Cargar_figura_4_1(puntito_t [FILASOFF][COLUMNASCONBORDE]);
void Cargar_figura_4_2(puntito_t [FILASOFF][COLUMNASCONBORDE]);
void Cargar_figura_4_3(puntito_t [FILASOFF][COLUMNASCONBORDE]);
void Cargar_figura_4_4(puntito_t [FILASOFF][COLUMNASCONBORDE]);

void Cargar_figura_5_1(puntito_t [FILASOFF][COLUMNASCONBORDE]);
void Cargar_figura_5_2(puntito_t [FILASOFF][COLUMNASCONBORDE]);
void Cargar_figura_5_3(puntito_t [FILASOFF][COLUMNASCONBORDE]);
void Cargar_figura_5_4(puntito_t [FILASOFF][COLUMNASCONBORDE]);

void Cargar_figura_6_1(puntito_t [FILASOFF][COLUMNASCONBORDE]);
void Cargar_figura_6_2(puntito_t [FILASOFF][COLUMNASCONBORDE]);
void Cargar_figura_6_3(puntito_t [FILASOFF][COLUMNASCONBORDE]);
void Cargar_figura_6_4(puntito_t [FILASOFF][COLUMNASCONBORDE]);

void Cargar_figura_7_1(puntito_t [FILASOFF][COLUMNASCONBORDE]);
void Cargar_figura_7_2(puntito_t [FILASOFF][COLUMNASCONBORDE]);
void Cargar_figura_7_3(puntito_t [FILASOFF][COLUMNASCONBORDE]);
void Cargar_figura_7_4(puntito_t [FILASOFF][COLUMNASCONBORDE]);

void Girar_Pieza(puntito_t m_juego[FILASCONBORDE][COLUMNASCONBORDE]);


int main(int argc, char** argv) {

  int i, j, k, l;

  Generar_marco();

  /*for(i=0;i<FILASCONBORDE;i++) {
      printf("\n");
      for(j=0;j<COLUMNASCONBORDE;j++)
      {
          if(matriz_de_juego[i][j].estado==BLOQUEADO)
              printf("|*|");
          else
              printf("   ");
      }
  }
  printf("\n\n");*/

  Generar_figuras();  //Tienen que ir antes de cargar, sino no carga nada

  /*for(k=0;k<QFIGURAS;k++) {
    printf("\n");
    for(i=0;i<FILASOFF;i++)
    {
        printf("\n");
        for(j=0;j<COLUMNASCONBORDE;j++)
        {
            if(figuras[k][0][i][j].estado==NO_BLOQUEADO)
                printf("|*|");
            else
                printf("%s", (j==0||j==(COLUMNASCONBORDE-1))?"| |":"   ");
        }
    }
    printf("\n");
  }
  printf("\n");*/



  // !!
  // Test : imprime cada figura y su version girada una vez por la derecha
  // !!
    
  position_t bloc[4];

  for(l=0;l<QFIGURAS;l++) {

      printf("\n\n\n\nPIEZA %d\n", l+1);

      for(k=0;k<NFIGURAS;k++) {

          printf("\nForma %d :\n", k+1);

          int b=0;

          for(i=0;i<FILASOFF;i++) {
              for(j=0;j<COLUMNASCONBORDE;j++) {
                  if(figuras[l][k][i][j].estado==NO_BLOQUEADO){
                      printf("|*|");
                      bloc[b].i=i+figuras[l][k][i][j].next_position.i;
                      bloc[b].j=j+figuras[l][k][i][j].next_position.j;
                      b++;
                  }
                  else
                      printf("%s", (j==0||j==(COLUMNASCONBORDE-1))?"| |":"   ");
              }
              printf("\n");
          }

          printf("\nGirada por la derecha :\n");

          for(i=0;i<FILASOFF;i++) {
              for(j=0;j<COLUMNASCONBORDE;j++) {
                  if(((i==bloc[0].i)&&(j==bloc[0].j))||
                     ((i==bloc[1].i)&&(j==bloc[1].j))||
                     ((i==bloc[2].i)&&(j==bloc[2].j))||
                     ((i==bloc[3].i)&&(j==bloc[3].j)))
                      printf("|*|");
                  else
                      printf("%s", (j==0||j==(COLUMNASCONBORDE-1))?"| |":"   ");
              }
              printf("\n");
          }

          printf("\n");

      }
      printf("\n");

  }
  printf("\n");
    
// !!
// Fin del Test
// !!



  Cargar_nueva_figura();

  /*for(i=0;i<FILASCONBORDE;i++) {
      printf("\n");
      for(j=0;j<COLUMNASCONBORDE;j++)
      {
          if(matriz_de_juego[i][j].estado==NO_BLOQUEADO)
              printf("|*|");
          if(matriz_de_juego[i][j].estado==BLOQUEADO)
              printf("| |");
          else
              printf("   ");
      }
  }*/

   // printf("\n%u\n",matriz_de_juego[0][7].ID);
   // printf("\n%u\n",matriz_de_juego[0][8].ID);
   // printf("\n%u\n",matriz_de_juego[0][9].ID);

  return (EXIT_SUCCESS);
}

/////           FUNCIONES          /////
void Cargar_nueva_figura(void){
  int i,j;
  unsigned int seed,ID;

  srand (time(NULL));  // Hay que buscar un rand "real" que sea en t de ejec
  seed = rand() % 7 ;  // NetBeans recomienda getrandom

  ID=rand()%MAXID;   //Genero un ID entre 0 y MAXID

  memcpy((void *)matriz_de_juego,(void *)(figuras+seed),sizeof(figuras[seed]));

  for(i=0;i<FILASOFF;i++) {
    for(j=0;j<COLUMNASCONBORDE;j++) {
      if(matriz_de_juego[i][j].estado==NO_BLOQUEADO)  //Le asigno el número de ID a la figura
        matriz_de_juego[i][j].ID=ID;
    }
  }
}

//Después se le puede agregar un random para el color,etc
void Generar_figuras(void){
    int i=0;
    int j=0;

    Cargar_figura_1_1(figuras[i][j++]);
    Cargar_figura_1_2(figuras[i][j++]);
    Cargar_figura_1_3(figuras[i][j++]);
    Cargar_figura_1_4(figuras[i][j++]);

    j=0;
    Cargar_figura_2_1(figuras[++i][j++]);
    Cargar_figura_2_2(figuras[i][j++]);
    Cargar_figura_2_3(figuras[i][j++]);
    Cargar_figura_2_4(figuras[i][j++]);

    j=0;
    Cargar_figura_3_1(figuras[++i][j++]);
    Cargar_figura_3_2(figuras[i][j++]);
    Cargar_figura_3_3(figuras[i][j++]);
    Cargar_figura_3_4(figuras[i][j++]);

    j=0;
    Cargar_figura_4_1(figuras[++i][j++]);
    Cargar_figura_4_2(figuras[i][j++]);
    Cargar_figura_4_3(figuras[i][j++]);
    Cargar_figura_4_4(figuras[i][j++]);

    j=0;
    Cargar_figura_5_1(figuras[++i][j++]);
    Cargar_figura_5_2(figuras[i][j++]);
    Cargar_figura_5_3(figuras[i][j++]);
    Cargar_figura_5_4(figuras[i][j++]);

    j=0;
    Cargar_figura_6_1(figuras[++i][j++]);
    Cargar_figura_6_2(figuras[i][j++]);
    Cargar_figura_6_3(figuras[i][j++]);
    Cargar_figura_6_4(figuras[i][j++]);

    j=0;
    Cargar_figura_7_1(figuras[++i][j++]);
    Cargar_figura_7_2(figuras[i][j++]);
    Cargar_figura_7_3(figuras[i][j++]);
    Cargar_figura_7_4(figuras[i][j++]);
}

void Generar_marco(void) {
    int i,j;

    /* Hay que ver si cerramos el marco en la parte superior de la pantalla ON
     * Cerrar la parte OFF  me parece al pedo*/

    for(i=0;i<FILASCONBORDE;i++)
        matriz_de_juego[i][0].estado=BLOQUEADO;

    for(i=0;i<FILASCONBORDE;i++)
        matriz_de_juego[i][COLUMNASCONBORDE-1].estado=BLOQUEADO;

    for(j=0;j<COLUMNASCONBORDE;j++)
        matriz_de_juego[0][j].estado=BLOQUEADO;

    for(j=0;j<COLUMNASCONBORDE;j++)
        matriz_de_juego[FILASCONBORDE-1][j].estado=BLOQUEADO;
}

// Figura 1
//
//               |*||*||*||*|
//
//
void Cargar_figura_1_1(puntito_t mataux[FILASOFF][COLUMNASCONBORDE]){
        mataux[1][6].estado=NO_BLOQUEADO;
        mataux[1][6].next_position.i=-1;
        mataux[1][6].next_position.j=2;

        mataux[1][7].estado=NO_BLOQUEADO;
        mataux[1][7].next_position.i=0;
        mataux[1][7].next_position.j=1;

        mataux[1][8].estado=NO_BLOQUEADO;
        mataux[1][8].next_position.i=1;
        mataux[1][8].next_position.j=0;

        mataux[1][9].estado=NO_BLOQUEADO;
        mataux[1][9].next_position.i=2;
        mataux[1][9].next_position.j=-1;
}
void Cargar_figura_1_2(puntito_t mataux[FILASOFF][COLUMNASCONBORDE]){
        mataux[0][8].estado=NO_BLOQUEADO;
        mataux[0][8].next_position.i=2;
        mataux[0][8].next_position.j=1;

        mataux[1][8].estado=NO_BLOQUEADO;
        mataux[1][8].next_position.i=1;
        mataux[1][8].next_position.j=0;

        mataux[2][8].estado=NO_BLOQUEADO;
        mataux[2][8].next_position.i=0;
        mataux[2][8].next_position.j=-1;

        mataux[3][8].estado=NO_BLOQUEADO;
        mataux[3][8].next_position.i=-1;
        mataux[3][8].next_position.j=-2;
}
void Cargar_figura_1_3(puntito_t mataux[FILASOFF][COLUMNASCONBORDE]){
        mataux[2][6].estado=NO_BLOQUEADO;
        mataux[2][6].next_position.i=-2;
        mataux[2][6].next_position.j=1;

        mataux[2][7].estado=NO_BLOQUEADO;
        mataux[2][7].next_position.i=-1;
        mataux[2][7].next_position.j=0;

        mataux[2][8].estado=NO_BLOQUEADO;
        mataux[2][8].next_position.i=0;
        mataux[2][8].next_position.j=-1;

        mataux[2][9].estado=NO_BLOQUEADO;
        mataux[2][9].next_position.i=1;
        mataux[2][9].next_position.j=-2;
}
void Cargar_figura_1_4(puntito_t mataux[FILASOFF][COLUMNASCONBORDE]){
        mataux[0][7].estado=NO_BLOQUEADO;
        mataux[0][7].next_position.i=1;
        mataux[0][7].next_position.j=-1;

        mataux[1][7].estado=NO_BLOQUEADO;
        mataux[1][7].next_position.i=0;
        mataux[1][7].next_position.j=0;

        mataux[2][7].estado=NO_BLOQUEADO;
        mataux[2][7].next_position.i=-1;
        mataux[2][7].next_position.j=1;

        mataux[3][7].estado=NO_BLOQUEADO;
        mataux[3][7].next_position.i=-2;
        mataux[3][7].next_position.j=2;
}

// Figura 2
//                  |*|
//                  |*||*||*|
//
//
void Cargar_figura_2_1(puntito_t mataux[FILASOFF][COLUMNASCONBORDE]){
        mataux[0][7].estado=NO_BLOQUEADO;
        mataux[0][7].next_position.i=0;
        mataux[0][7].next_position.j=1;

        mataux[1][7].estado=NO_BLOQUEADO;
        mataux[1][7].next_position.i=-1;
        mataux[1][7].next_position.j=2;

        mataux[1][8].estado=NO_BLOQUEADO;
        mataux[1][8].next_position.i=0;
        mataux[1][8].next_position.j=0;

        mataux[1][9].estado=NO_BLOQUEADO;
        mataux[1][9].next_position.i=1;
        mataux[1][9].next_position.j=-1;
}
void Cargar_figura_2_2(puntito_t mataux[FILASOFF][COLUMNASCONBORDE]){
        mataux[0][8].estado=NO_BLOQUEADO;
        mataux[0][8].next_position.i=1;
        mataux[0][8].next_position.j=-1;

        mataux[0][9].estado=NO_BLOQUEADO;
        mataux[0][9].next_position.i=1;
        mataux[0][9].next_position.j=0;

        mataux[1][8].estado=NO_BLOQUEADO;
        mataux[1][8].next_position.i=0;
        mataux[1][8].next_position.j=0;

        mataux[2][8].estado=NO_BLOQUEADO;
        mataux[2][8].next_position.i=0;
        mataux[2][8].next_position.j=1;
}
void Cargar_figura_2_3(puntito_t mataux[FILASOFF][COLUMNASCONBORDE]){
        mataux[1][7].estado=NO_BLOQUEADO;
        mataux[1][7].next_position.i=-1;
        mataux[1][7].next_position.j=1;

        mataux[1][8].estado=NO_BLOQUEADO;
        mataux[1][8].next_position.i=0;
        mataux[1][8].next_position.j=0;

        mataux[1][9].estado=NO_BLOQUEADO;
        mataux[1][9].next_position.i=1;
        mataux[1][9].next_position.j=-2;

        mataux[2][9].estado=NO_BLOQUEADO;
        mataux[2][9].next_position.i=0;
        mataux[2][9].next_position.j=-1;
}
void Cargar_figura_2_4(puntito_t mataux[FILASOFF][COLUMNASCONBORDE]){
        mataux[0][8].estado=NO_BLOQUEADO;
        mataux[0][8].next_position.i=0;
        mataux[0][8].next_position.j=-1;

        mataux[1][8].estado=NO_BLOQUEADO;
        mataux[1][8].next_position.i=0;
        mataux[1][8].next_position.j=0;

        mataux[2][7].estado=NO_BLOQUEADO;
        mataux[2][7].next_position.i=-1;
        mataux[2][7].next_position.j=0;

        mataux[2][8].estado=NO_BLOQUEADO;
        mataux[2][8].next_position.i=-1;
        mataux[2][8].next_position.j=1;
}

// Figura 3
//                        |*|
//                  |*||*||*|
//
//
void Cargar_figura_3_1(puntito_t mataux[FILASOFF][COLUMNASCONBORDE]){
        mataux[0][9].estado=NO_BLOQUEADO;
        mataux[0][9].next_position.i=0;
        mataux[0][9].next_position.j=-1;

        mataux[1][7].estado=NO_BLOQUEADO;
        mataux[1][7].next_position.i=1;
        mataux[1][7].next_position.j=1;

        mataux[1][8].estado=NO_BLOQUEADO;
        mataux[1][8].next_position.i=0;
        mataux[1][8].next_position.j=0;

        mataux[1][9].estado=NO_BLOQUEADO;
        mataux[1][9].next_position.i=1;
        mataux[1][9].next_position.j=0;
}
void Cargar_figura_3_2(puntito_t mataux[FILASOFF][COLUMNASCONBORDE]){
        mataux[0][8].estado=NO_BLOQUEADO;
        mataux[0][8].next_position.i=1;
        mataux[0][8].next_position.j=-1;

        mataux[1][8].estado=NO_BLOQUEADO;
        mataux[1][8].next_position.i=0;
        mataux[1][8].next_position.j=0;

        mataux[2][8].estado=NO_BLOQUEADO;
        mataux[2][8].next_position.i=0;
        mataux[2][8].next_position.j=-1;

        mataux[2][9].estado=NO_BLOQUEADO;
        mataux[2][9].next_position.i=-1;
        mataux[2][9].next_position.j=0;
}
void Cargar_figura_3_3(puntito_t mataux[FILASOFF][COLUMNASCONBORDE]){
        mataux[1][7].estado=NO_BLOQUEADO;
        mataux[1][7].next_position.i=-1;
        mataux[1][7].next_position.j=0;

        mataux[1][8].estado=NO_BLOQUEADO;
        mataux[1][8].next_position.i=0;
        mataux[1][8].next_position.j=0;

        mataux[1][9].estado=NO_BLOQUEADO;
        mataux[1][9].next_position.i=-1;
        mataux[1][9].next_position.j=-1;

        mataux[2][7].estado=NO_BLOQUEADO;
        mataux[2][7].next_position.i=0;
        mataux[2][7].next_position.j=1;
}
void Cargar_figura_3_4(puntito_t mataux[FILASOFF][COLUMNASCONBORDE]){
        mataux[0][7].estado=NO_BLOQUEADO;
        mataux[0][7].next_position.i=1;
        mataux[0][7].next_position.j=0;

        mataux[0][8].estado=NO_BLOQUEADO;
        mataux[0][8].next_position.i=0;
        mataux[0][8].next_position.j=1;

        mataux[1][8].estado=NO_BLOQUEADO;
        mataux[1][8].next_position.i=0;
        mataux[1][8].next_position.j=0;

        mataux[2][8].estado=NO_BLOQUEADO;
        mataux[2][8].next_position.i=-1;
        mataux[2][8].next_position.j=1;
}

// Figura 4
//
//                  |*||*|
//                  |*||*|
//
void Cargar_figura_4_1(puntito_t mataux[FILASOFF][COLUMNASCONBORDE]){
        mataux[0][7].estado=NO_BLOQUEADO;
        mataux[0][7].next_position.i=0;
        mataux[0][7].next_position.j=0;

        mataux[0][8].estado=NO_BLOQUEADO;
        mataux[0][8].next_position.i=0;
        mataux[0][8].next_position.j=0;

        mataux[1][7].estado=NO_BLOQUEADO;
        mataux[1][7].next_position.i=0;
        mataux[1][7].next_position.j=0;

        mataux[1][8].estado=NO_BLOQUEADO;
        mataux[1][8].next_position.i=0;
        mataux[1][8].next_position.j=0;

}
void Cargar_figura_4_2(puntito_t mataux[FILASOFF][COLUMNASCONBORDE]){
        mataux[0][7].estado=NO_BLOQUEADO;
        mataux[0][7].next_position.i=0;
        mataux[0][7].next_position.j=0;

        mataux[0][8].estado=NO_BLOQUEADO;
        mataux[0][8].next_position.i=0;
        mataux[0][8].next_position.j=0;

        mataux[1][7].estado=NO_BLOQUEADO;
        mataux[1][7].next_position.i=0;
        mataux[1][7].next_position.j=0;

        mataux[1][8].estado=NO_BLOQUEADO;
        mataux[1][8].next_position.i=0;
        mataux[1][8].next_position.j=0;

}
void Cargar_figura_4_3(puntito_t mataux[FILASOFF][COLUMNASCONBORDE]){
        mataux[0][7].estado=NO_BLOQUEADO;
        mataux[0][7].next_position.i=0;
        mataux[0][7].next_position.j=0;

        mataux[0][8].estado=NO_BLOQUEADO;
        mataux[0][8].next_position.i=0;
        mataux[0][8].next_position.j=0;

        mataux[1][7].estado=NO_BLOQUEADO;
        mataux[1][7].next_position.i=0;
        mataux[1][7].next_position.j=0;

        mataux[1][8].estado=NO_BLOQUEADO;
        mataux[1][8].next_position.i=0;
        mataux[1][8].next_position.j=0;

}
void Cargar_figura_4_4(puntito_t mataux[FILASOFF][COLUMNASCONBORDE]){
        mataux[0][7].estado=NO_BLOQUEADO;
        mataux[0][7].next_position.i=0;
        mataux[0][7].next_position.j=0;

        mataux[0][8].estado=NO_BLOQUEADO;
        mataux[0][8].next_position.i=0;
        mataux[0][8].next_position.j=0;

        mataux[1][7].estado=NO_BLOQUEADO;
        mataux[1][7].next_position.i=0;
        mataux[1][7].next_position.j=0;

        mataux[1][8].estado=NO_BLOQUEADO;
        mataux[1][8].next_position.i=0;
        mataux[1][8].next_position.j=0;

}

// Figura 5
//
//                     |*|
//                  |*||*||*|
//
void Cargar_figura_5_1(puntito_t mataux[FILASOFF][COLUMNASCONBORDE]){
        mataux[0][8].estado=NO_BLOQUEADO;
        mataux[0][8].next_position.i=0;
        mataux[0][8].next_position.j=0;

        mataux[1][7].estado=NO_BLOQUEADO;
        mataux[1][7].next_position.i=1;
        mataux[1][7].next_position.j=1;

        mataux[1][8].estado=NO_BLOQUEADO;
        mataux[1][8].next_position.i=0;
        mataux[1][8].next_position.j=0;

        mataux[1][9].estado=NO_BLOQUEADO;
        mataux[1][9].next_position.i=0;
        mataux[1][9].next_position.j=0;
}
void Cargar_figura_5_2(puntito_t mataux[FILASOFF][COLUMNASCONBORDE]){
        mataux[0][8].estado=NO_BLOQUEADO;
        mataux[0][8].next_position.i=1;
        mataux[0][8].next_position.j=-1;

        mataux[1][8].estado=NO_BLOQUEADO;
        mataux[1][8].next_position.i=0;
        mataux[1][8].next_position.j=0;

        mataux[1][9].estado=NO_BLOQUEADO;
        mataux[1][9].next_position.i=0;
        mataux[1][9].next_position.j=0;

        mataux[2][8].estado=NO_BLOQUEADO;
        mataux[2][8].next_position.i=0;
        mataux[2][8].next_position.j=0;
}
void Cargar_figura_5_3(puntito_t mataux[FILASOFF][COLUMNASCONBORDE]){
        mataux[1][7].estado=NO_BLOQUEADO;
        mataux[1][7].next_position.i=0;
        mataux[1][7].next_position.j=0;

        mataux[1][8].estado=NO_BLOQUEADO;
        mataux[1][8].next_position.i=0;
        mataux[1][8].next_position.j=0;

        mataux[1][9].estado=NO_BLOQUEADO;
        mataux[1][9].next_position.i=-1;
        mataux[1][9].next_position.j=-1;

        mataux[2][8].estado=NO_BLOQUEADO;
        mataux[2][8].next_position.i=0;
        mataux[2][8].next_position.j=0;
}
void Cargar_figura_5_4(puntito_t mataux[FILASOFF][COLUMNASCONBORDE]){
        mataux[0][8].estado=NO_BLOQUEADO;
        mataux[0][8].next_position.i=0;
        mataux[0][8].next_position.j=0;

        mataux[1][7].estado=NO_BLOQUEADO;
        mataux[1][7].next_position.i=0;
        mataux[1][7].next_position.j=0;

        mataux[1][8].estado=NO_BLOQUEADO;
        mataux[1][8].next_position.i=0;
        mataux[1][8].next_position.j=0;

        mataux[2][8].estado=NO_BLOQUEADO;
        mataux[2][8].next_position.i=-1;
        mataux[2][8].next_position.j=1;
}

// Figura 6
//
//                     |*||*|
//                  |*||*|
//
void Cargar_figura_6_1(puntito_t mataux[FILASOFF][COLUMNASCONBORDE]){
        mataux[1][8].estado=NO_BLOQUEADO;
        mataux[1][8].next_position.i=0;
        mataux[1][8].next_position.j=0;

        mataux[1][9].estado=NO_BLOQUEADO;
        mataux[1][9].next_position.i=0;
        mataux[1][9].next_position.j=-2;

        mataux[2][7].estado=NO_BLOQUEADO;
        mataux[2][7].next_position.i=-2;
        mataux[2][7].next_position.j=0;

        mataux[2][8].estado=NO_BLOQUEADO;
        mataux[2][8].next_position.i=0;
        mataux[2][8].next_position.j=0;

}
void Cargar_figura_6_2(puntito_t mataux[FILASOFF][COLUMNASCONBORDE]){
        mataux[0][7].estado=NO_BLOQUEADO;
        mataux[0][7].next_position.i=0;
        mataux[0][7].next_position.j=2;

        mataux[1][7].estado=NO_BLOQUEADO;
        mataux[1][7].next_position.i=0;
        mataux[1][7].next_position.j=0;

        mataux[1][8].estado=NO_BLOQUEADO;
        mataux[1][8].next_position.i=0;
        mataux[1][8].next_position.j=0;

        mataux[2][8].estado=NO_BLOQUEADO;
        mataux[2][8].next_position.i=-2;
        mataux[2][8].next_position.j=0;

}
void Cargar_figura_6_3(puntito_t mataux[FILASOFF][COLUMNASCONBORDE]){
        mataux[0][8].estado=NO_BLOQUEADO;
        mataux[0][8].next_position.i=0;
        mataux[0][8].next_position.j=0;

        mataux[0][9].estado=NO_BLOQUEADO;
        mataux[0][9].next_position.i=2;
        mataux[0][9].next_position.j=0;

        mataux[1][7].estado=NO_BLOQUEADO;
        mataux[1][7].next_position.i=0;
        mataux[1][7].next_position.j=2;

        mataux[1][8].estado=NO_BLOQUEADO;
        mataux[1][8].next_position.i=0;
        mataux[1][8].next_position.j=0;

}
void Cargar_figura_6_4(puntito_t mataux[FILASOFF][COLUMNASCONBORDE]){
        mataux[0][8].estado=NO_BLOQUEADO;
        mataux[0][8].next_position.i=2;
        mataux[0][8].next_position.j=0;

        mataux[1][8].estado=NO_BLOQUEADO;
        mataux[1][8].next_position.i=0;
        mataux[1][8].next_position.j=0;

        mataux[1][9].estado=NO_BLOQUEADO;
        mataux[1][9].next_position.i=0;
        mataux[1][9].next_position.j=0;

        mataux[2][9].estado=NO_BLOQUEADO;
        mataux[2][9].next_position.i=0;
        mataux[2][9].next_position.j=-2;

}

// Figura 7
//
//                  |*||*|
//                     |*||*|
//
void Cargar_figura_7_1(puntito_t mataux[FILASOFF][COLUMNASCONBORDE]){
        mataux[1][7].estado=NO_BLOQUEADO;
        mataux[1][7].next_position.i=0;
        mataux[1][7].next_position.j=0;

        mataux[1][8].estado=NO_BLOQUEADO;
        mataux[1][8].next_position.i=0;
        mataux[1][8].next_position.j=0;

        mataux[2][8].estado=NO_BLOQUEADO;
        mataux[2][8].next_position.i=-2;
        mataux[2][8].next_position.j=0;

        mataux[2][9].estado=NO_BLOQUEADO;
        mataux[2][9].next_position.i=0;
        mataux[2][9].next_position.j=-2;

}
void Cargar_figura_7_2(puntito_t mataux[FILASOFF][COLUMNASCONBORDE]){
        mataux[0][8].estado=NO_BLOQUEADO;
        mataux[0][8].next_position.i=0;
        mataux[0][8].next_position.j=0;

        mataux[1][7].estado=NO_BLOQUEADO;
        mataux[1][7].next_position.i=-1;
        mataux[1][7].next_position.j=0;

        mataux[1][8].estado=NO_BLOQUEADO;
        mataux[1][8].next_position.i=0;
        mataux[1][8].next_position.j=0;

        mataux[2][7].estado=NO_BLOQUEADO;
        mataux[2][7].next_position.i=-1;
        mataux[2][7].next_position.j=2;

}
void Cargar_figura_7_3(puntito_t mataux[FILASOFF][COLUMNASCONBORDE]){
        mataux[0][7].estado=NO_BLOQUEADO;
        mataux[0][7].next_position.i=0;
        mataux[0][7].next_position.j=2;

        mataux[0][8].estado=NO_BLOQUEADO;
        mataux[0][8].next_position.i=2;
        mataux[0][8].next_position.j=0;

        mataux[1][8].estado=NO_BLOQUEADO;
        mataux[1][8].next_position.i=0;
        mataux[1][8].next_position.j=0;

        mataux[1][9].estado=NO_BLOQUEADO;
        mataux[1][9].next_position.i=0;
        mataux[1][9].next_position.j=0;

}
void Cargar_figura_7_4(puntito_t mataux[FILASOFF][COLUMNASCONBORDE]){
        mataux[0][9].estado=NO_BLOQUEADO;
        mataux[0][9].next_position.i=1;
        mataux[0][9].next_position.j=-2;

        mataux[1][8].estado=NO_BLOQUEADO;
        mataux[1][8].next_position.i=0;
        mataux[1][8].next_position.j=0;

        mataux[1][9].estado=NO_BLOQUEADO;
        mataux[1][9].next_position.i=1;
        mataux[1][9].next_position.j=0;

        mataux[2][8].estado=NO_BLOQUEADO;
        mataux[2][8].next_position.i=0;
        mataux[2][8].next_position.j=0;

}


void Girar_Pieza(puntito_t m_juego[FILASCONBORDE][COLUMNASCONBORDE]) {

  int Puede_Girar = 1;

  int i,j;
  for (i=0;(Puede_Girar==1)&&(i<FILASCONBORDE);i++) {
    for (j=0;(Puede_Girar==1)&&(j<COLUMNASCONBORDE);j++) {
      if ((m_juego[i][j].estado==NO_BLOQUEADO)&&(m_juego[i+m_juego[i][j].next_position.i][j+m_juego[i][j].next_position.i].estado==(NO_BLOQUEADO||LIBRE)))
        Puede_Girar = 0;
    }
  }

  if (Puede_Girar) {
    for (i=0;(Puede_Girar==1)&&(i<FILASCONBORDE);i++) {
      for (j=0;(Puede_Girar==1)&&(j<COLUMNASCONBORDE);j++) {
        if (m_juego[i][j].estado==NO_BLOQUEADO) {
          puntito_t temp = m_juego[i][j];
          m_juego[i][j].color = 0;
          m_juego[i][j].LED = 0;
          m_juego[i][j].estado = LIBRE;
          m_juego[i][j].ID = 0;
          m_juego[i][j].figuras = 0;
          m_juego[i][j].next_position.i = 0;
          m_juego[i][j].next_position.j = 0;
          m_juego[i+m_juego[i][j].next_position.i][j+m_juego[i][j].next_position.i]=temp;
        }
      }
    }
  }
}
