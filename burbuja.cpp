#include<conio.h>
#include<iostream>
using namespace std;
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
int main(){
int array[5]={2,4,5,1,3};
int v;
for(v=0;v<=4;v++)
{
                 cout <<array[v]<<endl;
}
cout <<"Ahora ordenamos"<<endl;
getche();
cout <<endl;
system ("cls");
burbuja(array);

for(v=0;v<=4;v++)
{
                 cout <<array[v]<<endl;
}
getche();
}
