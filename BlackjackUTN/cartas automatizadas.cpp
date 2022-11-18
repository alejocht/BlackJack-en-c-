///Ejercicio:
///Autor:CHT
///Fecha:
///Comentario:

#include <iostream>
#include <ctime>
#include "Cartas.h"
#include "Menu.h"
#include "Funciones de la cpu.h"
#include "Funciones esteticas.h"
#include "rlutil.h"
#include "Funciones para el jugador.h"
#include "zona de mensajes.h"

using namespace std;

int ContarCartas(int vector_nombre[], int tamanio)
{
    int contador=0;

    for(int i=0;i<tamanio;i++)
    {
       if(vector_nombre[i] != 0)
       {
          contador++;
       }
    }

    return contador;
}
//
void AccederAlValorDeCartaYDibujarla(int v[],int &cartas_dibujadas, int &posicion_x_carta_inicio, int y)
{
    int valor_a_dibujar;
    valor_a_dibujar=v[cartas_dibujadas];
    posicion_x_carta_inicio+=10;
    DibujarCarta(posicion_x_carta_inicio, y, valor_a_dibujar);
    cartas_dibujadas++;
    LimpiarYUbicar();

}

