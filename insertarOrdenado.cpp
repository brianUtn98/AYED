#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<conio.h>

using namespace std;

void insertarOrdenado(NodoArt *&lista,Articulo dato)
{
NodoArt *nuevo=new NodoArt();
NodoArt *paux=lista;
NodoArt *anterior=NULL;
    nuevo->info=dato;
    nuevo->sgte=NULL;

    if(!lista)
        lista=nuevo;
    else
    {
        while(paux && paux->info.CodArt<dato.CodArt)
        {
            anterior=paux;
            paux=paux->sgte;
        }
        if(paux && paux!=lista)
        {
            nuevo->sgte=anterior->sgte;
            anterior->sgte=nuevo;
        }
        else
            if(!paux)
            anterior->sgte=nuevo;
            else if(paux==lista)
                {
                nuevo->sgte=lista;
                lista=nuevo;
                }

    }
}

cargarLista(NodoArt *&lista)
{
FILE *f;
f=fopen("ArchivoArticulos.bin","rb");
Articulos buffer;
while(fread(&buffer,sizeof(Articulos),1,f))
{
    insertarOrdenado(lista,buffer);
}
}
