///Ejercicio:
///Autor:CHT
///Fecha:
///Comentario:

# include<iostream>
# include<cstdlib>
#include "rlutil.h"
#include "Cartas.h"
#include "Funciones esteticas.h"


using namespace std;


int main()
{
    DimensionarConsola();
    PonerFondoVerde();
    DibujarCarta(20,20);
    DibujarCarta(35,20);
	cout<<endl;
	system("pause");
	return 0;
}
