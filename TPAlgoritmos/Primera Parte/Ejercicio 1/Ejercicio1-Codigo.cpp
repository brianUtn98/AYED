#include<conio.h>
#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<string.h>

#define dirArchivo "Ejercicio1-Equipos.txt"
using namespace std;

struct equipo
{
      char nombre[10];
       char confederacion[10];
       int bolillero;
       char grupo;
};
// cargaEquipos recibe un vector del tipo struct equipo, y carga los 32 equipos en sus respectivas posiciones.
//Agregando Nombre, Confederacion y Bolillero de acuerdo a la tabla dada por la cátedra
void cargaEquipos(equipo equipos[])
     {
		 //usamos strcpy dado que se trata de un vector de caracteres, ya que un dato de tipo string rompería la estructura del archivo
	strcpy(equipos[0].nombre, "RUS");  strcpy(equipos[0].confederacion, "AFC"); equipos[0].bolillero=1;
   	strcpy(equipos[1].nombre, "ALE");  strcpy(equipos[1].confederacion, "UEFA"); equipos[1].bolillero=1;
   	strcpy(equipos[2].nombre, "BRA");  strcpy(equipos[2].confederacion, "CONMEBOL"); equipos[2].bolillero=1;
   	strcpy(equipos[3].nombre, "POR");  strcpy(equipos[3].confederacion, "UEFA"); equipos[3].bolillero=1;
   	strcpy(equipos[4].nombre, "ARG");  strcpy(equipos[4].confederacion, "CONMEBOL"); equipos[4].bolillero=1;
   	strcpy(equipos[5].nombre, "BEL");  strcpy(equipos[5].confederacion, "UEFA"); equipos[5].bolillero=1;
   	strcpy(equipos[6].nombre, "POL");  strcpy(equipos[6].confederacion, "UEFA"); equipos[6].bolillero=1;
   	strcpy(equipos[7].nombre, "FRA");  strcpy(equipos[7].confederacion, "UEFA"); equipos[7].bolillero=1;
   	strcpy(equipos[8].nombre, "ESP");  strcpy(equipos[8].confederacion, "UEFA"); equipos[8].bolillero=2;
   	strcpy(equipos[9].nombre, "PER");  strcpy(equipos[9].confederacion, "CONMEBOL"); equipos[9].bolillero=2;
   	strcpy(equipos[10].nombre, "SUI");  strcpy(equipos[10].confederacion, "UEFA"); equipos[10].bolillero=2;
   	strcpy(equipos[11].nombre, "ENG");  strcpy(equipos[11].confederacion, "UEFA"); equipos[11].bolillero=2;
   	strcpy(equipos[12].nombre, "COL");  strcpy(equipos[12].confederacion, "CONMEBOL"); equipos[12].bolillero=2;
   	strcpy(equipos[13].nombre, "MEX");  strcpy(equipos[13].confederacion, "CONCACAF"); equipos[13].bolillero=2;
   	strcpy(equipos[14].nombre, "URU");  strcpy(equipos[14].confederacion, "CONMEBOL"); equipos[14].bolillero=2;
   	strcpy(equipos[15].nombre, "CRO");  strcpy(equipos[15].confederacion, "UEFA"); equipos[15].bolillero=2;
   	strcpy(equipos[16].nombre, "DEN");  strcpy(equipos[16].confederacion, "UEFA"); equipos[16].bolillero=3;
   	strcpy(equipos[17].nombre, "ISL");  strcpy(equipos[17].confederacion, "UEFA"); equipos[17].bolillero=3;
   	strcpy(equipos[18].nombre, "CRC");  strcpy(equipos[18].confederacion, "CONCACAF"); equipos[18].bolillero=3;
   	strcpy(equipos[19].nombre, "SWE");  strcpy(equipos[19].confederacion, "UEFA"); equipos[19].bolillero=3;
   	strcpy(equipos[20].nombre, "TUN");  strcpy(equipos[20].confederacion, "CAF"); equipos[20].bolillero=3;
   	strcpy(equipos[21].nombre, "EGY");  strcpy(equipos[21].confederacion, "CAF"); equipos[21].bolillero=3;
   	strcpy(equipos[22].nombre, "SEN");  strcpy(equipos[22].confederacion, "CAF"); equipos[22].bolillero=3;
   	strcpy(equipos[23].nombre, "IRN");  strcpy(equipos[23].confederacion, "AFC"); equipos[23].bolillero=3;
   	strcpy(equipos[24].nombre, "SRB");  strcpy(equipos[24].confederacion, "UEFA"); equipos[24].bolillero=4;
   	strcpy(equipos[25].nombre, "NGA");  strcpy(equipos[25].confederacion, "CAF"); equipos[25].bolillero=4;
   	strcpy(equipos[26].nombre, "AUS");  strcpy(equipos[26].confederacion, "AFC"); equipos[26].bolillero=4;
   	strcpy(equipos[27].nombre, "JPN");  strcpy(equipos[27].confederacion, "AFC"); equipos[27].bolillero=4;
   	strcpy(equipos[28].nombre, "MAR");  strcpy(equipos[28].confederacion, "CAF"); equipos[28].bolillero=4;
   	strcpy(equipos[29].nombre, "PAN");  strcpy(equipos[29].confederacion, "CONCACAF"); equipos[29].bolillero=4;
   	strcpy(equipos[30].nombre, "KOR");  strcpy(equipos[30].confederacion, "AFC"); equipos[30].bolillero=4;
   	strcpy(equipos[31].nombre, "KSA");  strcpy(equipos[31].confederacion, "AFC"); equipos[31].bolillero=4;
   	cout << "Los equipos han sido cargados satifactoriamente" <<endl;
   	getche();
   	system("cls");


     }

