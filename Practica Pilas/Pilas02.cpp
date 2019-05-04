/*
Hacer un programa utilizando pilas que contenga el siguiente menú.
1. Insertar caracter a la pila.
2. Mostrar todos los elementos de la pila.
3. Salir.
*/
#include<iostream>
#include<conio.h>
#include<stdlib.h>

using namespace std;

struct Nodo{
char info;
Nodo *sgte;
};

char menu()
{
char opcion;
    cout << "Seleccione una opcion."<<endl;
    cout << "[1] Insertar caracter a la pila."<<endl;
    cout << "[2] Mostrar todos los elementos de la pila"<<endl;
    cout << "Esc Salir."<<endl;
    opcion=getche();
    return opcion;
}

void push(Nodo *&pila,char dato)
{
Nodo *nuevo=new Nodo();
    nuevo->info=dato;
    nuevo->sgte=pila;
    pila=nuevo;
    cout << "Dato ->"<<dato <<"<- se ha agregado satifactoriamente. "<<endl;
}

void pop(Nodo *&pila,char &dato)
{
Nodo *aux=pila;
    dato=aux->info;
    pila=aux->sgte;
    delete aux;
}

int main()
{
Nodo *pila=NULL;
char opcion;
int cantidad,j=0;
char dato;
    do
    {
    system("cls");
    opcion=menu();
        switch(opcion)
        {
        case '1':
            system("cls");
        cout << "Declare la cantidad de caracteres a ingresar: ";
        cin >> cantidad; cout <<endl;
            for(int i=0;i<cantidad;i++)
            {
                cout << "Ingrese el elemento [" <<i+1 << "]: ";
                cin >> dato; cout <<endl;
                push(pila,dato);
            }
        break;
        case '2':
            j=0;
            system("cls");
            while(pila)
            {
                pop(pila,dato);
                cout << "Elemento [" <<j+1 << "]: "<< dato <<endl;
                j++;
            }
            cout <<"Presione una tecla para continuar... "<<endl;
            getche();
        break;
        }
    }
    while(opcion!=27);
    system("cls");
    cout << "Cerrando programa... "<<endl;
    getche();
return 0;
}
