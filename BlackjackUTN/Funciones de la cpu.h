# include<iostream>
# include<cstdlib>
#include<ctime>

using namespace std;

int SumarMano(int vector_nombre[], int tamanio); //suma el vector
void InicializarVectorEnCero(int vector_nombre[], int tamanio);  //inicializa el vector
void MostrarVectorSiNoEsCero(int vector_nombre[], int tamanio);  //muestra las variables del vector que no esten en 0
int BuscarElPrimerCero(int vector_nombre[], int tamanio);	//devuelve el indice del primer 0 encontrado, recorriendo del 0 a tamanio-1
void SembrarAletoriedad();	//sembrar
int CartaAleatoria();
void TomarCarta(int v[]);
void PreparacionDeLaCPU(int v[]);

