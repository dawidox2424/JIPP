#include <iostream>
using namespace std;

/* Napisz funkcję otrzymującą jako argumenty referencje do dwóch zmiennych typu int,
 która zamienia ze sobą wartości zmiennych, do których referencje dostaliśmy w argumentach. */


 void fun2(int &ref1,int &ref2)
 {
     int temp;
     temp = ref1;
     ref1=ref2;
     ref2=temp;
 }

int main()
{
    int a=0;
    int b=0;

    int &ref_a = a;
    int &ref_b = b;

    cout << "Podaj a:";
    cin >> a;
    cout << endl;
    cout << "Podaj b:";
    cin >> b;

    fun2(ref_a,ref_b);

    cout << "Po wyk. funkcji, a:" << a << " oraz b:" << b << endl;



return 0;
}



