/*
Hacer un programa utilizando colas que contenga el siguiente menu:
1.Insertar caracter a una cola
2. Mostrar todos los elementos de una cola
3. Salir
*/
#include<iostream>
#include<conio.h>
#include<stdlib.h>

using namespace std;

struct Nodo{
char info;
Nodo *sgte;
};

char menu(){
char opcion;
cout << "[1] Insertar caracter a la cola " <<endl;
cout << "[2] Mostrar todos los elementos de la cola "<<endl;
cout << "[Esc] Salir" <<endl;
opcion=getche();

return opcion;
}

bool colaVacia(Nodo *frente)
{

    if(frente)
        return false;
    else
        return true;
}

void insertarCola(Nodo *&frente,Nodo *&fin,char dato)
{
Nodo *nuevo=new Nodo();
nuevo->info=dato;
nuevo->sgte=NULL;

    if(colaVacia(frente))
        frente=nuevo;
    else
        fin->sgte=nuevo;

    fin=nuevo;
}

void eliminarCola(Nodo *&frente,Nodo *&fin,char &dato)
{
dato=frente->info;
Nodo *aux=frente;
    if(frente==fin)
    {
        frente=NULL;
        fin=NULL;
    }
    else
        frente=frente->sgte;

    delete aux;
}

int main(){
char opcion,dato;
Nodo *frente=NULL;
Nodo *fin=NULL;
do
{
    system("cls");
    opcion=menu();
    switch(opcion)
    {
    case '1':
        system("cls");
        cout << "Inserte un caracter: ";
        cin >> dato; cout << endl;
        insertarCola(frente,fin,dato);
    break;
    case '2':
         system("cls");
        while(frente)
        {
            eliminarCola(frente,fin,dato);
            cout << dato <<endl;
        }
        getche();
    break;
    case '27':
        return 0;
    break;
    }
}
while(opcion!=27);
cout << "Cerrando programa."<<endl;
getche();
}
