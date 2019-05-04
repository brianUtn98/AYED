#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include<stdio.h>
#include<string.h>

using namespace std;

struct Alumno{
char nombre [30];
char apellido [30];
int dni;
int legajo;
char codCarrera;
};

struct Materia
{
char nombre[30];
float nota;
int legajo;
};

char menu(){
char opcion;
cout << "1. Agregar alumno."<<endl;
cout << "2. Modificar alumno."<<endl;
cout << "3. Buscar alumno."<<endl;
cout << "4. Borrar alumno."<<endl;
cout << "5. Mostrar el archivo."<<endl;
cout << "6. Vaciar archivo."<<endl;
cout << "7. Agregar materias."<<endl;
cout << "8. Mostrar lista de materias."<<endl;
cout << "Esc Salir."<<endl;

opcion=getche();
return opcion;
}

void agregarArchivo(int cantidad){
FILE *f;
Alumno buffer;
    f=fopen("Archivo.dat","ab");
  for(int i=0;i<cantidad;i++){
    cout << "Ingrese el nombre del alumno["<<i+1 <<"]: "; cin>>buffer.nombre; cout <<endl;
    cout << "Ingrese el apellido del alumno["<<i+1 <<"]: "; cin>>buffer.apellido; cout <<endl;
    cout << "Ingrese el DNI del alumno["<<i+1 <<"]: "; cin>>buffer.dni; cout <<endl;
    cout << "Ingrese el legajo del alumno["<<i+1 <<"]: "; cin>>buffer.legajo; cout <<endl;
    cout << "Ingrese el codigo de carrera del alumno["<<i+1 <<"]: "; cin>>buffer.codCarrera; cout <<endl;
    fwrite(&buffer,sizeof(Alumno),1,f);
  }
fclose(f);
}

void mostrarArchivo()
{
Alumno buffer;
FILE *f;
int i=0;
int tam;

    if(f=fopen("Archivo.dat","rb"))
    {
        fseek(f,0,SEEK_END);
        tam=ftell(f);
        if(tam)
        {
            fseek(f,0,SEEK_SET);
            //cout << "|Numero|   |Nombre| |Apellido| |DNI|      |Legajo|     |CodigoCarrera| "<<endl;
            fread(&buffer,sizeof(Alumno),1,f);
            while(!feof(f))
            {
                if(buffer.dni!=0)
            cout << "Alumno ["<<i+1<<"] " << buffer.nombre << " " << buffer.apellido << " DNI: " <<buffer.dni <<" Legajo: " <<buffer.legajo <<" CodCarrera: " << buffer.codCarrera <<endl;
            fread(&buffer,sizeof(Alumno),1,f);
            i++;
            }
        }
        else
            cout << "El archivo esta vacio." <<endl;
    }
    else
        cout << "No se encontro el archivo"<<endl;
}

