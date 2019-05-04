/*................................................................................................................................................................................ */
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<conio.h>

using namespace std;
/*................................................................................................................................................................................ */
struct Alumno
{
char nombre[30];
char apellido[30];
int dni;
int legajo;
char codCarrera;
};
/*................................................................................................................................................................................ */
struct NodoDE
{
Alumno info;
NodoDE *sgte;
NodoDE *ant;
};
/*................................................................................................................................................................................ */
char menu()
{
char opcion;
    cout << "1.Ingresar alumno."<<endl; //Listo
    cout << "2.Modificar alumno."<<endl; //Listo
    cout << "3.Borrar alumno."<<endl; // No esta listo
    cout << "4.Buscar alumno por legajo."<<endl; //Listo
    cout << "5.Mostrar lista como cola."<<endl; //Listo
    cout << "6.Mostrar lista como pila."<<endl; //Listo
    cout << "Esc. Salir."<<endl;
    opcion=getche();
}
/*................................................................................................................................................................................ */
NodoDE *obtenerUltimo(NodoDE *lista)
{
    if(lista)
    {
    while(lista->sgte)
        lista=lista->sgte;
    return lista;
    }
   else
    return NULL;
}
/*................................................................................................................................................................................ */
void insertarAlInicio(NodoDE *&lista,Alumno dato)
{
NodoDE *nuevo=new NodoDE();
    nuevo->info=dato;
    nuevo->sgte=lista;
    nuevo->ant=NULL;
    lista->ant=nuevo;
    lista=nuevo;
}
/*................................................................................................................................................................................ */
void insertarAlFinal(NodoDE *&lista,Alumno dato)
{
NodoDE *nuevo=new NodoDE();
NodoDE *paux=NULL;
    nuevo->info=dato;
    paux=obtenerUltimo(lista);
    paux->sgte=nuevo;
    nuevo->sgte=NULL;
    nuevo->ant=paux;
}
/*................................................................................................................................................................................ */
void insertarOrdenado(NodoDE *&lista,Alumno dato)
{
NodoDE *nuevo=new NodoDE();
NodoDE *aux=NULL;
NodoDE *anterior=NULL;

    if(!lista)//lista vacia
    {
        lista=new NodoDE();
        lista->info=dato;
        lista->sgte=NULL;
        lista->ant=NULL;
    }
    else//no vacia
    {
        aux=lista;
        while(aux && aux->info.legajo<dato.legajo)//aux sea != de NULL y aux->info sea menor al dato a ingresar
          {
            anterior=aux;
            aux=aux->sgte;
          }
        nuevo->info=dato;
        if(aux==lista)//caso insertar al inicio
        {
            nuevo->sgte=lista;
            nuevo->ant=NULL;
            lista->ant=nuevo;
            lista=nuevo;
        }
        else // caso no es 1° elemento
        {
            anterior->sgte=nuevo;
            nuevo->ant=anterior;
            nuevo->sgte=aux;
                if(aux)
                    aux->ant=nuevo;
        }
    }
}
/*................................................................................................................................................................................ */
void sprint(Alumno dato,int i)
{
    cout << "Alumno [" << i+1 << "]: "<<endl;
    cout << dato.nombre << " " << dato.apellido << " " << dato.dni << " " << dato.legajo << " " << dato.codCarrera <<endl;
}
/*................................................................................................................................................................................ */
void mostrarListaDerecho(NodoDE *lista)
{
int i=0;
   while(lista)
    {
    sprint(lista->info,i);
    lista=lista->sgte;
    i++;
    }
}
/*................................................................................................................................................................................ */
void mostrarListaReves(NodoDE *lista)
{
int i=0;
    lista=obtenerUltimo(lista);
    while(lista)
    {
    sprint(lista->info,i);
    lista=lista->ant;
    i++;
    }
}
/*................................................................................................................................................................................ */
NodoDE *buscarNodo(NodoDE *lista,int legajo)
{
    while(lista && (lista->info.legajo!=legajo))
        lista=lista->sgte;
    if(lista)
        return lista;
    else
        cout << "No se ha encontrado el alumno, o no existe."<<endl;
        return NULL;
}
/*................................................................................................................................................................................ */
char menuModificar()
{
char opcion;
    cout << "1.Modificar Nombre."<<endl;
    cout << "2.Modificar Apellido."<<endl;
    cout << "3.Modificar DNI."<<endl;
    cout << "4.Modificar Legajo."<<endl;
    cout << "5.Modificar codigo de carrera."<<endl;
    cout << "Esc. Salir."<<endl;
    opcion=getche();
    return opcion;
    }
