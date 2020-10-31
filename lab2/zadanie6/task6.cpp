#include <iostream>
#include <algorithm>
using namespace std;

template < class T > void swap( T **a, T **b )
    {
        T* temp = *a;
        *a = *b;
        *b = temp;
    }


int main()
{

    int a = 5; // deklaracja zmiennych typu int
    int b = 7;


    int *wskA = &a; // deklaracja wskazników
    int *wskB = &b;

    cout << "Przed:" << endl;
    cout << "a:" << *wskA << endl;
    cout << "b:" << *wskB << endl;

    swap(a,b);

    cout << "Po:" << endl;
    cout << "a:" << *wskA << endl;
    cout << "b:" << *wskB << endl;

    string napis1 = "Arbuz";
    string napis2 = "Melon";

    string *wsk1 = &napis1; // deklaracja wskazników
    string *wsk2 = &napis2;

    cout << "Przed:" << endl;
    cout << "NAPIS1:" << *wsk1 << endl;
    cout << "NAPIS2:" << *wsk2 << endl;

    swap(wsk1,wsk2);

    cout << "Po:" << endl;
    cout << "NAPIS1:" << *wsk1 << endl;
    cout << "NAPIS2:" << *wsk2 << endl;



}