void buscarArchivo(int n)
{
int tam;
int cantElementos;
FILE *f;
Alumno buffer;
f=fopen("Archivo.dat","rb");
    fseek(f,0,SEEK_END);
    tam=ftell(f);
    cantElementos=tam/sizeof(Alumno);
    if(n>cantElementos)
        cout << "La posicion buscada esta fuera del rango, existen "<<cantElementos<<" elementos." <<endl;
    else
    {
        fseek(f,sizeof(Alumno)*(n-1),SEEK_SET);
        fread(&buffer,sizeof(Alumno),1,f);
        cout << "El alumno buscado, en la posicion "<<n<<" es: "<< buffer.nombre<<" "<<buffer.apellido<<"."<<endl;
    }


}
char menuModifica()
{
char opcion;
    cout << "Que desea modificar? "<<endl;
    cout << "1. Nombre"<<endl;
    cout << "2. Apellido"<<endl;
    cout << "3. DNI"<<endl;
    cout <<"4. Legajo"<<endl;
    cout << "5.Codigo de carrera"<<endl;
    cout << "6. Todo"<<endl;
    cout << "Esc Salir"<<endl;
    opcion=getche();
    return opcion;
}
void modificarArchivo(int n)
{
char opcion;
int tam;
int cantElementos;
FILE *f;
Alumno buffer;
f=fopen("Archivo.dat","rb+");
    fseek(f,0,SEEK_END);
    tam=ftell(f);
    cantElementos=tam/sizeof(Alumno);

if(n>cantElementos)
        cout << "La posicion a modificar esta fuera del rango, existen " <<cantElementos<<" elementos."<<endl;
    else
{
    fseek(f,sizeof(Alumno)*(n-1),SEEK_SET);
    fread(&buffer,sizeof(Alumno),1,f);
    opcion=menuModifica();
        switch(opcion)
        {
        case '1':
            system("cls");
        cout << "Ingrese nuevo nombre: "; cin >> buffer.nombre; cout <<endl;
        fseek(f,sizeof(Alumno)*(n-1),SEEK_SET);
        fwrite(&buffer,sizeof(Alumno),1,f);
        break;
        case '2':
             system("cls");
        cout << "Ingrese nuevo apellido: "; cin >> buffer.apellido; cout <<endl;
        fseek(f,sizeof(Alumno)*(n-1),SEEK_SET);
        fwrite(&buffer,sizeof(Alumno),1,f);
        break;
        case '3':
             system("cls");
        cout << "Ingrese nuevo DNI: "; cin >> buffer.dni; cout <<endl;
        fseek(f,sizeof(Alumno)*(n-1),SEEK_SET);
        fwrite(&buffer,sizeof(Alumno),1,f);
        break;
        case '4':
             system("cls");
        cout << "Ingrese nuevo legajo: "; cin >> buffer.legajo; cout <<endl;
        fseek(f,sizeof(Alumno)*(n-1),SEEK_SET);
        fwrite(&buffer,sizeof(Alumno),1,f);
        break;
        case '5':
             system("cls");
        cout << "Ingrese nuevo codigo de carrera: "; cin >> buffer.codCarrera; cout <<endl;
        fseek(f,sizeof(Alumno)*(n-1),SEEK_SET);
        fwrite(&buffer,sizeof(Alumno),1,f);
        break;
        case '6':
             system("cls");
            cout << "Ingrese nuevo nombre: "; cin>>buffer.nombre; cout <<endl;
            cout << "Ingrese nuevo apellido: "; cin>>buffer.apellido; cout <<endl;
            cout << "Ingrese nuevo DNI: "; cin>>buffer.dni; cout <<endl;
            cout << "Ingrese nuevo legajo: "; cin>>buffer.legajo; cout <<endl;
            cout << "Ingrese nuevo codigo de carrera: "; cin>>buffer.codCarrera; cout <<endl;
            fseek(f,sizeof(Alumno)*(n-1),SEEK_SET);
            fwrite(&buffer,sizeof(Alumno),1,f);
        break;
        }

    }
fclose(f);
}

void limpiarArchivo()
{
FILE *f;
f=fopen("Archivo.dat","wb");
fclose(f);
}

void actualizarArchivo()
{
FILE *faux;
FILE *f;

Alumno buffer;
    faux=fopen("auxiliar.dat","wb");
     if (f=fopen("Archivo.dat","rb"))
            {
                while(!feof(f))
                {
                        fread(&buffer,sizeof(Alumno),1,f);
                        if(buffer.dni!=0 && !feof(f))
                        {
                        fwrite(&buffer,sizeof(Alumno),1,faux);
                        }
                }
                fclose(f);
            }
            fclose(faux);
    if(!remove("Archivo.dat"))
    {
        if(!rename("auxiliar.dat","Archivo.dat"))
            cout << "Se completo la operacion satifactoriamente"<<endl;
        else
            cout << "La operacion fallo."<<endl;
    }
    else
        cout << "No se pudo borrar el archivo viejo." <<endl;

}

