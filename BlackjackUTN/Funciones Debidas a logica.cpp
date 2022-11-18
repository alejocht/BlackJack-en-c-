///Ejercicio:
///Autor:CHT
///Fecha:
///Comentario:

# include<iostream>
# include<cstdlib>
#include<ctime>

using namespace std;

// Pensando a una inteligencia que evalue sus decisiones para ser una buena jugadora.
// Se le empiezan repartiendo dos cartas.
// Las cartas las guardo en un vector que luego sumare.
// si la suma es mayor o igual a 18, no pide mas.
// si fuese inferior a 18, va a pedir y sumar al vector.
// si se cruza con un as, evalua si el valor del vector+11 es menor o igual a 21. Caso de que asi sea, lo tomara como un once. Si no, como un uno.

int SumarMano(int vector_nombre[], int tamanio) //Suma la mano(vector) de cualquier jugador que se le invoque.
{
    int resultado=0;
    for(int i=0;i<tamanio;i++)
    {
        resultado+=vector_nombre[i];
    }
    return resultado;
}

void InicializarVectorEnCero(int vector_nombre[], int tamanio)//limpia cualquier residuo en las variables, evitando malos calculos.
{
   for(int i=0;i<tamanio;i++)
   {
       vector_nombre[i]=0;
   }
}

void MostrarVectorSiNoEsCero(int vector_nombre[], int tamanio)//para verificar algunas cosas que quiera ver.
{
    for(int i=0;i<tamanio;i++)
    {
       if(vector_nombre[i] != 0)
       {
            cout<<vector_nombre[i]<<endl;
       }
    }
}



void SembrarAletoriedad() //recordar usar la biblioteca ctime.
{
    srand(time(0));
}


int CartaAleatoria() //dependiente de SembrarAletoriedad.Retorna un valor aleatorio.
{
   return rand()%10+1;
}

int BuscarElPrimerCero(int vector_nombre[], int tamanio) // la funcion de mostrar cual es la primer carta sin asignar valor.
{
    int contador_de_ceros = 0, posicion = 0;

    for (int i = 0; i < tamanio; i++)
    {
        if (vector_nombre[i] == 0 && contador_de_ceros == 0)
        {
            posicion = i;
            contador_de_ceros++;
        }
    }
    return posicion;
}

void MostrarVector(int v[], int tam)
{
    for (int i = 0; i < tam; i++)
    {
        cout << v[i] << endl;
    }
}

void TomarCarta(int v[])
{
    int posicion = BuscarElPrimerCero(v, 22);
    v[posicion]=CartaAleatoria();
}

void RepartirPrimerasCartas(int v[])
{
    for (int i = 0; i < 2; i++)
    {
        v[i] = CartaAleatoria();
    }
}


void PreparacionDeLaCPU(int v[]) //post declaracion del vector mano_cpu
{
    bool stand=false;
    InicializarVectorEnCero(v, 22);
    RepartirPrimerasCartas(v);
    if(SumarMano(v,22)>=18)
    {
        stand=true;
    }
    while (!stand)
    {
        TomarCarta(v);
        if(SumarMano(v,22)>=18)
        {
            stand=true;
        }
        cout<<"."<<endl;
    }


}













int main()
{
    SembrarAletoriedad();
    int mano[22];
    PreparacionDeLaCPU(mano);
    MostrarVector(mano,22);
    cout<<endl;
    system("pause");
    return 0;
}


    /*int valor_de_mano=0;
    InicializarVectorEnCero(mano,22);
    mano[0]=CartaAleatoria();
    mano[1]=CartaAleatoria();
    MostrarVectorSiNoEsCero(mano,22);
    valor_de_mano=SumarMano(mano,22);
	cout<<endl;
	cout<<"la suma del vector es "<<valor_de_mano<<endl<<endl;
	while(SumarMano(mano,22)<=18)
    {
        Pedir_Quedarse(EvaluarSiPidoOMeQuedo(valor_de_mano), mano);
        MostrarVectorSiNoEsCero(mano,22);
    }

	system("pause");
	return 0;
}
*/
