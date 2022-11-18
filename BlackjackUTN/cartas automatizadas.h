#include <iostream>
#include <ctime>
#include "Cartas.h"
#include "Menu.h"
#include "Funciones de la cpu.h"
#include "Funciones esteticas.h"
#include "rlutil.h"
#include "Funciones para el jugador.h"

using namespace std;

int ContarCartas(int vector_nombre[], int tamanio);

void AccederAlValorDeCartaYDibujarla(int v[],int &cartas_dibujadas, int &posicion_x_carta_inicio, int y);
