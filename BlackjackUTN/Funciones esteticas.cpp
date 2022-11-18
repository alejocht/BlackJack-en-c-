# include<iostream>
# include<cstdlib>
#include <ctime>
#include <string.h>
#include "rlutil.h"
#include "Funciones esteticas.h"

using namespace std;
//funciones para paso 2

void DimensionarConsola()
{
    system("mode con: cols=160 lines=42");
}

//funciones para paso 3

void FondoNegro()
{
    rlutil::setBackgroundColor(rlutil::BLACK);
    system("cls");
}


//funciones paso 5
void PonerFondoVerde()
{
    rlutil::setBackgroundColor(rlutil::GREEN);
    rlutil::cls();

}
void HacerDelay(int ms)
{
    rlutil::msleep(ms);
}

void informarMano(int total_j1)
{
    cout<<endl;
    cout<<" Tu mano vale "<<total_j1<<".  ¿Queres plantarte o pedir otra? "<<endl;
}

void BorrarPantalla(){
    system("cls");
}

