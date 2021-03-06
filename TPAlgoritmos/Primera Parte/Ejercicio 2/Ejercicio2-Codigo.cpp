#include<conio.h>
#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<cstdlib> //librer�a que contiene funcion rand
#include<time.h>  // funcion que contiene funcion time
#include<fstream>

#define dirArchivo "Ejercicio2-Equipos.txt"
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

void inicializaGrupo(equipo equipos[], int inicio)
{
     for (int i=inicio; i<32; i++)
     {
         equipos[i].grupo='X';
         }
}


bool chequeoAleatorio(int aleatorio, int contadorAleatorio[])
{
    for(int i=0; i<8; i++)
        if(aleatorio == contadorAleatorio[i])
            return true;
    return false;
}

void generarAleatorio(int contadorAleatorio[]){
int aleatorio;
for(int j=0;j<8;j++)
contadorAleatorio[j]=0;
for(int i=0;i<8;i++){
   srand(time(0));
    do{
    aleatorio=1+rand()%8;
    }
    while(chequeoAleatorio(aleatorio,contadorAleatorio));
    contadorAleatorio[i]=aleatorio;
}
}

void leerArchivo(equipo equipos[]){
FILE *f;
if(f=fopen(dirArchivo,"rb"))
     {
             fread(equipos,sizeof(equipo),32,f);
             cout << "|Bolillero| |Grupo|  |Nombre| |Confederacion| " <<endl;
             for(int i=0;i<32;i++)
             {
             cout << equipos[i].bolillero << "            " << equipos[i].grupo << "         " << equipos[i].nombre << "     "  << equipos[i].confederacion <<endl;
             fread(equipos,sizeof(equipo),1,f);

             }


     }
     else
     {
             cout << "NO se ha podido abrir el archivo" << endl;
     }
             fclose(f);
             cout << "Presione una tecla para continuar..." << endl;
             getche();
             system("cls");

}


void leerVector(equipo equipos[]){
 cout << "|Bolillero| |Nombre| |Confederacion| " <<endl;
for(int i=0;i<32;i++)
   {

    cout << equipos[i].bolillero << "            " << equipos[i].grupo << "         " << equipos[i].nombre << "     "  << equipos[i].confederacion <<endl;
   }
}


bool chequeoUefa(equipo equipos[], char grupo){
	int contUefa=0;
	bool error;
	for(int i=0;i<32;i++)
	{
		if(equipos[i].grupo==grupo && strcmp(equipos[i].confederacion,"UEFA")==0)
		contUefa++;
	}
	if(contUefa>=2)
	error=true;
	else
	error=false;
	return error;


}
bool chequeoConfederacion(equipo equipos[],char grupo, int pos)
{
	bool error;
	for(int i=0;i<32;i++)
	{
		if(equipos[i].grupo==grupo && strcmp(equipos[i].confederacion,equipos[pos].confederacion)==0)
        {
				if(strcmp(equipos[pos].confederacion,"UEFA")==0)
				error=chequeoUefa(equipos, grupo);
				else
				error=true;
		}
		else
		error=false;
	}
	return error;
}

