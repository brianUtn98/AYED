#include<conio.h>
#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<string.h>

#define dirGrupoA "Ejercicio2-GrupoA.txt"
#define dirGrupoB "Ejercicio2-GrupoB.txt"
#define dirGrupoC "Ejercicio2-GrupoC.txt"
#define dirGrupoD "Ejercicio2-GrupoD.txt"
#define dirGrupoE "Ejercicio2-GrupoE.txt"
#define dirGrupoF "Ejercicio2-GrupoF.txt"
#define dirGrupoG "Ejercicio2-GrupoG.txt"
#define dirGrupoH "Ejercicio2-GrupoH.txt"
using namespace std;

struct equipo
{
      char nombre[10];
       char confederacion[10];
       int bolillero;
       char grupo;
};


void ordenaGrupo(equipo equipos[])
{

 equipo auxiliar;
for (int i=0; i<32; i++) {
    for (int j=0; j<32-i; j++)
    {
        if (atoi(equipos[i].grupo) <  atoi(equipos[j].grupo))
        {
        auxiliar=equipos[i];
        equipos[i] = equipos[j];
        equipos[j] = auxiliar;
        }
    }
}
for(int z=0;z<32;z++)
{
    cout << equipos[z].nombre << "  " <<equipos[z].confederacion<< "  "<<equipos[z].grupo <<endl;
}

}

void ordenaNombre(equipo equipos[])
{

    equipo auxiliar;
for (int i=0; i<32; i++) {
    for (int j=0; j<32-i; j++)
    {
        if (strcmp(equipos[i].nombre, equipos[j].nombre) < 0)
        {
        auxiliar=equipos[i];
        equipos[i] = equipos[j];
        equipos[j] = auxiliar;
        }
    }
}
for(int z=0;z<32;z++)
{
    cout << equipos[z].nombre << "  " <<equipos[z].confederacion<< "  "<<equipos[z].grupo <<endl;
}

}

void ordenaConf(equipo equipos[])
{

 equipo auxiliar;
for (int i=0; i<32; i++) {
    for (int j=0; j<32-i; j++)
    {
        if (strcmp(equipos[i].confederacion, equipos[j].confederacion) < 0)
        {
        auxiliar=equipos[i];
        equipos[i] = equipos[j];
        equipos[j] = auxiliar;
        }
    }
}
for(int z=0;z<32;z++)
{
    cout << equipos[z].nombre << "  " <<equipos[z].confederacion<< "  "<<equipos[z].grupo <<endl;
}

}

void leerArchivo(equipo equipos[])
{
       FILE *f;
       f=fopen(dirGrupoA,"rb");
       fread(equipos,sizeof(equipo),4,f);
       fclose(f);
        f=fopen(dirGrupoB,"rb");
       fread(equipos,sizeof(equipo),4,f);
       fclose(f);
        f=fopen(dirGrupoC,"rb");
       fread(equipos,sizeof(equipo),4,f);
       fclose(f);
        f=fopen(dirGrupoD,"rb");
       fread(equipos,sizeof(equipo),4,f);
       fclose(f);
        f=fopen(dirGrupoE,"rb");
       fread(equipos,sizeof(equipo),4,f);
       fclose(f);
        f=fopen(dirGrupoF,"rb");
       fread(equipos,sizeof(equipo),4,f);
       fclose(f);
        f=fopen(dirGrupoG,"rb");
       fread(equipos,sizeof(equipo),4,f);
       fclose(f);
        f=fopen(dirGrupoH,"rb");
       fread(equipos,sizeof(equipo),4,f);
       fclose(f);

}

int main(){
equipo equipos[32];

leerArchivo(equipos);

cout << "Ordenado por nombre: " <<endl;
ordenaNombre(equipos);
cout << "Presione una tecla para continuar..." <<endl;
getche();
system("cls");

cout <<"Ordenado por grupo: " <<endl;
ordenaGrupo(equipos);
cout << "Presione una tecla para continuar..."<<endl;
getche();
system("cls");
cout << "Ordenado por confederacion: " <<endl;
ordenaConf(equipos);

}