void borrarArchivo(int n)
{
    //1° Borra logicamente el valor. cambiando DNI de elemento a borrar por 0.
FILE *f;
int cantElementos,tam;
Alumno buffer;
            if(f=fopen("Archivo.dat","rb+"))
            {
                fseek(f,0,SEEK_END);
                tam=ftell(f);
                cantElementos=tam/sizeof(Alumno);
                    if(n>cantElementos)
                        cout << "El numero ingresado esta fuera de rango. Existen "<<cantElementos<<" elementos."<<endl;
                    else
                        {
                        fseek(f,sizeof(Alumno)*(n-1),SEEK_SET);
                        fread(&buffer,sizeof(Alumno),1,f);
                        buffer.dni=0;
                        fseek(f,sizeof(Alumno)*(n-1),SEEK_SET);
                        fwrite(&buffer,sizeof(Alumno),1,f);
                        fclose(f);
                        }
            }
            else
                cout << "No se ha encontrado el archivo"<<endl;



}
void crearArchivo()
{
FILE *f;
    f=fopen("Materias.dat","wb");
    fclose(f);
}

void agregarMaterias(int n)
{
FILE *f;
Materia buffer;
    if(f=fopen("Materias.dat","ab"))
    {
        for(int i=0;i<n;i++)
        {
            cout << "Ingrese el nombre de la materia: "; cin >> buffer.nombre; cout <<endl;
            cout << "Ingrese la nota del alumno: "; cin >> buffer.nota; cout <<endl;
            cout << "Ingrese el legajo del alumno relacionado: "; cin >> buffer.legajo; cout <<endl;
            fwrite(&buffer,sizeof(Materia),1,f);
        }
        fclose(f);
    }

}

void mostrarMaterias()
{
FILE *f;
Materia buffer;
    f=fopen("Materias.dat","rb");
        while(fread(&buffer,sizeof(Materia),1,f))
            cout << buffer.nombre << " " << buffer.nota << " " << buffer.legajo <<endl;
    fclose(f);
}

int main()
{
int cantidad,pos;
char opcion;
FILE *f;
 actualizarArchivo();
    do
    {
    system("cls");
    opcion=menu();
        switch(opcion)
        {
        case '1':
            system("cls");
            cout << "Ingrese cantidad de alumnos a ingresar: "; cin >> cantidad; cout << endl;
            agregarArchivo(cantidad);
            cout << "Presione una tecla para continuar."<<endl;
            getche();
        break;
        case '2':
            system("cls");
            cout << "Ingrese la posicion a modificar: "; cin >> pos; cout <<endl;
            modificarArchivo(pos);
            cout << "Presione una tecla para continuar."<<endl;
            getche();
        break;
        case '3':
            system("cls");
            cout << "Ingrese la posicion buscada: "; cin>> pos; cout <<endl;
            buscarArchivo(pos);
            cout << "Presione una tecla para continuar."<<endl;
            getche();
        break;
        case '4':
            system("cls");
            cout << "Ingrese la posicion que desea borrar: "; cin>> pos; cout <<endl;
            borrarArchivo(pos);
            cout << "Presione una tecla para continuar."<<endl;
            getche();
        break;
        case '5':
            system("cls");
            mostrarArchivo();
            cout << "Presione una tecla para continuar."<<endl;
            getche();
        break;
        case '6':
            do
            {
            system("cls");
            cout << "Esta seguro que desea vaciar el archivo? (S,N)"<<endl;
            opcion=getche();
            }
            while(opcion!='S' && opcion!='s' && opcion!='N' && opcion!='n');
            system("cls");
                if(opcion=='S' || opcion=='s')
                {
                    limpiarArchivo();
                    cout << "El archivo ha sido vaciada exitosamente."<<endl;
                }
                else
                    cout << "Se ha suspendido la operacion."<<endl;
                cout << "Presione una tecla para continuar."<<endl;
                getche();
        break;
        case '7':
             system("cls");
            cout << "Ingrese la cantidad de elementos a ingresar: "; cin >> cantidad; cout <<endl;
            f=fopen("Materias.dat","ab");
                if(!f)
                    crearArchivo();
            fclose(f);
                agregarMaterias(cantidad);
                 cout << "Presione una tecla para continuar."<<endl;
                getche();

        break;
        case '8':
            system("cls");
            mostrarMaterias();
             cout << "Presione una tecla para continuar."<<endl;
                getche();
        break;
        }
    }
    while(opcion!=27);
cout << "Saliendo del programa de Archivos binarios."<<endl;
getche();
return 0;
}


