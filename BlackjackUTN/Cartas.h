# include<iostream>
# include<cstdlib>
#include "rlutil.h"
#include <ctime>

using namespace std;

void SembrarAletoriedad(); //recordar usar la biblioteca ctime.
int ValorAleatorio(); //dependiente de SembrarAletoriedad.Retorna un valor aleatorio.
int PaloAleatorio(); //van en conjunto con carta aleatoria.
void ImprimirPalo(int x, int y, int PaloYaDefinido, int color_de_palo);
void DibujarRectanguloBlanco(int x, int y);
void EscribirValor(int x, int y, int color_de_palo, int valor);
void DibujarCarta(int x, int y, int valor);
void DibujarCartaOculta(int x, int y);
void RepartijaInicial(int carta_cpu_ejey, int comienzo_primer_carta, int carta_j1_ejey);
void TomarCartasInicialesJugador(int v[]);

