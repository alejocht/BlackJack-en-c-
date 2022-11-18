#include <iostream>
#include <ctime>
#include "Cartas.h"
#include "Menu.h"
#include "Funciones de la cpu.h"
#include "Funciones esteticas.h"
#include "rlutil.h"
using namespace std;

void InformarManoInicial(int mano_j1[]);
void MostrarOpciones();
void IngresarOpcion(char& boton_decision);
void CasoP(int mano_j1[]);
void CasoO(bool &turno_del_jugador);
bool GanoElJugador(int mano_cpu[], int mano_j1[]);
void InformarResultadoPartida(int mano_j1[], int mano_cpu[]);
void Decidir(char boton_decision, int mano_j1[], int mano_cpu[], bool &turno_del_jugador);
void Opciones( int mano_cpu[], int mano_j1[], bool &turno_del_jugador);
void RevisarSiSepaso(int mano_j1[], bool &turno_del_jugador);
