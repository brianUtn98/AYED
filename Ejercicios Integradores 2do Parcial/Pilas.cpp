/*Agrega elementos, modifica, muestra y desapila para luego guardar en un archivo en orden de salida.*/
#include<stdlib.h>
#include<iostream>
#include<conio.h>
#include<stdio.h>
using namespace std;

struct Alumno
{
char nombre[30];
char apellido[30];
int dni;
int legajo;
char codCarrera;
};

struct Nodo
{
Alumno info;
Nodo *sgte;
};

char menu()
{
char opcion;
	cout << "1. Agregar alumnos a la pila."<<endl;
	cout << "2. Mostrar pila."<<endl;
	cout << "3. Desapilar."<<endl;
	cout << "Esc Salir."<<endl;
	opcion=getche();
		return opcion;
}

void push(Nodo *&pila,Alumno dato)
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
	cout << "Se agrego elemento satifactoriamente. "<<endl;
}

void pop(Nodo *&pila,Alumno &dato)
{
Nodo *aux=pila;
	if(pila)
	{
	dato=aux->info;
	pila=aux->sgte;
	delete aux;
	}
	else
	cout << "La pila ya esta vacia."<<endl;
}
// Si me lees parpadeá dos veces
void mostrarPila(Nodo *pila)
{
int i=0;
	if(!pila)
		cout << "La pila esta vacia." <<endl;
	else
	{
		while(pila)
		{
		cout << "Alumno [" << i+1 << "]: " << pila->info.nombre << " " << pila->info.apellido << " " << pila->info.dni << " " << pila->info.legajo << " " << pila->info.codCarrera <<endl;
		pila=pila->sgte;
		i++;
		}
	}
}

void leerArchivoAPila(Nodo *&pila) //recibo pila por ref, porque voy a leer al archivo y cargarlo en la pila
{
FILE *f;
Alumno buffer;
f=fopen("Archivo.dat","rb");
    if(f)
    {
        fread(&buffer,sizeof(Alumno),1,f); //Lee primer elemento del file.
        while(!feof(f)) // Mientras que no llegue a final de archivo...
        {
        push(pila,buffer); //Mete elemento en la pila
        fread(&buffer,sizeof(Alumno),1,f); //Vuelve a leer(sgte).
        }
    }
    else
    cout << "No se pudo abrir el archivo, o no existe."<<endl;
fclose(f);
}

void agregarArchivo(Alumno dato) // cada archivo agregado a la pila
// tiene que ser agregado al archivo así mismo. Ok?
{
FILE *f;
f=fopen("Archivo.dat","ab"); //el tipo AB escribe al final, respetando contenido
    if(f)
    {
    fwrite(&dato,sizeof(Alumno),1,f); //Carga el dato en el archivo.
    }
    else
    cout << "No se pudo abrir el archivo, o no existe."<<endl;
fclose(f);
}

int main()
{
char opcion;
Alumno dato;
int cantidad,j;
Nodo *pila=NULL;
    leerArchivoAPila(pila);
	do
	{
		system("cls");
	opcion=menu();
	switch(opcion)
		{
		case '1':
			system("cls");
			cout << "Ingrese cantidad a ingresar: ";
			cin >> cantidad; cout <<endl;
				for(int i=0;i<cantidad;i++)
				{
				cout << "Elemento [" << i+1 << "]: "<<endl;
				cout << "Nombre: "; cin>> dato.nombre; cout <<endl;
				cout << "Apellido: "; cin>> dato.apellido; cout <<endl;
				cout << "DNI: "; cin>> dato.dni; cout <<endl;
				cout << "Legajo: "; cin>> dato.legajo; cout <<endl;
				cout << "Codigo de carrera: "; cin>> dato.codCarrera; cout <<endl;
				push(pila,dato);
				agregarArchivo(dato);
				}
			cout << "Presione una tecla para continuar."<<endl;
			getche();
		break;
		case '2':
			system("cls");
			mostrarPila(pila);
			cout << "Presione una tecla para continuar."<<endl;
			getche();
		break;
		case '3':
			system("cls");
			j=0;
			while(pila)
			{
				pop(pila,dato);
				cout << "Desapilando elemento [" << j+1 << "]: " << dato.nombre << " " << dato.apellido << " " << " " << dato.dni << " " << dato.legajo << " " << dato.codCarrera <<endl;
				j++;

			}
			cout << "Pila vacia"<<endl;
			cout << "Presione una tecla para continuar."<<endl;
			getche();
		break;
		}
	}
	while(opcion!=27);

cout << "Saliendo del programa."<<endl;
getche();
return 0;
}


// Vamos a hacer así. Primero quiero que al iniciar el programa, lea el archivo y lo cargue en la pila
