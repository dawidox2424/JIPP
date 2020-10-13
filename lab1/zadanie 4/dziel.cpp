#include <iostream>
#include <string.h>
#include <math.h>
using namespace std;

long int suma(long int a)
{
long int suma_dzielnikow=0;
for(int i=1; i<a; i++) 
    {
        if(a % i == 0)
        {
            suma_dzielnikow += i;
        }
    }
    return suma_dzielnikow;
}

int main() 
{
    long int a;
    long int b;
    
    cout << "Podaj liczbe calkowita a: ";
    cin >> a;
    cout << endl;
    cout << "Podaj liczbe calkowita b: ";
    cin >> b;
    cout << endl;

    if (suma(a) == b+1 && suma(b) == a+1)
    {
        cout << "Liczby " << a << " oraz " << b << " sa skojarzone!";
        cout << endl;
    } else cout << "Liczby nie sa skojarzone" << endl;
   
   

    return 0;
}