#include<conio.h>
#include<iostream>
#define tam 5
using namespace std;

int busqueda(const int array[],int dato){
int min,max,mid;
bool flag=0;
min=0;
max=tam;
mid=(max+min)/2;

                while(min <= max)
                {
                          if(array[mid]==dato)
                          {
                                   flag=1;
                                   break;
                                   }
                          if(array[mid]>dato)
                          {
                                 
                                  max=mid-1;
                                  mid=(max+min)/2;
                                  }
                          if(array[mid]<dato)
                          {
                                  
                                  min=mid+1;
                                  mid=(max+min)/2;
                                  }

                }
                return flag;
}
void burbuja(int array[]){
int i,j,aux;
    for(i=0;i<5;i++)
    {
                    for(j=0;j<5-i;j++)
                    {
                    if(array[j]>array[j+1])
                    {
                    aux=array[j];
                    array[j]=array[j+1];
                    array[j+1]=aux;
                    }
                    }
    }
  

}

int main()
{
int dato,i,w;
bool v;
int array[5]={3,4,5,6,7};
burbuja(array);
for(w=0;w<5;w++)
{
                cout<<array[w]<<endl;
}
v=busqueda(array,3);
cout <<"Ahora se ordena"<<endl;
getche();
cout <<endl;

if(v==1)
{
        cout << "Se encontró el valor" <<endl;
}       
else
{
    cout << "Valor no encontrado" <<endl;
}

getche();
}
