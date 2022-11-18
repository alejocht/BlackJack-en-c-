#include <iostream>
#include <cstdlib>
#include <conio.h>
#include <time.h>
#include "rlutil.h"
#include "Cartas.h"
#include "Funciones de la cpu.h"
#include "Funciones esteticas.h"
#include "Menu.h"



using namespace std;
void DibujarTitulo()
{
    rlutil::cls();

    int xcolumna;
    rlutil::setColor(rlutil::YELLOW);
    rlutil::locate(1,2);
    cout<<char(201);
    rlutil::locate(1,3);
    cout<<char(186);
    rlutil::locate(1,4);
    cout<<char(200);

    for(xcolumna=2;xcolumna<=159;xcolumna++)
    {
        rlutil::locate(xcolumna,2);
        cout<<char(205);
        rlutil::locate(xcolumna,4);
        cout<<char(205);
        rlutil::msleep(20);

    }

    rlutil::locate(160,2);
    cout<<char(187);
    rlutil::locate(160,3);
    cout<<char(186);
    rlutil::locate(160,4);
    cout<<char(188);

    char vtitulo[]="*********** ¡Bienvenido al Blackjack UTN! ***********";
    int vlongitud;
    vlongitud = strlen(vtitulo);
    int vcentro=(((160-vlongitud)/2)+1);


    for(xcolumna=2;xcolumna<=vcentro;xcolumna++)
    {
        rlutil::setColor(rand()%16);
        rlutil::locate(xcolumna,3);
        if(xcolumna-1!=1)
        {
            rlutil::locate(xcolumna-1,3);
            cout<<" ";
        }
        cout<<(vtitulo);
        rlutil::msleep(20);

    }

    rlutil::locate(12,12);
    rlutil::msleep(1000);
}



void colorearOpcion (const char* texto, int posx, int posy, bool select) {

    if(select)
    {
        rlutil::setBackgroundColor(rlutil::GREEN);
        rlutil::locate(posx - 3, posy);
        cout<<" "<<(char)175 << "  " << texto <<endl;
        }
        else {
            rlutil::setBackgroundColor(rlutil::BLACK);
            rlutil::locate(posx - 3, posy);
            cout<< "    " << texto <<endl;
        }


    rlutil::locate(posx, posy);
    cout<<texto<<endl;

 rlutil::setBackgroundColor(rlutil::BLACK);


}

void InformarReglas(){
    cout<<"El popular juego de cartas llamado Blackjack proviene de otro igualmente popular y que perdura desde hace"<<endl;
    cout<<"siglos. El juego original es “La Veintiuna” o “El Veintiuno” jugado en la comunidad Hispana de Miguel de Cervantes, quien"<<endl;
    cout<<"incluyo una referencia al juego de naipes en su obra [Rinconete y Cortadillo] (1612). Su atractivo siempre lo hizo"<<endl;
    cout<<"muy comun entre la gente ya desde finales del siglo XVI. Desde aquella epoca, el juego viajo por Europa y"<<endl;
    cout<<"America, haciendo que se pudiera enriquecer con variaciones que derivaron en uno de los mayores atractivos"<<endl;
    cout<<"existentes en los casinos actuales y que tantos aficionados tiene."<<endl;
}

void InformarComoFunciona(){
    cout<<"En el blackjack, las cartas de dieces, jotas, reinas y reyes tienen un valor de 10 cada una."<<endl;
    cout<<"El objetivo es llegar a 21, o al menos quedar lo mas cerca posible sin pasarse."<<endl;
}

void MostrarMenu(bool &bandera){

    int opc = 1;
    int y = 0;

    DimensionarConsola();

    rlutil::hidecursor();

    do {

       // rlutil::cls();

        //rlutil::setBackgroundColor(rlutil::color::DARKGREY);
//        rlutil::setColor(rlutil::color::WHITE);

        rlutil::locate(50,9);
        cout<<"*********** ¡Bienvenido al Blackjack UTN! ***********"<<endl;
        rlutil::locate(50,10);
        cout<<" || Por favor, seleccione una opcion para continuar. ||"<<endl;
        rlutil::locate(60,11);
        cout<<endl;
        rlutil::locate(60,12);
        cout<<"---------------------------------"<<endl;
        colorearOpcion (" Jugar! ", 60, 14, y == 0);
        colorearOpcion (" Reglas. ", 60, 15, y == 1);
        colorearOpcion (" Como Funciona? ", 60, 16, y == 2);
        colorearOpcion (" Salir ", 60, 17, y == 3);

        rlutil::locate(60,20);
         cout<<"---------------------------------"<<endl;

         //rlutil::locate(28,14 + y);
        //cout<<(char)175 <<endl;

        int key = rlutil::getkey();

        switch(key)
        {
        case 14: // flecha de arriba
            rlutil::locate(28,14 + y);
            cout<<" " <<endl;
            y--;
            if(y < 0){
                y = 0;
            }
            break;
        case 15: // flecha de abajo
            rlutil::locate(28,14 + y);
            cout<<" " <<endl;
            y++;
            if(y > 3){
                y = 3;
            }

            break;
        case 1: // tecla enter
            switch(y){
            case 3:
                opc = 0;
                cout<<endl<<"Presione cualquier tecla para finalizar el juego. ¡Gracias!";
                getch();

                break;

                case 0:
                DibujarTitulo();
                bandera=true;
                opc = 0;
                break;

                default:
                break;
            case 2:
                rlutil::cls();
                InformarComoFunciona();
                break;

            case 1:
                rlutil::cls();
                InformarReglas();
                break;

                        }

            break;

        default:
            break;
        }


        //cout<<"Key: "<<key;
        //rlutil::anykey();
        //opc = 1;





    } while (opc != 0);

}
