#include <iostream>
#include <ctime>
#include "Cartas.h"
#include "Menu.h"
#include "Funciones de la cpu.h"
#include "Funciones esteticas.h"
#include "rlutil.h"
#include "Funciones para el jugador.h"
#include "cartas automatizadas.h"
#include "zona de mensajes.h"
using namespace std;

int Blackjack();

int main()
    {
        int opcion;
        do
        {
            Blackjack();
            cout<<"[1] reiniciar [2] salir"<<endl;
            cin>>opcion;
            switch(opcion)
            {
                case 1:
                    //sigue
                break;
                case 2:
                    cout<<"gracias por jugar"<<endl;
                    cout<<"Alejo Chavez"<<endl;
                    cout<<"Gustavo Ruiz"<<endl;
                    cout<<"Leonardo Garcia"<<endl;
                    cout<<endl;
                    system("pause");
                    return 0;
                break;
            }

        }
        while(opcion != 2);

        return 0;
    }

    int Blackjack()
    {
        //------------------------DECLARACIONES DE VARIABLES/VECTORES-----------------------------



        //declaracion de variables para los dibujos de cartas
        const int carta_cpu_ejey=8;
        int comienzo_primer_carta_j1=46;
        int comienzo_primer_carta_cpu=46;
        const int carta_j1_ejey=25;
        int cartas_dibujadas_j1=0;
        int cartas_dibujadas_cpu=0;

        //manos
        int mano_cpu[22];
        int mano_j1[22];
        InicializarVectorEnCero(mano_cpu,22);
        InicializarVectorEnCero(mano_j1,22);

        //contadores de resultado de partidas
        int contador_j1=0;
        int contador_cpu=0;
        //contador de vueltas
        int cantidad_de_vueltas=0;


        //banderas que cortan ciclos

        bool turno_del_jugador=true;
        bool partida_en_ejecucion=false;

        //------------------------PREPARANDO LA CONSOLA Y EL AMBIENTE ALEATORIO-----------------------------

        //preparo la consola
        DimensionarConsola();
        //aletoriedad
        SembrarAletoriedad();

        //------------------------COMIENZO DEL JUEGO -----------------------------

        //menu
        MostrarMenu(partida_en_ejecucion);
        BorrarPantalla();
        //inicia una partida

        while(partida_en_ejecucion && contador_cpu<3 && contador_j1<3)
        {
            cantidad_de_vueltas++;
            rlutil::hidecursor();
            //si no lo pongo en verdadero, ocasionaria que el jugador no pueda volver a jugar otra ronda
            turno_del_jugador=true;
            int comienzo_primer_carta_j1=46;
            int comienzo_primer_carta_cpu=46;
            //para que sean manos nuevas/vacias
            InicializarVectorEnCero(mano_cpu,22);
            InicializarVectorEnCero(mano_j1,22);

            //presento el escenario(fondo)
            PonerFondoVerde();
            rlutil::setColor(rlutil::WHITE);
            //se reparten(dibujan) 2 cartas a cada uno
            RepartijaInicial(carta_cpu_ejey,comienzo_primer_carta_j1, carta_j1_ejey);
            TomarCartasInicialesJugador(mano_j1);

            HacerDelay(2000);
            DibujarCarta(comienzo_primer_carta_j1, carta_j1_ejey,mano_j1[0]);
            comienzo_primer_carta_j1+=10;
            DibujarCarta(comienzo_primer_carta_j1, carta_j1_ejey,mano_j1[1]);
            cartas_dibujadas_j1=2;
            InformarManoInicial(mano_j1);
            HacerDelay(2000);

            //------------------------PARTE DEL JUGADOR -----------------------------

            while(turno_del_jugador)
            {


                //se le informa el valor de sus cartas. (en Opciones)
                //evalua si quedarse o pedir mas.(en Opciones)
                //si se queda o se pasa, se pasa el turno(roptura del while). Se encuentra dentro de opciones
                Opciones(mano_cpu, mano_j1 ,turno_del_jugador);
                RevisarSiSepaso(mano_j1,turno_del_jugador);
                //si pide, se le dibujaran mas cartas
                while(ContarCartas(mano_j1,22)>cartas_dibujadas_j1)
                {

                    AccederAlValorDeCartaYDibujarla(mano_j1,cartas_dibujadas_j1,comienzo_primer_carta_j1,carta_j1_ejey);

                }
                MostrarTotalMano(mano_j1,22);
                //si se queda o se pasa, se pasa el turno(roptura del while)


            }
            //------------------------PARTE DE LA CPU-----------------------------
            //cpu recibe sus cartas y evalua
            PreparacionDeLaCPU(mano_cpu);
            HacerDelay(1000);

            //doy vuelta las primeras dos cartas de la cpu
            DibujarCarta(comienzo_primer_carta_cpu,carta_cpu_ejey,mano_cpu[0]);
            comienzo_primer_carta_cpu+=10;
            DibujarCarta(comienzo_primer_carta_cpu,carta_cpu_ejey,mano_cpu[1]);

            cartas_dibujadas_cpu=2;
            //ya se puede definir el ganador. true para el jugador, false para el cpu
            bool ganador=GanoElJugador( mano_cpu, mano_j1);
            //si el cpu pidio, se le dibujaran sus cartas restantes
            while(ContarCartas(mano_cpu,22)>cartas_dibujadas_cpu)
            {
                AccederAlValorDeCartaYDibujarla(mano_cpu, cartas_dibujadas_cpu, comienzo_primer_carta_cpu, carta_cpu_ejey);
            }
            HacerDelay(2000);

            //se evalua  quien gano
            //se contabiliza quien gano tambien
            if(ganador)
            {
                contador_j1++;
            }
            else
            {
                contador_cpu++;
            }
            InformarResultadoPartida(mano_j1,mano_cpu);
            LimpiarYUbicar();
            cout<<"el ganador es: ";
            if(GanoElJugador(mano_cpu,mano_j1))
            {
                cout<<"jugador";
            }
            else
            {
                cout<<"cpu";
            }
            MostrarContador(contador_j1,contador_cpu);
            HacerDelay(3000);


            //se anuncia por pantalla al ganador de la ronda




            //el primero en llegar a 3 puntos, gana



        }
        //pantalla de victoria o derrota
        BorrarPantalla();


    }