// escribirArchivo recibe el vector de tipo struct equipo, y lo escribe en un archivo binario.
        void escribirArchivo(equipo equipos[]){
         FILE *f;
             if(f=fopen(dirArchivo,"wb")) //Si el archivo se abre devolverá un valor que hará verdadera la respuesta a la condición. Sinó, devolverá 0 y será falso.
             {

                     fwrite(equipos, sizeof(equipo),32,f); //escribe los 32 equipos a la ves.
                     cout << "El archivo ha sido cargado satifactoriamente" <<endl;
             }
             else
             {
                     cout << "No se ha podido abrir el archivo" << endl;
             }
                     fclose(f); // cierra el archivo
                    getche();
                    system("cls");
        }

void leerArchivo(){
FILE *f;
if(f=fopen(dirArchivo,"rb"))
     {
             equipo equipos[32];
             fread(equipos,sizeof(equipo),32,f);
             cout << "|Bolillero| |Nombre| |Confederacion| " <<endl;
             for(int i=0;i<32;i++)
             {
             cout << equipos[i].bolillero << "            " << equipos[i].nombre << "      " << equipos[i].confederacion << endl;
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
 cout << equipos[i].bolillero << "            " << equipos[i].nombre << "      " << equipos[i].confederacion << endl;
}
cout << "Presione una tecla para continuar..." <<endl;
getche();
system("cls");
}


int Menu(){
	int opcion;
cout << "Bienvenido al programa orientado al mundial Rusia 2018. Seleccione una opcion." <<endl;
cout << "[1] Cargar equipos automaticamente." <<endl;
cout << "[2] Leer vector de equipos." <<endl;
cout << "[3] Cargar archivo de equipos." << endl;
cout << "[4] Leer archivo de equipos." << endl;
cout << "[5] Salir del programa.  " <<endl;
cin >> opcion;
return opcion;
}

void inicializarGrupo(equipo equipos[]){

for(int i=0;i<32;i++)
equipos[i].grupo='X';

}
int main()
{

	equipo equipos[32];
	int opcion;
	char aux;
    inicializarGrupo(equipos);
	do
	{

	opcion=Menu();
switch(opcion){
case 1: system("cls"); cargaEquipos(equipos); break;
case 2: system("cls"); leerVector(equipos); break;
case 3: system("cls"); escribirArchivo(equipos);  break;
case 4: system("cls"); leerArchivo(); break;
case 5: system("cls");
                       cout <<  "¿Esta seguro que desea salir? (S/N)"<<endl;
                       cin >> aux;
                       if(aux=='S' || aux=='s'){
                        cout << "Gracias por su visita." <<endl; getche();
						exit(-1);}
                       else{
                        system("cls");
                        }
break;
}
}
while((aux!='s' || aux!='S'));









getche();


}