/*................................................................................................................................................................................ */
void modificarNodo(NodoDE *&lista,int legajo)
{
char opcion;
NodoDE *paux;
Alumno buffer;
    paux=buscarNodo(lista,legajo);
    if(paux)
    {
        buffer=paux->info;
        do
        {
            system("cls");
            opcion=menuModificar();
                switch(opcion)
                {
                case '1':
                    system("cls");
                    cout << "Ingrese nuevo nombre: "; cin >> buffer.nombre; cout << endl;
                break;
                 case '2':
                     system("cls");
                    cout << "Ingrese nuevo apellido: "; cin >> buffer.apellido; cout << endl;
                break;
                 case '3':
                     system("cls");
                    cout << "Ingrese nuevo DNI: "; cin >> buffer.dni; cout << endl;
                break;
                 case '4':
                     system("cls");
                    cout << "Ingrese nuevo legajo: "; cin >> buffer.legajo; cout << endl;
                break;
                 case '5':
                     system("cls");
                    cout << "Ingrese nuevo codigo carrera: "; cin >> buffer.codCarrera; cout << endl;
                break;
                }
        }
        while(opcion!=27);
        paux->info=buffer;
    }
}
/*................................................................................................................................................................................ */
void borrarNodo(NodoDE *&lista,int legajo)
{
NodoDE *paux;
    paux=buscarNodo(lista,legajo);
        if(paux)//si existe
        {
                if(paux==lista)//Caso 1° elemento
                {
                    lista=lista->sgte;
                    lista->ant=NULL;
                    delete paux;
                }//2
                else
                {
                    if(!paux->sgte)// Caso último elemento
                    {
                        paux->ant->sgte=NULL;
                        delete paux;
                    }
                    else // Caso en medio
                    {
                        paux->ant->sgte=paux->sgte;
                        paux->sgte->ant=paux->ant;
                        delete paux;
                    }
                }
        }//1

}
/*................................................................................................................................................................................ */
void cargarLista(NodoDE *&lista)
{
FILE *f;
f=fopen("Archivo.dat","rb");
Alumno buffer;
    fread(&buffer,sizeof(Alumno),1,f);
    while(!feof(f))
    {
        insertarOrdenado(lista,buffer);
        fread(&buffer,sizeof(Alumno),1,f);
    }
}
/*................................................................................................................................................................................ */
/*
void cargarArchivo(Alumno dato)
{
FILE *f;
f=fopen("Archivo.dat","ab");
    fwrite(&dato,sizeof(Alumno),1,f);
fclose(f);
}*/
/*................................................................................................................................................................................ */
void actualizarArchivo(NodoDE *lista)
{
FILE *f;
f=fopen("Archivo.dat","wb");
    while(lista)
    {
        fwrite(&lista->info,sizeof(Alumno),1,f);
        lista=lista->sgte;
    }
}
/*................................................................................................................................................................................ */
int main()
{
Alumno dato;
char opcion;
NodoDE *lista=NULL;
NodoDE *paux=NULL;
int cantidad;
int j;
int legajo;
    cargarLista(lista);
    do
    {
        system("cls");
        opcion=menu();
        switch(opcion)
        {
        case '1':
            system("cls");
            cout << "Inserte la cantidad de alumnos que va a agregar: "; cin>>cantidad; cout <<endl;
                for(int i=0;i<cantidad;i++)
                {
                    cout << "Ingresando alumno nro [" << i+1 << "]: "<<endl;
                    cout << "Nombre: "; cin>> dato.nombre; cout <<endl;
                    cout << "Apellido: ";cin>>dato.apellido; cout <<endl;
                    cout << "DNI: "; cin>>dato.dni; cout << endl;
                    cout << "Legajo: "; cin>> dato.legajo; cout << endl;
                    cout << "Codigo de carrera: "; cin>> dato.codCarrera; cout <<endl;
                    insertarOrdenado(lista,dato);
                }
            cout << "Presione una tecla para continuar."<<endl;
            getche();
        break;
        case '2':
            system("cls");
            cout << "Ingrese el legajo del alumno a modificar: "; cin>>legajo; cout <<endl;
            modificarNodo(lista,legajo);
            cout << "Presione una tecla para continuar."<<endl;
            getche();
        break;
        case '3':
            system("cls");
            cout << "Ingrese el legajo del alumno a borrar: "; cin>>legajo; cout <<endl;
            borrarNodo(lista,legajo);
            cout << "Presione una tecla para continuar."<<endl;
            getche();
        break;
        case '4':
            system("cls");
            cout << "Ingrese el legajo del alumno a buscar: "; cin>> legajo; cout <<endl;
            paux=buscarNodo(lista,legajo);
                if(paux)
                {
            dato=paux->info;
            sprint(dato,0);
                }
            cout << "Presione una tecla para continuar."<<endl;
            getche();
        break;
        case '5':
            system("cls");
            mostrarListaDerecho(lista);
            cout << "Presione una tecla para continuar."<<endl;
            getche();
        break;
        case '6':
            system("cls");
            mostrarListaReves(lista);
            cout << "Presione una tecla para continuar."<<endl;
            getche();
        break;
        }
    }
    while(opcion!=27);
actualizarArchivo(lista);

return 0;
}
/*................................................................................................................................................................................ */



