#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<iostream>
using namespace std;

// Definicion de arbol binario
struct Nodo
{
int info;
Nodo *izq;
Nodo *der;
Nodo *padre;
};

char menu()
{
    char opcion;
    cout << "Arboles binarios." <<endl;
    cout << "---MENU---" << endl;
    cout << "1.Insertar nodos al arbol." << endl;
    cout << "2. Mostrar Arbol." <<endl;
    cout << "3. Buscar nodo. " <<endl;
    cout << "4. Pre Orden."<<endl;
    cout << "5. In Orden."<<endl;
    cout << "6. Post Orden" <<endl;
    cout << "Esc. Salir" << endl;
    opcion=getche();
    return opcion;
}

// Insertar nodos en arbol binario (de busqueda)

Nodo *crearNodo(int n,Nodo *padre) // Crear un nodo
{
Nodo *nuevo_nodo=new Nodo();
nuevo_nodo->info=n;
nuevo_nodo->der=NULL;
nuevo_nodo->izq=NULL;
nuevo_nodo->padre=padre;;
return nuevo_nodo;
}

void insertarNodo(Nodo *&arbol,int n,Nodo *padre) // Insertar un nodo ordenado.
{
Nodo *nuevo_nodo=crearNodo(n,padre);

    if(!arbol)
       arbol=nuevo_nodo;
    else
    {
        if(n<arbol->info)
        insertarNodo(arbol->izq,n,arbol);
        else
        insertarNodo(arbol->der,n,arbol);
    }

}

// Mostrar arbol

void mostrarArbol(Nodo *arbol,int contador)
{
    if(!arbol)
        return;
    else
    {
        mostrarArbol(arbol->der,contador+1);
        for(int i=0;i<contador;i++)
        cout << "  ";
        cout << arbol->info<<endl;
        mostrarArbol(arbol->izq,contador+1);
    }
}

//Buscar nodo

Nodo *buscarNodo(Nodo *arbol,int n)
{
    if(!arbol)
    return NULL;
    else if(arbol->info==n)
        return arbol;
    else if (n<arbol->info)
        return buscarNodo(arbol->izq,n);
    else
        return buscarNodo(arbol->der,n);
}

//Recorrido en PreOrden

void preOrden(Nodo *arbol)
{
    if(!arbol)
    return;
    else
    {
        cout << arbol->info<< " - ";
        preOrden(arbol->izq);
        preOrden(arbol->der);
    }



}

// Recorrido en InOrden

void inOrden(Nodo *arbol)
{
    if(!arbol)
    return;
    else
    {
    inOrden(arbol->izq);
    cout << arbol->info<< " - ";
    inOrden(arbol->der);
    }
}

void postOrden(Nodo *arbol)
{
    if(!arbol)
    return;
    else
    {
        postOrden(arbol->izq);
        postOrden(arbol->der);
        cout << arbol->info << " - ";
    }
}

//Eliminar nodo

Nodo hallarIzquierdo(Nodo *nodo)
{
   if(!arbol)
    return NULL;
   if(nodo->izq)

       return hallarIzquierdo(nodo->izq);
   else
        return nodo;
}

void reemplazar(Nodo *nodoReemplazar,Nodo *nuevoNodo)
{



}

void eliminarNodo(Nodo *nodoEliminar)
{
Nodo *izquierdo=NULL;
   if(nodoEliminar->der && nodoEliminar->izq) // Tiene dos hijos
   {
       izquierdo=hallarIzquierdo(nodoEliminar);
       nodoEliminar->info=izquierdo->info;
       eliminarNodo(izquierdo);
   }
   else if(nodoEliminar->izq)


}

void eliminar(Nodo *Arbol,int n)
{
    if(!arbol)
        return;
    else if(n < arbol->info)
        eliminar(arbol->izq,n);
    else if (n> arbol->info)
        eliminar(arbol->der);
    else
        eliminarNodo(arbol)
}

int main()
{
char opcion;
Nodo *arbol=NULL;
Nodo *buscado=NULL;
int cantidad,n,contador=0;
    do
    {
    system("cls");
    opcion=menu();
        switch(opcion)
        {
        case '1':
        system("cls");
        cout << "Ingrese la cantidad de nodos: "; cin >> cantidad; cout <<endl;
            for(int i=0;i<cantidad;i++)
            {
                cout << "Ingrese el numero [" << i+1 << "]: ";
                cin >> n; cout << endl;
                insertarNodo(arbol,n,NULL);
            }
        break;
        case '2':
        system("cls");
        mostrarArbol(arbol,contador);
        getche();
        break;
        case '3':
        system("cls");
        cout << "Ingrese el numero que desea buscar: "; cin >> n; cout <<endl;
        buscado=buscarNodo(arbol,n);
        if(buscado)
        {
            cout << "El nodo buscado es: " << buscado->info << " Su hijo derecho es: " <<endl;
            mostrarArbol(buscado->der,contador);
            cout << endl;
            cout << "Su hijo izquierdo es: " << endl;
            mostrarArbol(buscado->izq,contador);
            cout << endl;
            getche();
        }
        else
            cout << "No se ha encontrado el nodo." <<endl;
        break;
        case '4':
        system("cls");
            preOrden(arbol);
        getche();
        break;
        case '5':
        system("cls");
            inOrden(arbol);
        getche();
        break;
        case '6':
        system("cls");
            postOrden(arbol);
        getche();
        break;
        }
    }
    while(opcion!=27);
}
