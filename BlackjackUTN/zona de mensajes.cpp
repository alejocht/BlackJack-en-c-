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
#include "cartas automatizadas.h"

using namespace std;

void UbicarEnZonaDeMensaje()
{
    rlutil::locate(1,32);
}

void LimpiarZonaDeMensaje()
{
    int ancho;
    int alto;
    for(int alto=32;alto<=42;alto++)
    {
        for(int ancho=1;ancho<=160;ancho++)
        {
            rlutil::locate(ancho, alto);
            cout<<" ";
        }
    }
    rlutil::locate(1,1);

}

void LimpiarYUbicar()
{
    LimpiarZonaDeMensaje();
    UbicarEnZonaDeMensaje();


}


void MostrarTotalMano(int v[], int tam)
{
    int total_parcial;
    total_parcial=SumarMano(v, tam);
    rlutil::locate(141,31);
    cout<<"Tu mano vale: "<<total_parcial;
}
void LimpiarTotalMano()
{
    for(int i=141;i<=159;i++)
    {
        cout<<" ";
    }
}

void MostrarContador(int contador_jugador, int contador_cpu)
{
    rlutil::locate(56,16);
    cout<<"J1: "<<contador_jugador<<" vs CPU: "<<contador_cpu;
}
void LimpiarContador()
{
    for(int i=141;i<=159;i++)
    {
        cout<<" ";
    }
}