/* Esta funcion ira paso a paso, respetando lo asignado por la catedra */
void sorteaGrupo(equipo equipos[]){
    int ctrlUefa1=0,ctrlUefa2=0,ctrlUefa3=0,ctrlUefa4=0,ctrlUefa5=0,ctrlUefa6=0,ctrlUefa7=0,ctrlUefa8=0;
// Paso 1,
// en orden de salida, cada equipo del primer bolillero sera cabeza de cada grupo.
cout << "Comenzando primer etapa del sorteo..." <<endl;
equipos[0].grupo='A'; equipos[1].grupo='B'; equipos[2].grupo='C'; equipos[3].grupo='D'; equipos[4].grupo='E'; equipos[5].grupo='F'; equipos[6].grupo='G'; equipos[7].grupo='H';
cout << "Primer bolillero sorteado satifactoriamente. Presione una tecla para continuar..." <<endl;
getche();
system("cls");
int aleatorio;
int i=0,j=0;
bool error=false;




/*Paso 2*/
 //En este paso solo se debe comprobar que no se repita un equipo de conmebol (siendo Brazil del grupo C y Argentina del E.
 /* Las posiciones de este vector iran cargadas con valores del 1 al 8.*/
cout << "Comenzando segunda etapa del sorteo..." <<endl;
  int contadorAleatorio[8]={0,0,0,0,0,0,0,0};
    int auxiliar[8]={0,0,0,0,0,0,0,0};
while(error==true);
{
    generarAleatorio(contadorAleatorio);
    inicializaGrupo(equipos,8);
    for(int i=0;i<8;i++){
    switch(contadorAleatorio[i]){
    case 1: equipos[i+8].grupo='A';
    break;
    case 2: equipos[i+8].grupo='B';
    break;
    case 3: if(strcmp(equipos[i+8].confederacion,equipos[2].confederacion)==0)
            {
            i--;
            generarAleatorio(contadorAleatorio);

            }
            else
            {
            equipos[i+8].grupo='C';
            error=false;
            }
    break;
    case 4: equipos[i+8].grupo='D';
    break;
    case 5: if(strcmp(equipos[i+8].confederacion,equipos[4].confederacion)==0)
            {
            i--;
            generarAleatorio(contadorAleatorio);
            }
            else
            {
            equipos[i+8].grupo='E';
            error=false;
            }
    break;
    case 6: equipos[i+8].grupo='F';
    break;
    case 7: equipos[i+8].grupo='G';
    break;
    case 8: equipos[i+8].grupo='H';
    break;

    }
    }
}
cout << "Segundo bolillero sorteado satifactoriamente. Presione una tecla para continuar..." <<endl;
getche();
system("cls");

/*Paso 3*/

cout << "Comenzando tercera etapa del sorteo..." <<endl;
error=true;
int pos=0;
char grupo;
while(error==true)
{
generarAleatorio(contadorAleatorio);
 inicializaGrupo(equipos,16);
	for(i=0;i<8;i++)
	{
	    pos=i+16;

	switch(contadorAleatorio[i])
		{
		case 1:
        grupo='A';
		error=chequeoConfederacion(equipos,grupo,pos);
            if(error==true)
            {
            generarAleatorio(contadorAleatorio);
            i--;
            }
            else
            {
            equipos[i+16].grupo='A';
            }
		break;
		case 2:
        grupo='B';
        error=chequeoConfederacion(equipos,grupo,pos);
             if(error==true)
            {
            generarAleatorio(contadorAleatorio);
            i--;
            }
            else
            {
            equipos[i+16].grupo='B';
            }
        break;
        case 3:
        grupo='C';
        error=chequeoConfederacion(equipos,grupo,pos);
             if(error==true)
            {
            i--;
            generarAleatorio(contadorAleatorio);
            }
            else
            {
            equipos[i+16].grupo='C';
            }
        break;
        case 4:
        grupo='D';
        error=chequeoConfederacion(equipos,grupo,pos);
             if(error==true)
            {
            i--;
            generarAleatorio(contadorAleatorio);
            }
            else
            {
            equipos[i+16].grupo='D';
            }
        break;
        case 5:
        grupo='E';
        error=chequeoConfederacion(equipos,grupo,pos);
             if(error==true)
            {
            i--;
            generarAleatorio(contadorAleatorio);
            }
            else
            {
            equipos[i+16].grupo='E';
            }
        break;
        case 6:
        grupo='F';
        error=chequeoConfederacion(equipos,grupo,pos);
             if(error==true)
            {
            i--;
            generarAleatorio(contadorAleatorio);
            }
            else
            {
            equipos[i+16].grupo='F';
            }
        break;
        case 7:
        grupo='G';
        error=chequeoConfederacion(equipos,grupo,pos);
             if(error==true)
            {
            i--;
            generarAleatorio(contadorAleatorio);
            }
            else
            {
            equipos[i+16].grupo='G';
            }
        break;
        case 8:
        grupo='H';
        error=chequeoConfederacion(equipos,grupo,pos);
             if(error==true)
            {
            i--;
            generarAleatorio(contadorAleatorio);
            }
            else
            {
            equipos[i+16].grupo='H';
            }
        break;
		}
	}
}


cout << "Tercer bolillero sorteado satifactoriamente. Presione una tecla para continuar..." <<endl;
getche();
system("cls");

/*Paso 4*/
error=true;
pos=0;
generarAleatorio(contadorAleatorio);

while(error==true)
{
generarAleatorio(contadorAleatorio);
 inicializaGrupo(equipos,24);
	for(i=0;i<8;i++)
	{
	    pos=i+24;

	switch(contadorAleatorio[i])
		{
		case 1:
        grupo='A';
		error=chequeoConfederacion(equipos,grupo,pos);
            if(error==true)
            {
            generarAleatorio(contadorAleatorio);
            i--;
            }
            else
            {
            equipos[i+24].grupo='A';
            }
		break;
		case 2:
        grupo='B';
        error=chequeoConfederacion(equipos,grupo,pos);
             if(error==true)
            {
            generarAleatorio(contadorAleatorio);
            i--;
            }
            else
            {
            equipos[i+24].grupo='B';
            }
        break;
        case 3:
        grupo='C';
        error=chequeoConfederacion(equipos,grupo,pos);
             if(error==true)
            {
            i--;
            generarAleatorio(contadorAleatorio);
            }
            else
            {
            equipos[i+24].grupo='C';
            }
        break;
        case 4:
        grupo='D';
        error=chequeoConfederacion(equipos,grupo,pos);
             if(error==true)
            {
            i--;
            generarAleatorio(contadorAleatorio);
            }
            else
            {
            equipos[i+24].grupo='D';
            }
        break;
        case 5:
        grupo='E';
        error=chequeoConfederacion(equipos,grupo,pos);
             if(error==true)
            {
            i--;
            generarAleatorio(contadorAleatorio);
            }
            else
            {
            equipos[i+24].grupo='E';
            }
        break;
        case 6:
        grupo='F';
        error=chequeoConfederacion(equipos,grupo,pos);
             if(error==true)
            {
            i--;
            generarAleatorio(contadorAleatorio);
            }
            else
            {
            equipos[i+24].grupo='F';
            }
        break;
        case 7:
        grupo='G';
        error=chequeoConfederacion(equipos,grupo,pos);
             if(error==true)
            {
            i--;
            generarAleatorio(contadorAleatorio);
            }
            else
            {
            equipos[i+24].grupo='G';
            }
        break;
        case 8:
        grupo='H';
        error=chequeoConfederacion(equipos,grupo,pos);
             if(error==true)
            {
            i--;
            generarAleatorio(contadorAleatorio);
            }
            else
            {
            equipos[i+24].grupo='H';
            }
        break;
		}
	}
}

cout << "Cuarto bolillero sorteado satifactoriamente. Presione una tecla para continuar..." <<endl;
getche();
system("cls");




for(i=0;i<32;i++){
    cout << equipos[i].nombre << "  " << equipos[i].confederacion << "  " << equipos[i].grupo << endl;
}


FILE *f;
equipo auxVec[32];
int k=0;
    for(j=0;j<32;j++)
    {
        if(equipos[j].grupo=='A')
        {
        auxVec[j].bolillero=equipos[j].bolillero;
        strcpy(auxVec[j].confederacion,equipos[j].confederacion);
        strcpy(auxVec[j].nombre,equipos[j].nombre);
        auxVec[j].grupo='A';
        k++;
        }
    }
    f=fopen(dirGrupoA,"ab");

    fwrite(auxVec,sizeof(equipo),4,f);
    fclose(f);
    k=0;
     for(j=0;j<32;j++)
    {
        if(equipos[j].grupo=='B')
        {
        auxVec[j].bolillero=equipos[j].bolillero;
        strcpy(auxVec[j].confederacion,equipos[j].confederacion);
        strcpy(auxVec[j].nombre,equipos[j].nombre);
        auxVec[j].grupo='B';
        k++;
        }
    }
    f=fopen(dirGrupoB,"ab");

    fwrite(auxVec,sizeof(equipo),4,f);
    fclose(f);
    k=0;
     for(j=0;j<32;j++)
    {
        if(equipos[j].grupo=='C')
        {
        auxVec[j].bolillero=equipos[j].bolillero;
        strcpy(auxVec[j].confederacion,equipos[j].confederacion);
        strcpy(auxVec[j].nombre,equipos[j].nombre);
        auxVec[j].grupo='C';
        k++;
        }
    }
    f=fopen(dirGrupoC,"ab");

    fwrite(auxVec,sizeof(equipo),4,f);
    fclose(f);
    k=0;
     for(j=0;j<32;j++)
    {
        if(equipos[j].grupo=='D')
        {
        auxVec[j].bolillero=equipos[j].bolillero;
        strcpy(auxVec[j].confederacion,equipos[j].confederacion);
        strcpy(auxVec[j].nombre,equipos[j].nombre);
        auxVec[j].grupo='D';
        k++;
        }
    }
    f=fopen(dirGrupoD,"ab");

    fwrite(auxVec,sizeof(equipo),4,f);
    fclose(f);
    k=0;
     for(j=0;j<32;j++)
    {
        if(equipos[j].grupo=='E')
        {
        auxVec[j].bolillero=equipos[j].bolillero;
        strcpy(auxVec[j].confederacion,equipos[j].confederacion);
        strcpy(auxVec[j].nombre,equipos[j].nombre);
        auxVec[j].grupo='E';
        k++;
        }
    }
    f=fopen(dirGrupoE,"ab");

    fwrite(auxVec,sizeof(equipo),4,f);
    fclose(f);
    k=0;
     for(j=0;j<32;j++)
    {
        if(equipos[j].grupo=='F')
        {
        auxVec[j].bolillero=equipos[j].bolillero;
        strcpy(auxVec[j].confederacion,equipos[j].confederacion);
        strcpy(auxVec[j].nombre,equipos[j].nombre);
        auxVec[j].grupo='F';
        k++;
        }
    }
    f=fopen(dirGrupoF,"ab");

    fwrite(auxVec,sizeof(equipo),4,f);
    fclose(f);
    k=0;
     for(j=0;j<32;j++)
    {
        if(equipos[j].grupo=='G')
        {
        auxVec[j].bolillero=equipos[j].bolillero;
        strcpy(auxVec[j].confederacion,equipos[j].confederacion);
        strcpy(auxVec[j].nombre,equipos[j].nombre);
        auxVec[j].grupo='G';
        k++;
        }
    }
    f=fopen(dirGrupoG,"ab");

    fwrite(auxVec,sizeof(equipo),4,f);
    fclose(f);
    k=0;
     for(j=0;j<32;j++)
    {
        if(equipos[j].grupo=='H')
        {
        auxVec[j].bolillero=equipos[j].bolillero;
        strcpy(auxVec[j].confederacion,equipos[j].confederacion);
        strcpy(auxVec[j].nombre,equipos[j].nombre);
        auxVec[j].grupo='H';
        k++;
        }
    }
    f=fopen(dirGrupoH,"ab");

    fwrite(auxVec,sizeof(equipo),4,f);
    fclose(f);
}


int main(){
    equipo equipos[32];
    char opcion;
    cout << "Presione una tecla para leer el archivo." << endl;
    getche();
    leerArchivo(equipos);
    system("cls");
    cout << "�Desea sortear grupos? (S o N) " <<endl;
    cin >> opcion;
    if(opcion=='S' || opcion=='s')
    {
    system("cls");
    sorteaGrupo(equipos);
    }

    cout << "Gracias por su visita..." <<endl;
    getche();
    return 0;
    }
