/*
Hacer un programa que permita ingresar n valores enteros a una pila (n declarada por usuario)
y luego desapilarlos.
*/
#include<iostream>
#include<conio.h>
#include<stdlib.h>
using namespace std;

struct Nodo{
int info;
Nodo *sgte;
};

void agregarPila(Nodo *&pila,int dato)
{
Nodo *nuevo=new Nodo();
    nuevo->info=dato;
    nuevo->sgte=pila;
    pila=nuevo;
    cout << "Se ha agregado " << dato << " satifactoriamente." <<endl;
}

void desapilarPila(Nodo *&pila,int &dato)
{
Nodo *aux=pila;
    dato=aux->info;
    pila=aux->sgte;
    delete aux;
}

int main(){
int cantidad,dato;
Nodo *pila=NULL;
cout << "Digite la cantidad de nodos que desea ingresar: ";
cin >> cantidad; cout <<endl;

    for(int i=0;i<cantidad;i++)
    {
        cout << "Ingrese el dato nro [" << i+1 << "]: ";
        cin >> dato; cout << endl;
        agregarPila(pila,dato);
    }
    cout << "Presione una tecla para continuar. " <<endl;
    getche();
    system("cls");
    cout << "Desapilando pila... " <<endl;
    while(pila)
    {
        desapilarPila(pila,dato);
        cout << dato <<endl;
    }
cout << "Presione una tecla para salir." <<endl;
getche();
return 0;
}
