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

using namespace std;

//
int ValorAleatorio() //dependiente de SembrarAletoriedad.Retorna un valor aleatorio.
{
   return rand()%13+1;
}

int PaloAleatorio() //van en conjunto con carta aleatoria.
{
    int palo=rand()%4+1;
    switch(palo)
    {
        case 1:
            return 3;
        break;
        case 2:
            return 4;
        break;
        case 3:
            return 5;
        break;
        case 4:
            return 6;
        break;
    }
    return 0;
}


void ImprimirPalo(int x, int y,int PaloYaDefinido, int color_de_palo)
{
   rlutil::locate(x+3,y+2);
   rlutil::setBackgroundColor(15);
   rlutil::setColor(color_de_palo);
   cout<<char(PaloYaDefinido);
   rlutil::setBackgroundColor(0);
   rlutil::setColor(15);
}

void DibujarRectanguloBlanco(int x, int y)
{
    const int largo=6;
    const int ancho=7;
    rlutil::locate(x,y);
    rlutil::setBackgroundColor(15);
    for(int w=1;w<=largo;w++)
    {
        for(int i=1;i<=ancho;i++)
        {
            cout<<" ";
        }
        rlutil::locate(x,y++);

    }
    rlutil::setBackgroundColor(0);

}

void EscribirValor(int x,int y, int color_de_palo, int valor)
{

    rlutil::locate(x,y);
    rlutil::setBackgroundColor(15);
    rlutil::setColor(color_de_palo);
    if(valor>=2 && valor<=9)
    {
        cout<<valor;
        rlutil::locate(x+6,y+4);
        rlutil::setBackgroundColor(15);
        cout<<valor;
        rlutil::setBackgroundColor(0);
        rlutil::setColor(15);
    }

    if(valor==10)
    {
        rlutil::locate(x,y);
        rlutil::setBackgroundColor(15);
        cout<<valor;
        rlutil::setBackgroundColor(0);
        rlutil::locate(x+5,y+4);
        rlutil::setBackgroundColor(15);
        cout<<valor;
        rlutil::setBackgroundColor(0);
    }

    if(valor==1)
    {
        cout<<"A";
        rlutil::locate(x+6,y+4);
        rlutil::setBackgroundColor(15);
        cout<<"A";
        rlutil::setBackgroundColor(0);

    }

    if(valor==11)
    {
        cout<<"J";
        rlutil::locate(x+6,y+4);
        rlutil::setBackgroundColor(15);
        cout<<"J";
        rlutil::setBackgroundColor(0);

    }

    if(valor==12)
    {
        cout<<"Q";
        rlutil::locate(x+6,y+4);
        rlutil::setBackgroundColor(15);
        cout<<"Q";
        rlutil::setBackgroundColor(0);

    }

    if(valor==13)
    {
        cout<<"K";
        rlutil::locate(x+6,y+4);
        rlutil::setBackgroundColor(15);
        cout<<"K";
        rlutil::setBackgroundColor(0);

    }

}

void DibujarCarta(int x,int y, int valor)
{
    int PaloDeLamisma=PaloAleatorio();
    int Color=0;
    if(PaloDeLamisma<=4)
    {
        Color=4;
    }
    else
    {
        Color=0;
    }


    DibujarRectanguloBlanco(x,y);
    EscribirValor(x,y,Color, valor);
    ImprimirPalo(x,y,PaloDeLamisma,Color);

}

void DibujarCartaOculta(int x, int y)
{
    const int largo=6;
    const int ancho=7;
    rlutil::locate(x,y);
    rlutil::setColor(0);
    for(int w=1;w<=largo;w++)
    {
        for(int i=1;i<=ancho;i++)
        {
            rlutil::setBackgroundColor(4);
            cout<<char(178);
        }
        rlutil::locate(x,y++);

    }
    rlutil::setBackgroundColor(0);
    rlutil::setColor(15);

}

void RepartijaInicial(int carta_cpu_ejey,int comienzo_primer_carta, int carta_j1_ejey)
{
    //son guias para ver desde donde empezamos a dibujar. cada 10 caracteres horizontales, va otra carta.
    DibujarCartaOculta(comienzo_primer_carta,carta_cpu_ejey);
    DibujarCartaOculta(comienzo_primer_carta+10,carta_cpu_ejey);
    //cartas para el jugador
    DibujarCartaOculta(comienzo_primer_carta,carta_j1_ejey);
    DibujarCartaOculta(comienzo_primer_carta+10,carta_j1_ejey);

}

void TomarCartasInicialesJugador(int v[])
{
    TomarCarta(v);
    TomarCarta(v);
}



//se define un palo y se define la variable color(rojo o negro), luego EscribirValor e ImprimirPalo toman la variable Color.
//dibujar cartas con diferencia de 10 en el eje x entre carta A y carta B.

