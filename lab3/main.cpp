#include <iostream>
#include <conio.h>
#include <windows.h>
#include "matrix.cpp"
#include <fstream>
using namespace std;


int main()
{
    cout << "Witaj! swiecie" << endl;

    matrix pierwsza(3,3);
    pierwsza.set(0,0,9);
    pierwsza.set(0,1,12);
    pierwsza.set(1,0,10);

    matrix druga(3,3);
    druga.set(0,0,11);
    druga.set(0,1,11);
    druga.set(1,0,10);

    pierwsza.print();
    druga.print();

    matrix trzecia = pierwsza.multiply(druga);

    trzecia.print();

    trzecia.store("test","test.txt");

    return 0;
}

