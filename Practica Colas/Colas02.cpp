/*
Hacer un programa con cola que almacene numeros tipo float y al finalizar declare el promedio.
*/
#include<iostream>
#include<conio.h>
#include<stdlib.h>

using namespace std;

struct Nodo{
float info;
Nodo *sgte;
};

char menu()
{
char opcion;
system("cls");
    cout << "[1] Ingresar numero a la cola."<<endl;
    cout << "[2] Mostrar cola."<<endl;
    cout << "[Esc] Salir."<<endl;
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

void cqueue(Nodo *&frente,Nodo *&fin,float dato)
{
Nodo *nuevo=new Nodo();
nuevo->info=dato;
nuevo->sgte=NULL;
    if(colaVacia(frente))
        frente=nuevo;
    else
        fin->sgte=nuevo;

    fin=nuevo;
    cout << "Dato apilado satifactoriamente. "<<endl;
}

void cdequeue(Nodo *&frente,Nodo *&fin,float &dato)
{
Nodo *aux=frente;
dato=frente->info;
    if(frente==fin)
    {
        frente=NULL;
        fin=NULL;
    }
    else
        frente=frente->sgte;
    delete aux;
}

int main()
{
Nodo *frente=NULL;
Nodo *fin=NULL;
char opcion;
int cantidad,j=0;
float dato,suma,promedio;

    do
    {
    opcion=menu();
    switch(opcion)
        {
        case '1':
            system("cls");
            cout << "Ingrese cantidad de numero a ingresar: ";
            cin >> cantidad; cout <<endl;
                for(int i=0;i<cantidad;i++)
                {
                cout << "Ingrese el dato [" << i+1 <<"]: ";
                cin >> dato; cout << endl;
                cqueue(frente,fin,dato);
                }
        break;
        case '2':
            system("cls");
            while(frente)
            {
            cdequeue(frente,fin,dato);
            suma+=dato;
            cout << "Dato nro [" << j+1 << "]: " << dato <<endl;
            j++;
            }
            promedio=suma/j;
            cout << "La suma de los numeros es: " << suma<<endl;
            cout << "El promedio es: "<< promedio <<endl;
            getche();
        break;
        }
    }
    while(opcion!=27);
}
