#include <iostream>
using namespace std;

/* Napisz funkcję otrzymującą dwa argumenty referencję a oraz wskaźnik b do zmiennych typu int, 
która zamienia ze sobą wartości zmiennych, do których wskaźnik i referencję dostała w argumentach. */

 void fun3(int &ref_a,int *wsk_b)
 {
     int temp = ref_a;
     ref_a = *wsk_b;
     *wsk_b = temp;
 }

int main()
{
    int a=0;
    int b=0;

    int &ref_a = a;
    int *ptr_b = &b; 

    cout << "Podaj a:";
    cin >> a;
    cout << endl;
    cout << "Podaj b:";
    cin >> b;

    fun3(ref_a, ptr_b);

    cout << "Po wyk. funkcji, a:" << a << " oraz b:" << b << endl;



return 0;
}



