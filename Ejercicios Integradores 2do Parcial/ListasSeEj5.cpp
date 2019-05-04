#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<conio.h>

using namespace std;

struct Materia
{
char nombre[30];
float nota;
int legajo; //(*)
};

struct Alumno
{
char nombre[30];
char apellido[30];
int dni;
int legajo; //(*)
char codCarrera;
};

struct NodoMateria
{
Materia info;
NodoMateria *sgte;
};

struct NodoAlumno
{
Alumno info;
NodoAlumno *sgte;
NodoMateria *materia; //sublista
};

char menu()
{
char opcion;
    cout << "1.Insertar alumnos."<<endl;
    cout << "2.Listar materias totales."<<endl; // va a pedir el legajo del alumno.
    cout << "3.Listar materias aprobadas."<<endl; // "" "" ""
    cout << "4.Buscar promedio de alumno."<<endl; // "" "" ""
    cout << "5.Buscar alumno."<<endl;
    cout << "6.Insertar materias."<<endl; //Por legajo
    cout << "7.Mostrar lista."<<endl;
    cout << "Esc. Salir"<<endl;
    opcion=getche();
    return opcion;
}

NodoAlumno *obtenerUltimo(NodoAlumno *lista) // No lo use
{
    while(lista->sgte)
        lista=lista->sgte;
    return lista;
}

NodoMateria *obtenerUltimoMateria(NodoMateria *lista) // lo use
{
    while(lista->sgte)
        lista=lista->sgte;
    return lista;
}

NodoAlumno *obtenerAnterior(NodoAlumno *lista,NodoAlumno *busqueda) // No lo use
{
    while(lista && lista->sgte!=busqueda)
        lista=lista->sgte;
    return lista;

}

NodoAlumno *buscarNodo(NodoAlumno *lista,int legajo) // Leo el archivo de materias.
{
NodoAlumno *paux=lista;
    while(paux && (paux->info.legajo!=legajo))
        paux=paux->sgte;
    return paux;
}

