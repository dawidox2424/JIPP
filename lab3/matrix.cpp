#include <iostream>
#include <conio.h>
#include <windows.h>
#include "matrix.hpp"
using namespace std;


matrix::matrix(int x,int y)
{
    this->x = x;
    this->y = y;

matrix::mac = new double*[x];
for (int t=0; t<x; t++)
{
matrix::mac[t] = new double[y];
}
    for (int n=0; n<x; n++)
        for (int k=0; k<y; y++)
        mac[n][k] = 0;
}

matrix::matrix(int x)
{
    matrix::x = x;
    matrix::mac = new double*[x];

    for (int n=0; n<x; n++)
        for (int k=0; k<x; k++)
        mac[n][k] = 0;

}

void matrix::set(int x,int y, double value)
{
    mac[x][y] = value;
}

double matrix::get(int x,int y)
{
    return mac[x][y];
}


int matrix::cols()
{
    cout << x << endl;
}

int matrix::rows()
{
    cout << y << endl;
}

void matrix::print()
{
    for (int i=0; i<x; i++)
        for (int j=0; j<y; j++)
       cout << mac[x][y] << endl;
}

