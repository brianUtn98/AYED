#include<conio.h>
#include<stdio.h>
#include <iostream>
using namespace std;

int f(int n){
    if(n<=1){
             return n;                 
}
    else 
         {
             cout << n<<endl;
             return f(n-1)+f(n-2);
          
}
}  
int main(){
int n;
cout << "Ingrese un numero para determinar su sucesion de fibonacci" <<endl;
cin >> n;
cout << "La sucesion de fibonacci de " <<n << " es: " << f(n) <<endl;
getche();
}      
