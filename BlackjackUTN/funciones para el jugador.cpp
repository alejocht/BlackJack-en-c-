///Ejercicio:
///Autor:CHT
///Fecha:
///Comentario:

# include<iostream>
#include "Cartas.h"
#include "Menu.h"
#include "Funciones de la cpu.h"
#include "Funciones esteticas.h"
#include "rlutil.h"
#include "zona de mensajes.h"


using namespace std;

void InformarManoInicial(int mano_j1[])
{
    rlutil::locate(1,35);
    int valor_total;
    valor_total=SumarMano(mano_j1,22);
    LimpiarYUbicar();
    cout << "-----------------------------------" << endl;
    cout<<"tu mano vale "<<valor_total<<endl;
    cout << "-----------------------------------" << endl;
}

void MostrarOpciones()
{
    cout << "\t\t\t [P] Pedir otra carta \t [O] Plantarse" << endl;
}

void IngresarOpcion(char& boton_decision)
{
    cout << "elija su opcion mas adecuada:" << endl;
    cin >> boton_decision;
}

//caso 'p'
void CasoP(int mano_j1[])
{
    int valor_total;
    TomarCarta(mano_j1);
    valor_total=SumarMano(mano_j1,22);
    LimpiarYUbicar();
    UbicarEnZonaDeMensaje();
    cout << "-----------------------------------" << endl;
    cout<<"tu mano vale "<<valor_total<<endl;
    cout << "-----------------------------------" << endl;
}

//caso 'o'
void CasoO( bool &turno_del_jugador)
{
    turno_del_jugador=false;
    LimpiarYUbicar();
}

//funcion que define quien gana. Verdadero si gano el jugador, falso si gano cpu
bool GanoElJugador(int mano_cpu[],int mano_j1[]){
    int total_j1;
    int total_cpu;
    total_j1=SumarMano(mano_j1,22);
    total_cpu=SumarMano(mano_cpu,22);
    if(total_j1==21 && total_cpu != 21){
        return 1;
    }
    if(total_j1>21){
        return 0;
    }
    if(total_cpu>21 && total_j1<=21){
        return 1;
    }
    if(total_j1<21 && total_cpu<=21){
        if(total_cpu>=total_j1){
            return 0;
        }
        else{
            return 1;
        }
    }

}


void InformarResultadoPartida(int mano_j1[], int mano_cpu[])
{
    LimpiarYUbicar();
    if (GanoElJugador(mano_cpu, mano_j1))
    {

        cout << "Felicidades, ganaste!" << endl;
        rlutil::setColor(15);
    }
    else
    {
        cout << " Perdiste!" << endl;
        rlutil::setColor(15);
    }
}


void Decidir(char boton_decision, int mano_j1[], int mano_cpu[], bool &turno_del_jugador)
{
    switch (boton_decision)
    {
        case 'p':
            //tomar otra carta
            //informar el valor de mano
            CasoP(mano_j1);

        break;

        case 'o':
            //en caso que se quede, debe informar la mano de cpu e informar victoria o derrota
            CasoO(turno_del_jugador);

        break;

    }
}

void Opciones(int mano_cpu[], int mano_j1[], bool &turno_del_jugador)
{
    char boton_decision;
    MostrarOpciones();
    IngresarOpcion(boton_decision);
    Decidir(boton_decision, mano_j1, mano_cpu, turno_del_jugador);
}

void RevisarSiSepaso(int mano_j1[], bool &turno_del_jugador)
{
    int total_j1;
    total_j1=SumarMano(mano_j1,22);
    if(total_j1>21)
    {
        turno_del_jugador=false;
        HacerDelay(1000);
        LimpiarYUbicar();
        rlutil::setColor(rlutil::RED);
        cout<<"te pasaste de 21"<<endl;
        rlutil::setColor(rlutil::WHITE);
        HacerDelay(2000);
    }
}