void insertarOrdenado(NodoAlumno *&lista,Alumno dato)
{
NodoAlumno *nuevo=new NodoAlumno();
NodoAlumno *paux=lista;
NodoAlumno *anterior=NULL;
    nuevo->info=dato;
    nuevo->sgte=NULL;
    nuevo->materia=NULL;

    if(!lista)
        lista=nuevo;
    else
    {
        while(paux && paux->info.legajo<dato.legajo)
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

void insertarMateria(NodoMateria *&lista,Materia dato)
{
NodoMateria *nuevo=new NodoMateria();
NodoMateria *paux=NULL;

nuevo->info=dato;
nuevo->sgte=NULL;
    if(!lista)
        lista=nuevo;
    else
    {
    paux=obtenerUltimoMateria(lista);
    paux->sgte=nuevo;
    }
}

void cargarAlumnos(NodoAlumno *&lista)
{
FILE *f;
Alumno buffer;
    f=fopen("Archivo.dat","rb");
        while(fread(&buffer,sizeof(Alumno),1,f))
            insertarOrdenado(lista,buffer);
    fclose(f);
}

void cargarMaterias(NodoAlumno *&lista)
{
FILE *f;
Materia buffer;
NodoAlumno *paux;
    f=fopen("Materias.dat","rb");
        while(fread(&buffer,sizeof(Materia),1,f))
        {
            paux=buscarNodo(lista,buffer.legajo);
                if(paux)
                    insertarMateria(paux->materia,buffer);
        }
    fclose(f);
}

void mostrarListaMateria(NodoMateria *lista)
{
    if(lista)
    {
    cout << "Listando materias: "<<endl;
    while(lista)
        {
        cout << lista->info.nombre << " " << lista->info.nota <<endl;
        lista=lista->sgte;
        }
    }
    else
        cout << "Sin materias"<<endl;
}

void mostrarListaMateriaAprobada(NodoMateria *lista)
{
int i=0;
    if(lista)
    {
        while(lista)
        {
            if(lista->info.nota>=6)
                {
                cout << lista->info.nombre << " " <<lista->info.nota << endl;
                i++;
                }
            lista=lista->sgte;

        }
        if(!i)
        cout << "El alumno no posee materias aprobadas."<<endl;
    }
    else
    {
        cout << "Sin materias."<<endl;
    }


}

float calcularPromedio(NodoMateria *lista)
{
float suma;
int i=0;
float prom;
    while(lista)
    {
    suma+=lista->info.nota;
    i++;
    lista=lista->sgte;
    }
    if(i)
    {
        prom=suma/i;
    return prom;
    }
    else
        cout << "El alumno no posee materias."<<endl;
}

void mostrarLista(NodoAlumno *lista)
{
int i=0;
    if(lista)
    {
    while(lista)
        {
        cout <<"--------------------------------------------------------------" << endl;
        cout << "Alumno [" <<i+1<< "]: " <<endl;
        cout << lista->info.nombre << " " << lista->info.apellido << " " << lista->info.dni << " " << lista->info.legajo << " " << lista->info.codCarrera <<endl;
            if(lista->materia)
            {
            mostrarListaMateria(lista->materia);
            }
            else
                cout << "Alumno sin materias."<<endl;
                lista=lista->sgte;
                i++;
        }
    }
    else
        cout << "La lista esta vacia."<<endl;
}

void actualizarArchivoAlumno(NodoAlumno *lista)
{
FILE *f;
FILE *f2;
    f=fopen("Archivo.dat","wb");
    f2=fopen("Materias.dat","wb");
        while(lista)
        {
            fwrite(&lista->info,sizeof(Alumno),1,f);
                while(lista->materia)
                {
                    fwrite(&lista->materia->info,sizeof(Materia),1,f2);
                    lista->materia=lista->materia->sgte;
                }
               lista=lista->sgte;
        }
    fclose(f);
    fclose(f2);
}

void borrarListaAlumno(NodoAlumno *&lista)
{
NodoAlumno *paux=lista;
    while(lista)
    {
        paux=lista;
        lista=paux->sgte;
        delete paux;
    }
}

void borrarListaMateria(NodoMateria *&lista)
{
NodoMateria *paux;
    while(lista)
    {
        paux=lista;
        lista=paux->sgte;
        delete paux;
    }
}


int main()
{
char opcion;
int cantidad,legajo,j=0;
float prom;
NodoAlumno *lista=NULL;
NodoAlumno *paux=NULL;
Alumno datoAlumno;
Materia datoMateria;
    cargarAlumnos(lista);
    cargarMaterias(lista);
    /*mostrarLista(lista);*/

    do
    {
    system("cls");
    opcion=menu();
        switch(opcion)
        {
            case '1':
                system("cls");
                cout << "Ingrese cantidad de alumnos: "; cin >> cantidad; cout << endl;
                    for(int i=0;i<cantidad;i++)
                        {
                        cout << "Alumno [" << i+1 << "]: "<<endl;
                        cout << "Ingrese nombre: "; cin >> datoAlumno.nombre; cout << endl;
                        cout << "Ingrese apellido: "; cin >> datoAlumno.apellido; cout << endl;
                        cout << "Ingrese DNI: "; cin >> datoAlumno.dni; cout << endl;
                        cout << "Ingrese Legajo: "; cin >> datoAlumno.legajo; cout << endl;
                        cout << "Ingrese Codigo de carrera: "; cin >> datoAlumno.codCarrera; cout << endl;
                        insertarOrdenado(lista,datoAlumno);
                        }
                cout << "Presione una tecla para continuar."<<endl;
                getche();
            break;
            case '2':
                system("cls");
                    cout << "Ingrese legajo del alumno: "; cin>>legajo; cout <<endl;
                    paux=buscarNodo(lista,legajo);
                        if(paux)
                        {
                            cout << "Lista de materias del alumno " << paux->info.nombre << " " << paux->info.apellido<< " : " <<endl;
                            mostrarListaMateria(paux->materia);
                        }
                        else
                            cout << "El alumno no ha sido encontrado"<<endl;
                cout << "Presione una tecla para continuar."<<endl;
                getche();
            break;
            case '3':
                system("cls");
                    cout << "Ingrese legajo del alumno: "; cin>>legajo; cout <<endl;
                    paux=buscarNodo(lista,legajo);
                        if(paux)
                        {
                            cout << "Lista de materias aprobadas del alumno " << paux->info.nombre << " " << paux->info.apellido<< " : " <<endl;
                            mostrarListaMateriaAprobada(paux->materia);
                        }
                        else
                            cout << "El alumno no ha sido encontrado"<<endl;
                cout << "Presione una tecla para continuar."<<endl;
                getche();
            break;
            case '4':
                system("cls");
                    cout << "Ingrese legajo del alumno: "; cin>>legajo; cout <<endl;
                    paux=buscarNodo(lista,legajo);
                        if(paux)
                        {
                            prom=calcularPromedio(paux->materia);
                            cout << "El promedio del alumno " << paux->info.nombre << " " << paux->info.apellido << " es: " << prom <<endl;
                        }
                        else
                            cout << "El alumno no ha sido encontrado"<<endl;

                cout << "Presione una tecla para continuar."<<endl;
                getche();
            break;
            case '5':
                system("cls");
                    cout << "Ingrese legajo del alumno: "; cin>>legajo; cout <<endl;
                    paux=buscarNodo(lista,legajo);
                        if(paux)
                        {
                        cout << "El alumno buscado es: " <<endl;
                        cout << paux->info.nombre << " " << paux->info.apellido << " " << paux->info.dni << " " << paux->info.legajo << " " << paux->info.codCarrera << endl;
                        mostrarListaMateria(paux->materia);
                        }
                        else
                            cout << "El alumno no ha sido encontrado"<<endl;
                cout << "Presione una tecla para continuar."<<endl;
                getche();
            break;
            case '6':
                system("cls");
                    cout << "Ingrese legajo del alumno: "; cin>>legajo; cout <<endl;
                    paux=buscarNodo(lista,legajo);
                    if(paux)
                    {
                    cout << "Ingrese el nombre de la materia: "; cin >> datoMateria.nombre; cout <<endl;
                    cout << "Ingrese la nota del alumno: "; cin >> datoMateria.nota; cout <<endl;
                    datoMateria.legajo=legajo;
                    insertarMateria(paux->materia,datoMateria);
                    }
                    else
                        cout << "El alumno no ha sido encontrado"<<endl;
                cout << "Presione una tecla para continuar."<<endl;
                getche();
            break;
            case '7':
                system("cls");
                    cout << "Lista de alumnos: "<<endl;
                    mostrarLista(lista);
                    cout << "Presione una tecla para continuar."<<endl;
                    getche();
            break;

        }
    }
    while(opcion!=27);

    actualizarArchivoAlumno(lista);
    //Borrar listas
    paux=lista;
    while(paux)
    {
        borrarListaMateria(paux->materia);
        paux=paux->sgte;
        j++;
    }
cout <<endl;
    borrarListaAlumno(lista);

mostrarLista(lista);

cout << "Cerrando el programa."<<endl;
getche();
return 0;

}
