#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<conio.h>

using namespace std;

struct Nodo
{
int info;
Nodo *sgte;
};

void push(Nodo *&pila,int dato)
{
Nodo *nuevo=new Nodo();
    nuevo->info=dato;
    nuevo->sgte=NULL;
    if(!pila)
        pila=nuevo;
    else
        {
        nuevo->sgte=pila;
        pila=nuevo;
        }
}

void pop(Nodo *&pila,int &dato)
{
Nodo *aux=pila;
    if(pila)
    {
        dato=aux->info;
        pila=aux->sgte;
        delete aux;
    }
}

void cqueue(Nodo *&frente,Nodo *&fin,int dato)
{
Nodo *nuevo=new Nodo();
    nuevo->info=dato;
    nuevo->sgte=NULL;
        if(!frente)
            frente=nuevo;
        else
            fin->sgte=nuevo;
        fin=nuevo;
}

void cdequeue(Nodo *&frente,Nodo *&fin,int &dato)
{
Nodo *aux=frente;
dato=aux->info;
    if(frente==fin)
    {
        frente=NULL;
        fin=NULL;
    }
    else
    {
        frente=aux->sgte;
    }
    delete aux;
}

int main()
{
Nodo *pila=NULL;
Nodo *frente=NULL;
Nodo *fin=NULL;
bool error=false;
int num,num1,num2;
int aux;
char tecla;
    cout << "Ingrese un numero: "<<endl;
    cin >> num; cout <<endl;

   aux=num;

    while(aux>0)
    {
        push(pila,aux%10);
        cqueue(frente,fin,aux%10);
        aux=aux/10;
    }

    while(pila && frente)
    {
        pop(pila,num1);
        cdequeue(frente,fin,num2);
        cout << num1 << " " <<num2 <<endl;
        if(num1!=num2)
            error=true;
    }

    if(error)
        cout << "El numero no es capicua."<<endl;
    else
        cout << "El numero es capicua."<<endl;
}
