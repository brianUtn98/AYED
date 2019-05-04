#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<iostream>


using namespace std;


// Punto 1 - Definir estructuras necesarias.
/* float M[n][n];
Nodo *lista=NULL;
FILE *f;*/
const int n=6;
#define Archivo "Final 19-12-18.bin"

struct Nodo
{
float info;
Nodo *sgte;
};
// Funcion Punto 2
float cargarMatriz(FILE *f,float M[][n])
{
float buffer;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i!=j)
            {
              fread(&buffer,sizeof(float),1,f);
              M[i][j]=buffer;
            }
            else
            {
                M[i][j]=0.0;
            }
        }
    }

}
// Esta funcion es opcional
float mostrarMatriz(float M[][n])
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            cout << M[i][j] << " ";
    cout << endl;
    }
}
// Funcion auxiliar
Nodo *ObtenerUltimo(Nodo *lista)
{
        while(lista && lista->sgte)
            lista=lista->sgte;
        return lista;
}
void insertarUltimoNodo(Nodo *&lista,Nodo *&ultimo,float info)
{
Nodo *nuevo=NULL;
    nuevo->info=info;
    nuevo->sgte=NULL;
    if(lista)
        ultimo->sgte=nuevo;
    else
        lista=nuevo;
}
// Funcion Punto 3
void linealizarMatriz(Nodo *&lista,float M[][n])
{
Nodo *ultimo=NULL;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i!=j)
            {
        ultimo=ObtenerUltimo(lista);
        insertarUltimoNodo(lista,ultimo,M[i][j]);
            }
        }
    }
}
// Esta funcion es opcional
void mostrarLista(Nodo *lista)
{
    while(lista->sgte)
    {
        lista=lista->sgte;
        cout << lista->info << " ";
    }
    cout << endl;
}


int main()
{
float M[n][n];
Nodo *lista=NULL;
FILE *f;
int cantElementos=(n*n)-n;

/*
Punto 2 - Dado un archivo de (N.N)-N elementos de tipo float,
cargar una matriz cuadrada (NxN) en la triangular superior y
en la triangular inferior.
*/
f=fopen(Archivo,"rb");
cargarMatriz(f,M);
fclose(f);
getche();
mostrarMatriz(M);

/*
Punto 3 - Linealizar la matriz, utilizando una lista enlazada y la funcion
InsertarUltimoNodo(Nodo *&lista,Nodo *final,float info);
*/

linealizarMatriz(lista,M);
mostrarLista(lista);

}
