#include <iostream>
#include <conio.h>
#include <windows.h>
#include "matrix.hpp"
#include <fstream>
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
        for (int k=0; k<y; k++)
        mac[n][k] = 0;
}

matrix::matrix(int x)
{
    matrix::x = x;
    matrix::mac = new double*[x];

    for (int t=0; t<x; t++)
{
matrix::mac[t] = new double[x];
}

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
    return x;
}

int matrix::rows()
{
    return y;
}

void matrix::print()
{
    cout << endl;
    for (int i=0; i<x; i++)
    {
    for (int j=0; j<y; j++)
    {
    cout << mac[i][j] << " ";
    }
    cout << endl;
    }
}

matrix matrix::add(matrix m2)
{
    matrix m3(this->x,this->y);

    for (int i=0; i<x; i++)
        for (int j=0; j<y; j++)
            m3.mac[i][j] = m2.mac[i][j] + this->mac[i][j];

            return m3;
}

matrix matrix::subtract(matrix m2)
{
    matrix m3(this->x,this->y);

    for (int i=0; i<x; i++)
        for (int j=0; j<y; j++)
            m3.mac[i][j] = this->mac[i][j] - m2.mac[i][j];

            return m3;
}

matrix matrix::multiply(matrix m2)
{
    matrix m3(this->x,m2.y);

    for (int i=0; i<x; i++)
        for (int j=0; j<y; j++)
            m3.mac[i][j] += this->mac[i][j] * m2.mac[i][j];

            return m3;
}


void matrix::store(string filename,string path)
{   
    //fstream plik;
    ofstream file(path);
 
    if(file)    
    {
        file << "Wymiary macierzy:" << this->x << " oraz " << this->y << endl;
        file << endl;
        for (int i=0; i<x; i++)
        {
        for (int j=0; j<y; j++)
        {
        file << mac[i][j] << " ";
        }
        file << endl;
        }
        }
    else
    {
        cout << "can't open the file !" << endl;
    }
}


