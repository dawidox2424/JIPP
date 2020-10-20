#include <iostream>
using namespace std;


/* Napisz funkcję otrzymującą jako argumenty wskaźniki 
do dwóch zmiennych typu int, która zamienia ze 
sobą wartości wskazywanych zmiennych tylko wtedy
 gdy wskazywana przez drugi argument zmienna jest 
 mniejsza od zmiennej wskazywanej przez pierwszy argument. */

 void fun1(int *wsk_a,int *wsk_b)
 {
     if(*wsk_a > *wsk_b)
     {
        int temp;
        temp = *wsk_a;
        *wsk_a = *wsk_b;
        *wsk_b = temp;
     }
 }

int main()
{
    int a=0;
    int b=0;

    int *ptr_a =&a; //wskaznik na adres a
    int *ptr_b =&b; //wskaznik na adres b

    cout << "Podaj a:";
    cin >> a;
    cout << endl;
    cout << "Podaj b:";
    cin >> b;

    
   fun1(ptr_a,ptr_b);

    cout << "a:" << a << endl;
    cout << "b:" << b << endl;

return 0;
}



