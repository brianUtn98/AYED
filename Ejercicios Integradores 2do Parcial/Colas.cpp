#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<conio.h>

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
	cout << "1. Agregar alumnos a la cola."<<endl;
	cout << "2. Mostrar cola."<<endl;
	cout << "3. Desencolar por cantidad."<<endl;
	cout << "4. Desencolar completo."<<endl;
	cout << "Esc Salir."<<endl;
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
//Agregar elemento a la cola
void cqueue(Nodo *&frente,Nodo *&fin,Alumno dato)
{
Nodo *nuevo=new Nodo();
nuevo->info=dato;
nuevo->sgte=NULL;
    if(colaVacia(frente))
    {
        frente=nuevo;
    }
    else
    {
        fin->sgte=nuevo;
    }
    fin=nuevo;

}

void cdequeue(Nodo *&frente,Nodo *&fin,Alumno &dato)
{
Nodo *aux=frente;
dato=frente->info;
    if(frente==fin)
    {
        frente=NULL;
        fin=NULL;
    }
    else
        frente=aux->sgte;
    delete aux;
}

void leerArchivoACola(Nodo *&frente,Nodo *&fin)
{
FILE *f;
Alumno buffer;
f=fopen("Archivo.dat","rb");
    if(f)
        {
        fread(&buffer,sizeof(Alumno),1,f);
        while(!feof(f))
            {
            cqueue(frente,fin,buffer);
            fread(&buffer,sizeof(Alumno),1,f);
            }
        }
    else
        cout << "No se ha podido abrir el archivo, o no existe."<<endl;
fclose(f);
}

void mostrarCola(Nodo *frente,Nodo *fin)
{
int i=0;
    if(colaVacia(frente))
        cout << "Cola vacia"<<endl;
    else
        {
            cout << "Mostrando cola."<<endl;
            while(frente)
            {
            cout << "Alumno [" <<i+1<<"]: "<<frente->info.nombre << " "<<frente->info.apellido<< " "<<frente->info.dni<<" "<<frente->info.legajo<<" "<<frente->info.codCarrera<<endl;
            frente=frente->sgte;
            i++;
            }
        }

}

void agregarArchivo(Alumno buffer)
{
FILE *f;
f=fopen("Archivo.dat","ab");
    if(f)
        {
            fwrite(&buffer,sizeof(Alumno),1,f);
        }
        else
            cout << "No se ha podido abrir el archivo, o no existe."<<endl;
}

int main()
{
Nodo *frente=NULL;
Nodo *fin=NULL;
Alumno dato;
char opcion;
int cantidad,j;
    leerArchivoACola(frente,fin);

    do
    {
        system("cls");
        opcion=menu();
            switch(opcion)
            {
            case '1':
                system("cls");
                cout << "Ingrese la cantidad de alumnos a ingresar: "; cin>> cantidad; cout <<endl;
                for(int i=0;i<cantidad;i++)
				{
				cout << "Elemento [" << i+1 << "]: "<<endl;
				cout << "Nombre: "; cin>> dato.nombre; cout <<endl;
				cout << "Apellido: "; cin>> dato.apellido; cout <<endl;
				cout << "DNI: "; cin>> dato.dni; cout <<endl;
				cout << "Legajo: "; cin>> dato.legajo; cout <<endl;
				cout << "Codigo de carrera: "; cin>> dato.codCarrera; cout <<endl;
				cqueue(frente,fin,dato);
				agregarArchivo(dato);
				}
            cout << "Presione una tecla para continuar."<<endl;
            getche();
            break;

            case '2':
                system("cls");
                mostrarCola(frente,fin);
            cout << "Presione una tecla para continuar."<<endl;
            getche();
            break;

            case '3':
                system("cls");
                cout << "Ingrese cantidad a desencolar: "; cin >> cantidad; cout <<endl;
                    for(int k=0;k<cantidad;k++)
                    {
                        cdequeue(frente,fin,dato);
                        cout << "Desencolando elemento [" << k+1 << "]: " << dato.nombre << " " << dato.apellido << " " << " " << dato.dni << " " << dato.legajo << " " << dato.codCarrera <<endl;

                    }
                cout << "Presione una tecla para continuar."<<endl;
                getche();
            break;

            case '4':
                system("cls");
                while(frente)
                {
                cdequeue(frente,fin,dato);
                cout << "Desencolando elemento [" << j+1 << "]: " << dato.nombre << " " << dato.apellido << " " << " " << dato.dni << " " << dato.legajo << " " << dato.codCarrera <<endl;
				j++;
                }
            cout << "Presione una tecla para continuar."<<endl;
            getche();
            break;
            }
    }
    while(opcion!=27);

}
